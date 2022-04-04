#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    pRFID = new RFID_DLL;
    connect(pRFID,SIGNAL(sendCardNumberToExe(QString)),
            this,SLOT(recvCardNumberFromDll(QString)));
}

MainWindow::~MainWindow()
{
    delete ui;
    delete pRFID;
    pRFID = nullptr;
}

void MainWindow::getCardNumberFromDll()
{
    pRFID->getCardNumberFromEngine();
}

void MainWindow::recvCardNumberFromDll(QString recvd)
{
    cardNumber = recvd;
    ui->label_2->setText(cardNumber);
}
