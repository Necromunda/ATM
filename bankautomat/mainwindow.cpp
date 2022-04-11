#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    pRFID = new RFID_DLL;

    connect(this,SIGNAL(getNumber()),
            pRFID,SLOT(getCardNumberFromEngine()));

    connect(pRFID,SIGNAL(sendCardNumberToExe(QString)),
            this,SLOT(recvCardNumberFromDll(QString)));

    // This signal starts the process of reading the RFID-device
    emit getNumber();
//    pRFID->getCardNumberFromEngine();
    qDebug()<<cardNumber;
}

MainWindow::~MainWindow()
{
    delete ui;
    ui = nullptr;
    delete pRFID;
    pRFID = nullptr;
}

void MainWindow::recvCardNumberFromDll(QString recvd)
{
    // Contains the verified card number
    cardNumber = recvd;

    // Displaying the card number for debugging purposes, not needed in final product
    ui->label_2->setText(cardNumber);
}
