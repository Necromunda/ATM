/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout_2;
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
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(484, 427);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        verticalLayout_2 = new QVBoxLayout(centralwidget);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        le_Pin_code = new QLineEdit(centralwidget);
        le_Pin_code->setObjectName(QString::fromUtf8("le_Pin_code"));
        le_Pin_code->setMinimumSize(QSize(40, 30));
        le_Pin_code->setEchoMode(QLineEdit::PasswordEchoOnEdit);
        le_Pin_code->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(le_Pin_code);

        verticalSpacer = new QSpacerItem(20, 10, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        btn_addone = new QPushButton(centralwidget);
        btn_addone->setObjectName(QString::fromUtf8("btn_addone"));

        gridLayout->addWidget(btn_addone, 0, 0, 1, 1);

        btn_addthree = new QPushButton(centralwidget);
        btn_addthree->setObjectName(QString::fromUtf8("btn_addthree"));

        gridLayout->addWidget(btn_addthree, 0, 2, 1, 1);

        btn_addtwo = new QPushButton(centralwidget);
        btn_addtwo->setObjectName(QString::fromUtf8("btn_addtwo"));

        gridLayout->addWidget(btn_addtwo, 0, 1, 1, 1);

        btn_addseven = new QPushButton(centralwidget);
        btn_addseven->setObjectName(QString::fromUtf8("btn_addseven"));

        gridLayout->addWidget(btn_addseven, 2, 0, 1, 1);

        btn_addsix = new QPushButton(centralwidget);
        btn_addsix->setObjectName(QString::fromUtf8("btn_addsix"));

        gridLayout->addWidget(btn_addsix, 1, 2, 1, 1);

        btn_addzero = new QPushButton(centralwidget);
        btn_addzero->setObjectName(QString::fromUtf8("btn_addzero"));

        gridLayout->addWidget(btn_addzero, 3, 1, 1, 1);

        btn_addfive = new QPushButton(centralwidget);
        btn_addfive->setObjectName(QString::fromUtf8("btn_addfive"));

        gridLayout->addWidget(btn_addfive, 1, 1, 1, 1);

        btn_addfour = new QPushButton(centralwidget);
        btn_addfour->setObjectName(QString::fromUtf8("btn_addfour"));

        gridLayout->addWidget(btn_addfour, 1, 0, 1, 1);

        btn_addnine = new QPushButton(centralwidget);
        btn_addnine->setObjectName(QString::fromUtf8("btn_addnine"));

        gridLayout->addWidget(btn_addnine, 2, 2, 1, 1);

        btn_addeight = new QPushButton(centralwidget);
        btn_addeight->setObjectName(QString::fromUtf8("btn_addeight"));

        gridLayout->addWidget(btn_addeight, 2, 1, 1, 1);

        btn_cancel = new QPushButton(centralwidget);
        btn_cancel->setObjectName(QString::fromUtf8("btn_cancel"));

        gridLayout->addWidget(btn_cancel, 4, 1, 1, 1);

        btn_clear = new QPushButton(centralwidget);
        btn_clear->setObjectName(QString::fromUtf8("btn_clear"));

        gridLayout->addWidget(btn_clear, 4, 0, 1, 1);

        btn_addconfirm = new QPushButton(centralwidget);
        btn_addconfirm->setObjectName(QString::fromUtf8("btn_addconfirm"));

        gridLayout->addWidget(btn_addconfirm, 4, 2, 1, 1);


        verticalLayout->addLayout(gridLayout);


        verticalLayout_2->addLayout(verticalLayout);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 484, 25));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        btn_addone->setText(QCoreApplication::translate("MainWindow", "1", nullptr));
        btn_addthree->setText(QCoreApplication::translate("MainWindow", "3", nullptr));
        btn_addtwo->setText(QCoreApplication::translate("MainWindow", "2", nullptr));
        btn_addseven->setText(QCoreApplication::translate("MainWindow", "7", nullptr));
        btn_addsix->setText(QCoreApplication::translate("MainWindow", "6", nullptr));
        btn_addzero->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        btn_addfive->setText(QCoreApplication::translate("MainWindow", "5", nullptr));
        btn_addfour->setText(QCoreApplication::translate("MainWindow", "4", nullptr));
        btn_addnine->setText(QCoreApplication::translate("MainWindow", "9", nullptr));
        btn_addeight->setText(QCoreApplication::translate("MainWindow", "8", nullptr));
        btn_cancel->setText(QCoreApplication::translate("MainWindow", "cancel", nullptr));
        btn_clear->setText(QCoreApplication::translate("MainWindow", "clear", nullptr));
        btn_addconfirm->setText(QCoreApplication::translate("MainWindow", "confirm", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
