#include "bankmain.h"
#include "ui_bankmain.h"

bankmain::bankmain(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::bankmain)
{
    qDebug() << "bankmain constructor";
    ui->setupUi(this);
//    timer = new QTimer(this);
//    timer->setSingleShot(true);
//    timer->setInterval(5000);
//    connect(timer,SIGNAL(timeout()),
//            this,SLOT(timeout()));
//    connect(this,SIGNAL(stopTimer(void)),
//            this, SLOT(killTimer(void)));
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
    qDebug() << "Timeout timer started";
    timer->start(5000);
}

void bankmain::timeout()
{
    qDebug() << "Timeout";
    emit loggingOut();
}

void bankmain::killTimer()
{
    timer->stop();
}

void bankmain::closeEvent(QCloseEvent *event)
{
    event->accept();
    emit loggingOut();
}

void bankmain::on_exitButton_clicked()
{
    QWidget::close();
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
//    emit stopTimer();
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
