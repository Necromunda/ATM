#ifndef BANKMAIN_H
#define BANKMAIN_H

#include <QDialog>
#include "drawmoney.h"


namespace Ui {
class bankMain;
}

class bankMain : public QDialog
{
    Q_OBJECT

public:
    explicit bankMain(QWidget *parent = nullptr);
    ~bankMain();

private slots:
    void on_btn_showBalance_clicked();

    void on_btn_withdrawMoney_clicked();

    void on_btn_showTransactions_clicked();

    void on_btn_showPreviousActions_clicked();

    void on_btn_showNextActions_clicked();

    void on_btn_logOut_clicked();

private:
    Ui::bankMain *ui;



signals:

};

#endif // BANKMAIN_H
