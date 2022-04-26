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

// Tilakoneen signaalien ja slottien yhdistäminen

    connect(this,SIGNAL(cardNumberRead_signal(states,events)),
            this,SLOT(runStateMachine(states,events)));
    connect(this,SIGNAL(pinCorrect_signal(states,events)),
            this,SLOT(runStateMachine(states,events)));
    connect(this,SIGNAL(attemptWithdrawal_signal(states,events)),
            this,SLOT(runStateMachine(states,events)));

    connect(this,SIGNAL(showTransactions_signal(states,events)),
            this,SLOT(runStateMachine(states,events)));

    connect(this,SIGNAL(checkBalance_signal(states,events)),
            this,SLOT(runStateMachine(states,events)));
    connect(this,SIGNAL(doneCheckingBalance_signal(states, events)),
            this,SLOT(runStateMachine(states, events)));

    connect(this,SIGNAL(cardRemoved_signal(states,events)),
            this,SLOT(runStateMachine(states,events)));


    qDebug() << "Starting RFID-reader.";
    emit getNumber();

    State = waitingCard;
    Event = programStart;

    runStateMachine(State,Event);
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

//    delete pBankMain;
//    pBankMain = nullptr;
    
    delete pREST;
    pREST = nullptr;
}

void MainWindow::runStateMachine(states s, events e)
{
    qDebug()<<"Running state machine: State = "<<State<<" and event = "<< e;
    switch (s) {

        case waitingCard:
            waitingCardHandler(e);
        break;

        case waitingPin:
            waitingPinHandler(e);
        break;

        case userLogged:
            userLoggedHandler(e);
        break;

        case withdrawMoney:
            withdrawMoneyHandler(e);
        break;

        case showTransactions:
            showTransactionsHandler(e);
        break;

        case checkBalance:
            checkBalanceHandler(e);

        default:
            qDebug()<<"State = "<<State<<" and event = "<< e;
    }
}

void MainWindow::waitingCardHandler(events e)
{
    qDebug()<<"WaitingCardHandler: State = "<<State<<" and event = "<< e;
    if(e == programStart)
    {
        State = waitingCard;
        qDebug()<<"Entered to waitingCard state";
    }
    else if(e == userInsertedCard)
    {
        State = waitingPin;
        qDebug()<<"Entered to waitingPin state";
        emit cardNumberRead_signal(State,e);
    }
    else
    {
        qDebug()<<"WaitingCardHandler: Wrong event in this state = "<<State<<" Event = "<<e;
    }

}
void MainWindow::waitingPinHandler(events e)
{
    if(e == userInsertedCard){
        // Just staying in this state
        qDebug()<<"Waiting for user to insert PIN";
    }
    else if(e == userGaveWrongPin)
    {
        // Just staying in this state
        State = waitingPin;
        Event = pinWrong;
        qDebug()<<"Wrong Pin number, staying at waitingPin state";
    }
    else if(e == userGaveCorrectPin)
    {
        qDebug()<<"Entering userLogged state, emitting pinCorrect_signal";
        State = userLogged;
        Event = pinCorrect;
        emit pinCorrect_signal(State,Event);
        //runStateMachine(State,Event);
    }
    else
    {
        qDebug()<<"WaitingPinHandler: Wrong event in this state = "<<State<<" Event = "<<e;
    }
}
void MainWindow::userLoggedHandler(events e)
{
    if(e == pinCorrect){
        qDebug()<<"Entered userLogged state, waiting for action";
    }
    else if(e == attemptWithdrawal)
    {
        qDebug()<<"Exiting from userLogged state, entering to withdrawMoney state, emitting attemptWithdrawal_signal";
        State = withdrawMoney;
        Event = attemptWithdrawal;
        emit attemptWithdrawal_signal(State,Event);
        //runStateMachine(State,Event);
    }
    else if(e == showTransactions_event)
    {
        qDebug()<<"Exiting from userLogged state, entering to showTransactions State, emitting showTransactions_signal";
        State = showTransactions;
        Event = showTransactions_event;
        emit showTransactions_signal(State,Event);
    }
    else if(e == checkBalance_event)
    {
        qDebug()<<"Exiting from userLogged state, entering to checkBalance state, emitting checkBalance_signal";
        State = checkBalance;
        Event = checkBalance_event;
        emit checkBalance_signal(State,Event);
    }
    else
    {
        qDebug()<<"Wrong event in this state = "<<State<<" Event = "<<e;
    }
}
void MainWindow::withdrawMoneyHandler(events e)
{
    if(e == attemptWithdrawal)
    {
        qDebug()<<"Attempting withdrawal";
        //Event = attemptWithdrawal;
        //emit attemptWithdrawal_signal(State,Event);
        //runStateMachine(State,Event);

    }
    else if(e == doneWithdrawing)
    {
        State = userLogged;
        Event = pinCorrect;
        emit doneWithdrawing_signal(State, Event);
        qDebug()<<"Entering to userLogged State";
    }
    else if(e == insufficientBalance)
    {
        State = withdrawMoney;
        Event = insufficientBalance;
        qDebug()<<"Insufficient balance, staying in attemptWithdrawal state";

    }
    else
    {
        qDebug()<<"Wrong event in this state = "<<State<<" Event = "<<e;
    }
}

