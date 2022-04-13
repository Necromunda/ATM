#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    pRFID = new RFID_DLL;
    pREST = new REST_DLL;

    connect(this,SIGNAL(getNumber()),
            pRFID,SLOT(getCardNumberFromEngine()));

    connect(pRFID,SIGNAL(sendCardNumberToExe(QString)),
            this,SLOT(recvCardNumberFromDll(QString)));


    connect(this, SIGNAL(getREST(QString, QString, QString, QString)),
            pREST,SLOT(ExecuteRestOperation(QString, QString, QString, QString)));
    connect(pREST,SIGNAL(sendResultToExe(QString)),
            this,SLOT(recvResultsFromREST(QString)));

    // This signal starts the process of reading the RFID-device
    emit getNumber();
}

MainWindow::~MainWindow()
{
    delete ui;
    ui = nullptr;
    delete pRFID;
    pRFID = nullptr;
    delete pREST;
    pREST = nullptr;

}

void MainWindow::recvCardNumberFromDll(QString recvd)
{
    // Contains the verified card number
    cardNumber = recvd;

    // Displaying the card number for debugging purposes, not needed in final product
    ui->label_2->setText(cardNumber);
}

void MainWindow::recvResultsFromREST(QString msg)
{
    ui->REST_results->setText(msg);
}

void MainWindow::on_Button_rest_clicked()
{
    // Parametrit: Token, metodi tarkenne, body
    QString token = ui->lineEdit_Token->text();
    QString metodi = ui->lineEdit_metodi->text();
    QString tarkenne = ui->lineEdit_tarkenne->text();
    QString body = ui->lineEdit_body->text();

    if(token != "" && metodi != ""&& tarkenne != ""&& body != ""){
        emit getREST(token, metodi, tarkenne, body);
    }
    else{
        ui->REST_results->setText("Täytä joka kenttä ennen lähetystä!");
    }
}

