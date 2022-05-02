#include "transfermoney.h"
#include "ui_transfermoney.h"

transfermoney::transfermoney(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::transfermoney)
{
    ui->setupUi(this);
    rx.setPattern("FI\\d{16}");
    ui->recvLineEdit->setValidator(new QRegExpValidator(rx,this));
    ui->amountLineEdit->setValidator(new QIntValidator(0, 9999, this));
    timer = new QTimer(this);
    timer->setSingleShot(true);
    timer->setInterval(60000);
    connect(timer,SIGNAL(timeout()),
            this,SLOT(timeout()));
    timer->start();
}

transfermoney::~transfermoney()
{
    qDebug() << "Money transfer destructor";
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
    ui->amountLineEdit->clear();
    ui->transactionStatusLabel->clear();
    QString tSendIban, tRecvIban, tAmount;
    tSendIban = ui->senderLineEdit->text();
    tRecvIban = ui->recvLineEdit->text();
    tAmount = ui->amountLineEdit->text();
    if (tRecvIban.count() == 18 && tAmount != "" && tAmount != "0") {
        if (tSendIban == tRecvIban) {
            ui->transactionStatusLabel->setText("Error: Duplicate Iban");
        } else {
            ui->transactionStatusLabel->setText("Success!");
            emit execTransaction(tSendIban, tRecvIban, tAmount);
        }
    } else {
        ui->transactionStatusLabel->setText("Error: Check input");
    }
}

void transfermoney::on_closeButton_clicked()
{
    this->close();
}
