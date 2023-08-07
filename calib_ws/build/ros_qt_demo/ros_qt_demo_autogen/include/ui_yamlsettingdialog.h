/********************************************************************************
** Form generated from reading UI file 'yamlsettingdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.12.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_YAMLSETTINGDIALOG_H
#define UI_YAMLSETTINGDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_yamlSettingDialog
{
public:
    QGroupBox *groupBox;
    QWidget *verticalLayoutWidget_2;
    QVBoxLayout *verticalLayout_5;
    QLabel *label_5;
    QLabel *label_7;
    QLabel *label_3;
    QLabel *label_8;
    QLabel *label_4;
    QLabel *label_6;
    QWidget *verticalLayoutWidget_3;
    QVBoxLayout *verticalLayout_6;
    QLineEdit *lineEdit_x;
    QLineEdit *lineEdit_y;
    QLineEdit *lineEdit_z;
    QLineEdit *lineEdit_roll;
    QLineEdit *lineEdit_pitch;
    QLineEdit *lineEdit_yaw;
    QLabel *label_9;
    QLabel *label_10;
    QLineEdit *lineEdit_map_match_min_num;
    QLineEdit *lineEdit_max_icp_fittness_score;
    QLabel *label_11;
    QPushButton *button_save;
    QPushButton *button_calib;

    void setupUi(QDialog *yamlSettingDialog)
    {
        if (yamlSettingDialog->objectName().isEmpty())
            yamlSettingDialog->setObjectName(QString::fromUtf8("yamlSettingDialog"));
        yamlSettingDialog->resize(530, 342);
        groupBox = new QGroupBox(yamlSettingDialog);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(0, 0, 531, 341));
        verticalLayoutWidget_2 = new QWidget(groupBox);
        verticalLayoutWidget_2->setObjectName(QString::fromUtf8("verticalLayoutWidget_2"));
        verticalLayoutWidget_2->setGeometry(QRect(70, 50, 76, 181));
        verticalLayout_5 = new QVBoxLayout(verticalLayoutWidget_2);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        verticalLayout_5->setContentsMargins(0, 0, 0, 0);
        label_5 = new QLabel(verticalLayoutWidget_2);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        verticalLayout_5->addWidget(label_5);

        label_7 = new QLabel(verticalLayoutWidget_2);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        verticalLayout_5->addWidget(label_7);

        label_3 = new QLabel(verticalLayoutWidget_2);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        verticalLayout_5->addWidget(label_3);

        label_8 = new QLabel(verticalLayoutWidget_2);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        verticalLayout_5->addWidget(label_8);

        label_4 = new QLabel(verticalLayoutWidget_2);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        verticalLayout_5->addWidget(label_4);

        label_6 = new QLabel(verticalLayoutWidget_2);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        verticalLayout_5->addWidget(label_6);

        verticalLayoutWidget_3 = new QWidget(groupBox);
        verticalLayoutWidget_3->setObjectName(QString::fromUtf8("verticalLayoutWidget_3"));
        verticalLayoutWidget_3->setGeometry(QRect(120, 50, 131, 182));
        verticalLayout_6 = new QVBoxLayout(verticalLayoutWidget_3);
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        verticalLayout_6->setContentsMargins(0, 0, 0, 0);
        lineEdit_x = new QLineEdit(verticalLayoutWidget_3);
        lineEdit_x->setObjectName(QString::fromUtf8("lineEdit_x"));

        verticalLayout_6->addWidget(lineEdit_x);

        lineEdit_y = new QLineEdit(verticalLayoutWidget_3);
        lineEdit_y->setObjectName(QString::fromUtf8("lineEdit_y"));

        verticalLayout_6->addWidget(lineEdit_y);

        lineEdit_z = new QLineEdit(verticalLayoutWidget_3);
        lineEdit_z->setObjectName(QString::fromUtf8("lineEdit_z"));

        verticalLayout_6->addWidget(lineEdit_z);

        lineEdit_roll = new QLineEdit(verticalLayoutWidget_3);
        lineEdit_roll->setObjectName(QString::fromUtf8("lineEdit_roll"));

        verticalLayout_6->addWidget(lineEdit_roll);

        lineEdit_pitch = new QLineEdit(verticalLayoutWidget_3);
        lineEdit_pitch->setObjectName(QString::fromUtf8("lineEdit_pitch"));

        verticalLayout_6->addWidget(lineEdit_pitch);

        lineEdit_yaw = new QLineEdit(verticalLayoutWidget_3);
        lineEdit_yaw->setObjectName(QString::fromUtf8("lineEdit_yaw"));

        verticalLayout_6->addWidget(lineEdit_yaw);

        label_9 = new QLabel(groupBox);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setGeometry(QRect(280, 50, 171, 21));
        label_10 = new QLabel(groupBox);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setGeometry(QRect(280, 90, 171, 21));
        lineEdit_map_match_min_num = new QLineEdit(groupBox);
        lineEdit_map_match_min_num->setObjectName(QString::fromUtf8("lineEdit_map_match_min_num"));
        lineEdit_map_match_min_num->setGeometry(QRect(460, 50, 51, 25));
        lineEdit_max_icp_fittness_score = new QLineEdit(groupBox);
        lineEdit_max_icp_fittness_score->setObjectName(QString::fromUtf8("lineEdit_max_icp_fittness_score"));
        lineEdit_max_icp_fittness_score->setGeometry(QRect(460, 90, 51, 25));
        label_11 = new QLabel(groupBox);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setGeometry(QRect(10, 10, 181, 41));
        button_save = new QPushButton(groupBox);
        button_save->setObjectName(QString::fromUtf8("button_save"));
        button_save->setGeometry(QRect(120, 290, 100, 30));
        button_calib = new QPushButton(groupBox);
        button_calib->setObjectName(QString::fromUtf8("button_calib"));
        button_calib->setGeometry(QRect(340, 290, 100, 30));

        retranslateUi(yamlSettingDialog);

        QMetaObject::connectSlotsByName(yamlSettingDialog);
    } // setupUi

    void retranslateUi(QDialog *yamlSettingDialog)
    {
        yamlSettingDialog->setWindowTitle(QApplication::translate("yamlSettingDialog", "Dialog", nullptr));
        groupBox->setTitle(QString());
        label_5->setText(QApplication::translate("yamlSettingDialog", "x : ", nullptr));
        label_7->setText(QApplication::translate("yamlSettingDialog", "y : ", nullptr));
        label_3->setText(QApplication::translate("yamlSettingDialog", "z : ", nullptr));
        label_8->setText(QApplication::translate("yamlSettingDialog", "roll : ", nullptr));
        label_4->setText(QApplication::translate("yamlSettingDialog", "pitch : ", nullptr));
        label_6->setText(QApplication::translate("yamlSettingDialog", "yaw :", nullptr));
        label_9->setText(QApplication::translate("yamlSettingDialog", "map_match_min_num : ", nullptr));
        label_10->setText(QApplication::translate("yamlSettingDialog", "max_icp_fittness_score : ", nullptr));
        label_11->setText(QApplication::translate("yamlSettingDialog", "lidar2_to_lidar1_InitPose : ", nullptr));
        button_save->setText(QApplication::translate("yamlSettingDialog", "save", nullptr));
        button_calib->setText(QApplication::translate("yamlSettingDialog", "Calib", nullptr));
    } // retranslateUi

};

namespace Ui {
    class yamlSettingDialog: public Ui_yamlSettingDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_YAMLSETTINGDIALOG_H
