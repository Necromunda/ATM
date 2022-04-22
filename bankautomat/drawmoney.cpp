#include "drawmoney.h"
#include "ui_drawmoney.h"

drawMoney::drawMoney(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::drawMoney)
{
    ui->setupUi(this);
}

drawMoney::~drawMoney()
{
    delete ui;
    ui = nullptr;
}

void drawMoney::on_btn_draw20_clicked()
{

}


void drawMoney::on_btn_draw40_clicked()
{

}


void drawMoney::on_btn_draw60_clicked()
{

}


void drawMoney::on_btn_draw100_clicked()
{

}


void drawMoney::on_btn_draw200_clicked()
{

}


void drawMoney::on_btn_draw500_clicked()
{

}


void drawMoney::on_btn_drawConfirm_clicked()
{

}


void drawMoney::on_btn_closeWindow_clicked()
{

}

