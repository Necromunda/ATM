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

void bankmain::closeEvent(QCloseEvent *event)
{
    event->accept();
    emit loggingOut();
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
//    QString res = json_obj["balance"].toString();
    QString res = QString::number(json_obj["balance"].toInt());
    qDebug() << res;
    ui->balanceLabel->setText(res);
}

void bankmain::on_balanceButton_clicked()
{
    emit updateBalance();
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
    connect(pDrawMoney, SIGNAL(drawThisAmount(QString)),
            this,SLOT(drawMoney(QString)));
    pDrawMoney->show();
}

void bankmain::drawMoney(QString msg)
{
    emit drawMoneySignal(msg);
}

void bankmain::on_exitButton_clicked()
{
    emit loggingOut();
}
