#include "engine.h"

Engine::Engine(QObject *parent) : QObject(parent)
{
}

Engine::~Engine()
{
}

void Engine::getData(QByteArray token, QString method, QString route, QString body)
{
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

        //  qDebug() << answer;
        emit sendTransfers(answer);
    }
    );
    request.setUrl(QUrl("http://localhost:3000/"+route));
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
    request.setRawHeader(QByteArray("Authorization"),(token));
    if(method == "get" || method == "GET"){
        manager->get(request);
    } else if(method == "post" || method == "POST"){
        QJsonObject jsonObj;
        QJsonDocument jsonDoc = QJsonDocument::fromJson(body.toUtf8());
        jsonObj = jsonDoc.object();
        manager->post(request, QJsonDocument(jsonObj).toJson());
    } else if(method == "update" || method == "UPDATE"){
        QJsonObject jsonObj;
        QJsonDocument jsonDoc = QJsonDocument::fromJson(body.toUtf8());
        jsonObj = jsonDoc.object();
        manager->put(request, QJsonDocument(jsonObj).toJson());
    } else if(method == "withdraw" || method == "WITHDRAW"){
        QJsonObject jsonObj;
        jsonObj.insert("balance",body);
        qDebug() << "Body: " << jsonObj;
        manager->put(request, QJsonDocument(jsonObj).toJson());
    } else if(method == "delete" || method == "DELETE"){
        manager->deleteResource(request);
    }
}

void Engine::postTransfer(QByteArray token, QString method, QString route, QJsonObject body)
{
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
        //  qDebug() << answer;
        emit sendTransfers(answer);
    }
    );
    request.setUrl(QUrl("http://localhost:3000/"+route));
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
    request.setRawHeader(QByteArray("Authorization"),(token));
    if(method == "get" || method == "GET"){
        manager->get(request);
    } else if (method == "post" || method == "POST") {
        qDebug() << "Body: " << body;
        manager->post(request, QJsonDocument(body).toJson());
    }
}
