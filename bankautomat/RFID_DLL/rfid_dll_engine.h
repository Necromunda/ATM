#ifndef RFID_DLL_ENGINE_H
#define RFID_DLL_ENGINE_H

#include <QObject>
#include <QDebug>
#include <QSerialPort>
#include <QSerialPortInfo>
#include <QtNetwork>
#include <QNetworkAccessManager>
#include <QJsonDocument>

class RFID_DLL_ENGINE : public QObject
{
    Q_OBJECT

public:
    RFID_DLL_ENGINE(QObject *parent = nullptr);
    ~RFID_DLL_ENGINE();
    void readRFID(void);
    void portSettings(void);

private:
    QSerialPort serial;
    QByteArray datas, response_data;
    QString cardNumber;
    QNetworkAccessManager *getManager;
    QNetworkReply *reply;
    bool settingsSet = false;
    bool read = false;

signals:
    void sendCardNumber(QString);
    void checkCard(void);

private slots:
    void dbConnect(void);
    void checkCardValidity(QNetworkReply*);
};

#endif // RFID_DLL_ENGINE_H
