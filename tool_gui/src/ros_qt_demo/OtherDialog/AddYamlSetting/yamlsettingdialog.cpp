#include "yamlsettingdialog.h"
#include "qmessagebox.h"
#include "ui_yamlsettingdialog.h"
#include <yaml-cpp/emitter.h>
#include <yaml-cpp/node/parse.h>


yamlSettingDialog::status yamlSettingDialog::state=needRun;
yamlSettingDialog::yamlSettingDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::yamlSettingDialog)
{
    ui->setupUi(this);
    on_button_initYaml_clicked();
    saveMessageBox = new QMessageBox(this);
    saveMessageBox->setWindowTitle("File");
    saveMessageBox->setText("参数已保存！");
    saveMessageBox->setStandardButtons(QMessageBox::NoButton);
}

yamlSettingDialog::~yamlSettingDialog()
{
    delete ui;
}

void yamlSettingDialog::on_button_initYaml_clicked()
{
    qDebug()<<QDir::currentPath();
//    yamlfilePath = QFileDialog::getOpenFileName(this, "Open Yaml File", "", "YAML Files (*.yaml)");
    QDir *dir = new QDir(QDir::currentPath());
    qDebug()<<dir;
    yamlfilePath = QDir::currentPath()+"/calib_gui/calib_ws/src/multi_LIDAR_calibration/cfg/param.yaml";
    //获取项目所在路径
    qDebug()<<yamlfilePath;  //("home/wxd/calib_gui/calib_ws/src/multi_LIDAR_calibration/cfg/param.yaml")
    if (!yamlfilePath.isEmpty())
    {
        qDebug()<<QDir::currentPath();
        readAndDisplayYamlFile(yamlfilePath);
    }
}

// 在MainWindow的实现文件中添加对应的函数
void yamlSettingDialog::readAndDisplayYamlFile(const QString& filePath)
{
    QFile file(filePath);
    if (file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        QTextStream in(&file);
        QString yamlContent = in.readAll();
        file.close();

        // 解析yaml内容并显示参数值到对应的控件
        YAML::Node yamlNode = YAML::Load(yamlContent.toStdString());

        // 读取init_transform中的参数值
        double x = yamlNode["init_transform"]["x"].as<double>();
        double y = yamlNode["init_transform"]["y"].as<double>();
        double z = yamlNode["init_transform"]["z"].as<double>();
        double roll = yamlNode["init_transform"]["roll"].as<double>();
        double pitch = yamlNode["init_transform"]["pitch"].as<double>();
        double yaw = yamlNode["init_transform"]["yaw"].as<double>();
        double map_match_min_num=yamlNode["map_match_min_num"].as<double>();
        double max_icp_fittness_score=yamlNode["max_icp_fittness_score"].as<double>();
        // 将参数值显示在对应的控件中
        ui->lineEdit_x->setText(QString::number(x));
        ui->lineEdit_y->setText(QString::number(y));
        ui->lineEdit_z->setText(QString::number(z));
        ui->lineEdit_roll->setText(QString::number(roll));
        ui->lineEdit_pitch->setText(QString::number(pitch));
        ui->lineEdit_yaw->setText(QString::number(yaw));
        ui->lineEdit_map_match_min_num->setText(QString::number(map_match_min_num));
        ui->lineEdit_max_icp_fittness_score->setText(QString::number(max_icp_fittness_score));
    }
    else
    {
        // 文件打开失败，输出错误信息
        qDebug() << "Failed to open file: " << filePath;
    }
}


void yamlSettingDialog::on_button_save_clicked()
{
    // 将修改后的内容写回到原始的yaml文件中
    //    QString originalFilePath = "/path/to/your/original/yaml/file.yaml";
    //writeYamlFile(yamlfilePath, modifiedContent);
    saveYamlFile(yamlfilePath);
    // 确保调用的标定程序能够读取修改后的yaml文件
}

void yamlSettingDialog::saveYamlFile(const QString& filePath)
{
    // 获取用户在控件中修改的参数值
    double x = ui->lineEdit_x->text().toDouble();
    double y = ui->lineEdit_y->text().toDouble();
    double z = ui->lineEdit_z->text().toDouble();
    double roll = ui->lineEdit_roll->text().toDouble();
    double pitch = ui->lineEdit_pitch->text().toDouble();
    double yaw = ui->lineEdit_yaw->text().toDouble();
    double map_match_min_num = ui->lineEdit_map_match_min_num->text().toDouble();
    double max_icp_fittness_score = ui->lineEdit_max_icp_fittness_score->text().toDouble();

//    QString savepath = ui->lineEdit_savepath->text();

    // 构建YAML文本
    YAML::Emitter emitter;
    emitter << YAML::BeginMap;
    emitter << YAML::Key << "init_transform" << YAML::Value;
    emitter << YAML::BeginMap;
    emitter << YAML::Key << "x" << YAML::Value << x;
    emitter << YAML::Key << "y" << YAML::Value << y;
    emitter << YAML::Key << "z" << YAML::Value << z;
    emitter << YAML::Key << "roll" << YAML::Value << roll;
    emitter << YAML::Key << "pitch" << YAML::Value << pitch;
    emitter << YAML::Key << "yaw" << YAML::Value << yaw;
    emitter << YAML::EndMap;
    emitter << YAML::Key << "map_match_min_num" << YAML::Value << map_match_min_num;
    emitter << YAML::Key << "max_icp_fittness_score" << YAML::Value << max_icp_fittness_score;
//    emitter << YAML::Key << "savepath" << YAML::Value << savepath.toStdString();
    emitter << YAML::EndMap;

    // 将YAML文本写入文件
    QFile file(filePath);
    if (file.open(QIODevice::WriteOnly | QIODevice::Text))
    {
        QTextStream out(&file);
        out << "%YAML:1.0\n";
        out << emitter.c_str();
        file.close();
        // 显示连接成功的消息框
        saveMessageBox->show();

        // 启动定时器，设置定时器间隔为2000毫秒（2秒）
        QTimer::singleShot(1000, saveMessageBox, &QMessageBox::hide);
    }
    else
    {
        // 文件打开失败，输出错误信息
        qDebug() << "Failed to open file: " << filePath;
    }
}

/**
 * @brief 启动roslaunch
 */
void yamlSettingDialog::on_button_calib_clicked()
{
    if(state==needRun)
    {
        ui->button_calib->setEnabled(false);
        // 启动roslaunch命令
        roslaunchProcess = new QProcess(this);
        QString setupScriptPath = QDir::currentPath() + "/calib_gui/calib_ws/devel/setup.sh";
        QString command = ". " + setupScriptPath + " && roslaunch multi_LiDAR_calibration multi_lidar_calibration.launch";
        roslaunchProcess->startDetached("bash", QStringList() << "-c" << command);
        qDebug()<<command;
        showCalibMessage();
        state=Running;
        // 关闭当前的模态对话框
        accept();
    }else{
        showWarningMessage();
    }
}

void yamlSettingDialog::showCalibMessage() {
        QMessageBox msgBox;
        msgBox.setText("标定程序已启动");
        msgBox.exec();
}
void yamlSettingDialog::showWarningMessage() {
        QMessageBox msgBox;
        msgBox.setText("请勿重复启动 calib !!!");
        msgBox.exec();
        accept();
}
