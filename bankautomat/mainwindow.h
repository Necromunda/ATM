#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDebug>
#include <QTimer>
#include "rfid_dll.h"
#include "rfid_dll_engine.h"
#include "bankmain.h"



QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

enum states
{
    waitingCard,        // program waits for user to insert a valid card
    waitingPin,         // valid card inserted, program waits for user to give a PIN number
    userLogged,         // valid card and correct PIN, user has logged in succesfully
    withdrawMoney,      // Money withdrawal window
    showTransactions,   // Show transactions window
    checkBalance        // Check balance window
};

enum events
{
    programStart,           // program has started
    userInsertedCard,       // user inserted a valid card
    userGaveCorrectPin,     // user gave correct PIN
    userGaveWrongPin,       // user gave wrong PIN
    pinCorrect,             // PIN was correct, moving on
    pinWrong,               // PIN was wrong, staying here
    debitChosen,            // user chose debit
    creditChosen,           // user chose credit
    attemptWithdrawal,      // user attempts withdrawal
    doneWithdrawing,        // user quits withdrawing
    insufficientBalance,    // withdrawing denied, insufficient account balance
    showTransactions_event, // user wants to see transactions
    doneShowingTransactions,// user is done seeing transactions
    checkBalance_event,     // user wants to check account balance
    doneCheckingBalance,    // user is done checking account balance
    startTimer,             // timer starts if user does nothing
    timerExpires,           // timer expired, closing current window / logging out
    cardRemoved,            // card removed (or not not inserted)
    cardLocked,             // user gave wrong PIN three times, card gets locked
    userLoggedOut           // user logged out

};

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    RFID_DLL *pRFID;
    bankMain *pBankMain;

    QString cardNumber;


    states State = waitingCard;
    events Event;
    QTimer timer;

    void waitingCardHandler (events e);
    void waitingPinHandler (events e);
    void userLoggedHandler (events e);
    void withdrawMoneyHandler (events e);
    void showTransactionsHandler (events e);
    void checkBalanceHandler (events e);




signals:
    void getNumber(void);
    void getTransfers(int, QString);
    void cardNumberRead_signal(states,events);
    void pinCorrect_signal(states, events);
    void checkBalance_signal(states, events);
    void doneCheckingBalance_signal(states, events);
    void showTransactions_signal(states, events);
    void doneShowingTransactions_signal(states, events);
    void attemptWithdrawal_signal(states, events);
    void doneWithdrawing_signal(states, events);
    void startTimer_signal(states,events);
    void cardLocked_signal(states, events);
    void cardRemoved_signal(states, events);
    void logOut_signal(states, events);



public slots:
    void recvCardNumberFromDll(QString);
    void recvTransfersFromDll(QString);

    void runStateMachine(states, events);
    void handleTimeout();

private slots:
    void on_transfersButton_clicked();
    //void on_withdrawalButton_clicked();
    //void on_showTransactionsButton_clicked();
    //void on_checkBalanceButton_clicked();
    //void on_logOutButton_clicked();


};
#endif // MAINWINDOW_H
