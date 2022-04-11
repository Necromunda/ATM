/********************************************************************************
** Form generated from reading UI file 'loginui.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGINUI_H
#define UI_LOGINUI_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_LoginUi
{
public:
    QVBoxLayout *verticalLayout;
    QLineEdit *lineEdit;
    QGridLayout *gridLayout;
    QPushButton *pushButton_8;
    QPushButton *pushButton_0;
    QPushButton *pushButton_2;
    QPushButton *pushButton_9;
    QPushButton *pushButton_5;
    QPushButton *pushButton_1;
    QPushButton *pushButton_Clear;
    QPushButton *pushButton_7;
    QPushButton *pushButton_6;
    QPushButton *pushButton_4;
    QPushButton *pushButton_3;
    QPushButton *pushButton_Ok;

    void setupUi(QDialog *LoginUi)
    {
        if (LoginUi->objectName().isEmpty())
            LoginUi->setObjectName(QString::fromUtf8("LoginUi"));
        LoginUi->resize(272, 198);
        LoginUi->setMaximumSize(QSize(16777215, 16777215));
        verticalLayout = new QVBoxLayout(LoginUi);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        lineEdit = new QLineEdit(LoginUi);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setMaxLength(4);
        lineEdit->setEchoMode(QLineEdit::Normal);
        lineEdit->setReadOnly(true);

        verticalLayout->addWidget(lineEdit);

        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        pushButton_8 = new QPushButton(LoginUi);
        pushButton_8->setObjectName(QString::fromUtf8("pushButton_8"));

        gridLayout->addWidget(pushButton_8, 1, 1, 1, 1);

        pushButton_0 = new QPushButton(LoginUi);
        pushButton_0->setObjectName(QString::fromUtf8("pushButton_0"));

        gridLayout->addWidget(pushButton_0, 4, 1, 1, 1);

        pushButton_2 = new QPushButton(LoginUi);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));

        gridLayout->addWidget(pushButton_2, 3, 1, 1, 1);

        pushButton_9 = new QPushButton(LoginUi);
        pushButton_9->setObjectName(QString::fromUtf8("pushButton_9"));

        gridLayout->addWidget(pushButton_9, 1, 2, 1, 1);

        pushButton_5 = new QPushButton(LoginUi);
        pushButton_5->setObjectName(QString::fromUtf8("pushButton_5"));

        gridLayout->addWidget(pushButton_5, 2, 1, 1, 1);

        pushButton_1 = new QPushButton(LoginUi);
        pushButton_1->setObjectName(QString::fromUtf8("pushButton_1"));

        gridLayout->addWidget(pushButton_1, 3, 0, 1, 1);

        pushButton_Clear = new QPushButton(LoginUi);
        pushButton_Clear->setObjectName(QString::fromUtf8("pushButton_Clear"));

        gridLayout->addWidget(pushButton_Clear, 4, 0, 1, 1);

        pushButton_7 = new QPushButton(LoginUi);
        pushButton_7->setObjectName(QString::fromUtf8("pushButton_7"));

        gridLayout->addWidget(pushButton_7, 1, 0, 1, 1);

        pushButton_6 = new QPushButton(LoginUi);
        pushButton_6->setObjectName(QString::fromUtf8("pushButton_6"));

        gridLayout->addWidget(pushButton_6, 2, 2, 1, 1);

        pushButton_4 = new QPushButton(LoginUi);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));

        gridLayout->addWidget(pushButton_4, 2, 0, 1, 1);

        pushButton_3 = new QPushButton(LoginUi);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));

        gridLayout->addWidget(pushButton_3, 3, 2, 1, 1);

        pushButton_Ok = new QPushButton(LoginUi);
        pushButton_Ok->setObjectName(QString::fromUtf8("pushButton_Ok"));

        gridLayout->addWidget(pushButton_Ok, 4, 2, 1, 1);


        verticalLayout->addLayout(gridLayout);


        retranslateUi(LoginUi);

        QMetaObject::connectSlotsByName(LoginUi);
    } // setupUi

    void retranslateUi(QDialog *LoginUi)
    {
        LoginUi->setWindowTitle(QCoreApplication::translate("LoginUi", "Dialog", nullptr));
        pushButton_8->setText(QCoreApplication::translate("LoginUi", "8", nullptr));
        pushButton_0->setText(QCoreApplication::translate("LoginUi", "0", nullptr));
        pushButton_2->setText(QCoreApplication::translate("LoginUi", "2", nullptr));
        pushButton_9->setText(QCoreApplication::translate("LoginUi", "9", nullptr));
        pushButton_5->setText(QCoreApplication::translate("LoginUi", "5", nullptr));
        pushButton_1->setText(QCoreApplication::translate("LoginUi", "1", nullptr));
        pushButton_Clear->setText(QCoreApplication::translate("LoginUi", "Clear", nullptr));
        pushButton_7->setText(QCoreApplication::translate("LoginUi", "7", nullptr));
        pushButton_6->setText(QCoreApplication::translate("LoginUi", "6", nullptr));
        pushButton_4->setText(QCoreApplication::translate("LoginUi", "4", nullptr));
        pushButton_3->setText(QCoreApplication::translate("LoginUi", "3", nullptr));
        pushButton_Ok->setText(QCoreApplication::translate("LoginUi", "Ok", nullptr));
    } // retranslateUi

};

namespace Ui {
    class LoginUi: public Ui_LoginUi {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGINUI_H
