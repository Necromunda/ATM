#include "engine.h"

Engine::Engine(QObject *parent) : QObject(parent)
{

}

void Engine::getData(int i, QString token)
{
    manager = new QNetworkAccessManager();
    QObject::connect(manager, &QNetworkAccessManager::finished,
        this, [=](QNetworkReply *reply) {
            if (reply->error()) {
                qDebug() << reply->errorString();
                return;
            }

            QString answer = reply->readAll();

            qDebug() << answer;
            emit sendTransfers(answer);
        }
    );
    request.setUrl(QUrl("http://localhost:3000/transfers/"+QString::number(i)));
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
    QByteArray bearerToken="Bearer ";
    bearerToken+=token;
    request.setRawHeader(QByteArray("Authorization"),(bearerToken));
    manager->get(request);


//    emit sendTransfers("kuuluuko? " +QString::number(i) + " vastaus: ");


}
