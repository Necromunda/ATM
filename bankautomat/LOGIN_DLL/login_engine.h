#ifndef LOGIN_ENGINE_H
#define LOGIN_ENGINE_H

#include <QObject>
#include <QtNetwork>
#include <QNetworkAccessManager>
#include <QJsonDocument>
#include <QCloseEvent>
#include "loginui.h"
#include "debitcreditwindow.h"

class LOGIN_ENGINE : public QObject
{
    Q_OBJECT
public:
    LOGIN_ENGINE(QObject *parent = nullptr);
    ~LOGIN_ENGINE();
    void checkForCredit(QString);

private:
    LoginUi *pLOGIN_UI;
    debitCreditWindow *pDebitCredit;
    QNetworkAccessManager *manager;
    QNetworkReply *reply;
    QByteArray myToken;
    QString cardNumber, token, msg, res, credit, accountId, cardType;
    int tries;
    bool loginSuccesful = false;

signals:
    void startAuth(QString);
    void sendTokenToLogin(QByteArray, QString);
    void wrongPinMsg(QString);
    void loginFailedInEngine(void);
    void beginTimer(void);
    void killTimer(void);
    void resetTimer(void);
    void cardLock(QString);

private slots:
    void recvCardType(QString);
    void recvPin(QString);
    void recvCardNumber(QString);
    void tokenReq(QString);
    void tokenRes(QNetworkReply *reply);
    void cardLockHandler(QString);
    void rejected();
};

#endif // LOGIN_ENGINE_H
