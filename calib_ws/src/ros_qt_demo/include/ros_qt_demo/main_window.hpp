/**
 * @file /include/class1_ros_qt_demo/main_window.hpp
 *
 * @brief Qt based gui for class1_ros_qt_demo.
 *
 * @date November 2010
 **/
#ifndef class1_ros_qt_demo_MAIN_WINDOW_H
#define class1_ros_qt_demo_MAIN_WINDOW_H

/*****************************************************************************
** Includes
*****************************************************************************/

#include <QtWidgets/QMainWindow>
#include <QtWidgets>
#include <QComboBox>
#include <QtGui>
#include <QIcon>
#include <QPixmap>
#include <QGraphicsPixmapItem>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QMessageBox>
#include <QCheckBox>
#include <QColorDialog>
#include <QDebug>
#include <QSpinBox>
#include <QDebug>
#include <QTextStream>
#include <QProcess>
#include <QSystemTrayIcon>
#include <iostream>
#include "ui_main_window.h"
#include "qnode.hpp"
#include "qrviz.hpp"
#include "../../CustomControl/MyPalette/mypalette.h"
#include "../../OtherDialog/AddYamlSetting/yamlsettingdialog.h"
#include "../../OtherDialog/AddBagSetting/bagsettingdialog.h"
#include <QCoreApplication>
#include <QThread>

#include <rosbag/view.h>
#include "qcustomplot.h"
#include <yaml-cpp/yaml.h>
#include <QAction>




/*****************************************************************************
** Namespace
*****************************************************************************/

namespace class1_ros_qt_demo {

/*****************************************************************************
** Interface [MainWindow]
*****************************************************************************/
/**
 * @brief Qt central, all operations relating to the view part here.
 */
class MainWindow : public QMainWindow {
Q_OBJECT

public:
	MainWindow(int argc, char** argv, QWidget *parent = 0);
	~MainWindow();

//	void ReadSettings(); // Load up qt program settings at startup
//	void WriteSettings(); // Save qt program settings when closing

	void closeEvent(QCloseEvent *event); // Overloaded function
	void showNoMasterMessage();
    void showNoConnectMessage();
    void showNoCalibMessage();
    void showRepeatClickMessage();
    void showCalibMessage();
    void showBagMessage();
    void showRoscoreMessage();

  /******************************************add
  ** 向UI界面添加新图层相关控件方法
  *******************************************/
    //QTreeWidgetItem* add_TreeWidgetItem_Grid(QTreeWidget* treeWidget, QString& displayName);
    QTreeWidgetItem* add_TreeWidgetItem_PointCloud2(QTreeWidget* treeWidget, QString& displayName, QString& topicName);


    /******************************************
  ** 修改图层相关属性方法
  *******************************************/
    void slot_modify_PointCloud2_attribute();

    void setupPlot();

    void readAndDisplayYamlFile(const QString& filePath);

    /******************************************
  ** 移除图层相关属性方法
  *******************************************/
    void remove_TreeWidgetItem_PointCloud2(QTreeWidget* treeWidget, QTreeWidgetItem* item);

    void onClose();

    void saveYamlFile(const QString& filePath);

public Q_SLOTS:
	/******************************************
	** Auto-connections (connectSlotsByName())
	*******************************************/
	void on_actionAbout_triggered();
    void on_action_Connect_triggered();
    void on_action_Roscore_triggered();
    void on_action_InitSetting_triggered();
    void on_action_view_triggered();
    void on_action_BagSetting_triggered();

    //Global Options相关槽函数
    void slot_set_global_options();

    //style改变槽函数
    void slot_onStyleComboBox_text_changed();

    //point size编辑结束槽函数
    void slot_onPointSizeLineEdit_edit_finished();

    void translationDataReceived(double x, double y, double z);

//    void quatDataReceived(double w, double x, double y, double z);  //不需要四元数显示，变成欧拉角了

    void eulerDataReceived(double eulerx, double eulery, double eulerz);

    void onCalibrationFinishedSlot();

    void updateFitnessScorePlot(double fitnessScore);
    /******************************************
    ** Manual connections
    *******************************************/
    void updateLoggingView(); // no idea why this can't connect automatically



private:
	Ui::MainWindowDesign ui;
	QNode qnode;

    QHash<QTreeWidgetItem*, rviz::Display*> m_LayerHash;
    QList<QTreeWidgetItem*> keyOrder; // 用于保存键的顺序

    //Global Options树控件
    QTreeWidgetItem* Global;
    QComboBox* FFCBox;                    //Fixed Frame ComboBox
    MyPalette* BPalette;                  //Background Palette
    yamlSettingDialog* yamlSetting;
    bagSettingDialog* bagSetting;
    qrviz* myviz;

    QProcess* roscoreProcess = nullptr;

    QProcess* rosnodeKill;

    QStringList pointCloud2TopicList;

    enum status
    {
        Connect,
        Calib,
        BagPlay,
    };

    enum status state;

    QVector<double> fitnessScores_;
    
    QVector<double> xData;

    QMessageBox* connectMessageBox;


    /**
   * @brief 逆序遍历QTreeWidgetItem所有子节点(包括儿子节点、孙子节点、曾孙节点...)并删除他们(包括从UI界面移除以及释放内存)
   * @attention 该方法会使用delete关键字释放内存，在调用该方法前请保证所有的子节点对象都是通过new关键字创建的
   * @param QTreeWidgetItem* item   ———— 待移除子节点的QTreeWidgetItem指针
   */
    inline void removeChildren(QTreeWidgetItem* item)
    {
        for (int i = item->childCount() - 1; i >= 0; i--) {
            if(item->child(i)->childCount() > 0)
            {
                removeChildren(item->child(i)); //递归删除子节点的子节点
            }
            //因为QTreeWidgetItem::takeChild(int index)方法会从UI界面移除index下标的项并返回它，所以我们直接delete其返回值
            delete item->takeChild(i);        //从UI界面移除项并释放其内存
        }
    }
};

}
 // namespace class1_ros_qt_demo

#endif // class1_ros_qt_demo_MAIN_WINDOW_H
