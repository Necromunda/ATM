#ifndef RFID_DLL_ENGINE_H
#define RFID_DLL_ENGINE_H

#include <QObject>
#include <QDebug>
#include <QSerialPort>
#include <QSerialPortInfo>
#include <QString>
#include <QByteArray>

class RFID_DLL_ENGINE : public QObject
{
    Q_OBJECT

public:
    RFID_DLL_ENGINE(QObject *parent = nullptr);
    void readRFID(void);
    void portSettings(void);

private:
    QSerialPort serial;
    QByteArray datas;
    QString cardNumber;
    bool settingsSet = false;

signals:
    void sendCardNumber(QString);
};

#endif // RFID_DLL_ENGINE_H
