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


    QNetworkRequest request((baseurl+"/verify/"+cardnum));

    cardNumberManager = new QNetworkAccessManager(this);

    connect(cardNumberManager, SIGNAL(finished(QNetworkReply*)), this, SLOT(cardNumberSlot(QNetworkReply*)));

    reply = cardNumberManager->get(request);
}

void MainWindow::cardNumberSlot(QNetworkReply *reply)
{
    //response_data=reply->readAll();
    //qDebug()<<"saammeko mitaan"+response_data;
    qDebug()<<"DATA : "+response_data;
     QJsonDocument json_doc = QJsonDocument::fromJson(response_data);
     QJsonArray json_array = json_doc.array();
     QString card;
     foreach (const QJsonValue &value, json_array) {
        QJsonObject json_obj = value.toObject();
        //card+=QString::number(json_obj["id_book"].toInt())+", "+json_obj["name"].toString()+", "+json_obj["author"].toString()+"\r";
        card+=json_obj["cardnumber"].toString()+"\r";
     }
        qDebug()<<response_data;
        if(cardnum==card){
            objectloginMenu->show();
        }
        else
        {
            qDebug()<<"You fcked it again, mr. Anderson";
     }
}

