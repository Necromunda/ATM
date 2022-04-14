#include "drawmoney.h"
#include "ui_drawmoney.h"

drawmoney::drawmoney(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::drawmoney)
{
    ui->setupUi(this);
//    this->setWindowModality(Qt::WindowModal);
}

drawmoney::~drawmoney()
{
    delete ui;
    ui = nullptr;
}
