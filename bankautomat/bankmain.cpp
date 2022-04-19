#include "bankmain.h"
#include "ui_bankmain.h"

bankMain::bankMain(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::bankMain)
{
    ui->setupUi(this);
}

bankMain::~bankMain()
{
    delete ui;
}

void bankMain::on_btn_closeBankMain_clicked()
{
    close();
}


void bankMain::on_btn_accountBalance_clicked()
{

}

