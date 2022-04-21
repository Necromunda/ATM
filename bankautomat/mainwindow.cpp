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
    connect(this, SIGNAL(restTransfer(QByteArray, QString, QString, QJsonObject)),
            pREST,SLOT(execPostTransfer(QByteArray, QString, QString, QJsonObject)));
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
        connect(pBankMain,SIGNAL(addTransfer(void)),
                this,SLOT(postTransfer(void)));
        connect(this,SIGNAL(beginTimer(void)),
                pBankMain,SLOT(startTimer(void)));
        connect(pBankMain,SIGNAL(getAccId(void)),
                this,SLOT(getAccountId(void)));
        bankW = true;
    };
    getName();
    this->hide();
    pBankMain->show();
    emit beginTimer();
}

void MainWindow::loggedOut()
{
    if (loggedIn) {
        qDebug() << "Session terminated";
        cardNumber = "";
        accountId = "";
        myToken = "";
        pBankMain->close();
        this->show();
        loggedIn = false;
        disconnect(this, SIGNAL(sendRestResult(QByteArray)), nullptr, nullptr);
        emit loggedOutRestartEngine();
    }
}

void MainWindow::on_exitApp_clicked()
{
    QWidget::close();
}

void MainWindow::recvResultsFromREST(QByteArray msg)
{
    qDebug() << "Rest done, result: " << msg;
    emit sendRestResult(msg);
}

void MainWindow::getName()
{
    connect(this,SIGNAL(sendRestResult(QByteArray)),
            pBankMain,SLOT(setName(QByteArray)));
    emit getREST(myToken, "GET", "cards/name/"+cardNumber, "");
}

void MainWindow::getBalance()
{
    disconnect(this, SIGNAL(sendRestResult(QByteArray)), nullptr, nullptr);
    connect(this,SIGNAL(sendRestResult(QByteArray)),
            pBankMain,SLOT(setBalance(QByteArray)));
    emit getREST(myToken, "GET", "cards/balance/"+cardNumber, "");
}

void MainWindow::drawMoney(QString msg)
{
    amount = msg;
    disconnect(this, SIGNAL(sendRestResult(QByteArray)), nullptr, nullptr);
    emit getREST(myToken, "WITHDRAW", "cards/updateBalance/"+cardNumber, msg);
}

void MainWindow::postTransfer()
{
    dateTime = QDateTime::currentDateTime().toString(Qt::ISODate);
    QJsonObject jsonObj;
    jsonObj.insert("amount", "-"+amount);
    jsonObj.insert("date", dateTime);
    jsonObj.insert("card_number", cardNumber);
    jsonObj.insert("accounts_account_id", "1");
    emit restTransfer(myToken, "POST", "transfers/", jsonObj);
}

void MainWindow::getAccountId()
{
    disconnect(this, SIGNAL(sendRestResult(QByteArray)), nullptr, nullptr);
    connect(this,SIGNAL(sendRestResult(QByteArray)),
            this,SLOT(recvAccountId(QByteArray)));
    emit getREST(myToken, "GET", "cards/accountId/"+cardNumber, "");
}

void MainWindow::recvAccountId(QByteArray msg)
{
    disconnect(this, SIGNAL(sendRestResult(QByteArray)), nullptr, nullptr);
    QJsonDocument json_doc = QJsonDocument::fromJson(msg);
    QJsonObject json_obj = json_doc.object();
    accountId = QString::number(json_obj["accounts_account_id"].toInt());
    qDebug() << "Card: " << cardNumber << ", AccId: " << accountId;
}

void MainWindow::on_pushButton_clicked()
{
    cardNumber = "05009BA52";
    emit sendCardNumberToLogin(cardNumber);
}

