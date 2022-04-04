#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    qDebug() << "TestiExe konstruktori";
    ui->setupUi(this);
    pRFID = new RFID_DLL;
    connect(pRFID,SIGNAL(sendCardNumberToExe(QString)),
            this,SLOT(recvCardNumberFromDll(QString)));
}

MainWindow::~MainWindow()
{
    qDebug() << "TestiExe destruktori";
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
    qDebug() << "recvCardNumberFromDll function";
    ui->label_2->setText(cardNumber);
}

