#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDebug>
#include "rfid_dll.h"
#include "rfid_dll_engine.h"
#include "dll_rest_2.h"
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
    DLL_REST_2 *pREST2;
    QString cardNumber;

signals:
    void getNumber(void);
    void getTransfers(int, QString);

public slots:
    void recvCardNumberFromDll(QString);
    void recvTransfersFromDll(QString);

private slots:
    void on_transfersButton_clicked();
};
#endif // MAINWINDOW_H
