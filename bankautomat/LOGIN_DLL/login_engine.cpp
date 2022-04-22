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

    connect(this,SIGNAL(cardLock(QString)),
            this,SLOT(cardLockHandler(QString)));
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
    cardLockHandler("status");
}

void LOGIN_ENGINE::tokenReq(QString pin)
{
    QString site_url = "http://localhost:3000/login/";
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
            qDebug() << "Locking card.";
            pLOGIN_UI->close();
            reply->deleteLater();
            manager->deleteLater();
            cardLockHandler("lock");
        }
    }
}

void LOGIN_ENGINE::cardLockHandler(QString method)
{
    manager = new QNetworkAccessManager();
    QObject::connect(manager, &QNetworkAccessManager::finished,
                     this, [=](QNetworkReply *reply) {
        if (reply->error()) {
            QString answer = reply->errorString();
            qDebug() << "error" << reply->errorString();
            return;
        }
        QByteArray answer=reply->readAll();
        qDebug() << answer;
        if (method == "status") {
            QJsonDocument json_doc = QJsonDocument::fromJson(answer);
            QJsonObject json_obj = json_doc.object();
            res = QString::number(json_obj["locked"].toInt());
            qDebug() << res;
            if (res == "0") {
                pLOGIN_UI->show();
                emit beginTimer();
            } else if (res == "1"){
                qDebug() << "Card is locked.";
            } else {
                qDebug() << "Can't determine locked status.";
            }
        }
        //    manager->deleteLater();
        //    reply->deleteLater();
    }
    );
    if (method == "lock") {
        QNetworkRequest request(("http://localhost:3000/lock/"+cardNumber));
        request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
        QJsonObject jsonObj;
        jsonObj.insert("locked", 1);
        qDebug() << jsonObj;
        manager->put(request, QJsonDocument(jsonObj).toJson());
    } else if (method == "status") {
        QNetworkRequest request(("http://localhost:3000/lock/status/"+cardNumber));
        manager->get(request);
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
