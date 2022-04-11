#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    pRFID = new RFID_DLL;

    connect(this,SIGNAL(getNumber()),
            pRFID,SLOT(getCardNumberFromEngine(void)));

    connect(pRFID,SIGNAL(sendCardNumberToExe(QString, bool)),
            this,SLOT(recvCardNumberFromDll(QString, bool)));


    // This signal starts the process of reading the RFID-device
    emit getNumber();
}

MainWindow::~MainWindow()
{
    delete ui;
    ui = nullptr;
    delete pRFID;
    pRFID = nullptr;
    delete pLOGIN;
    pLOGIN = nullptr;
}

void MainWindow::recvCardNumberFromDll(QString recvd, bool valid)
{
    // Contains the verified card number
    if (valid) {
//        pRFID->closeRFID();
        cardNumber = recvd;
        pLOGIN = new LOGIN_DLL;

        connect(this,SIGNAL(sendCardNumberToLogin(QString)),
                pLOGIN,SLOT(recvCardNumberFromExe(QString)));

        connect(pLOGIN,SIGNAL(sendTokenToExe(QByteArray)),
                this,SLOT(recvTokenFromLogin(QByteArray)));

        emit sendCardNumberToLogin(cardNumber);
    } else {
        exit(0);
    }

    // Displaying the card number for debugging purposes, not needed in final product
    ui->label_2->setText(cardNumber);
}

void MainWindow::recvTokenFromLogin(QByteArray token)
{
    myToken = token;
    qDebug() << "Token recv" << myToken;
}
