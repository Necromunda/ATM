#include "login_engine.h"

LOGIN_ENGINE::LOGIN_ENGINE(QObject *parent) : QObject(parent)
{
    qDebug() << "LOGIN_ENGINE constructor";
    tries = 3;
    pLOGIN_UI = new LoginUi;

    connect(pLOGIN_UI,SIGNAL(sendPinToEngine(QString)),
            this,SLOT(recvPin(QString)));

    connect(this,SIGNAL(startAuth(void)),
            this,SLOT(tokenReq(void)));

    connect(this,SIGNAL(wrongPinMsg(QString)),
            pLOGIN_UI,SLOT(wrongPin(QString)));

    connect(pLOGIN_UI,SIGNAL(aboutToQuit()),
            this,SLOT(rejected()));

    connect(this,SIGNAL(beginTimer(void)),
            pLOGIN_UI,SLOT(startTimer(void)));

    connect(this,SIGNAL(killTimer(void)),
            pLOGIN_UI,SLOT(stopTimer(void)));

    connect(this,SIGNAL(resetTimer(void)),
            pLOGIN_UI,SLOT(resetTimer(void)));
}

void LOGIN_ENGINE::recvPin(QString code)
{
    pinCode = code;
    qDebug() << pinCode << "In login";
    loginSuccesful = false;
    emit startAuth();
}

void LOGIN_ENGINE::recvCardNumber(QString num)
{
    cardNumber = num;
    qDebug() << cardNumber << "in login";
    pLOGIN_UI->show();
    emit beginTimer();
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
        loginSuccesful = true;
        tries = 3;
        qDebug() << "Correct pin.";
        pLOGIN_UI->close();
        reply->deleteLater();
        postManager->deleteLater();
        emit wrongPinMsg("Enter 4 digit pin.");
        emit sendTokenToLogin(myToken);
    } else {
        tries--;
        qDebug() << "Incorrect pin.";
        QString s = QString::number(tries);
        msg = "Incorrect pin, "+ s +" tries left";
        if (tries > 0) {
            emit resetTimer();
            emit wrongPinMsg(msg);
        } else {
            qDebug() << "Card locked.";
            pLOGIN_UI->close();
            reply->deleteLater();
            postManager->deleteLater();
        }
    }
}

void LOGIN_ENGINE::rejected()
{
    qDebug() << "Window was closed";
    emit killTimer();
    if (!loginSuccesful) {
        tries = 3;
        emit wrongPinMsg("Enter 4 digit pin.");
        emit loginFailedInEngine();
    }
}
