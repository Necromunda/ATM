#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDebug>
#include "rfid_dll.h"
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
    LOGIN_DLL *pLOGIN;
    QString cardNumber;
    QByteArray myToken;

signals:
    void getNumber(void);
    void sendCardNumberToLogin(QString);

public slots:
    void recvCardNumberFromDll(QString);
    void recvTokenFromLogin(QByteArray);

};
#endif // MAINWINDOW_H
