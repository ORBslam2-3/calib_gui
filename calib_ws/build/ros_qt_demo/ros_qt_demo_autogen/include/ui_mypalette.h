/********************************************************************************
** Form generated from reading UI file 'mypalette.ui'
**
** Created by: Qt User Interface Compiler version 5.12.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MYPALETTE_H
#define UI_MYPALETTE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MyPalette
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QGraphicsView *ColorDisplay;
    QLineEdit *ColorLineEdit;
    QPushButton *btn_SelectColor;

    void setupUi(QWidget *MyPalette)
    {
        if (MyPalette->objectName().isEmpty())
            MyPalette->setObjectName(QString::fromUtf8("MyPalette"));
        MyPalette->resize(299, 188);
        MyPalette->setBaseSize(QSize(140, 25));
        MyPalette->setFocusPolicy(Qt::NoFocus);
        MyPalette->setAutoFillBackground(true);
        verticalLayout = new QVBoxLayout(MyPalette);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(2);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        ColorDisplay = new QGraphicsView(MyPalette);
        ColorDisplay->setObjectName(QString::fromUtf8("ColorDisplay"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(ColorDisplay->sizePolicy().hasHeightForWidth());
        ColorDisplay->setSizePolicy(sizePolicy);
        ColorDisplay->setMinimumSize(QSize(16, 16));
        ColorDisplay->setMaximumSize(QSize(16, 16));
        ColorDisplay->setBaseSize(QSize(16, 16));
        ColorDisplay->setAutoFillBackground(true);

        horizontalLayout->addWidget(ColorDisplay);

        ColorLineEdit = new QLineEdit(MyPalette);
        ColorLineEdit->setObjectName(QString::fromUtf8("ColorLineEdit"));
        ColorLineEdit->setAutoFillBackground(true);
        ColorLineEdit->setMaxLength(18);

        horizontalLayout->addWidget(ColorLineEdit);

        btn_SelectColor = new QPushButton(MyPalette);
        btn_SelectColor->setObjectName(QString::fromUtf8("btn_SelectColor"));
        sizePolicy.setHeightForWidth(btn_SelectColor->sizePolicy().hasHeightForWidth());
        btn_SelectColor->setSizePolicy(sizePolicy);
        btn_SelectColor->setMinimumSize(QSize(16, 16));
        btn_SelectColor->setMaximumSize(QSize(16, 16));
        btn_SelectColor->setBaseSize(QSize(16, 16));
        btn_SelectColor->setAutoFillBackground(true);

        horizontalLayout->addWidget(btn_SelectColor);

        horizontalLayout->setStretch(1, 1);

        verticalLayout->addLayout(horizontalLayout);


        retranslateUi(MyPalette);

        QMetaObject::connectSlotsByName(MyPalette);
    } // setupUi

    void retranslateUi(QWidget *MyPalette)
    {
        MyPalette->setWindowTitle(QApplication::translate("MyPalette", "Form", nullptr));
        ColorLineEdit->setText(QApplication::translate("MyPalette", "255; 255; 255", nullptr));
        btn_SelectColor->setText(QApplication::translate("MyPalette", "...", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MyPalette: public Ui_MyPalette {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MYPALETTE_H
