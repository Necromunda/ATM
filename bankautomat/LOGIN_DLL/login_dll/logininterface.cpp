#include "logininterface.h"
#include "ui_logininterface.h"

LoginInterface::LoginInterface(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LoginInterface)
{
    ui->setupUi(this);
    qDebug()<<"Welcome ui";
    pLogin = new Login_dll;
}

LoginInterface::~LoginInterface()
{
    delete ui;
    qDebug()<< "Farewell ui";
    delete pLogin;
    pLogin = nullptr;
}

void LoginInterface::fckwstrings()
{
    qDebug()<< baseStr;
    addStr="monkey";
    baseStr.insert(baseStr.size(),addStr);
    qDebug()<< baseStr;

}

void LoginInterface::fckwstrings2()
{
    qDebug() << baseStr;
    addStr=" gets eaten raw";
    baseStr.insert(baseStr.size(), addStr);
    qDebug() << baseStr;
    qDebug() << "Piece of crap or piece of cake?";
}

void LoginInterface::fckwstrings3()
{
    baseStr="";
    if(baseStr==""){
    qDebug() << baseStr << "Clear succesfull";
    }
}

void LoginInterface::addNumber()
{
    baseStr.insert(baseStr.size(), addStr);
}


void LoginInterface::on_btn_addone_clicked()
{
//fckwstrings();
    addStr="1";
    if(baseStr.size()<4){
        addNumber();
        qDebug() << baseStr;
    }
    //ui->le_Pin_code->setEchoMode(QLineEdit::Password);
    //le_Pin_Code.setEchoMode(QLineEdit.password);
    ui->le_Pin_code->setText(baseStr);

}


void LoginInterface::on_btn_addtwo_clicked()
{
//fckwstrings2();
    addStr="2";
    if(baseStr.size()<4){
        addNumber();
        qDebug() << baseStr;
    }
    ui->le_Pin_code->setText(baseStr);

}


void LoginInterface::on_btn_addthree_clicked()
{
    addStr="3";
    if(baseStr.size()<4){
        addNumber();
        qDebug() << baseStr;
    }
    ui->le_Pin_code->setText(baseStr);
}


void LoginInterface::on_btn_addfour_clicked()
{
    addStr="4";
    if(baseStr.size()<4){
        addNumber();
        qDebug() << baseStr;
    }
    ui->le_Pin_code->setText(baseStr);
}


void LoginInterface::on_btn_addfive_clicked()
{
    addStr="5";
    if(baseStr.size()<4){
        addNumber();
        qDebug() << baseStr;
    }
    ui->le_Pin_code->setText(baseStr);
}


void LoginInterface::on_btn_addsix_clicked()
{
    addStr="6";
    if(baseStr.size()<4){
        addNumber();
        qDebug() << baseStr;
    }
    ui->le_Pin_code->setText(baseStr);
}


void LoginInterface::on_btn_addseven_clicked()
{
    addStr="7";
    if(baseStr.size()<4){
        addNumber();
        qDebug() << baseStr;
    }
    ui->le_Pin_code->setText(baseStr);
}


void LoginInterface::on_btn_addeight_clicked()
{
    addStr="8";
    if(baseStr.size()<4){
        addNumber();
        qDebug() << baseStr;
    }
    ui->le_Pin_code->setText(baseStr);
}


void LoginInterface::on_btn_addnine_clicked()
{
    addStr="9";
    if(baseStr.size()<4){
        addNumber();
        qDebug() << baseStr;
    }
    ui->le_Pin_code->setText(baseStr);
}


void LoginInterface::on_btn_addzero_clicked()
{
    addStr="0";
    if(baseStr.size()<4){
        addNumber();
        qDebug() << baseStr;
    }
    ui->le_Pin_code->setText(baseStr);
}

//le_Pin_Code.setEchoMode(QLineEdit.password);


void LoginInterface::on_btn_clear_clicked()
{
    fckwstrings3();
    qDebug() << baseStr;
    ui->le_Pin_code->setText(baseStr);
}


void LoginInterface::on_btn_cancel_clicked()
{

}


void LoginInterface::on_btn_addconfirm_clicked()
{

}
