#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDebug>
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
    QByteArray myToken;


signals:
    void getNumber(void);
    void sendCardNumberToLogin(QString);
    void loggedOutRestartEngine(void);
    void getREST(QString, QString, QString, QString); // Parametrit: Token, metodi tarkenne, body

public slots:
    void recvCardNumberFromDll(QString);
    void recvTokenFromLogin(QByteArray);
    void loggedOut(void);
    void recvResultsFromREST(QString);

private slots:
    void on_exitApp_clicked();
    void on_Button_rest_clicked();
    
};
#endif // MAINWINDOW_H
