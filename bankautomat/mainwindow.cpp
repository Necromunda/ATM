#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    pRFID = new RFID_DLL;

    // Connecting signal from mainwindow to rfid_dll slot getCardNumberFromEngine()
    connect(this,SIGNAL(getNumber()),
            pRFID,SLOT(getCardNumberFromEngine()));

    // Connecting signal from rfid_dll to mainwindow slot recvCardNumberFromDll()
    connect(pRFID,SIGNAL(sendCardNumberToExe(QString)),
            this,SLOT(recvCardNumberFromDll(QString)));

    // This signal starts the process of reading the RFID-device
    emit getNumber();
}

MainWindow::~MainWindow()
{
    delete ui;
    delete pRFID;
    pRFID = nullptr;
}

void MainWindow::recvCardNumberFromDll(QString recvd)
{
    cardNumber = recvd; // Contains the card number

    // Displaying the card number for debugging purposes, not needed in final product
    ui->label_2->setText(cardNumber);
}
