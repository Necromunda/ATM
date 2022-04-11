#include "mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    qDebug()<<"Welcome ui";


    /*
    pLogin = new Login_dll;
    pRFID = new RFID_DLL;

    // Connecting signal from mainwindow to rfid_dll slot getCardNumberFromEngine()
    connect(this,SIGNAL(getNumber()),
            pRFID,SLOT(getCardNumberFromEngine()));

    // Connecting signal from rfid_dll to mainwindow slot recvCardNumberFromDll()
    connect(pRFID,SIGNAL(sendCardNumberToExe(QString)),
            this,SLOT(recvCardNumberFromDll(QString)));

    // This signal starts the process of reading the RFID-device
    emit getNumber(); */
}

MainWindow::~MainWindow()
{

    delete ui;
    ui=nullptr;
    qDebug()<< "Farewell ui";
    delete pLogin;
    pLogin = nullptr;


    //delete pRFID;
    //pRFID = nullptr;
}

/*
void MainWindow::recvCardNumberFromDll(QString recvd)
{
cardNumber = recvd; // Contains the card number

// Displaying the card number for debugging purposes, not needed in final product
//ui->label_2->setText(cardNumber);
}
*/



/*
void MainWindow::fckwstrings()
{
    qDebug()<< baseStr;
    addStr="monkey";
    baseStr.insert(baseStr.size(),addStr);
    qDebug()<< baseStr;

}

void MainWindow::fckwstrings2()
{
    qDebug() << baseStr;
    addStr=" gets eaten raw";
    baseStr.insert(baseStr.size(), addStr);
    qDebug() << baseStr;
    qDebug() << "Piece of crap or piece of cake?";
}

*/

void MainWindow::fckwstrings3()
{
    baseStr="";
    if(baseStr==""){
    qDebug() << baseStr << "Clear succesfull";
    }
}


void MainWindow::addNumber()
{
    baseStr.insert(baseStr.size(), addStr);
}


void MainWindow::on_btn_addone_clicked()
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


void MainWindow::on_btn_addtwo_clicked()
{
//fckwstrings2();
    addStr="2";
    if(baseStr.size()<4){
        addNumber();
        qDebug() << baseStr;
    }
    ui->le_Pin_code->setText(baseStr);

}


void MainWindow::on_btn_addthree_clicked()
{
    addStr="3";
    if(baseStr.size()<4){
        addNumber();
        qDebug() << baseStr;
    }
    ui->le_Pin_code->setText(baseStr);
}


void MainWindow::on_btn_addfour_clicked()
{
    addStr="4";
    if(baseStr.size()<4){
        addNumber();
        qDebug() << baseStr;
    }
    ui->le_Pin_code->setText(baseStr);
}


void MainWindow::on_btn_addfive_clicked()
{
    addStr="5";
    if(baseStr.size()<4){
        addNumber();
        qDebug() << baseStr;
    }
    ui->le_Pin_code->setText(baseStr);
}


void MainWindow::on_btn_addsix_clicked()
{
    addStr="6";
    if(baseStr.size()<4){
        addNumber();
        qDebug() << baseStr;
    }
    ui->le_Pin_code->setText(baseStr);
}


void MainWindow::on_btn_addseven_clicked()
{
    addStr="7";
    if(baseStr.size()<4){
        addNumber();
        qDebug() << baseStr;
    }
    ui->le_Pin_code->setText(baseStr);
}


void MainWindow::on_btn_addeight_clicked()
{
    addStr="8";
    if(baseStr.size()<4){
        addNumber();
        qDebug() << baseStr;
    }
    ui->le_Pin_code->setText(baseStr);
}


void MainWindow::on_btn_addnine_clicked()
{
    addStr="9";
    if(baseStr.size()<4){
        addNumber();
        qDebug() << baseStr;
    }
    ui->le_Pin_code->setText(baseStr);
}


void MainWindow::on_btn_addzero_clicked()
{
    addStr="0";
    if(baseStr.size()<4){
        addNumber();
        qDebug() << baseStr;
    }
    ui->le_Pin_code->setText(baseStr);
}

//le_Pin_Code.setEchoMode(QLineEdit.password);


void MainWindow::on_btn_clear_clicked()
{
    fckwstrings3();
    qDebug() << baseStr;
    ui->le_Pin_code->setText(baseStr);
}


void MainWindow::on_btn_cancel_clicked()
{

}


void MainWindow::on_btn_addconfirm_clicked()
{

}

