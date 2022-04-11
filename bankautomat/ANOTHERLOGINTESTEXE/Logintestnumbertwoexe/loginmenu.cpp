#include "loginmenu.h"
#include "ui_loginmenu.h"

loginMenu::loginMenu(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::loginMenu)
{
    ui->setupUi(this);
    objectmenuofactuality = new menuofactuality;
}

loginMenu::~loginMenu()
{
    delete ui;
    delete objectmenuofactuality;
    objectmenuofactuality=nullptr;
    ui=nullptr;
}

void loginMenu::fckwstrings3()
{
    baseStr="";
    if(baseStr==""){
    qDebug() << baseStr << "Clear succesfull";
    }
}

void loginMenu::addNumber()
{
    baseStr.insert(baseStr.size(), addStr);
}

void loginMenu::on_btn_addone_clicked()
{
    addStr="1";
    if(baseStr.size()<4){
        addNumber();
        qDebug() << baseStr;
    }
    //ui->le_Pin_code->setEchoMode(QLineEdit::Password);
    //le_Pin_Code.setEchoMode(QLineEdit.password);
    ui->le_Pin_code->setText(baseStr);
}


void loginMenu::on_btn_addtwo_clicked()
{
    addStr="2";
    if(baseStr.size()<4){
        addNumber();
        qDebug() << baseStr;
    }
    ui->le_Pin_code->setText(baseStr);
}


void loginMenu::on_btn_addthree_clicked()
{
    addStr="3";
    if(baseStr.size()<4){
        addNumber();
        qDebug() << baseStr;
    }
    ui->le_Pin_code->setText(baseStr);
}


void loginMenu::on_btn_addfour_clicked()
{
    addStr="4";
    if(baseStr.size()<4){
        addNumber();
        qDebug() << baseStr;
    }
    ui->le_Pin_code->setText(baseStr);
}


void loginMenu::on_btn_addfive_clicked()
{
    addStr="5";
    if(baseStr.size()<4){
        addNumber();
        qDebug() << baseStr;
    }
    ui->le_Pin_code->setText(baseStr);
}


void loginMenu::on_btn_addsix_clicked()
{
    addStr="6";
    if(baseStr.size()<4){
        addNumber();
        qDebug() << baseStr;
    }
    ui->le_Pin_code->setText(baseStr);
}


void loginMenu::on_btn_addseven_clicked()
{
    addStr="7";
    if(baseStr.size()<4){
        addNumber();
        qDebug() << baseStr;
    }
    ui->le_Pin_code->setText(baseStr);
}


void loginMenu::on_btn_addeight_clicked()
{
    addStr="8";
    if(baseStr.size()<4){
        addNumber();
        qDebug() << baseStr;
    }
    ui->le_Pin_code->setText(baseStr);
}


void loginMenu::on_btn_addnine_clicked()
{
    addStr="9";
    if(baseStr.size()<4){
        addNumber();
        qDebug() << baseStr;
    }
    ui->le_Pin_code->setText(baseStr);
}


void loginMenu::on_btn_addzero_clicked()
{
    addStr="0";
    if(baseStr.size()<4){
        addNumber();
        qDebug() << baseStr;
    }
    ui->le_Pin_code->setText(baseStr);
}


void loginMenu::on_btn_clear_clicked()
{
    fckwstrings3();
    qDebug() << baseStr;
    ui->le_Pin_code->setText(baseStr);
}


void loginMenu::on_btn_cancel_clicked()
{

}


void loginMenu::on_btn_addconfirm_clicked()
{

objectmenuofactuality->show();
}

