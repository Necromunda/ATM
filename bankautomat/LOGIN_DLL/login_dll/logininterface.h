#ifndef LOGININTERFACE_H
#define LOGININTERFACE_H

#include <lengine.h>
#include <login_dll.h>
#include <QDialog>

namespace Ui {
class LoginInterface;
}

class LoginInterface : public QDialog
{
    Q_OBJECT

public:
    explicit LoginInterface(QWidget *parent = nullptr);
    ~LoginInterface();

    void fckwstrings();
    void fckwstrings2();
    void fckwstrings3();
    void addNumber();

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
    Ui::LoginInterface *ui;
    Login_dll * pLogin;
    QString baseStr="";
    QString addStr;
};
#endif // MAINWINDOW_H
