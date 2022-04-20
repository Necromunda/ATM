#include "bankmain.h"
#include "ui_bankmain.h"

bankmain::bankmain(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::bankmain)
{
    qDebug() << "bankmain constructor";
    ui->setupUi(this);
    timer = new QTimer(this);
    timer->setSingleShot(true);
    timer->setInterval(30000);
    connect(timer,SIGNAL(timeout()),
            this,SLOT(timeout()));
}

bankmain::~bankmain()
{
    qDebug() << "bankmain destructor";
    delete ui;
    ui = nullptr;

    delete pDrawMoney;
    pDrawMoney = nullptr;

    delete timer;
    timer = nullptr;
}

void bankmain::resetTimer()
{
    qDebug() << "Bankmain timer stopped. Time: " << timer->remainingTime();
    timer->stop();
    timer->start();
    qDebug() << "Bankmain timer restarted. Time: " << timer->remainingTime();
}

void bankmain::startTimer()
{
    qDebug() << "Bankmain timeout timer started";
    timer->start();
}

void bankmain::timeout()
{
    qDebug() << "Bankmain timeout";
    QWidget::close();
}

void bankmain::closeEvent(QCloseEvent *event)
{
    ui->balanceLabel->clear();
    qDebug() << "Received close-event";
    event->accept();
    qDebug() << "Bankmain close event. Time remaining: " << timer->remainingTime();
    if (timer->isActive()) {
        timer->stop();
    }
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
    resetTimer();
    emit updateBalance();
}

void bankmain::on_accountActionsButton_clicked()
{
    resetTimer();
}

void bankmain::on_prevActionsButton_clicked()
{
    resetTimer();
}

void bankmain::on_nextActionsButton_clicked()
{
    resetTimer();
}

void bankmain::on_drawMoneyButton_clicked()
{
    resetTimer();
    pDrawMoney = new drawmoney(this);
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
