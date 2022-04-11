#ifndef LOGINMENU_H
#define LOGINMENU_H

#include "menuofactuality.h"

#include <QDialog>
#include <QDebug>

namespace Ui {
class loginMenu;
}

class loginMenu : public QDialog
{
    Q_OBJECT

public:
    explicit loginMenu(QWidget *parent = nullptr);
    ~loginMenu();

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
    Ui::loginMenu *ui;
    QString baseStr="";
    QString addStr;
    menuofactuality *objectmenuofactuality;
};

#endif // LOGINMENU_H
