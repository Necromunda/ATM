#ifndef RFID_DLL_ENGINE_H
#define RFID_DLL_ENGINE_H

#include <QObject>
#include <QDebug>
#include <QSerialPort>
#include <QSerialPortInfo>
#include <QString>
#include <QByteArray>
#include <QtNetwork>
#include <QNetworkAccessManager>
#include <QJsonDocument>

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
    QNetworkAccessManager *getManager;
    QNetworkReply *reply;
    QByteArray response_data;
    bool settingsSet = false;
    bool read = false;

signals:
    void sendCardNumber(QString, bool);
    void checkCard();

private slots:
    void dbConnect();
    void checkCardValidity(QNetworkReply*);
};

#endif // RFID_DLL_ENGINE_H
