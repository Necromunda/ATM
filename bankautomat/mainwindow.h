#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDebug>
#include "rfid_dll.h"
#include "rfid_dll_engine.h"
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
    RFID_DLL *pRFID;
    REST_DLL *pREST;
    QString cardNumber;


signals:
    void getNumber(void);
    void getREST(QString, QString, QString, QString); // Parametrit: Token, metodi tarkenne, body

public slots:
    void recvCardNumberFromDll(QString);
    void recvResultsFromREST(QString);

private slots:
    void on_Button_rest_clicked();
};
#endif // MAINWINDOW_H
