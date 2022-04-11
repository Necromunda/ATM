#include "rfid_dll_engine.h"

RFID_DLL_ENGINE::RFID_DLL_ENGINE(QObject *parent) : QObject(parent)
{
    qDebug() << "RFID engine konstruktori?";
    portSettings();
}

void RFID_DLL_ENGINE::readRFID()
{
    qDebug() << "RFID dll engine";
    if (settingsSet) {
        qDebug()<<"RFID dll enginen if-ehto";
        QObject::connect(&serial, &QSerialPort::readyRead, [&]
        {
            qDebug()<<"Settings set?";
            //this is called when readyRead() is emitted
            qDebug() << "New data available: " << serial.bytesAvailable();
            datas = serial.readAll();
            qDebug() << datas;
            datas.remove(0,4);
            datas.chop(3);
            cardNumber = QString(datas);
            emit sendCardNumber(cardNumber);
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
        qDebug() << "Suck a fucking duck";
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
