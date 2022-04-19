#include "bankmain.h"
#include "ui_bankmain.h"

bankMain::bankMain(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::bankMain)
{
    ui->setupUi(this);
}

bankMain::~bankMain()
{
    delete ui;
    ui = nullptr;

}

void bankMain::on_btn_showBalance_clicked()
{

}

void bankMain::on_btn_showTransactions_clicked()
{

}

void bankMain::on_btn_withdrawMoney_clicked()
{

}


void bankMain::on_btn_logOut_clicked()
{
    close();
}

