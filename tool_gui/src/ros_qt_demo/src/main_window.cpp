/**
 * @file /src/main_window.cpp
 *
 * @brief Implementation for the qt gui.
 *
 * @date February 2011
 **/
/*****************************************************************************
** Includes
*****************************************************************************/

#include <QtGui>
#include <QMessageBox>
#include <iostream>
#include "../include/ros_qt_demo/main_window.hpp"

/*****************************************************************************
** Namespaces
*****************************************************************************/

namespace class1_ros_qt_demo {

using namespace Qt;

/*****************************************************************************
** Implementation [MainWindow]
*****************************************************************************/

MainWindow::MainWindow(int argc, char** argv, QWidget *parent)
	: QMainWindow(parent)
	, qnode(argc,argv)
{
	ui.setupUi(this); // Calling this incidentally connects all ui's triggers to on_...() callbacks in this class.
    QObject::connect(ui.actionAbout_Qt, SIGNAL(triggered(bool)), qApp, SLOT(aboutQt())); // qApp is a global variable for the application

    // 创建状态栏
    QStatusBar *statusBar = new QStatusBar(this);
    setStatusBar(statusBar);

    // 创建标签和对应的LineEdit
    QLabel *labelX = new QLabel("X:", this);
    QLabel *labelY = new QLabel("Y:", this);
    QLabel *labelZ = new QLabel("Z:", this);
    QLabel *labelRoll = new QLabel("Roll:", this);
    QLabel *labelPitch = new QLabel("Pitch:", this);
    QLabel *labelYaw = new QLabel("Yaw:", this);
    // 添加数据控件到状态栏
    statusBar->addWidget(labelX);
    statusBar->addWidget(ui.lineEditX);
    ui.lineEditX->setFixedWidth(150);
    statusBar->addWidget(labelY);
    statusBar->addWidget(ui.lineEditY);
    ui.lineEditY->setFixedWidth(150);
    statusBar->addWidget(labelZ);
    statusBar->addWidget(ui.lineEditZ);
    ui.lineEditZ->setFixedWidth(150);
    statusBar->addWidget(labelRoll);
    statusBar->addWidget(ui.lineEditqRoll);
    ui.lineEditqRoll->setFixedWidth(150);
    statusBar->addWidget(labelPitch);
    statusBar->addWidget(ui.lineEditqPitch);
    ui.lineEditqPitch->setFixedWidth(150);
    statusBar->addWidget(labelYaw);
    statusBar->addWidget(ui.lineEditqYaw);
    ui.lineEditqYaw->setFixedWidth(150);
    //QObject::connect(ui.action_Connect, SIGNAL(triggered(bool)), this, SLOT(on_action_connect_triggered()));
    //QObject::connect(ui.action_Roscore, SIGNAL(triggered(bool)), this, SLOT(on_action_roscore_triggered()));
    // 连接action_Setting的triggered信号到相应的槽函数
    //connect(ui.action_Setting, &QAction::triggered, this, &MainWindow::on_action_Setting_triggered);
    //on_actionSetting_triggered函数名需要连接，但是on_action_Setting_triggered函数名就不需要连接了，会运行两次出现两个配置框

	setWindowIcon(QIcon(":/images/icon.png"));
    //ui.tab_manager->setCurrentIndex(0); // ensure the first tab is showing - qt-designer should have this already hardwired, but often loses it (settings?).
    QObject::connect(&qnode, SIGNAL(rosShutdown()), this, SLOT(close()));

    pointCloud2TopicList = QStringList()<< "/G0/laser_cloud_map" << "/G6/laser_cloud_map" << "/merge_cloud_map";
    /*********************
    ** Initialization
    **********************/
    #pragma region rViz 树组件设计代码
    //设置树组件头
    ui.treeWidget_layer->setHeaderLabels(QStringList() << "key" << "value");
    //设置拉伸最后列属性为false
    ui.treeWidget_layer->header()->setStretchLastSection(false);
    //设置所有列自动拉伸
    ui.treeWidget_layer->header()->setSectionResizeMode(QHeaderView::Stretch);
    ui.treeWidget_layer->hide();  // 隐藏 treeWidget_layer


//    this->setWindowFlags(Qt::FramelessWindowHint);//移除边框
//    this->showFullScreen();//全屏显示

    // 连接 customContextMenuRequested 信号到槽函数
    connect(&qnode, &QNode::translationDataReceived, this, &MainWindow::translationDataReceived);
//    connect(&qnode, &QNode::quatDataReceived, this, &MainWindow::quatDataReceived);
    connect(&qnode, &QNode::eulerDataReceived, this, &MainWindow::eulerDataReceived);
    connect(&qnode, &QNode::calibrationFinishedSignal, this, &MainWindow::onCalibrationFinishedSlot);

    setupPlot();  //曲线图

    // 连接qnode的信号和mainwindow的槽函数
    connect(&qnode, &QNode::fitnessScoreUpdated, this, &MainWindow::updateFitnessScorePlot);
    connect(qApp, &QCoreApplication::aboutToQuit, this, &MainWindow::onClose);
    // 设置groupBox为初始隐藏状态
    ui.groupBox->hide();
    /***********************************************************************************************
   *                                     设计Global Options树                                     *
   ***********************************************************************************************/
    Global = new QTreeWidgetItem(QStringList() << "全局设置");
    //设置图标
    Global->setIcon(0,QIcon("://rViz/options.png"));
    //加载根节点
    ui.treeWidget_layer->addTopLevelItem(Global);
    //设置默认展开
    Global->setExpanded(true);

    /*
   * 定义子节点1 ———— Fixed Frame(FixedFrame是RViz中用来表示“世界”坐标系的参考系。FixedFrame应该是相对于世界不动的，否则会导致显示错误)
   * 所有的固定数据应该转换到固定坐标系下。比如一堵墙的坐标应该是个固定数据吧。但如果我们把FixedFrame设置为“base_link”(机器人本体坐标系)的话，
   * 那么该坐标系会随着机器人运动而运动，那墙的坐标在该坐标系下也是运动的，这是不应该的。所以一般也不会把FixedFrame设置为“base_link”。
   * 而“map”是一个虚拟的世界坐标系，它的z轴指向正上方(天空)，它就是一个固定的坐标系，不会随着机器人运动而变化。
   */
    QTreeWidgetItem* FixedFrame = new QTreeWidgetItem(QStringList() << "固定坐标系");
    //初始化一个combobox
    FFCBox = new QComboBox();
    FFCBox->addItems(QStringList() << "world");                     //添加项
    FFCBox->setSizeAdjustPolicy(QComboBox::AdjustToMinimumContentsLength);  //设置尺寸调整策略为适应最小内容
    FFCBox->setEditable(true);                                              //设置可编辑
    //连接combobox当前文本更改信号与全局设置槽函数
    connect(FFCBox, &QComboBox::currentTextChanged, this, &MainWindow::slot_set_global_options);
    //添加子节点1
    Global->addChild(FixedFrame);
    //添加combobox于子节点1的第一列
    ui.treeWidget_layer->setItemWidget(FixedFrame, 1, FFCBox);

    /*
   * 定义子节点2 ———— Background Color
   */
    QTreeWidgetItem* BackgroundColor = new QTreeWidgetItem(QStringList() << "背景颜色");
    //添加子节点2
    Global->addChild(BackgroundColor);
    //初始化一个MyPalette对象
    BPalette = new MyPalette();
    //设置初始颜色
    BPalette->setColor(238, 238, 236);
    //添加mypalette于子节点2的第一列
    ui.treeWidget_layer->setItemWidget(BackgroundColor, 1, BPalette);
    //连接mypalette颜色改变信号与全局设置槽函数
    connect(BPalette, &MyPalette::colorchanged, this, &MainWindow::slot_set_global_options);

     #pragma endregion

     #pragma region rViz dock widget其他控件相关代码
    /* Qt的元对象系统会通过我们设置的槽函数的函数名自动匹配对应控件的信号，如果没有找到对应的信号，则会报出如下错误：
   * QMetaObject::connectSlotsByName: No matching signal for on_button_add_clicked()
   * 对于上面这个错误，因为我们实际上没有名为“button_add”的控件，所以找不到对应的"点击"信号
   * 而下方代码注释掉的原因也就是因为自动匹配的关系，无需再手动connect了
   */
//    connect(ui.button_add_layer, &QPushButton::clicked, this, &MainWindow::on_button_add_layer_clicked);
//    connect(ui.button_remove_layer, &QPushButton::clicked, this, &MainWindow::on_button_remove_layer_clicked);

    #pragma endregion

	/*********************
	** Logging
	**********************/
	ui.view_logging->setModel(qnode.loggingModel());
    QObject::connect(&qnode, SIGNAL(loggingUpdated()), this, SLOT(updateLoggingView()));

    connectMessageBox = new QMessageBox(this);
    connectMessageBox->setWindowTitle("Connect");
    connectMessageBox->setText("连接成功！！！");
    connectMessageBox->setStandardButtons(QMessageBox::NoButton);
    on_action_Roscore_triggered();
    sleep(1);
    on_action_Connect_triggered();

}

