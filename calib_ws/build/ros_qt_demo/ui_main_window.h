/********************************************************************************
** Form generated from reading UI file 'main_window.ui'
**
** Created by: Qt User Interface Compiler version 5.12.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAIN_WINDOW_H
#define UI_MAIN_WINDOW_H

#include <QtCore/QLocale>
#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTreeWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "qcustomplot.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindowDesign
{
public:
    QAction *action_Quit;
    QAction *actionAbout;
    QAction *actionAbout_Qt;
    QAction *action_Connect;
    QAction *action_Setting;
    QAction *action_Roscore;
    QAction *actionLogView;
    QAction *action_BagSetting;
    QAction *actionCalib;
    QAction *action_view;
    QAction *action_InitSetting;
    QWidget *centralwidget;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *RVizLayout;
    QTreeWidget *treeWidget_layer;
    QGroupBox *groupBox;
    QCustomPlot *customPlot;
    QListView *view_logging;
    QLineEdit *lineEditZ;
    QLabel *label_Z;
    QLineEdit *lineEditY;
    QLabel *label_X;
    QLabel *label_Y;
    QLineEdit *lineEditX;
    QLineEdit *lineEditqYaw;
    QLineEdit *lineEditqPitch;
    QLineEdit *lineEditqRoll;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QMenuBar *menubar;
    QMenu *menu_File;
    QMenu *menuSetting;
    QMenu *menuLog;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindowDesign)
    {
        if (MainWindowDesign->objectName().isEmpty())
            MainWindowDesign->setObjectName(QString::fromUtf8("MainWindowDesign"));
        MainWindowDesign->resize(1920, 1139);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/images/icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        MainWindowDesign->setWindowIcon(icon);
        MainWindowDesign->setLocale(QLocale(QLocale::English, QLocale::Australia));
        action_Quit = new QAction(MainWindowDesign);
        action_Quit->setObjectName(QString::fromUtf8("action_Quit"));
        action_Quit->setShortcutContext(Qt::ApplicationShortcut);
        actionAbout = new QAction(MainWindowDesign);
        actionAbout->setObjectName(QString::fromUtf8("actionAbout"));
        actionAbout_Qt = new QAction(MainWindowDesign);
        actionAbout_Qt->setObjectName(QString::fromUtf8("actionAbout_Qt"));
        action_Connect = new QAction(MainWindowDesign);
        action_Connect->setObjectName(QString::fromUtf8("action_Connect"));
        action_Setting = new QAction(MainWindowDesign);
        action_Setting->setObjectName(QString::fromUtf8("action_Setting"));
        action_Roscore = new QAction(MainWindowDesign);
        action_Roscore->setObjectName(QString::fromUtf8("action_Roscore"));
        actionLogView = new QAction(MainWindowDesign);
        actionLogView->setObjectName(QString::fromUtf8("actionLogView"));
        action_BagSetting = new QAction(MainWindowDesign);
        action_BagSetting->setObjectName(QString::fromUtf8("action_BagSetting"));
        actionCalib = new QAction(MainWindowDesign);
        actionCalib->setObjectName(QString::fromUtf8("actionCalib"));
        action_view = new QAction(MainWindowDesign);
        action_view->setObjectName(QString::fromUtf8("action_view"));
        action_InitSetting = new QAction(MainWindowDesign);
        action_InitSetting->setObjectName(QString::fromUtf8("action_InitSetting"));
        centralwidget = new QWidget(MainWindowDesign);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        verticalLayoutWidget = new QWidget(centralwidget);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(10, 0, 1911, 951));
        RVizLayout = new QVBoxLayout(verticalLayoutWidget);
        RVizLayout->setObjectName(QString::fromUtf8("RVizLayout"));
        RVizLayout->setContentsMargins(0, 0, 0, 0);
        treeWidget_layer = new QTreeWidget(centralwidget);
        QTreeWidgetItem *__qtreewidgetitem = new QTreeWidgetItem();
        __qtreewidgetitem->setText(1, QString::fromUtf8("2"));
        __qtreewidgetitem->setText(0, QString::fromUtf8("1"));
        treeWidget_layer->setHeaderItem(__qtreewidgetitem);
        treeWidget_layer->setObjectName(QString::fromUtf8("treeWidget_layer"));
        treeWidget_layer->setGeometry(QRect(0, 60, 20, 21));
        treeWidget_layer->setColumnCount(2);
        treeWidget_layer->header()->setMinimumSectionSize(150);
        treeWidget_layer->header()->setDefaultSectionSize(150);
        treeWidget_layer->header()->setStretchLastSection(false);
        groupBox = new QGroupBox(centralwidget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(1300, 0, 620, 951));
        customPlot = new QCustomPlot(groupBox);
        customPlot->setObjectName(QString::fromUtf8("customPlot"));
        customPlot->setGeometry(QRect(0, 20, 610, 431));
        view_logging = new QListView(groupBox);
        view_logging->setObjectName(QString::fromUtf8("view_logging"));
        view_logging->setGeometry(QRect(0, 450, 610, 501));
        lineEditZ = new QLineEdit(centralwidget);
        lineEditZ->setObjectName(QString::fromUtf8("lineEditZ"));
        lineEditZ->setGeometry(QRect(420, 980, 125, 30));
        label_Z = new QLabel(centralwidget);
        label_Z->setObjectName(QString::fromUtf8("label_Z"));
        label_Z->setGeometry(QRect(390, 980, 30, 30));
        lineEditY = new QLineEdit(centralwidget);
        lineEditY->setObjectName(QString::fromUtf8("lineEditY"));
        lineEditY->setGeometry(QRect(250, 980, 125, 30));
        label_X = new QLabel(centralwidget);
        label_X->setObjectName(QString::fromUtf8("label_X"));
        label_X->setGeometry(QRect(50, 980, 30, 30));
        label_Y = new QLabel(centralwidget);
        label_Y->setObjectName(QString::fromUtf8("label_Y"));
        label_Y->setGeometry(QRect(220, 980, 30, 30));
        lineEditX = new QLineEdit(centralwidget);
        lineEditX->setObjectName(QString::fromUtf8("lineEditX"));
        lineEditX->setGeometry(QRect(80, 980, 125, 30));
        lineEditqYaw = new QLineEdit(centralwidget);
        lineEditqYaw->setObjectName(QString::fromUtf8("lineEditqYaw"));
        lineEditqYaw->setGeometry(QRect(1035, 980, 125, 30));
        lineEditqPitch = new QLineEdit(centralwidget);
        lineEditqPitch->setObjectName(QString::fromUtf8("lineEditqPitch"));
        lineEditqPitch->setGeometry(QRect(835, 980, 125, 30));
        lineEditqRoll = new QLineEdit(centralwidget);
        lineEditqRoll->setObjectName(QString::fromUtf8("lineEditqRoll"));
        lineEditqRoll->setGeometry(QRect(630, 980, 125, 30));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(580, 980, 50, 30));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(780, 980, 50, 30));
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(985, 980, 50, 30));
        MainWindowDesign->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindowDesign);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1920, 27));
        menu_File = new QMenu(menubar);
        menu_File->setObjectName(QString::fromUtf8("menu_File"));
        menuSetting = new QMenu(menubar);
        menuSetting->setObjectName(QString::fromUtf8("menuSetting"));
        menuLog = new QMenu(menubar);
        menuLog->setObjectName(QString::fromUtf8("menuLog"));
        MainWindowDesign->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindowDesign);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindowDesign->setStatusBar(statusbar);

        menubar->addAction(menu_File->menuAction());
        menubar->addAction(menuSetting->menuAction());
        menubar->addAction(menuLog->menuAction());
        menu_File->addSeparator();
        menu_File->addAction(actionAbout);
        menu_File->addAction(actionAbout_Qt);
        menu_File->addSeparator();
        menu_File->addAction(action_Roscore);
        menu_File->addAction(action_Connect);
        menu_File->addAction(action_Quit);
        menuSetting->addAction(action_InitSetting);
        menuSetting->addAction(action_BagSetting);
        menuLog->addAction(action_view);

        retranslateUi(MainWindowDesign);
        QObject::connect(action_Quit, SIGNAL(triggered()), MainWindowDesign, SLOT(close()));

        QMetaObject::connectSlotsByName(MainWindowDesign);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindowDesign)
    {
        MainWindowDesign->setWindowTitle(QApplication::translate("MainWindowDesign", "QRosApp", nullptr));
        action_Quit->setText(QApplication::translate("MainWindowDesign", "&Quit", nullptr));
#ifndef QT_NO_SHORTCUT
        action_Quit->setShortcut(QApplication::translate("MainWindowDesign", "Ctrl+Q", nullptr));
#endif // QT_NO_SHORTCUT
        actionAbout->setText(QApplication::translate("MainWindowDesign", "&About", nullptr));
        actionAbout_Qt->setText(QApplication::translate("MainWindowDesign", "About &Qt", nullptr));
        action_Connect->setText(QApplication::translate("MainWindowDesign", "Connect", nullptr));
        action_Setting->setText(QApplication::translate("MainWindowDesign", "Setting", nullptr));
        action_Roscore->setText(QApplication::translate("MainWindowDesign", "Roscore", nullptr));
        actionLogView->setText(QApplication::translate("MainWindowDesign", "LogView", nullptr));
        action_BagSetting->setText(QApplication::translate("MainWindowDesign", "Bag\350\256\276\347\275\256", nullptr));
        actionCalib->setText(QApplication::translate("MainWindowDesign", "Calib", nullptr));
        action_view->setText(QApplication::translate("MainWindowDesign", "View", nullptr));
        action_InitSetting->setText(QApplication::translate("MainWindowDesign", "\345\210\235\345\247\213\345\217\202\346\225\260", nullptr));
        groupBox->setTitle(QString());
        label_Z->setText(QApplication::translate("MainWindowDesign", "Z\357\274\232", nullptr));
        label_X->setText(QApplication::translate("MainWindowDesign", "X\357\274\232", nullptr));
        label_Y->setText(QApplication::translate("MainWindowDesign", "Y\357\274\232", nullptr));
        lineEditqRoll->setText(QString());
        label->setText(QApplication::translate("MainWindowDesign", "Roll  : ", nullptr));
        label_2->setText(QApplication::translate("MainWindowDesign", "Pitch  : ", nullptr));
        label_3->setText(QApplication::translate("MainWindowDesign", "Yaw  : ", nullptr));
        menu_File->setTitle(QApplication::translate("MainWindowDesign", "&App", nullptr));
        menuSetting->setTitle(QApplication::translate("MainWindowDesign", "Setting", nullptr));
        menuLog->setTitle(QApplication::translate("MainWindowDesign", "Log", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindowDesign: public Ui_MainWindowDesign {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAIN_WINDOW_H
