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

    delete pDrawMoney;
    pDrawMoney = nullptr;
}

void bankmain::setName(QByteArray msg)
{
    qDebug() << "Setting name";
    QJsonDocument json_doc = QJsonDocument::fromJson(msg);
    QJsonObject json_obj = json_doc.object();
    QString res = json_obj["fullname"].toString();
    ui->ownerNameLabel->setText("Account owner: " + res);
}

void bankmain::setBalance(QByteArray msg)
{
    qDebug() << "Setting balance";
    QJsonDocument json_doc = QJsonDocument::fromJson(msg);
    QJsonObject json_obj = json_doc.object();
    QString res = json_obj["balance"].toString();
    ui->balanceLabel->setText(res);
}

void bankmain::on_balanceButton_clicked()
{
    emit updateBalance();
//    myBalance = 70123;
//    ui->balanceLabel->setText(QString::number(myBalance));
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
