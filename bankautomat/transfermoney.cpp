#include "transfermoney.h"
#include "ui_transfermoney.h"

transfermoney::transfermoney(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::transfermoney)
{
    ui->setupUi(this);
//    ui->recvLineEdit->setValidator(new QValidator)
    timer = new QTimer(this);
    timer->setSingleShot(true);
    timer->setInterval(30000);
    connect(timer,SIGNAL(timeout()),
            this,SLOT(timeout()));
    timer->start();
}

transfermoney::~transfermoney()
{
    delete ui;
    ui = nullptr;
}

void transfermoney::setIban(QString msg)
{
    ui->senderLineEdit->setText(msg);
}

void transfermoney::timeout()
{
    this->close();
}

void transfermoney::resetTimer()
{
    timer->stop();
    timer->start();
}

void transfermoney::closeEvent(QCloseEvent *)
{
    if (timer->isActive()) {
        timer->stop();
    }
    timer->deleteLater();
    emit startBankmainTimer();
    this->deleteLater();
}

void transfermoney::on_execTransaction_clicked()
{
    resetTimer();
}


void transfermoney::on_closeButton_clicked()
{
    this->close();
}

