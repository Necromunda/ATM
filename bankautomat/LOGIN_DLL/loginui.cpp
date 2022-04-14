#include "loginui.h"
#include "ui_loginui.h"

LoginUi::LoginUi(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LoginUi)
{
    ui->setupUi(this);
//    this->setWindowModality(Qt::WindowModal);
}

LoginUi::~LoginUi()
{
    qDebug() << "destroying login window";
    delete ui;
}

void LoginUi::wrongPin(QString msg)
{
    ui->lineEdit->setPlaceholderText(msg);
}

void LoginUi::on_pushButton_Ok_clicked()
{
    pin = ui->lineEdit->text();
    ui->lineEdit->clear();
    emit sendPinToEngine(pin);
}

void LoginUi::on_pushButton_Clear_clicked()
{
    ui->lineEdit->clear();
}

void LoginUi::on_pushButton_0_clicked()
{
    ui->lineEdit->setText(ui->lineEdit->text()+ "0");
}

void LoginUi::on_pushButton_1_clicked()
{
    ui->lineEdit->setText(ui->lineEdit->text()+ "1");
}

void LoginUi::on_pushButton_2_clicked()
{
    ui->lineEdit->setText(ui->lineEdit->text()+ "2");
}

void LoginUi::on_pushButton_3_clicked()
{
    ui->lineEdit->setText(ui->lineEdit->text()+ "3");
}

void LoginUi::on_pushButton_4_clicked()
{
    ui->lineEdit->setText(ui->lineEdit->text()+ "4");
}

void LoginUi::on_pushButton_5_clicked()
{
    ui->lineEdit->setText(ui->lineEdit->text()+ "5");
}

void LoginUi::on_pushButton_6_clicked()
{
    ui->lineEdit->setText(ui->lineEdit->text()+ "6");
}

void LoginUi::on_pushButton_7_clicked()
{
    ui->lineEdit->setText(ui->lineEdit->text()+ "7");
}

void LoginUi::on_pushButton_8_clicked()
{
    ui->lineEdit->setText(ui->lineEdit->text()+ "8");
}

void LoginUi::on_pushButton_9_clicked()
{
    ui->lineEdit->setText(ui->lineEdit->text()+ "9");
}

