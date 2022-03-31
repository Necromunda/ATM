#include "rfid.h"
#include "ui_rfid.h"

RFID::RFID(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::RFID)
{
    ui->setupUi(this);
}

RFID::~RFID()
{
    delete ui;
}
