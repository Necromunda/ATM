/********************************************************************************
** Form generated from reading UI file 'loginmenu.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGINMENU_H
#define UI_LOGINMENU_H

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

class Ui_loginMenu
{
public:
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QLineEdit *le_Pin_code;
    QSpacerItem *verticalSpacer;
    QGridLayout *gridLayout;
    QPushButton *btn_addone;
    QPushButton *btn_addthree;
    QPushButton *btn_addtwo;
    QPushButton *btn_addseven;
    QPushButton *btn_addsix;
    QPushButton *btn_addzero;
    QPushButton *btn_addfive;
    QPushButton *btn_addfour;
    QPushButton *btn_addnine;
    QPushButton *btn_addeight;
    QPushButton *btn_cancel;
    QPushButton *btn_clear;
    QPushButton *btn_addconfirm;

    void setupUi(QDialog *loginMenu)
    {
        if (loginMenu->objectName().isEmpty())
            loginMenu->setObjectName(QString::fromUtf8("loginMenu"));
        loginMenu->resize(731, 534);
        layoutWidget = new QWidget(loginMenu);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(70, 60, 258, 211));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        le_Pin_code = new QLineEdit(layoutWidget);
        le_Pin_code->setObjectName(QString::fromUtf8("le_Pin_code"));
        le_Pin_code->setMinimumSize(QSize(40, 30));
        le_Pin_code->setEchoMode(QLineEdit::PasswordEchoOnEdit);
        le_Pin_code->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(le_Pin_code);

        verticalSpacer = new QSpacerItem(20, 10, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        btn_addone = new QPushButton(layoutWidget);
        btn_addone->setObjectName(QString::fromUtf8("btn_addone"));

        gridLayout->addWidget(btn_addone, 0, 0, 1, 1);

        btn_addthree = new QPushButton(layoutWidget);
        btn_addthree->setObjectName(QString::fromUtf8("btn_addthree"));

        gridLayout->addWidget(btn_addthree, 0, 2, 1, 1);

        btn_addtwo = new QPushButton(layoutWidget);
        btn_addtwo->setObjectName(QString::fromUtf8("btn_addtwo"));

        gridLayout->addWidget(btn_addtwo, 0, 1, 1, 1);

        btn_addseven = new QPushButton(layoutWidget);
        btn_addseven->setObjectName(QString::fromUtf8("btn_addseven"));

        gridLayout->addWidget(btn_addseven, 2, 0, 1, 1);

        btn_addsix = new QPushButton(layoutWidget);
        btn_addsix->setObjectName(QString::fromUtf8("btn_addsix"));

        gridLayout->addWidget(btn_addsix, 1, 2, 1, 1);

        btn_addzero = new QPushButton(layoutWidget);
        btn_addzero->setObjectName(QString::fromUtf8("btn_addzero"));

        gridLayout->addWidget(btn_addzero, 3, 1, 1, 1);

        btn_addfive = new QPushButton(layoutWidget);
        btn_addfive->setObjectName(QString::fromUtf8("btn_addfive"));

        gridLayout->addWidget(btn_addfive, 1, 1, 1, 1);

        btn_addfour = new QPushButton(layoutWidget);
        btn_addfour->setObjectName(QString::fromUtf8("btn_addfour"));

        gridLayout->addWidget(btn_addfour, 1, 0, 1, 1);

        btn_addnine = new QPushButton(layoutWidget);
        btn_addnine->setObjectName(QString::fromUtf8("btn_addnine"));

        gridLayout->addWidget(btn_addnine, 2, 2, 1, 1);

        btn_addeight = new QPushButton(layoutWidget);
        btn_addeight->setObjectName(QString::fromUtf8("btn_addeight"));

        gridLayout->addWidget(btn_addeight, 2, 1, 1, 1);

        btn_cancel = new QPushButton(layoutWidget);
        btn_cancel->setObjectName(QString::fromUtf8("btn_cancel"));

        gridLayout->addWidget(btn_cancel, 4, 1, 1, 1);

        btn_clear = new QPushButton(layoutWidget);
        btn_clear->setObjectName(QString::fromUtf8("btn_clear"));

        gridLayout->addWidget(btn_clear, 4, 0, 1, 1);

        btn_addconfirm = new QPushButton(layoutWidget);
        btn_addconfirm->setObjectName(QString::fromUtf8("btn_addconfirm"));

        gridLayout->addWidget(btn_addconfirm, 4, 2, 1, 1);


        verticalLayout->addLayout(gridLayout);


        retranslateUi(loginMenu);

        QMetaObject::connectSlotsByName(loginMenu);
    } // setupUi

    void retranslateUi(QDialog *loginMenu)
    {
        loginMenu->setWindowTitle(QCoreApplication::translate("loginMenu", "Dialog", nullptr));
        btn_addone->setText(QCoreApplication::translate("loginMenu", "1", nullptr));
        btn_addthree->setText(QCoreApplication::translate("loginMenu", "3", nullptr));
        btn_addtwo->setText(QCoreApplication::translate("loginMenu", "2", nullptr));
        btn_addseven->setText(QCoreApplication::translate("loginMenu", "7", nullptr));
        btn_addsix->setText(QCoreApplication::translate("loginMenu", "6", nullptr));
        btn_addzero->setText(QCoreApplication::translate("loginMenu", "0", nullptr));
        btn_addfive->setText(QCoreApplication::translate("loginMenu", "5", nullptr));
        btn_addfour->setText(QCoreApplication::translate("loginMenu", "4", nullptr));
        btn_addnine->setText(QCoreApplication::translate("loginMenu", "9", nullptr));
        btn_addeight->setText(QCoreApplication::translate("loginMenu", "8", nullptr));
        btn_cancel->setText(QCoreApplication::translate("loginMenu", "cancel", nullptr));
        btn_clear->setText(QCoreApplication::translate("loginMenu", "clear", nullptr));
        btn_addconfirm->setText(QCoreApplication::translate("loginMenu", "confirm", nullptr));
    } // retranslateUi

};

namespace Ui {
    class loginMenu: public Ui_loginMenu {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGINMENU_H
