#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDebug>
#include <QCloseEvent>
#include <QDate>
#include <QTime>
#include <QJsonObject>
#include "bankmain.h"
#include "rfid_dll.h"
#include "login_dll.h"
#include "rest_dll.h"

#include "engine.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

enum states
{
    waitingCard,        // program waits for user to insert a valid card
    waitingPin,         // valid card inserted, program waits for user to give a PIN number
    userLogged,         // valid card and correct PIN, user has logged in succesfully
    withdrawMoney,      // withdraw money
    showTransactions,   // show transactions
    checkBalance        // check balance
};

enum events
{
    programStart,           // program has started
    userInsertedCard,       // user inserted a valid card
    userGaveCorrectPin,     // user gave correct PIN
    userGaveWrongPin,       // user gave wrong PIN
    pinCorrect,             // PIN was correct, opening bankMain window
    pinWrong,               // PIN was wrong, staying at waitingCard state
    debitChosen,            // user chose debit
    creditChosen,           // user chose credit
    attemptWithdrawal,      // user attempts withdrawal, opening drawMoney window
    doneWithdrawing,        // user quits withdrawing, going back to bankMain window
    insufficientBalance,    // withdrawing denied due to insufficient account balance
    showTransactions_event, // user wants to see transactions
    doneShowingTransactions,// user is done seeing transactions
    checkBalance_event,     // user wants to check account balance
    doneCheckingBalance,    // user is done checking account balance
    startTimer,             // timer starts if user does nothing
    timerExpired,           // timer expired, program closes current window / logs user out
    cardRemoved,            // card removed
    cardLocked,             // user gave wrong PIN three times, card gets locked
    userLoggedOut           // user logged out, going back to waitingCard state

};

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    bankmain *pBankMain;
    RFID_DLL *pRFID;
    LOGIN_DLL *pLOGIN;
    REST_DLL *pREST;
    QString dateTime, cardNumber, amount, accountId, cardType;

    states State = waitingCard;
    events Event;
    QTimer timer;

    void waitingCardHandler (events e);
    void waitingPinHandler (events e);
    void userLoggedHandler (events e);
    void withdrawMoneyHandler (events e);
    void showTransactionsHandler (events e);
    void checkBalanceHandler (events e);

    QByteArray myToken;
    bool loggedIn = false;
    bool bankW = false;
    void getName(void);

signals:
    void finishProgram(void);
    void getNumber(void);
    void cardNumberRead_signal(states, events);
    void pinCorrect_signal(states, events);
    void checkBalance_signal(states, events);
    void doneCheckingBalance_signal(states, events);
    void showTransactions_signal(states, events);
    void doneShowingTransactions_signal(states, events);
    void attemptWithdrawal_signal(states, events);
    void doneWithdrawing_signal(states, events);
    void startTimer_signal(states, events);
    void timerExpired_signal(states, events);
    void cardLocked_signal(states, events);
    void cardRemoved_signal(states, events);
    void logOut_signal(states, events);

    void sendCardNumberToLogin(QString);
    void loggedOutRestartEngine(void);
    void getREST(QByteArray, QString, QString, QString); // Parametrit: Tunniste, Token, Metodi Tarkenne, Body
    void restName(QByteArray, QString, QString, QString); // Parametrit: Tunniste, Token, Metodi Tarkenne, Body
    void restTransfer(QByteArray, QString, QString, QJsonObject); // Parametrit: Tunniste, Token, Metodi Tarkenne, Body
    void sendRestResult(QByteArray);
    void beginTimer(void);
    void sendCardType(QString);

public slots:
    void runStateMachine(states, events);

private slots:
    void closeEvent(QCloseEvent*);
    void recvCardNumberFromDll(QString);
    void recvTokenFromLogin(QByteArray, QString);
    void loggedOut(void);
    void recvResultsFromREST(QByteArray);
    void getBalance(void);
    void drawMoney(QString);
    void postTransfer(void);
    void getAccountId(void);
    void recvAccountId(QByteArray);
    void getTransferLog(void);
    void getCustomTransfers(int, int);
    void getSelectedDateTransfers(QString);
    void on_exitApp_clicked();
    void disconnectRest(void);
    void getIban(void);
    void execTransaction(QString, QString, QString);
};
#endif // MAINWINDOW_H
