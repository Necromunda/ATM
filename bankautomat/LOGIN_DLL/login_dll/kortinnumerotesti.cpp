#include "kortinnumerotesti.h"
#include "ui_kortinnumerotesti.h"

Kortinnumerotesti::Kortinnumerotesti(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Kortinnumerotesti)
{
    ui->setupUi(this);
}

Kortinnumerotesti::~Kortinnumerotesti()
{
    delete ui;
}
