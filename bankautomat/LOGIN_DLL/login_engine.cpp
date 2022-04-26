#include "login_engine.h"

LOGIN_ENGINE::LOGIN_ENGINE(QObject *parent) : QObject(parent)
{
    qDebug() << "LOGIN_ENGINE constructor";
    tries = 3;
    pLOGIN_UI = new LoginUi();

    connect(pLOGIN_UI,SIGNAL(sendPinToEngine(QString)),
            this,SLOT(recvPin(QString)));

    connect(this,SIGNAL(startAuth(QString)),
            this,SLOT(tokenReq(QString)));

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

    connect(this,SIGNAL(cardLocked(void)),
            this,SLOT(lockCard(void)));
}

LOGIN_ENGINE::~LOGIN_ENGINE()
{
}

void LOGIN_ENGINE::recvPin(QString code)
{
    qDebug() << code << "In login";
    loginSuccesful = false;
    emit startAuth(code);
}

void LOGIN_ENGINE::recvCardNumber(QString num)
{
    cardNumber = num;
    qDebug() << cardNumber << "in login";
    pLOGIN_UI->show();
    emit beginTimer();
}

void LOGIN_ENGINE::tokenReq(QString pin)
{
    QString site_url = "http://banksimul-api.herokuapp.com/login/";
    QNetworkRequest request((site_url));
    QJsonObject jsonObj;
    jsonObj.insert("card_number", cardNumber);
    jsonObj.insert("pin_code", pin);
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");

    manager = new QNetworkAccessManager(this);

    connect(manager,SIGNAL(finished(QNetworkReply*)),
            this,SLOT(tokenRes(QNetworkReply*)));

    reply = manager->post(request, QJsonDocument(jsonObj).toJson());
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
        manager->deleteLater();
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
            pLOGIN_UI->close();
            reply->deleteLater();
            manager->deleteLater();
//            emit cardLocked();
        }
    }
}

void LOGIN_ENGINE::lockCard()
{
    qDebug() << "Locking card.";
    manager = new QNetworkAccessManager();
    QObject::connect(manager, &QNetworkAccessManager::finished,
                     this, [=](QNetworkReply *reply) {
        if (reply->error()) {
            QString answer = reply->errorString();
            qDebug() << reply->errorString();
            //  emit sendTransfers(answer);
            return;
        }
        QByteArray answer=reply->readAll();
        qDebug() << answer;
        //  qDebug() << answer;
    }
    );
    QNetworkRequest request;
    request.setUrl(QUrl("http://banksimul-api.herokuapp.com/lock/"+cardNumber));
    manager->put(request, "");
    manager->deleteLater();
    reply->deleteLater();
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
