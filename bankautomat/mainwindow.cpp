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

    connect(pRFID,SIGNAL(sendCardNumberToExe(QString)),
            this,SLOT(recvCardNumberFromDll(QString)));

    pLOGIN = new LOGIN_DLL;

    connect(this,SIGNAL(sendCardNumberToLogin(QString)),
            pLOGIN,SLOT(recvCardNumberFromExe(QString)));

    connect(pLOGIN,SIGNAL(sendTokenToExe(QByteArray)),
            this,SLOT(recvTokenFromLogin(QByteArray)));

    connect(pLOGIN,SIGNAL(restartRFID(void)),
            pRFID,SLOT(restartEngine(void)));

    connect(this,SIGNAL(loggedOutRestartEngine(void)),
            pRFID,SLOT(restartEngine(void)));

    pREST = new REST_DLL;

    connect(this, SIGNAL(getREST(QByteArray, QString, QString, QString)),
            pREST,SLOT(ExecuteRestOperation(QByteArray, QString, QString, QString)));

    connect(pREST,SIGNAL(sendResultToExe(QByteArray)),
            this,SLOT(recvResultsFromREST(QByteArray)));

    // This signal starts the process of reading the RFID-device
    qDebug() << "Starting RFID-reader.";
    emit getNumber();
}

MainWindow::~MainWindow()
{
    qDebug() << "MainWindow destructor";
    delete ui;
    ui = nullptr;

    delete pRFID;
    pRFID = nullptr;
    
    delete pLOGIN;
    pLOGIN = nullptr;

    delete pBankMain;
    pBankMain = nullptr;
    
    delete pREST;
    pREST = nullptr;
}

void MainWindow::closeEvent(QCloseEvent *event)
{
    if (loggedIn) {
        event->ignore();
    } else {
        qDebug() << "Application closed";
        event->accept();
        exit(0);
    }
}

void MainWindow::recvCardNumberFromDll(QString recvd)
{
    cardNumber = recvd;
    emit sendCardNumberToLogin(cardNumber);
}

void MainWindow::recvTokenFromLogin(QByteArray token)
{
    loggedIn = true;
    myToken = "Bearer " + token;
    if (!bankW) {
        pBankMain = new bankmain;

        connect(pBankMain,SIGNAL(loggingOut(void)),
                this,SLOT(loggedOut(void)));

        connect(pBankMain,SIGNAL(updateBalance(void)),
                this,SLOT(getBalance(void)));

        connect(pBankMain,SIGNAL(drawMoneySignal(QString)),
                this,SLOT(drawMoney(QString)));

        connect(this,SIGNAL(beginTimer(void)),
                pBankMain,SLOT(startTimer(void)));
        bankW = true;
    };
    getName();
    this->close();
    pBankMain->show();
    emit beginTimer();
}

void MainWindow::loggedOut()
{
    if (loggedIn) {
        qDebug() << "Session terminated";
        pBankMain->close();
        this->show();
        loggedIn = false;
        emit loggedOutRestartEngine();
    }
}

void MainWindow::on_exitApp_clicked()
{
    QWidget::close();
}

void MainWindow::recvResultsFromREST(QByteArray msg)
{
    restAnsw = msg;
    qDebug() << "Rest done, result: " << restAnsw;
    emit sendRestResult(restAnsw);
    disconnect(this, SIGNAL(sendRestResult(QByteArray)), nullptr, nullptr);
}

void MainWindow::getBalance()
{
    connect(this,SIGNAL(sendRestResult(QByteArray)),
            pBankMain,SLOT(setBalance(QByteArray)));
    emit getREST(myToken, "GET", "cards/balance/"+cardNumber, "");
}

void MainWindow::drawMoney(QString msg)
{
    emit getREST(myToken, "WITHDRAW", "cards/updateBalance/"+cardNumber, msg);
}

void MainWindow::getName()
{
    connect(this,SIGNAL(sendRestResult(QByteArray)),
            pBankMain,SLOT(setName(QByteArray)));
    emit getREST(myToken, "GET", "cards/name/"+cardNumber, "");
}

void MainWindow::on_pushButton_clicked()
{
    cardNumber = "05009BA52";
    emit sendCardNumberToLogin(cardNumber);
}

