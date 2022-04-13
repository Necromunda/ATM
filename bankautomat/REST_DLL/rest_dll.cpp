#include "rest_dll.h"

REST_DLL::REST_DLL(QObject *parent) : QObject(parent)
{
    pENGINE = new Engine;
    connect(pENGINE,SIGNAL(sendTransfers(QString)),
            this, SLOT(getResultsFromEngine(QString)));
}

REST_DLL::~REST_DLL(){
    delete pENGINE;
    pENGINE = nullptr;
}

void REST_DLL::getResultsFromEngine(QString msg)
{
    emit sendResultToExe(msg);
}

void REST_DLL::ExecuteRestOperation(QString token, QString method, QString route, QString body)
{
    pENGINE->getData(token, method, route, body);
}
