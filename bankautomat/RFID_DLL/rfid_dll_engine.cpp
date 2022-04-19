#include "rfid_dll_engine.h"

RFID_DLL_ENGINE::RFID_DLL_ENGINE(QObject *parent) : QObject(parent)
{
    connect(this,SIGNAL(checkCard()),
            this,SLOT(dbConnect()));
}

void RFID_DLL_ENGINE::readRFID()
{
    if (!settingsSet) {
        portSettings();
    } else {
        serial.open(QIODevice::ReadOnly);
    }
    QObject::connect(&serial, &QSerialPort::readyRead, [&]
    {
        //this is called when readyRead() is emitted
        qDebug() << "New data available: " << serial.bytesAvailable();
        datas = serial.readAll();
        qDebug() << datas;
        datas.remove(0,3);
        datas.chop(3);
        cardNumber = QString(datas);
        emit checkCard();
    });
    QObject::connect(&serial,
                     static_cast<void(QSerialPort::*)(QSerialPort::SerialPortError)>
                     (&QSerialPort::error),
                     [&](QSerialPort::SerialPortError error)
    {
        //this is called when a serial communication error occurs
        qDebug() << "An error occured: " << error;
    });
}

void RFID_DLL_ENGINE::portSettings(void)
{
    foreach (const QSerialPortInfo &info, QSerialPortInfo::availablePorts()) {
        qDebug() << "Port : " << info.portName();
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
    qDebug() << "Checking card validity in " << site_url;
    QNetworkRequest request((site_url));

    getManager = new QNetworkAccessManager(this);

    connect(getManager, SIGNAL(finished(QNetworkReply*)),
            this, SLOT(checkCardValidity(QNetworkReply*)));

    reply = getManager->get(request);
}

void RFID_DLL_ENGINE::checkCardValidity(QNetworkReply *reply)
{
    response_data=reply->readAll();
    qDebug() << "Response: " << response_data;
    if (response_data == "true") {
        qDebug() << "Card valid";
        serial.close();
        emit sendCardNumber(cardNumber);
    } else {
        qDebug() << "Card not valid";
    }

    reply->deleteLater();
    getManager->deleteLater();
}
