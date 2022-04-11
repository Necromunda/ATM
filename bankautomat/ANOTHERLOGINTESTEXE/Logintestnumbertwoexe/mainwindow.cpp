#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    qDebug()<<"Welcome ui";
    objectdbUrl = new dbUrl;

    baseurl = objectdbUrl->getBaseurl();

    objectloginMenu = new loginMenu;

}

MainWindow::~MainWindow()
{
    delete ui;
    delete objectloginMenu;
    ui = nullptr;
    qDebug()<< "Farewell ui";
    objectloginMenu = nullptr;
}


void MainWindow::on_btn_sendCardNum_clicked()
{
    qDebug() << "baseurl="+baseurl;
    objectloginMenu->show();


    QNetworkRequest request((baseurl+"/cards"));

    cardNumberManager = new QNetworkAccessManager(this);

    connect(cardNumberManager, SIGNAL(finished(QNetworkReply*)), this, SLOT(cardNumberSlot(QNetworkReply*)));

    reply = cardNumberManager->get(request);
}

void MainWindow::cardNumberSlot(QNetworkReply *reply)
{
    response_data=reply->readAll();
    qDebug()<<response_data;
}

