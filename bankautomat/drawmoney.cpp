#include "drawmoney.h"
#include "ui_drawmoney.h"

drawmoney::drawmoney(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::drawmoney)
{
    ui->setupUi(this);
    amount = 0;
    cAmount = 0;
    ui->customAmountLineEdit->setValidator(new QIntValidator(0, 100, this));
}

drawmoney::~drawmoney()
{
    delete ui;
    ui = nullptr;
}

QString drawmoney::moneyHandler(int money)
{
    amount = ui->drawMoneyLineEdit->text().toInt();
    amount += money;
    return QString::number(amount);
}

void drawmoney::on_closeButton_clicked()
{
    this->close();
}

void drawmoney::on_drawButton_clicked()
{
    drawThis = ui->drawMoneyLineEdit->text();
    qDebug() << "Draw this amout: " << drawThis;
    emit drawThisAmount(drawThis);    // Uncomment when rest-api ready
}

void drawmoney::on_amountCustomButton_clicked()
{
    cAmount = ui->customAmountLineEdit->text().toInt();
    ui->drawMoneyLineEdit->setText(moneyHandler(cAmount));
}

void drawmoney::on_amount20Button_clicked()
{
    ui->drawMoneyLineEdit->setText(moneyHandler(20));
}

void drawmoney::on_amount40Button_clicked()
{
    ui->drawMoneyLineEdit->setText(moneyHandler(40));
}

void drawmoney::on_amount60Button_clicked()
{
    ui->drawMoneyLineEdit->setText(moneyHandler(60));
}

void drawmoney::on_amount80Button_clicked()
{
    ui->drawMoneyLineEdit->setText(moneyHandler(80));
}

void drawmoney::on_amount100Button_clicked()
{
    ui->drawMoneyLineEdit->setText(moneyHandler(100));
}

void drawmoney::on_amount200Button_clicked()
{
    ui->drawMoneyLineEdit->setText(moneyHandler(200));
}

void drawmoney::on_amount500Button_clicked()
{
    ui->drawMoneyLineEdit->setText(moneyHandler(500));
}
