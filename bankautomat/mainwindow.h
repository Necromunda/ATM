#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDebug>
#include <QTimer>
#include "rfid_dll.h"
#include "rfid_dll_engine.h"


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

enum states
{
    waitingCard,
    waitingPin,
    userLogged,
    withdrawMoney,
    showTransactions,
    checkBalance
};

enum events
{
    userInsertedCard,
    userGaveCorrectPin,
    userGaveWrongPin,
    pinCorrect,
    pinWrong,
    debitChosen,
    creditChosen,
    attemptWithdrawal,
    doneWithdrawing,
    insufficientBalance,
    showTransactions_event,
    doneShowingTransactions,
    checkBalance_event,
    doneCheckingBalance,
    cardRemoved,
    cardLocked

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
    void cardRemoved_signal(states, events);



public slots:
    void recvCardNumberFromDll(QString);
    void recvTransfersFromDll(QString);

    void runStateMachine(states, events);
    void handleTimeout();

private slots:
    void on_transfersButton_clicked();
    void on_withdrawalButton_clicked();
    void on_checkBalanceButton_clicked();


};
#endif // MAINWINDOW_H
