#include "rest_dll.h"

REST_DLL::REST_DLL(QObject *parent) : QObject(parent)
{
    pENGINE = new Engine;

    connect(pENGINE,SIGNAL(sendTransfers(QByteArray)),
            this, SLOT(getResultsFromEngine(QByteArray)));
}

REST_DLL::~REST_DLL()
{
    delete pENGINE;
    pENGINE = nullptr;
}

void REST_DLL::getResultsFromEngine(QByteArray msg)
{
    emit sendResultToExe(msg);
}

void REST_DLL::ExecuteRestOperation(QByteArray token, QString method, QString route, QString body)
{
    pENGINE->getData(token, method, route, body);
}

void REST_DLL::execPostTransfer(QByteArray token, QString method, QString route, QJsonObject body)
{
    pENGINE->postTransfer(token, method, route, body);
}
