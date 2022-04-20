#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDebug>
#include <QCloseEvent>
#include "bankmain.h"
#include "rfid_dll.h"
#include "login_dll.h"
#include "rest_dll.h"

#include "engine.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

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
    QString cardNumber;
    QByteArray myToken, restAnsw;
    bool loggedIn = false;
    bool bankW = false;
    void getName(void);

signals:
    void getNumber(void);
    void sendCardNumberToLogin(QString);
    void loggedOutRestartEngine(void);
    void getREST(QByteArray, QString, QString, QString); // Parametrit: Tunniste, Token, Metodi Tarkenne, Body
    void sendRestResult(QByteArray);
    void beginTimer(void);

private slots:
    void closeEvent(QCloseEvent*);
    void recvCardNumberFromDll(QString);
    void recvTokenFromLogin(QByteArray);
    void loggedOut(void);
    void recvResultsFromREST(QByteArray);
    void getBalance(void);
    void drawMoney(QString);
    void on_exitApp_clicked();

    void on_pushButton_clicked();
};
#endif // MAINWINDOW_H
