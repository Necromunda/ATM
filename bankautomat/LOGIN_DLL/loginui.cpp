#include "loginui.h"
#include "ui_loginui.h"

LoginUi::LoginUi(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LoginUi)
{
    ui->setupUi(this);
    timer = new QTimer(this);
    timer->setSingleShot(true);
    timer->setInterval(10000);
    connect(timer,SIGNAL(timeout()),
            this,SLOT(timeout()));
}

LoginUi::~LoginUi()
{
    qDebug() << "LoginUi destructor";
    delete ui;
    ui = nullptr;

    delete timer;
    timer = nullptr;
}

void LoginUi::closeEvent(QCloseEvent *event)
{
    if (this->isHidden()) {
        event->ignore();
    } else {
        event->accept();
        ui->lineEdit->clear();
        emit aboutToQuit();
    }
}

void LoginUi::resetTimer()
{
    qDebug() << "Login timer stopped. Time: " << timer->remainingTime();
    timer->stop();
    timer->start();
    qDebug() << "Login timer restarted. Time: " << timer->remainingTime();
}

void LoginUi::startTimer()
{
    qDebug() << "Login timeout timer started";
    timer->start();
}

void LoginUi::stopTimer()
{
    qDebug() << "Login timeout timer stopped";
    timer->stop();
}

void LoginUi::timeout()
{
    qDebug() << "Login timeout";
    QWidget::close();
}

void LoginUi::wrongPin(QString msg)
{
    ui->lineEdit->setPlaceholderText(msg);
}

void LoginUi::on_pushButton_Ok_clicked()
{
    QString pin = ui->lineEdit->text();
    if (pin == "") {
        ui->lineEdit->setPlaceholderText("Insert pin");
    } else {
        ui->lineEdit->clear();
        emit sendPinToEngine(pin);
    }
    pin = "";
}

void LoginUi::on_pushButton_Clear_clicked()
{
    resetTimer();
    QString temp = ui->lineEdit->text();
    temp.chop(1);
    ui->lineEdit->setText(temp);
    temp = "";
}

void LoginUi::on_pushButton_0_clicked()
{
    resetTimer();
    ui->lineEdit->setText(ui->lineEdit->text()+ "0");
}

void LoginUi::on_pushButton_1_clicked()
{
    resetTimer();
    ui->lineEdit->setText(ui->lineEdit->text()+ "1");
}

void LoginUi::on_pushButton_2_clicked()
{
    resetTimer();
    ui->lineEdit->setText(ui->lineEdit->text()+ "2");
}

void LoginUi::on_pushButton_3_clicked()
{
    resetTimer();
    ui->lineEdit->setText(ui->lineEdit->text()+ "3");
}

void LoginUi::on_pushButton_4_clicked()
{
    resetTimer();
    ui->lineEdit->setText(ui->lineEdit->text()+ "4");
}

void LoginUi::on_pushButton_5_clicked()
{
    resetTimer();
    ui->lineEdit->setText(ui->lineEdit->text()+ "5");
}

void LoginUi::on_pushButton_6_clicked()
{
    resetTimer();
    ui->lineEdit->setText(ui->lineEdit->text()+ "6");
}

void LoginUi::on_pushButton_7_clicked()
{
    resetTimer();
    ui->lineEdit->setText(ui->lineEdit->text()+ "7");
}

void LoginUi::on_pushButton_8_clicked()
{
    resetTimer();
    ui->lineEdit->setText(ui->lineEdit->text()+ "8");
}

void LoginUi::on_pushButton_9_clicked()
{
    resetTimer();
    ui->lineEdit->setText(ui->lineEdit->text()+ "9");
}

