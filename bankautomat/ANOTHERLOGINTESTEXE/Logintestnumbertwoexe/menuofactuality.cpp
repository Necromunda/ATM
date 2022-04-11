#include "menuofactuality.h"
#include "ui_menuofactuality.h"

menuofactuality::menuofactuality(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::menuofactuality)
{
    ui->setupUi(this);
}

menuofactuality::~menuofactuality()
{
    delete ui;
}