    MainWindow::~MainWindow() {
    }

/*****************************************************************************
** Implementation [Slots]
*****************************************************************************/

void MainWindow::showNoMasterMessage() {
	QMessageBox msgBox;
	msgBox.setText("Couldn't find the ros master.");
	msgBox.exec();
    close();
}

void MainWindow::showNoConnectMessage() {
    QMessageBox msgBox;
    msgBox.setText("Please Connect");
    msgBox.exec();
}

void MainWindow::showRepeatClickMessage() {
    QMessageBox msgBox;
    msgBox.setText("invalid！Repeat Click");
    msgBox.exec();
}

void MainWindow::showNoCalibMessage() {
    QMessageBox msgBox;
    msgBox.setText("请启动标定程序");
    msgBox.exec();
}

void MainWindow::showRoscoreMessage() {
    QMessageBox msgBox;
    msgBox.setText("roscore已打开");
    msgBox.exec();
}

/**
 * @brief 设置全局设置槽函数
 */
void MainWindow::slot_set_global_options()
{
    myviz->SetFixedFrame(FFCBox->currentText());                //设置固定坐标系
    myviz->SetPanelBackgroundColor(BPalette->currentColor());   //设置背景颜色
}



/***********************************************************************************************
 *                                向UI界面添加新图层相关控件方法定义                                 *
 ***********************************************************************************************/
/**
 * @brief 向QTreeidget添加PointCloud2顶层节点
 * @param QTreeWidget* treeWidget 待添加PointCloud2顶层节点的QTreeWidget指针
 */
QTreeWidgetItem* MainWindow::add_TreeWidgetItem_PointCloud2(QTreeWidget* treeWidget, QString& displayName, QString& topicName )
{
    QTreeWidgetItem* PointCloud2 = new QTreeWidgetItem(QStringList() << displayName);
    //设置图标
    PointCloud2->setIcon(0, QIcon("://rViz/PointCloud2.png"));
    //初始化一个checkbox
    QCheckBox* checkBox = new QCheckBox();
    //设置复选框默认选中状态
    checkBox->setCheckState(Qt::Checked);
    //连接checkbox状态改变信号与修改点云2图层属性槽函数
    connect(checkBox, &QCheckBox::stateChanged, this, &MainWindow::slot_modify_PointCloud2_attribute);
    //加载根节点
    treeWidget->addTopLevelItem(PointCloud2);
    //添加checkbox于根节点第一列
    treeWidget->setItemWidget(PointCloud2, 1, checkBox);
    //设置默认展开(默认展开应写在加载根节点后)
    PointCloud2->setExpanded(true);
    //设置用户数据
    //PointCloud2->setData(0, Qt::UserRole, AddLayer::pointcloud2);
    //PointCloud2->setData(0, Qt::UserRole, 0);

    /*
   * 定义子节点1 ———— topic
   */
    QTreeWidgetItem* PointCloud2Topic = new QTreeWidgetItem(QStringList() << "话题");
    //添加子节点1
    PointCloud2->addChild(PointCloud2Topic);
    //初始化一个combobox
    QComboBox* combobox = new QComboBox();
    combobox->addItems(pointCloud2TopicList);
    combobox->setCurrentIndex(1);                                              //设置默认显示
    combobox->setCurrentText(topicName);                                        //设置项(需要注意的是，如果topicName不匹配任何一个已经添加好的项，那么setCurrentText()方法将不起作用)
    combobox->setSizeAdjustPolicy(QComboBox::AdjustToMinimumContentsLength);    //设置尺寸调整策略为适应最小内容
    combobox->setEditable(true);                                                //设置可编辑
    //添加combobox于子节点1的第一列
    treeWidget->setItemWidget(PointCloud2Topic, 1, combobox);
    //连接combobox当前文本改变信号与修改点云2图层属性槽函数
    connect(combobox, &QComboBox::currentTextChanged, this, &MainWindow::slot_modify_PointCloud2_attribute);

    /*
   * 定义子节点2 ———— style
   */
    QTreeWidgetItem* PointCloud2RenderStyle = new QTreeWidgetItem(QStringList() << "渲染模式");
    //添加子节点2
    PointCloud2->addChild(PointCloud2RenderStyle);
    //初始化一个combobox
    QComboBox* StyleComboBox = new QComboBox();
    StyleComboBox->addItems(QStringList() << "Points");   //添加项
    StyleComboBox->setEditable(false);                                                                           //设置不可编辑
    StyleComboBox->setSizeAdjustPolicy(QComboBox::AdjustToMinimumContentsLength);                                //设置尺寸调整策略为适应最小内容
    //添加combobox于子节点2的第一列
    treeWidget->setItemWidget(PointCloud2RenderStyle, 1, StyleComboBox);
    //连接combobox当前文本改变信号与修改点云2图层属性槽函数
    connect(StyleComboBox, &QComboBox::currentTextChanged, this, &MainWindow::slot_modify_PointCloud2_attribute);
    //连接combobox当前文本改变信号与点云2图层渲染风格改变槽函数
    connect(StyleComboBox, &QComboBox::currentTextChanged, this, &MainWindow::slot_onStyleComboBox_text_changed);

    /*
   * 定义子节点3 ———— size
   */
    QTreeWidgetItem* PointCloud2PointSize = new QTreeWidgetItem(QStringList() << "大小 (Pixels)");
    //添加子节点3
    PointCloud2->addChild(PointCloud2PointSize);
    //初始化一个lineedit
    QLineEdit* PointSizeLineEdit = new QLineEdit("3");
    //正则表达式限制只能输入正浮点数
    PointSizeLineEdit->setValidator(new QRegExpValidator(QRegExp("^(([0-9]+\\.[0-9]*[1-9][0-9]*)|([0-9]*[1-9][0-9]*\\.[0-9]+)|([0-9]*[1-9][0-9]*)|0)$")));
    //设置最小宽度
    PointSizeLineEdit->setMinimumWidth(150);
    //添加lineedit于子节点3第一列
    treeWidget->setItemWidget(PointCloud2PointSize, 1, PointSizeLineEdit);
    //连接lineedit文本改变信号与修改点云2图层属性槽函数
    connect(PointSizeLineEdit, &QLineEdit::textChanged, this, &MainWindow::slot_modify_PointCloud2_attribute);
    //连接lineedit编辑结束信号与数据处理槽函数
    connect(PointSizeLineEdit, &QLineEdit::editingFinished, this, &MainWindow::slot_onPointSizeLineEdit_edit_finished);

    //调用qrviz类的接口创建图层对象实体并取得其指针
    rviz::Display* display = myviz->CreateDisplay("rviz/PointCloud2", "myPointCloud2");
    //向Hash表中插入键值对
    m_LayerHash.insert(PointCloud2, display);

    keyOrder << PointCloud2;  //保存键的顺序

    //默认调用一次修改图层属性函数
    myviz->ModifyPointCloud2Attribute(display, combobox->currentText(), StyleComboBox->currentText(), PointSizeLineEdit->text().toDouble(), checkBox->isChecked());

    return PointCloud2;
}


/**
 * @brief 修改点云2图层属性槽函数
 */
void MainWindow::slot_modify_PointCloud2_attribute()
{
    QTreeWidgetItem* pointcloud2;
    QCheckBox* checkBox;
    QComboBox* comboBox;
    QComboBox* StyleComboBox;
    QLineEdit* PointSizeLineEdit;
    if(ui.treeWidget_layer->currentItem()->parent() == nullptr)
    {
        //获取顶层节点
        pointcloud2 = ui.treeWidget_layer->currentItem();
    }
    else
    {
        //获取顶层节点
        pointcloud2 = ui.treeWidget_layer->currentItem()->parent();
    }
    //获取顶层节点第二列单元格中的QCheckBox控件
    checkBox = qobject_cast<QCheckBox*>(ui.treeWidget_layer->itemWidget(pointcloud2, 1));
    //获取顶层节点的子节点1第二列单元格中的QComboBox控件
    comboBox = qobject_cast<QComboBox*>(ui.treeWidget_layer->itemWidget(pointcloud2->child(0), 1));
    //获取顶层节点的子节点2第二列单元格中的QComboBox控件
    StyleComboBox = qobject_cast<QComboBox*>(ui.treeWidget_layer->itemWidget(pointcloud2->child(1), 1));
    //获取顶层节点的子节点3第二列单元格中的QLineEdit控件
    PointSizeLineEdit = qobject_cast<QLineEdit*>(ui.treeWidget_layer->itemWidget(pointcloud2->child(2), 1));
    if(checkBox->isChecked())
    {
        for(int index = 0; index < pointcloud2->childCount(); index++)
        {
            pointcloud2->child(index)->setDisabled(false);
        }
        comboBox->setEnabled(true);
        StyleComboBox->setEnabled(true);
        PointSizeLineEdit->setEnabled(true);
    }
    else
    {
        for(int index = 0; index < pointcloud2->childCount(); index++)
        {
            pointcloud2->child(index)->setDisabled(true);
        }
        comboBox->setEnabled(false);
        StyleComboBox->setEnabled(false);
        PointSizeLineEdit->setEnabled(false);
    }
    double doubleSize = PointSizeLineEdit->text().toDouble();
    if(doubleSize < 0.0001)
    {
        doubleSize = 0.0001;    //限制最小输入
    }
    myviz->ModifyPointCloud2Attribute(m_LayerHash.value(pointcloud2), comboBox->currentText(), StyleComboBox->currentText(), doubleSize, checkBox->isChecked());
}

/**
 * @brief style改变槽函数
 */
void MainWindow::slot_onStyleComboBox_text_changed()
{
    //获取当前item
    QTreeWidgetItem* current_item = ui.treeWidget_layer->currentItem();
    //获取父节点
    QTreeWidgetItem* parent_item = current_item->parent();
    //获取当前item的索引
    int current_index = parent_item->indexOfChild(current_item);
    //获取下一个item
    QTreeWidgetItem* next_item = parent_item->child(current_index + 1);
    /*Qt 5访问TreeWidgetItem的兄弟节点比较麻烦，总体逻辑如上代码。如果您的Qt版本为Qt 6及以上，
    则可以使用QTreeWidgetItem类的sibling(int i)方法快速地访问相对位置为i（i可以为负数）兄弟节点。
    在使用指针返回值之前，建议做非空检查；这里我偷懒没有做任何非空检查*/

    //获取当前item第二列的ComboBox
    QComboBox* combobox = qobject_cast<QComboBox*>(ui.treeWidget_layer->itemWidget(current_item, 1));
    //获取下一个item第二列的LineEdit
    QLineEdit* lineedit = qobject_cast<QLineEdit*>(ui.treeWidget_layer->itemWidget(next_item, 1));
    if(combobox->currentText() == "Points")
    {
        next_item->setText(0, "大小 (Pixels)");
        lineedit->setText("3");
    }
    else
    {
        next_item->setText(0, "大小 (m)");
        lineedit->setText("0.1");
    }
}



/**
 * @brief point size编辑结束槽函数
 */
void MainWindow::slot_onPointSizeLineEdit_edit_finished()
{
    //获取当前item第二列的Linedit
    QLineEdit* lineedit = qobject_cast<QLineEdit*>(ui.treeWidget_layer->itemWidget(ui.treeWidget_layer->currentItem(), 1));
    double doubleSize = lineedit->text().toDouble();
    if(doubleSize < 0.0001)
    {
        doubleSize = 0.0001;      //限制最小输入
    }
    lineedit->setText(QString::number(doubleSize));
}


/*****************************************************************************
** Implemenation [Slots][manually connected]
*****************************************************************************/

/**
 * This function is signalled by the underlying model. When the model changes,
 * this will drop the cursor down to the last line in the QListview to ensure
 * the user can always see the latest log message.
 */
void MainWindow::updateLoggingView() {
        ui.view_logging->scrollToBottom();
}

/*****************************************************************************
** Implementation [Menu]
*****************************************************************************/

void MainWindow::on_actionAbout_triggered() {
    QMessageBox::about(this, tr("About ..."),tr("<h2>PACKAGE_NAME Test Program 0.10</h2><p>Copyright Yujin Robot</p><p>This package needs an about description.</p>"));
}

void MainWindow::on_action_Connect_triggered()
{
    /*if ( ui.checkbox_use_environment->isChecked() ) {*/
    if ( !qnode.init() ) {
        showNoMasterMessage();    //连接失败
    } else {
        ui.action_Connect->setEnabled(false);
        myviz = new qrviz(ui.RVizLayout);

        QString str1("G0");
        QString str2("/G0/laser_cloud_map");
        add_TreeWidgetItem_PointCloud2(ui.treeWidget_layer, str1,str2);
        QString str3("G6");
        QString str4("/G6/laser_cloud_map");
        add_TreeWidgetItem_PointCloud2(ui.treeWidget_layer, str3,str4);
        QString str5("mergeMap");
        QString str6("/merge_cloud_map");
        add_TreeWidgetItem_PointCloud2(ui.treeWidget_layer, str5,str6);
        state=Connect;
        // 显示连接成功的消息框
//        QMessageBox::information(this, "Connect", "Connect Succeed!");

        // 显示连接成功的消息框
        connectMessageBox->show();

        // 启动定时器，设置定时器间隔为2000毫秒（2秒）
        QTimer::singleShot(1500, connectMessageBox, &QMessageBox::hide);
    }

}

void MainWindow::on_action_InitSetting_triggered()
{
    if ( state!=Connect) {
        showNoConnectMessage();
    }
    else{
        yamlSetting = nullptr;
        if (!yamlSetting)
        {
            yamlSetting = new yamlSettingDialog(this);
            yamlSetting->show();
        }
        else
        {
            // 如果配置对话框已经创建，则将其置于前台（如果对话框被最小化，则显示它）
            yamlSetting->raise();
            yamlSetting->activateWindow();
        }
    }
}

void MainWindow::on_action_BagSetting_triggered()
{
    if ( state!=Connect) {
        showNoConnectMessage();
    }else{
        // 如果配置对话框尚未创建，则创建并显示
        bagSetting = nullptr;
        if (!bagSetting)
        {
            bagSetting = new bagSettingDialog(this);
            bagSetting->show();
        }
        else
        {
            // 如果配置对话框已经创建，则将其置于前台（如果对话框被最小化，则显示它）
            bagSetting->raise();
            bagSetting->activateWindow();
        }
    }
}

void MainWindow::on_action_Roscore_triggered()
{
    ui.action_Roscore->setEnabled(false); // 禁用 action_roscore

    roscoreProcess = new QProcess(this);
    // Start roscore process and check if it is started successfully
    roscoreProcess->startDetached("bash", QStringList() << "-c" << "roscore");

    qDebug() << "roscore started successfully!";

}

void MainWindow::on_action_view_triggered()
{
        if (ui.groupBox->isHidden()) {
            ui.groupBox->show(); // 如果groupBox当前处于隐藏状态，则展开
        } else {
            ui.groupBox->hide(); // 如果groupBox当前处于展开状态，则隐藏
        }
}


void MainWindow::translationDataReceived(double x, double y, double z)
{

    // 将数据添加到对应的数据模型中
    ui.lineEditX->setText(QString::number(x));
    ui.lineEditX->setReadOnly(true);
    ui.lineEditY->setText(QString::number(y));
    ui.lineEditY->setReadOnly(true);
    ui.lineEditZ->setText(QString::number(z));
    ui.lineEditZ->setReadOnly(true);

}

//void MainWindow::quatDataReceived(double w, double x, double y, double z)
//{

//    // 将数据添加到对应的数据模型中
//    ui.lineEditqW->setText(QString::number(w));
//    ui.lineEditqW->setReadOnly(true);
//    ui.lineEditqX->setText(QString::number(x));
//    ui.lineEditqX->setReadOnly(true);
//    ui.lineEditqY->setText(QString::number(y));
//    ui.lineEditqY->setReadOnly(true);
//    ui.lineEditqZ->setText(QString::number(z));
//    ui.lineEditqZ->setReadOnly(true);

//}

void MainWindow::eulerDataReceived(double eulerx, double eulery, double eulerz)
{

    // 将数据添加到对应的数据模型中
    ui.lineEditqRoll->setText(QString::number(eulerx));
    ui.lineEditqRoll->setReadOnly(true);
    ui.lineEditqPitch->setText(QString::number(eulery));
    ui.lineEditqPitch->setReadOnly(true);
    ui.lineEditqYaw->setText(QString::number(eulerz));
    ui.lineEditqYaw->setReadOnly(true);
}

/**
 * @brief 从QTreeidget移除PointCloud2顶层节点
 * @param QTreeWidget* treeWidget ———— 待PointCloud2顶层节点的QTreeWidget指针
 * @param QTreeWidgetItem* item   ———— 待移除的QTreeWidgetItem指针移除
 */
void MainWindow::remove_TreeWidgetItem_PointCloud2(QTreeWidget* treeWidget, QTreeWidgetItem* item)
{
    //删除rviz::Display对象
    myviz->DeleteDisplayLayer(m_LayerHash.value(item));
    //从哈希表中移除键值对
    m_LayerHash.remove(item);
    //获取第二列单元格中的QCheckBox控件
    qDebug()<<treeWidget->itemWidget(item, 1);
    QCheckBox* checkBox = qobject_cast<QCheckBox*>(treeWidget->itemWidget(item, 1));
    if(checkBox)
    {
        //如果该单元格中包含QCheckBox控件，则先将其从QTreeWidget控件中移除
        treeWidget->removeItemWidget(item, 1);
        //堆中创建的对象需要手动释放内存
        delete checkBox;
    }
    //获取子节点1(topic)第二列单元格中的QComboBox控件
    QComboBox* comboBox = qobject_cast<QComboBox*>(ui.treeWidget_layer->itemWidget(item->child(0), 1));
    if(comboBox)
    {
        //如果该单元格中包含QSpinBox控件，则先将其从QTreeWidget控件中移除
        treeWidget->removeItemWidget(item->child(0), 1);
        //堆中创建的对象需要手动释放内存
        delete comboBox;
    }
    //获取子节点2(style)第二列单元格中的QComboBox控件
    QComboBox* StyleComboBox = qobject_cast<QComboBox*>(ui.treeWidget_layer->itemWidget(item->child(1), 1));
    if(StyleComboBox)
    {
        //如果该单元格中包含QComboBox控件，则先将其从QTreeWidget控件中移除
        treeWidget->removeItemWidget(item->child(1), 1);
        //堆中创建的对象需要手动释放内存
        delete StyleComboBox;
    }
    //获取子节点3(point size)第二列单元格中的QLineEdit控件
    QLineEdit* PointSizeLineEdit = qobject_cast<QLineEdit*>(ui.treeWidget_layer->itemWidget(item->child(2), 1));
    if(PointSizeLineEdit)
    {
        //如果该单元格中包含QLineEdit控件，则先将其从QTreeWidget控件中移除
        treeWidget->removeItemWidget(item->child(2), 1);
        //堆中创建的对象需要手动释放内存
        delete PointSizeLineEdit;
    }

    //删除顶层节点的所有子节点
    removeChildren(item);
    //从QtreeWidget中移除顶层节点并删除QTreeWidgetItem对象
    treeWidget->takeTopLevelItem(treeWidget->indexOfTopLevelItem(item));
    delete item;
}

void MainWindow::onCalibrationFinishedSlot() {  //当标定完成时会发送信号，移除G0 G6的地图，只看融合后的地图
    for (int i = 0; i < 2; i++) {
        QTreeWidgetItem* key = keyOrder.at(i);
        remove_TreeWidgetItem_PointCloud2(ui.treeWidget_layer, key);
    }
}

void MainWindow::updateFitnessScorePlot(double fitnessScore)
{
    // 将fitness_score的值添加到fitnessScores中
    fitnessScores_.append(fitnessScore);

    // 更新曲线图显示
    //ui.customPlot->graph()->setData(xData,fitnessScores_);
    // 更新曲线图显示
    QCPGraph* graph = ui.customPlot->graph();
    graph->setData(xData, fitnessScores_);

    // 设置曲线样式和线条颜色
    graph->setPen(QPen(Qt::blue)); // 设置线条颜色为蓝色
    graph->setLineStyle(QCPGraph::lsLine); // 设置曲线为直线
    ui.customPlot->replot();
}

void MainWindow::setupPlot()
{
    ui.customPlot->addGraph();
    ui.customPlot->xAxis->setLabel("Iterations"); // 设置x轴标签
    ui.customPlot->yAxis->setLabel("Fitness Score"); // 设置y轴标签
    ui.customPlot->xAxis->setRange(0, 50); // 设置x轴范围，根据迭代次数自行调整
    ui.customPlot->yAxis->setRange(0, 20); // 设置y轴范围，根据实际fitness_score值的范围自行调整
    ui.customPlot->replot();

    // 初始化 xData
    xData.clear();
    // 将 QVector 转换为 QVector<double>
    for (int i = 0; i < 50; ++i) {
        xData.append(i); // 设置 x 轴数据，此处假设数据按顺序递增
    }
}

void MainWindow::onClose()
{

    system("rosnode kill -a&");
    system("killall roscore&");
}


void MainWindow::closeEvent(QCloseEvent *event)
{
    QMainWindow::closeEvent(event);
}

}  // namespace class1_ros_qt_demo

