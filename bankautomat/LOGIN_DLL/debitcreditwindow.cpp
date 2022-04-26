#include "debitcreditwindow.h"
#include "ui_debitcreditwindow.h"

debitCreditWindow::debitCreditWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::debitCreditWindow)
{
    ui->setupUi(this);
}

debitCreditWindow::~debitCreditWindow()
{
    delete ui;
}

void debitCreditWindow::on_debitButton_clicked()
{
    emit sendCardType("debit");
}


void debitCreditWindow::on_creditButton_clicked()
{
    emit sendCardType("credit");
}

