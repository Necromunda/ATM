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

    delete timer;
    timer = nullptr;
}

void bankmain::startTimer()
{
    timer = new QTimer(this);
    timer->setSingleShot(true);
    connect(timer,SIGNAL(timeout()),
            this,SLOT(timeout()));
    connect(this,SIGNAL(restartTimer(void)),
            this, SLOT(initTimer(void)));
    emit restartTimer();
}

void bankmain::timeout()
{
    qDebug() << "Timeout";
    delete timer;
    timer = nullptr;
    emit loggingOut();
}

void bankmain::initTimer()
{
    qDebug() << "Timeout timer started";
    timer->setInterval(5000);
    timer->start();
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
    emit restartTimer();
    pDrawMoney = new drawmoney;
    connect(pDrawMoney, SIGNAL(drawThisAmount(QString)),
            this,SLOT(drawMoney(QString)));
    pDrawMoney->show();
}

void bankmain::drawMoney(QString msg)
{
    connect(this,SIGNAL(cancelWithdrawal(QString)),
            pDrawMoney,SLOT(negativeBal(QString)));
    int oldBal = QString(ui->balanceLabel->text()).toInt();
    int withdrawal = QString(msg).toInt();

    if ((oldBal-withdrawal) >= 0) {
        emit drawMoneySignal(msg);
    } else {
        emit cancelWithdrawal("Balance too low");
    }
}

void bankmain::on_exitButton_clicked()
{
    emit loggingOut();
}
