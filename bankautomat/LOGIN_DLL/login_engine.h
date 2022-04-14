#ifndef LOGIN_ENGINE_H
#define LOGIN_ENGINE_H

#include <QObject>
#include <QtNetwork>
#include <QNetworkAccessManager>
#include <QJsonDocument>
#include <QCloseEvent>
#include "loginui.h"

class LOGIN_ENGINE : public QObject
{
    Q_OBJECT
public:
    explicit LOGIN_ENGINE(QObject *parent = nullptr);

private:
    LoginUi *pLOGIN_UI;
    QNetworkAccessManager *postManager;
    QNetworkReply *reply;
    QByteArray myToken;
    QString pinCode, cardNumber, token, msg;
    int tries;

signals:
    void startAuth(void);
    void sendTokenToLogin(QByteArray);
    void wrongPinMsg(QString);
    void loginFailedInEngine(void);

private slots:
    void recvPin(QString);
    void recvCardNumber(QString);
    void tokenReq(void);
    void tokenRes(QNetworkReply *reply);
    void rejected();
};

#endif // LOGIN_ENGINE_H
