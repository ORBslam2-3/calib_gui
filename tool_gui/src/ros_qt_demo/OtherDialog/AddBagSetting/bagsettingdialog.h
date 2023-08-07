#ifndef BAGSETTINGDIALOG_H
#define BAGSETTINGDIALOG_H

#include <QDialog>
#include<QFileDialog>
#include <rosbag/view.h>
#include <QAction>
#include <QDebug>
#include <QProcess>
#include <qmessagebox.h>
#include <unordered_map>
namespace Ui {
class bagSettingDialog;
}

class bagSettingDialog : public QDialog
{
    Q_OBJECT

public:
    explicit bagSettingDialog(QWidget *parent = nullptr);
    ~bagSettingDialog();

    void showBagMessage();
    void showWarningMessage();

public Q_SLOTS:
    void on_button_openFile_clicked();
    void on_comboBox1_currentIndexChanged(const QString& selectedTopic);
    void on_comboBox2_currentIndexChanged(const QString& selectedTopic);
    void handleCustomTopicMapping1(const QString& selectedTopic, const QString& customTopic);
    void handleCustomTopicMapping2(const QString& selectedTopic, const QString& customTopic);
    void updatePlayCommand();
    void on_button_playBag_clicked();

private:
    Ui::bagSettingDialog *ui;

    QString filePath;

    // 声明私有成员变量用于存储话题映射关系
    std::unordered_map<std::string, std::string> topicMapping1;
    std::unordered_map<std::string, std::string> topicMapping2;

    QString playCommand;  // 添加playCommand成员变量

    QProcess* rosbagProcess;

    enum status
    {
        //启动状态
        needPlay,
        Playing,
    };
    static status state;
};

#endif // BAGSETTINGDIALOG_H
