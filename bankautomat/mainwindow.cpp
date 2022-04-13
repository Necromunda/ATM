#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    pRFID = new RFID_DLL;
    pREST2 = new DLL_REST_2;

    connect(this,SIGNAL(getNumber()),
            pRFID,SLOT(getCardNumberFromEngine(void)));

    connect(pRFID,SIGNAL(sendCardNumberToExe(QString, bool)),
            this,SLOT(recvCardNumberFromDll(QString, bool)));

    connect(this, SIGNAL(getTransfers(int, QString)),
            pREST2,SLOT(getData(int, QString)));

    connect(pREST2,SIGNAL(sendTransfersToExe(QString)),
            this,SLOT(recvTransfersFromDll(QString)));

    // This signal starts the process of reading the RFID-device
    emit getNumber();
}

MainWindow::~MainWindow()
{
    delete ui;
    ui = nullptr;

    delete pRFID;
    pRFID = nullptr;

    delete pREST2;
    pREST2 = nullptr;
    
    delete pLOGIN;
    pLOGIN = nullptr;
}

void MainWindow::recvCardNumberFromDll(QString recvd, bool valid)
{
    // Contains the verified card number
    if (valid) {
        cardNumber = recvd;
        pLOGIN = new LOGIN_DLL;

        connect(this,SIGNAL(sendCardNumberToLogin(QString)),
                pLOGIN,SLOT(recvCardNumberFromExe(QString)));

        connect(pLOGIN,SIGNAL(sendTokenToExe(QByteArray)),
                this,SLOT(recvTokenFromLogin(QByteArray)));

        connect(pLOGIN,SIGNAL(restartRFID(void)),
                pRFID,SLOT(getCardNumberFromEngine(void)));

        emit sendCardNumberToLogin(cardNumber);
    } else {
        emit getNumber();
//        exit(0);
    }
}

void MainWindow::recvTransfersFromDll(QString msg)
{

}

void MainWindow::recvTokenFromLogin(QByteArray token)
{
    myToken = token;
    qDebug() << "Token recv" << myToken;
}
