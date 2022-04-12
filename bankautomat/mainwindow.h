#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDebug>
#include "rfid_dll.h"
#include "rfid_dll_engine.h"
#include "dll_rest_2.h"
#include "engine.h"
#include "login_dll.h"

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
    RFID_DLL *pRFID;
    DLL_REST_2 *pREST2;
    LOGIN_DLL *pLOGIN;
    QString cardNumber;
    QByteArray myToken;

signals:
    void getNumber(void);
    void getTransfers(int, QString);
    void sendCardNumberToLogin(QString);

public slots:
    void recvCardNumberFromDll(QString, bool);
    void recvTokenFromLogin(QByteArray);
    void recvTransfersFromDll(QString);

};
#endif // MAINWINDOW_H
