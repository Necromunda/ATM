#include "rfid_dll_engine.h"

RFID_DLL_ENGINE::RFID_DLL_ENGINE(QObject *parent) : QObject(parent)
{
    connect(this,SIGNAL(checkCard()),
            this,SLOT(dbConnect()));
    portSettings();
}

void RFID_DLL_ENGINE::readRFID()
{
    if (settingsSet) {
        QObject::connect(&serial, &QSerialPort::readyRead, [&]
        {
            //this is called when readyRead() is emitted
            qDebug() << "New data available: " << serial.bytesAvailable();
            datas = serial.readAll();
            qDebug() << datas;
            datas.remove(0,3);
            datas.chop(3);
            cardNumber = QString(datas);
            qDebug() << cardNumber;
            emit checkCard();
        });
        QObject::connect(&serial,
                         static_cast<void(QSerialPort::*)(QSerialPort::SerialPortError)>
                         (&QSerialPort::error),
                         [&](QSerialPort::SerialPortError error)
        {
            //this is called when a serial communication error occurs
            qDebug() << "An error occured: " << error;
            exit(0);
        });
    } else {
        portSettings();
    }
}

void RFID_DLL_ENGINE::portSettings(void)
{
    foreach (const QSerialPortInfo &info, QSerialPortInfo::availablePorts()) {
        qDebug() << "Name : " << info.portName();
        serial.setPort(info);
    }
    if(!serial.setBaudRate(QSerialPort::Baud1200))
        qDebug() << serial.errorString();
    if(!serial.setDataBits(QSerialPort::Data7))
        qDebug() << serial.errorString();
    if(!serial.setParity(QSerialPort::EvenParity))
        qDebug() << serial.errorString();
    if(!serial.setFlowControl(QSerialPort::HardwareControl))
        qDebug() << serial.errorString();
    if(!serial.setStopBits(QSerialPort::OneStop))
        qDebug() << serial.errorString();
    if(!serial.open(QIODevice::ReadOnly))
        qDebug() << serial.errorString();
    settingsSet = true;
}

void RFID_DLL_ENGINE::dbConnect()
{
    QString site_url="http://localhost:3000/verify/"+cardNumber;
    qDebug() << site_url;
    QNetworkRequest request((site_url));
    //WEBTOKEN START
//    QByteArray myToken="Bearer eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJ1c2VybmFtZSI6IjA1MDA5QkE1MkQiLCJpYXQiOjE2NDk0MDc1MDcsImV4cCI6MTY0OTQxMTEwN30.Mf-VFtOutNa5G6Qt4RGSWwa46GX8kY8te8HSkTXhTsw";
//    request.setRawHeader(QByteArray("Authorization"),(myToken));
    //WEBTOKEN END
    getManager = new QNetworkAccessManager(this);

    connect(getManager, SIGNAL(finished(QNetworkReply*)), this, SLOT(checkCardValidity(QNetworkReply*)));

    reply = getManager->get(request);
}

void RFID_DLL_ENGINE::checkCardValidity(QNetworkReply *reply)
{
    // Getting json.array as a response, then converting it to a json.object
    //    response_data=reply->readAll();
    //    //    qDebug()<<"DATA : "+response_data;
    //    QJsonDocument json_doc = QJsonDocument::fromJson(response_data);
    //    QJsonArray json_array = json_doc.array();
    //    QString cards;
    //    foreach (const QJsonValue &value, json_array) {
    //        QJsonObject json_obj = value.toObject();
    //        cards+=json_obj["card_number"].toString()/*+", "+json_obj["pin_code"].toString()+", "+
    //                        QString::number(json_obj["locked"].toInt())+", "+QString::number(json_obj["accounts_account_id"].toInt())+", "+
    //                        QString::number(json_obj["users_user_id"].toInt())*/+"\r";
    //    }

    // Getting json.object as a response
//    response_data=reply->readAll();
//    QJsonDocument json_doc = QJsonDocument::fromJson(response_data);
//    QJsonObject json_obj = json_doc.object();
//    QString card;
//    card=json_obj["card_number"].toString()+"\r";

//    qDebug() << card;

//    bool compare = card.contains(cardNumber+"\r", Qt::CaseSensitive);
//    qDebug() << cardNumber;
    response_data=reply->readAll();
    if (response_data == "true") {
        qDebug() << "Card exists";
        emit sendCardNumber(cardNumber,true);
    } else {
        qDebug() << "Card doesn't exist";
        emit sendCardNumber(cardNumber,false);
    }

    reply->deleteLater();
    getManager->deleteLater();
}
