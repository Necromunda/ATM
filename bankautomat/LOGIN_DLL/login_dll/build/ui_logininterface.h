/********************************************************************************
** Form generated from reading UI file 'logininterface.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGININTERFACE_H
#define UI_LOGININTERFACE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_LoginInterface
{
public:
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QLineEdit *le_Pin_code;
    QSpacerItem *verticalSpacer;
    QGridLayout *gridLayout;
    QPushButton *btn_addseven;
    QPushButton *btn_addsix;
    QPushButton *btn_addzero;
    QPushButton *btn_addeight;
    QPushButton *btn_cancel;
    QPushButton *btn_addfour;
    QPushButton *btn_addone;
    QPushButton *btn_addfive;
    QPushButton *btn_addnine;
    QPushButton *btn_addthree;
    QPushButton *btn_addconfirm;
    QPushButton *btn_addtwo;
    QPushButton *btn_clear;

    void setupUi(QDialog *LoginInterface)
    {
        if (LoginInterface->objectName().isEmpty())
            LoginInterface->setObjectName(QString::fromUtf8("LoginInterface"));
        LoginInterface->resize(696, 476);
        verticalLayoutWidget = new QWidget(LoginInterface);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(110, 40, 462, 355));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        le_Pin_code = new QLineEdit(verticalLayoutWidget);
        le_Pin_code->setObjectName(QString::fromUtf8("le_Pin_code"));
        le_Pin_code->setMinimumSize(QSize(40, 30));
        le_Pin_code->setEchoMode(QLineEdit::PasswordEchoOnEdit);
        le_Pin_code->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(le_Pin_code);

        verticalSpacer = new QSpacerItem(20, 10, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        btn_addseven = new QPushButton(verticalLayoutWidget);
        btn_addseven->setObjectName(QString::fromUtf8("btn_addseven"));

        gridLayout->addWidget(btn_addseven, 2, 0, 1, 1);

        btn_addsix = new QPushButton(verticalLayoutWidget);
        btn_addsix->setObjectName(QString::fromUtf8("btn_addsix"));

        gridLayout->addWidget(btn_addsix, 1, 2, 1, 1);

        btn_addzero = new QPushButton(verticalLayoutWidget);
        btn_addzero->setObjectName(QString::fromUtf8("btn_addzero"));

        gridLayout->addWidget(btn_addzero, 3, 1, 1, 1);

        btn_addeight = new QPushButton(verticalLayoutWidget);
        btn_addeight->setObjectName(QString::fromUtf8("btn_addeight"));

        gridLayout->addWidget(btn_addeight, 2, 1, 1, 1);

        btn_cancel = new QPushButton(verticalLayoutWidget);
        btn_cancel->setObjectName(QString::fromUtf8("btn_cancel"));

        gridLayout->addWidget(btn_cancel, 4, 1, 1, 1);

        btn_addfour = new QPushButton(verticalLayoutWidget);
        btn_addfour->setObjectName(QString::fromUtf8("btn_addfour"));

        gridLayout->addWidget(btn_addfour, 1, 0, 1, 1);

        btn_addone = new QPushButton(verticalLayoutWidget);
        btn_addone->setObjectName(QString::fromUtf8("btn_addone"));

        gridLayout->addWidget(btn_addone, 0, 0, 1, 1);

        btn_addfive = new QPushButton(verticalLayoutWidget);
        btn_addfive->setObjectName(QString::fromUtf8("btn_addfive"));

        gridLayout->addWidget(btn_addfive, 1, 1, 1, 1);

        btn_addnine = new QPushButton(verticalLayoutWidget);
        btn_addnine->setObjectName(QString::fromUtf8("btn_addnine"));

        gridLayout->addWidget(btn_addnine, 2, 2, 1, 1);

        btn_addthree = new QPushButton(verticalLayoutWidget);
        btn_addthree->setObjectName(QString::fromUtf8("btn_addthree"));

        gridLayout->addWidget(btn_addthree, 0, 2, 1, 1);

        btn_addconfirm = new QPushButton(verticalLayoutWidget);
        btn_addconfirm->setObjectName(QString::fromUtf8("btn_addconfirm"));

        gridLayout->addWidget(btn_addconfirm, 4, 2, 1, 1);

        btn_addtwo = new QPushButton(verticalLayoutWidget);
        btn_addtwo->setObjectName(QString::fromUtf8("btn_addtwo"));

        gridLayout->addWidget(btn_addtwo, 0, 1, 1, 1);

        btn_clear = new QPushButton(verticalLayoutWidget);
        btn_clear->setObjectName(QString::fromUtf8("btn_clear"));

        gridLayout->addWidget(btn_clear, 4, 0, 1, 1);


        verticalLayout->addLayout(gridLayout);


        retranslateUi(LoginInterface);

        QMetaObject::connectSlotsByName(LoginInterface);
    } // setupUi

    void retranslateUi(QDialog *LoginInterface)
    {
        LoginInterface->setWindowTitle(QCoreApplication::translate("LoginInterface", "Dialog", nullptr));
        btn_addseven->setText(QCoreApplication::translate("LoginInterface", "7", nullptr));
        btn_addsix->setText(QCoreApplication::translate("LoginInterface", "6", nullptr));
        btn_addzero->setText(QCoreApplication::translate("LoginInterface", "0", nullptr));
        btn_addeight->setText(QCoreApplication::translate("LoginInterface", "8", nullptr));
        btn_cancel->setText(QCoreApplication::translate("LoginInterface", "cancel", nullptr));
        btn_addfour->setText(QCoreApplication::translate("LoginInterface", "4", nullptr));
        btn_addone->setText(QCoreApplication::translate("LoginInterface", "1", nullptr));
        btn_addfive->setText(QCoreApplication::translate("LoginInterface", "5", nullptr));
        btn_addnine->setText(QCoreApplication::translate("LoginInterface", "9", nullptr));
        btn_addthree->setText(QCoreApplication::translate("LoginInterface", "3", nullptr));
        btn_addconfirm->setText(QCoreApplication::translate("LoginInterface", "confirm", nullptr));
        btn_addtwo->setText(QCoreApplication::translate("LoginInterface", "2", nullptr));
        btn_clear->setText(QCoreApplication::translate("LoginInterface", "clear", nullptr));
    } // retranslateUi

};

namespace Ui {
    class LoginInterface: public Ui_LoginInterface {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGININTERFACE_H
