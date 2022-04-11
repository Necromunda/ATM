/********************************************************************************
** Form generated from reading UI file 'menuofactuality.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MENUOFACTUALITY_H
#define UI_MENUOFACTUALITY_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_menuofactuality
{
public:
    QPushButton *pushButton;
    QPushButton *pushButton_2;

    void setupUi(QDialog *menuofactuality)
    {
        if (menuofactuality->objectName().isEmpty())
            menuofactuality->setObjectName(QString::fromUtf8("menuofactuality"));
        menuofactuality->resize(400, 300);
        pushButton = new QPushButton(menuofactuality);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(130, 60, 151, 61));
        pushButton_2 = new QPushButton(menuofactuality);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(130, 150, 171, 61));

        retranslateUi(menuofactuality);

        QMetaObject::connectSlotsByName(menuofactuality);
    } // setupUi

    void retranslateUi(QDialog *menuofactuality)
    {
        menuofactuality->setWindowTitle(QCoreApplication::translate("menuofactuality", "Dialog", nullptr));
        pushButton->setText(QCoreApplication::translate("menuofactuality", "Nosta rahaa", nullptr));
        pushButton_2->setText(QCoreApplication::translate("menuofactuality", "KAH", nullptr));
    } // retranslateUi

};

namespace Ui {
    class menuofactuality: public Ui_menuofactuality {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MENUOFACTUALITY_H
