#ifndef ENGINE_H
#define ENGINE_H

#include <QObject>
#include <QtNetwork>
#include <QNetworkAccessManager>
#include <QJsonDocument>

class Engine : public QObject
{
    Q_OBJECT
public:
    Engine(QObject *parent = nullptr);
    void getData(QString, QString, QString, QString);

private:
    QNetworkAccessManager *manager;
    QNetworkRequest request;
    QNetworkReply *reply;
    QByteArray response_data;

signals:
    void sendTransfers(QString);
};

#endif // ENGINE_H
