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

private:
    LoginUi *pLOGIN_UI;
    debitCreditWindow *pDebitCredit;
    QNetworkAccessManager *manager;
    QNetworkReply *reply;
    QByteArray myToken;
    QString cardNumber, token, msg, accountId;
    int tries;
    bool loginSuccesful = false;

signals:
    void askForDebitOrCredit(QString);
    void startAuth(QString);
    void sendTokenToLogin(QByteArray, QString);
    void wrongPinMsg(QString);
    void loginFailedInEngine(void);
    void beginTimer(void);
    void killTimer(void);
    void resetTimer(void);
    void cardLock(QString);

private slots:
    void askDebitOrCredit(QString);
    void checkForCredit(QString);
    void recvCardType(QString);
    void recvPin(QString);
    void recvCardNumber(QString);
    void tokenReq(QString);
    void tokenRes(QNetworkReply *reply);
    void cardLockHandler(QString);
    void rejected(void);
};

#endif // LOGIN_ENGINE_H
