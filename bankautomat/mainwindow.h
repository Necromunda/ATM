#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDebug>
#include "rfid_dll.h"
#include "rfid_dll_engine.h"
#include "dll_rest_2.h"
#include "dll_rest_2_engine.h" // 12.4. kulkee Joonalla vielä ilmeisesti nimellä engine.h

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
    QString cardNumber;
    DLL_REST_2 *pREST;



signals:
    void getNumber(void);

public slots:
    void recvCardNumberFromDll(QString);

};
#endif // MAINWINDOW_H
