#include "bankmain.h"
#include "ui_bankmain.h"

bankmain::bankmain(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::bankmain)
{
    qDebug() << "New session created";
    ui->setupUi(this);
    timer = new QTimer(this);
    timer->setSingleShot(true);
    timer->setInterval(30000);
    connect(timer,SIGNAL(timeout()),
            this,SLOT(timeout()));
    bot = 1;
    top = 5;
}

bankmain::~bankmain()
{
    delete ui;
    ui = nullptr;
    delete timer;
    timer = nullptr;
}

void bankmain::resetTimer()
{
 //   qDebug() << "Bankmain timer stopped. Time: " << timer->remainingTime();
    timer->stop();
    timer->start();
 //   qDebug() << "Bankmain timer restarted. Time: " << timer->remainingTime();
}

void bankmain::startTimer()
{
//    qDebug() << "Bankmain timeout timer started";
    timer->start();
}

void bankmain::stopTimer()
{
//    qDebug() << "Bankmain timeout timer stopped";
    timer->stop();
}

void bankmain::timeout()
{
    qDebug() << "Bankmain timeout";
    QWidget::close();
}

void bankmain::closeEvent(QCloseEvent *event)
{
//    qDebug() << "Received close-event";
//    qDebug() << "Bankmain close event. Time remaining: " << timer->remainingTime();
    event->accept();
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
    emit getAccId();
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
    emit disconnectRestSignal();
    emit getAllTransfers();
}

void bankmain::on_prevActionsButton_clicked()
{
    resetTimer();
    bot -= 4;
    top -= 4;
    if (bot<1) {
        bot = 1;
        top = 5;
    }
    resetTimer();
    emit disconnectRestSignal();
    emit getCustom(bot, top);
}

void bankmain::on_nextActionsButton_clicked()
{
    resetTimer();
    bot += 4;
    top += 4;
    resetTimer();
    emit disconnectRestSignal();
    emit getCustom(bot, top);
}

void bankmain::on_drawMoneyButton_clicked()
{
    stopTimer();
    pDrawMoney = new drawmoney(this);
    connect(pDrawMoney,SIGNAL(drawThisAmount(QString)),
            this,SLOT(drawMoney(QString)));
    connect(pDrawMoney,SIGNAL(startBankmainTimer(void)),
            this,SLOT(startTimer(void)));
    pDrawMoney->show();
    emit updateBalance();
}

void bankmain::drawMoney(QString msg)
{
    connect(this,SIGNAL(cancelWithdrawal(QString)),
            pDrawMoney,SLOT(negativeBal(QString)));
    int oldBal = QString(ui->balanceLabel->text()).toInt();
    int withdrawal = QString(msg).toInt();

    qDebug() << "Card type is: " << cardType;
    if ((oldBal-withdrawal) < 0) {
        if (cardType == "credit") {
            emit drawMoneySignal(msg);
            emit addTransfer();
        } else {
            emit cancelWithdrawal("Balance too low");
        }
    } else {
        emit drawMoneySignal(msg);
        emit addTransfer();
    }
}

void bankmain::recvTransferLog(QByteArray msg)
{
    QJsonDocument json_doc = QJsonDocument::fromJson(msg);
    QJsonArray json_array = json_doc.array();
    QString log;
    foreach (const QJsonValue &value, json_array) {
        QJsonObject json_obj = value.toObject();
        log+=json_obj["action"].toString()+". Amount: "+QString::number(json_obj["amount"].toInt())+". Date: "+json_obj["date"].toString()+"\r";
    }
    ui->transferLogList->setText(log);
    emit disconnectRestSignal();
}

void bankmain::recvCustomTransfers(QByteArray msg)
{
    QJsonDocument json_doc = QJsonDocument::fromJson(msg);
    QJsonArray json_array = json_doc.array();
    QString log;
    foreach (const QJsonValue &value, json_array) {
        QJsonObject json_obj = value.toObject();
        log+=json_obj["action"].toString()+". Amount: "+QString::number(json_obj["amount"].toInt())+". Date: "+json_obj["date"].toString()+"\r";
    }
    ui->transferLogList->setText(log);
    emit disconnectRestSignal();
}

void bankmain::recvCardType(QString msg)
{
    cardType = msg;
}

void bankmain::recvSelectedDateTransfers(QByteArray msg)
{
    QJsonDocument json_doc = QJsonDocument::fromJson(msg);
    QJsonArray json_array = json_doc.array();
    QString log;
    foreach (const QJsonValue &value, json_array) {
        QJsonObject json_obj = value.toObject();
        log+=json_obj["action"].toString()+". Amount: "+QString::number(json_obj["amount"].toInt())+". Date: "+json_obj["date"].toString()+"\r";
    }
    ui->transferLogList->setText(log);
    emit disconnectRestSignal();
}

void bankmain::on_calendarWidget_clicked(const QDate &date)
{
    emit disconnectRestSignal();
    selectedDate = QDate::fromString(date.toString(Qt::ISODate),"yyyy-MM-dd").toString("dd-MM-yyyy");
    emit sendSelectedDate(selectedDate);
}


void bankmain::on_transferMoneyButton_clicked()
{
    QDesktopServices::openUrl(QUrl("http://localhost:3000", QUrl::TolerantMode));
}