void MainWindow::showTransactionsHandler(events e)
{
    if(e == showTransactions_event)
    {
        qDebug()<<"Entering to showTransactions State, waiting for transactions";
        State = showTransactions;
//        Event = showTransactions_event;
//        emit showTransactions_signal(State,Event);
    }
    else if(e == doneShowingTransactions)
    {
        qDebug()<<"Exiting showTransactions State, entering to userLogged state";
        State = userLogged;
        Event = pinCorrect;
        runStateMachine(State,Event);
    }
    else
    {
        qDebug()<<"Wrong event in this state = "<<State<<" Event = "<<e;
    }
}

void MainWindow::checkBalanceHandler(events e)
{
    if(e == checkBalance_event)
    {
        qDebug()<<"Entering to checkBalance state";
    }
    else if(e == doneCheckingBalance)
    {
        qDebug()<<"Exiting checkBalance state, emitting doneCheckingBalance_signal";
        State = userLogged;
        Event = pinCorrect;
        emit doneCheckingBalance_signal(State,Event);
    }
    else
    {
        qDebug()<<"Wrong event in this state = "<<State<<" Event = "<<e;
    }
}







void MainWindow::closeEvent(QCloseEvent *event)
{
    if (loggedIn) {
        event->ignore();
    } else {
        qDebug() << "Application closed";
        event->accept();
//        this->deleteLater();
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
    Event = userGaveCorrectPin;
    runStateMachine(State, Event);
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
        connect(pBankMain,SIGNAL(getAllTransfers(void)),
                this,SLOT(getTransferLog(void)));
        connect(pBankMain,SIGNAL(disconnectRestSignal(void)),
                this,SLOT(disconnectRest(void)));
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
        State = waitingCard;
        Event = programStart;
        runStateMachine(State, Event);
        qDebug() << "Session terminated";
        cardNumber = "";
        accountId = "";
        myToken = "";
        pBankMain->deleteLater();
        this->show();
        loggedIn = false;
        bankW = false;
        disconnectRest();
        emit loggedOutRestartEngine();
    }
}

void MainWindow::on_exitApp_clicked()
{
    this->close();
}

void MainWindow::disconnectRest()
{
    disconnect(this, SIGNAL(sendRestResult(QByteArray)), nullptr, nullptr);
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
    Event = checkBalance_event;
    runStateMachine(State, Event);
    disconnectRest();
    connect(this,SIGNAL(sendRestResult(QByteArray)),
            pBankMain,SLOT(setBalance(QByteArray)));
    emit getREST(myToken, "GET", "cards/balance/"+cardNumber, "");
    Event = doneCheckingBalance;
    runStateMachine(State,Event);
}

void MainWindow::drawMoney(QString msg)
{
    amount = msg;
    disconnectRest();
    emit getREST(myToken, "WITHDRAW", "cards/updateBalance/"+cardNumber, msg);
    Event = attemptWithdrawal;
    runStateMachine(State,Event);
}

void MainWindow::postTransfer()
{
    dateTime = QDateTime::currentDateTime().toString(Qt::ISODate);
    QJsonObject jsonObj;
    jsonObj.insert("amount", amount);
    jsonObj.insert("date", dateTime);
    jsonObj.insert("card_number", cardNumber);
    jsonObj.insert("accounts_account_id", accountId);
    emit restTransfer(myToken, "POST", "transfers/", jsonObj);
    Event = doneWithdrawing;
    runStateMachine(State, Event);
}

void MainWindow::getAccountId()
{
    disconnectRest();
    connect(this,SIGNAL(sendRestResult(QByteArray)),
            this,SLOT(recvAccountId(QByteArray)));
    emit getREST(myToken, "GET", "cards/accountId/"+cardNumber, "");
}

void MainWindow::recvAccountId(QByteArray msg)
{
    disconnectRest();
    QJsonDocument json_doc = QJsonDocument::fromJson(msg);
    QJsonObject json_obj = json_doc.object();
    accountId = QString::number(json_obj["accounts_account_id"].toInt());
    qDebug() << "Card: " << cardNumber << ", AccId: " << accountId;
}

void MainWindow::getTransferLog()
{
    Event = showTransactions_event;
    runStateMachine(State,Event);
    connect(this,SIGNAL(sendRestResult(QByteArray)),
            pBankMain,SLOT(recvTransferLog(QByteArray)));
    emit getREST(myToken, "GET", "transfers/"+accountId, "");
    Event = doneShowingTransactions;
    runStateMachine(State, Event);
}

void MainWindow::on_pushButton_clicked()
{
    Event = userInsertedCard;
    runStateMachine(State, Event);
    cardNumber = "05009BA52";
    emit sendCardNumberToLogin(cardNumber);

}

void MainWindow::on_pushButton_2_clicked()
{
    Event = userInsertedCard;
    runStateMachine(State, Event);
    cardNumber = "06000649B0";
    emit sendCardNumberToLogin(cardNumber);
}
