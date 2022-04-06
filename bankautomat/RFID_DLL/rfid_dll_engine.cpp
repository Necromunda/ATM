#include "rfid_dll_engine.h"

RFID_DLL_ENGINE::RFID_DLL_ENGINE(QObject *parent) : QObject(parent)
{
    connect(this,SIGNAL(checkCard()),
            this,SLOT(checkIfCardExists()));
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
//            emit sendCardNumber(cardNumber);
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

void RFID_DLL_ENGINE::checkIfCardExists()
{
    QString site_url="http://localhost:3000/cards/";
    QNetworkRequest request((site_url));
    //WEBTOKEN ALKU
    QByteArray myToken="Bearer eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJ1c2VybmFtZSI6IjA1MDA5QkE1MkQiLCJpYXQiOjE2NDkyNTA3NDMsImV4cCI6MTY0OTI1NDM0M30.zT_WzDrrJivEZxaqlHfrbYgmcgudyy9GSJp5cQVgmZk";
    request.setRawHeader(QByteArray("Authorization"),(myToken));
    //WEBTOKEN LOPPU
    getManager = new QNetworkAccessManager(this);

    connect(getManager, SIGNAL(finished(QNetworkReply*)), this, SLOT(db(QNetworkReply*)));

    reply = getManager->get(request);
}

void RFID_DLL_ENGINE::db(QNetworkReply *reply)
{
    response_data=reply->readAll();
    //    qDebug()<<"DATA : "+response_data;
    QJsonDocument json_doc = QJsonDocument::fromJson(response_data);
    QJsonArray json_array = json_doc.array();
    QString cards;
    foreach (const QJsonValue &value, json_array) {
        QJsonObject json_obj = value.toObject();
        cards+=json_obj["card_number"].toString()/*+", "+json_obj["pin_code"].toString()+", "+
                        QString::number(json_obj["locked"].toInt())+", "+QString::number(json_obj["accounts_account_id"].toInt())+", "+
                        QString::number(json_obj["users_user_id"].toInt())*/+"\r";
    }

    qDebug() << cards;
    //    qDebug() << cards.contains(cardNumber+"\r", Qt::CaseSensitive);
    bool compare = cards.contains(cardNumber+"\r", Qt::CaseSensitive);
    qDebug() << cardNumber;
    if (compare) {
        qDebug() << "Card exists";
        emit sendCardNumber(cardNumber);
    } else {
        emit sendCardNumber("Card doesn't exist");
        qDebug() << "Card doesn't exist";
    }

    reply->deleteLater();
    getManager->deleteLater();
}
