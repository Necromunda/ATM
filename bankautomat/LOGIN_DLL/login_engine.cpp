#include "login_engine.h"

LOGIN_ENGINE::LOGIN_ENGINE(QObject *parent) : QObject(parent)
{
    pLOGIN_UI = new LoginUi;

    connect(pLOGIN_UI,SIGNAL(sendPinToEngine(QString)),
            this,SLOT(recvPin(QString)));

    connect(this,SIGNAL(startAuth(void)),
            this,SLOT(tokenReq(void)));
}

void LOGIN_ENGINE::recvPin(QString code)
{
    pinCode = code;
    qDebug() << pinCode << "In login";
    emit startAuth();
}

void LOGIN_ENGINE::recvCardNumber(QString num)
{
    cardNumber = num;
    qDebug() << cardNumber << "In login";
    openUi();
}

void LOGIN_ENGINE::openUi(void)
{
    pLOGIN_UI->open();
}

void LOGIN_ENGINE::tokenReq(void)
{
    QString site_url = "http://localhost:3000/login/";
    QNetworkRequest request((site_url));
    QJsonObject jsonObj;
    jsonObj.insert("card_number", cardNumber);
    jsonObj.insert("pin_code", pinCode);
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");

    postManager = new QNetworkAccessManager(this);

    connect(postManager,SIGNAL(finished(QNetworkReply*)),
            this,SLOT(tokenRes(QNetworkReply*)));

    reply = postManager->post(request, QJsonDocument(jsonObj).toJson());
}

void LOGIN_ENGINE::tokenRes(QNetworkReply *reply)
{
    myToken=reply->readAll();
    qDebug() << myToken;

    if (myToken != "false") {
        delete pLOGIN_UI;
        pLOGIN_UI = nullptr;
        emit sendTokenToLogin(myToken);
    }

    reply->deleteLater();
    postManager->deleteLater();
}
