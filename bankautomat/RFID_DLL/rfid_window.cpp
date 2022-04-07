#include "rfid_window.h"
#include "ui_rfid_window.h"

rfid_window::rfid_window(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::rfid_window)
{
    ui->setupUi(this);

}

rfid_window::~rfid_window()
{
    delete ui;
}

void rfid_window::displayNumber(QString num)
{
    qDebug() << "in window";
    QString cardNumber = num;
    ui->label->setText(cardNumber);
}
