/********************************************************************************
** Form generated from reading UI file 'bagsettingdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.12.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BAGSETTINGDIALOG_H
#define UI_BAGSETTINGDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_bagSettingDialog
{
public:
    QLineEdit *lineEdit;
    QPushButton *button_openFile;
    QLabel *label;
    QComboBox *comboBox1;
    QLabel *label_3;
    QLabel *label_4;
    QComboBox *comboBox2;
    QPushButton *button_playBag;

    void setupUi(QDialog *bagSettingDialog)
    {
        if (bagSettingDialog->objectName().isEmpty())
            bagSettingDialog->setObjectName(QString::fromUtf8("bagSettingDialog"));
        bagSettingDialog->resize(547, 333);
        lineEdit = new QLineEdit(bagSettingDialog);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(50, 20, 360, 30));
        button_openFile = new QPushButton(bagSettingDialog);
        button_openFile->setObjectName(QString::fromUtf8("button_openFile"));
        button_openFile->setGeometry(QRect(410, 20, 60, 30));
        label = new QLabel(bagSettingDialog);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(15, 15, 30, 40));
        comboBox1 = new QComboBox(bagSettingDialog);
        comboBox1->setObjectName(QString::fromUtf8("comboBox1"));
        comboBox1->setGeometry(QRect(130, 90, 200, 30));
        label_3 = new QLabel(bagSettingDialog);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(20, 90, 100, 30));
        label_4 = new QLabel(bagSettingDialog);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(20, 130, 100, 30));
        comboBox2 = new QComboBox(bagSettingDialog);
        comboBox2->setObjectName(QString::fromUtf8("comboBox2"));
        comboBox2->setGeometry(QRect(130, 130, 200, 30));
        button_playBag = new QPushButton(bagSettingDialog);
        button_playBag->setObjectName(QString::fromUtf8("button_playBag"));
        button_playBag->setGeometry(QRect(330, 230, 150, 60));

        retranslateUi(bagSettingDialog);

        QMetaObject::connectSlotsByName(bagSettingDialog);
    } // setupUi

    void retranslateUi(QDialog *bagSettingDialog)
    {
        bagSettingDialog->setWindowTitle(QApplication::translate("bagSettingDialog", "Dialog", nullptr));
        lineEdit->setText(QString());
        button_openFile->setText(QApplication::translate("bagSettingDialog", "open", nullptr));
        label->setText(QApplication::translate("bagSettingDialog", "bag\357\274\232", nullptr));
        label_3->setText(QApplication::translate("bagSettingDialog", "Lidar1_topic : ", nullptr));
        label_4->setText(QApplication::translate("bagSettingDialog", "Lidar2_topic : ", nullptr));
        button_playBag->setText(QApplication::translate("bagSettingDialog", "Play", nullptr));
    } // retranslateUi

};

namespace Ui {
    class bagSettingDialog: public Ui_bagSettingDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BAGSETTINGDIALOG_H
