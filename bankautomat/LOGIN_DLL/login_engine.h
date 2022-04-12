#ifndef LOGIN_ENGINE_H
#define LOGIN_ENGINE_H

#include <QObject>
#include <QtNetwork>
#include <QNetworkAccessManager>
#include <QJsonDocument>
#include "loginui.h"

class LOGIN_ENGINE : public QObject
{
    Q_OBJECT
public:
    explicit LOGIN_ENGINE(QObject *parent = nullptr);
    void openUi(void);

private:
    LoginUi *pLOGIN_UI;
    QNetworkAccessManager *postManager;
    QNetworkReply *reply;
    QByteArray myToken;
    QString pinCode;
    QString cardNumber;
    QString token;

signals:
    void startAuth(void);
    void sendTokenToLogin(QByteArray);

private slots:
    void recvPin(QString);
    void recvCardNumber(QString);
    void tokenReq(void);
    void tokenRes(QNetworkReply *reply);
};

#endif // LOGIN_ENGINE_H
