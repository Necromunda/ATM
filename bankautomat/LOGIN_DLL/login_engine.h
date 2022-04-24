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
    LOGIN_ENGINE(QObject *parent = nullptr);
    ~LOGIN_ENGINE();

private:
    LoginUi *pLOGIN_UI;
    QNetworkAccessManager *manager;
    QNetworkReply *reply;
    QByteArray myToken;
    QString cardNumber, token, msg;
    int tries;
    bool loginSuccesful = false;

signals:
    void startAuth(QString);
    void sendTokenToLogin(QByteArray);
    void wrongPinMsg(QString);
    void loginFailedInEngine(void);
    void beginTimer(void);
    void killTimer(void);
    void resetTimer(void);
    void cardLocked(void);

private slots:
    void recvPin(QString);
    void recvCardNumber(QString);
    void tokenReq(QString);
    void tokenRes(QNetworkReply *reply);
    void lockCard(void);
    void rejected();
};

#endif // LOGIN_ENGINE_H
