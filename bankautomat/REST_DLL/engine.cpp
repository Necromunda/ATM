#include "engine.h"

Engine::Engine(QObject *parent) : QObject(parent)
{

}

void Engine::getData(QString token, QString method, QString route, QString body)
{
    qDebug() << "GetData from engine called with " + token + method + route + body;
    manager = new QNetworkAccessManager();
    QObject::connect(manager, &QNetworkAccessManager::finished,
        this, [=](QNetworkReply *reply) {
            if (reply->error()) {
                QString answer = reply->errorString();
                qDebug() << reply->errorString();
                emit sendTransfers(answer);
                return;
            }

            QString answer = reply->readAll();

            qDebug() << answer;
            emit sendTransfers(answer);
        }
    );
    request.setUrl(QUrl("http://localhost:3000/"+route));
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
    QByteArray bearerToken="Bearer ";
    bearerToken+=token;
    request.setRawHeader(QByteArray("Authorization"),(bearerToken));
    if(method == "get" || method == "GET"){
        manager->get(request);
    }
    else if(method == "post" || method == "POST"){
        QJsonObject jsonObj;
        QJsonDocument jsonDoc = QJsonDocument::fromJson(body.toUtf8());
        jsonObj = jsonDoc.object();
        manager->post(request, QJsonDocument(jsonObj).toJson());
    }
    else if(method == "update" || method == "UPDATE"){
        QJsonObject jsonObj;
        QJsonDocument jsonDoc = QJsonDocument::fromJson(body.toUtf8());
        jsonObj = jsonDoc.object();
        manager->put(request, QJsonDocument(jsonObj).toJson());
    }
    else if(method == "delete" || method == "DELETE"){
        manager->deleteResource(request);
    }



//    emit sendTransfers("kuuluuko? " +QString::number(i) + " vastaus: ");


}
