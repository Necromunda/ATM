#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "login_dll.h"
#include "ui_mainwindow.h"
//#include "rfid_dll.h"
//#include "rfid_dll_engine.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void fckwstrings();
    void fckwstrings2();
    void fckwstrings3();
    void addNumber();

signals:
// void getNumber(void);

public slots:

   // void recvCardNumberFromDll(QString);

private slots:
    void on_btn_addone_clicked();

    void on_btn_addtwo_clicked();

    void on_btn_addthree_clicked();

    void on_btn_addfour_clicked();

    void on_btn_addfive_clicked();

    void on_btn_addsix_clicked();

    void on_btn_addseven_clicked();

    void on_btn_addeight_clicked();

    void on_btn_addnine_clicked();

    void on_btn_addzero_clicked();

    void on_btn_clear_clicked();

    void on_btn_cancel_clicked();

    void on_btn_addconfirm_clicked();

private:
    Ui::MainWindow *ui;
    Login_dll * pLogin;
    QString baseStr="";
    QString addStr;
    // RFID_DLL *pRFID;
    // QString cardNumber;
};
#endif // MAINWINDOW_H

/*Ui::MainWindow *ui;
RFID_DLL *pRFID;
QString cardNumber;

signals:
void getNumber(void);

public slots:
void recvCardNumberFromDll(QString);
*/
