#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    pRFID = new RFID_DLL;
    pBankMain = new bankMain(this);

    connect(this,SIGNAL(getNumber()),
            pRFID,SLOT(getCardNumberFromEngine()));

    connect(pRFID,SIGNAL(getTransfers(QString)),
            this,SLOT(recvTransfersFromDll(QString)));

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

    connect(this,SIGNAL(cardRemoved_signal(states,events)),
            this,SLOT(runStateMachine(states,events)));

    connect(&this->timer,SIGNAL(timeout()),
            this,SLOT(handleTimeout()));



    // This signal starts the process of reading the RFID-device
    emit getNumber();

    State = waitingCard;
    Event = programStart;

    runStateMachine(State,Event);



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

void MainWindow::recvTransfersFromDll(QString msg)
{
    ui->transfersEdit->setText(msg);
}

void MainWindow::on_transfersButton_clicked()
{
    QString x = ui->transferID->text();
    QString token = ui->tokenEdit->text();
    if(x != "" && token != ""){
        emit getTransfers(x.toInt(), token);
    }
    else{
        ui->transferID->setText("Kirjoita account id");
        ui->tokenEdit->setText("Kirjoita token");
    }
}

void MainWindow::runStateMachine(states s, events e)
{
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

void MainWindow::handleTimeout()
{
    State = waitingCard;
    Event = timerExpires;
    runStateMachine(State,Event);
}




void MainWindow::waitingCardHandler(events e)
{
    qDebug()<<"State = "<<State<<" and event = "<< e;
    if(e == programStart)
    {
        State = waitingCard;
        qDebug()<<"Entered to waitingCard state";
    }
    else if(e == userInsertedCard)
    {
        State = waitingPin;
        emit cardNumberRead_signal(State,Event);
        qDebug()<<"Entered to waitingPin state";
    }
    else
    {
        qDebug()<<"Wrong event in this state = "<<State<<" Event = "<<e;
    }

}
void MainWindow::waitingPinHandler(events e)
{

    if(e == userGaveWrongPin)
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
        qDebug()<<"Wrong event in this state = "<<State<<" Event = "<<e;
    }
}

void MainWindow::userLoggedHandler(events e)
{

    if(e == attemptWithdrawal)
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
        qDebug()<<"Exiting from userLogged state, emitting attemptWithdrawal_signal";
        State = withdrawMoney;
        Event = attemptWithdrawal;
        emit attemptWithdrawal_signal(State,Event);
        //runStateMachine(State,Event);

    }
    else if(e == doneWithdrawing)
    {
        State = userLogged;
        qDebug()<<"Entering to userLogged State";
    }
    else if(e == insufficientBalance)
    {
        qDebug()<<"Insufficient balance, Entering to userLogged State";

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
        qDebug()<<"Entering to showTransactions State, emitting showTransactions_signal";
        State = showTransactions;
        Event = showTransactions_event;
        emit showTransactions_signal(State,Event);
    }
    else if(e == doneShowingTransactions)
    {
        qDebug()<<"Exiting showTransactions State, entering to userLogged state";
        State = userLogged;
        Event = doneShowingTransactions;
        //runStateMachine(State,Event);
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
        emit doneCheckingBalance_signal(State,Event);
    }
    else
    {
        qDebug()<<"Wrong event in this state = "<<State<<" Event = "<<e;
    }
}

/******************************************
   Click Handlers
******************************************/

/*

void MainWindow::on_transfersButton_clicked()
{
    // State =
    // Event =
    runStateMachine(State,Event);
}

void MainWindow::on_withDrawalButton_clicked()
{
     State = withdrawMoney;
     Event = attemptWithdrawal;
    runStateMachine(State,Event);
}


void MainWindow::on_showTransactionsButton_clicked()
{
    State = showTransactions;
    Event = showTransactions_event;
    runStateMachine(State,Event);
}


void MainWindow::on_checkBalanceButton_clicked()
{
    State = checkBalance;
    Event = checkBalance_event;
    runStateMachine(State,Event);
}


void MainWindow::on_clickHandlerButtonPohja1_clicked()
{
    State =
    Event =
    runStateMachine(State,Event);
}


void MainWindow::on_clickHandlerButtonPohja2_clicked()
{
    State =
    Event =
    runStateMachine(State,Event);
}


void MainWindow::on_clickHandlerButtonPohja3_clicked()
{
    State =
    Event =
    runStateMachine(State,Event);
}

*/
