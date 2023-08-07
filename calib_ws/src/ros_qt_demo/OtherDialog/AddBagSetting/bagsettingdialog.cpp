#include "bagsettingdialog.h"
#include "ui_bagsettingdialog.h"

bagSettingDialog::status bagSettingDialog::state=needPlay;
bagSettingDialog::bagSettingDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::bagSettingDialog)
{
    ui->setupUi(this);
}

bagSettingDialog::~bagSettingDialog()
{
    delete ui;
}

void bagSettingDialog::on_button_openFile_clicked()
{
    QString filePath0 = QFileDialog::getOpenFileName(this, tr("选择文件"), "", tr("所有文件 (*.*)"));

    // 检查用户是否选择了文件
    if (!filePath0.isEmpty()) {

        filePath=filePath0;
        ui->lineEdit->setText(filePath);
        // 执行进一步的操作，例如解析文件
        // filePath 包含用户选择的文件路径

        // 读取 ROS bag 文件
        rosbag::Bag bag;
        bag.open(filePath.toStdString(), rosbag::bagmode::Read);

        // 获取话题列表
        std::vector<std::string> topics;
        std::set<std::string> uniqueTopics; // 用于记录已经添加的话题名
        rosbag::View view(bag);
//        for (const rosbag::ConnectionInfo* connection : view.getConnections()) {
//            topics.push_back(connection->topic);
//        }
        for (const rosbag::MessageInstance& msg_instance : view) {
            std::string message_type = msg_instance.getDataType();
            if (message_type == "sensor_msgs/PointCloud2") {
                std::string topic = msg_instance.getTopic();
                // 判断是否已经添加过该话题
                if (uniqueTopics.find(topic) == uniqueTopics.end()) {
                    topics.push_back(topic);
                    uniqueTopics.insert(topic);
                }
            }
        }

        // 添加话题列表到 QComboBox 控件
        for (const std::string& topic : topics) {
            ui->comboBox1->addItem(QString::fromStdString(topic));
        }

        for (const std::string& topic : topics) {
            ui->comboBox2->addItem(QString::fromStdString(topic));
        }

        // 关闭 ROS bag 文件
        bag.close();

    }

}

void bagSettingDialog::on_comboBox1_currentIndexChanged(const QString& selectedTopic)
{
    // 获取用户选择的话题
    //QString selectedTopic = ui.comboBox1->currentText();

    // 处理选中的话题（在这里可以根据需要执行相关操作）
    handleCustomTopicMapping1(selectedTopic, "/G0/velodyne_points");
}

void bagSettingDialog::on_comboBox2_currentIndexChanged(const QString& selectedTopic)
{
    // 获取用户选择的话题
    //QString selectedTopic = ui.comboBox2->currentText();

    // 处理选中的话题（在这里可以根据需要执行相关操作）
    handleCustomTopicMapping2(selectedTopic, "/G6/velodyne_points");
}

//void bagSettingDialog::on_comboBox1_currentIndexChanged1(int index)
//{
//    // 获取用户选择的话题
//    QString selectedTopic = ui->comboBox1->currentText();

//    // 处理选中的话题（在这里可以根据需要执行相关操作）
//    handleCustomTopicMapping1(selectedTopic, "/G0/velodyne_points");
//}

//void bagSettingDialog::on_comboBox2_currentIndexChanged2(int index)
//{
//    // 获取用户选择的话题
//    QString selectedTopic = ui->comboBox2->currentText();

//    // 处理选中的话题（在这里可以根据需要执行相关操作）
//    handleCustomTopicMapping2(selectedTopic, "/G6/velodyne_points");
//}

void bagSettingDialog::handleCustomTopicMapping1(const QString& selectedTopic, const QString& customTopic) {
    topicMapping1.clear();
    // 更新话题映射关系
    topicMapping1[selectedTopic.toStdString()] = customTopic.toStdString();
    qDebug()<<"topic1"<<selectedTopic<<"tototototototoot"<<customTopic;
    updatePlayCommand();

}
void bagSettingDialog::handleCustomTopicMapping2(const QString& selectedTopic, const QString& customTopic) {
    topicMapping2.clear();
    // 更新话题映射关系
    topicMapping2[selectedTopic.toStdString()] = customTopic.toStdString();
    qDebug()<<"topic2"<<selectedTopic<<"tototototototoot"<<customTopic;
    updatePlayCommand();
}


void bagSettingDialog::updatePlayCommand() {
    QString command = "rosbag play " + filePath + " ";


    auto it1 = topicMapping1.begin();
    auto it2 = topicMapping2.begin();
    if (!topicMapping1.empty()&&!topicMapping2.empty()) {
        command += QString::fromStdString(it1->first) + ":=" + QString::fromStdString(it1->second) + " ";
        command += QString::fromStdString(it2->first) + ":=" + QString::fromStdString(it2->second) + " ";
    }else {
        // 处理容器为空的情况
    }

    // 更新播放命令但不启动播放
    playCommand = command;
    qDebug()<<playCommand;
}

void bagSettingDialog::on_button_playBag_clicked()
{
    updatePlayCommand();
    if(state==needPlay)
    {
        ui->button_playBag->setEnabled(false);
        // 打印最终输出的命令
        qDebug() << "playCommand:" << playCommand;
        // 启动ROS bag播放命令
        rosbagProcess = new QProcess(this);
        rosbagProcess->startDetached("bash", QStringList() << "-c" << playCommand);
        state=Playing;
        showBagMessage();
        accept();
    }else{
        showWarningMessage();
    }

}

void bagSettingDialog::showBagMessage() {
        QMessageBox msgBox;
        msgBox.setText("bag已启动");
        msgBox.exec();
}
void bagSettingDialog::showWarningMessage() {
        QMessageBox msgBox;
        msgBox.setText("请勿重复播放 bag !!!");
        msgBox.exec();
        accept();
}
