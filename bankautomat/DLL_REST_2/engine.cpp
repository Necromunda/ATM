#include "engine.h"

Engine::Engine(QObject *parent) : QObject(parent)
{

}

void Engine::getData(int i)
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
    manager->get(request);


//    emit sendTransfers("kuuluuko? " +QString::number(i) + " vastaus: ");


}
