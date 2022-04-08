#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    pRFID = new RFID_DLL;
    pREST2 = new DLL_REST_2;

    // Connecting signal from mainwindow to rfid_dll slot getCardNumberFromEngine()
    connect(this,SIGNAL(getNumber()),
            pRFID,SLOT(getCardNumberFromEngine()));

    // Connecting signal from rfid_dll to mainwindow slot recvCardNumberFromDll()
    connect(pRFID,SIGNAL(sendCardNumberToExe(QString)),
            this,SLOT(recvCardNumberFromDll(QString)));

    connect(this, SIGNAL(getTransfers(int)),
            pREST2,SLOT(getData(int)));
    connect(pREST2,SIGNAL(sendTransfersToExe(QString)),
            this,SLOT(recvTransfersFromDll(QString)));

    // This signal starts the process of reading the RFID-device
    emit getNumber();
}

MainWindow::~MainWindow()
{
    delete ui;
    delete pRFID;
    delete pREST2;
    pRFID = nullptr;
    pREST2 = nullptr;
}

void MainWindow::recvCardNumberFromDll(QString recvd)
{
    cardNumber = recvd; // Contains the card number

    // Displaying the card number for debugging purposes, not needed in final product
    ui->label_2->setText(cardNumber);
}

void MainWindow::recvTransfersFromDll(QString msg)
{
    ui->transfersEdit->setText(msg);
}

void MainWindow::on_transfersButton_clicked()
{
    QString x = ui->transferID->text();
    if(x != ""){
        emit getTransfers(x.toInt());
    }
    else{
        ui->transferID->setText("Kirjoita account id");
    }
}

