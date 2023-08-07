#ifndef YAMLSETTINGDIALOG_H
#define YAMLSETTINGDIALOG_H

#include <QDialog>
#include <QFileDialog>
#include <QProcess>
#include <QLoggingCategory>
#include <yaml-cpp/yaml.h>
#include <qmessagebox.h>
#include <qtimer.h>

namespace Ui {
class yamlSettingDialog;
}

class yamlSettingDialog : public QDialog
{
    Q_OBJECT

public:
    explicit yamlSettingDialog(QWidget *parent = nullptr);
    virtual ~yamlSettingDialog(); // 声明析构函数为虚函数

    void readAndDisplayYamlFile(const QString& filePath);
    void saveYamlFile(const QString& filePath);
    void showCalibMessage();
    void showWarningMessage();



public Q_SLOTS:
    void on_button_initYaml_clicked(); //打开路径下的yaml，并将内容展示到ui界面
    void on_button_save_clicked();     //保存修改后的配置参数
    void on_button_calib_clicked();

private:
    Ui::yamlSettingDialog *ui;

    QString yamlfilePath; //yaml文件路径

    QProcess* roslaunchProcess;

    enum status
    {
      //启动状态
        needRun,
        Running,
    };
    static status state;

    QMessageBox* saveMessageBox;
};

#endif // YAMLSETTINGDIALOG_H
