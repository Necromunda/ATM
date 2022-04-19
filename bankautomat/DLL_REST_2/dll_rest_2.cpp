#include "dll_rest_2.h"

DLL_REST_2::DLL_REST_2(QObject *parent) : QObject(parent)
{
    pENGINE = new Engine;
    connect(pENGINE,SIGNAL(sendTransfers(QString)),
            this, SLOT(getTransfersFromEngine(QString)));
}

DLL_REST_2::~DLL_REST_2(){
    delete pENGINE;
    pENGINE = nullptr;
}

void DLL_REST_2::getTransfersFromEngine(QString msg)
{
    emit sendTransfersToExe(msg);
}

void DLL_REST_2::getData(int i, QString token)
{
    pENGINE->getData(i, token);
}
