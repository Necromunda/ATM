#include "bankmain.h"
#include "ui_bankmain.h"

bankmain::bankmain(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::bankmain)
{
    qDebug() << "bankmain constructor";
    ui->setupUi(this);
}

bankmain::~bankmain()
{
    delete ui;
    ui = nullptr;
}

void bankmain::on_balanceButton_clicked()
{
    myBalance = 70123;
    ui->balanceLabel->setText(QString::number(myBalance));
}

void bankmain::on_accountActionsButton_clicked()
{

}

void bankmain::on_prevActionsButton_clicked()
{

}

void bankmain::on_nextActionsButton_clicked()
{

}

void bankmain::on_drawMoneyButton_clicked()
{
    pDrawMoney = new drawmoney;
    pDrawMoney->show();
}

void bankmain::on_exitButton_clicked()
{
    emit loggingOut();
}
