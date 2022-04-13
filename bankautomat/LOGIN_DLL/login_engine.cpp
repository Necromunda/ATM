#include "login_engine.h"

LOGIN_ENGINE::LOGIN_ENGINE(QObject *parent) : QObject(parent)
{
    i = 3;
    pLOGIN_UI = new LoginUi;

    connect(pLOGIN_UI,SIGNAL(sendPinToEngine(QString)),
            this,SLOT(recvPin(QString)));

    connect(this,SIGNAL(startAuth(void)),
            this,SLOT(tokenReq(void)));

    connect(this,SIGNAL(wrongPinMsg(QString)),
            pLOGIN_UI,SLOT(wrongPin(QString)));
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
    pLOGIN_UI->show();
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

    if (myToken != "false") {
        qDebug() << "Correct pin.";
        pLOGIN_UI->close();
        reply->deleteLater();
        postManager->deleteLater();
        emit sendTokenToLogin(myToken);
    } else {
        i--;
        qDebug() << "Incorrect pin.";
        QString s = QString::number(i);
        msg = "Incorrect pin, "+s+" tries left";
        if (i > 0) {
            emit wrongPinMsg(msg);
        } else {
            reply->deleteLater();
            postManager->deleteLater();
            pLOGIN_UI->close();
            emit loginFailedInEngine();
        }
    }
}
