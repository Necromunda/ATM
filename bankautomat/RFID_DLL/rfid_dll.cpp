#include "rfid_dll.h"

RFID_DLL::RFID_DLL(QObject *parent) : QObject(parent)
{
    pRFID_ENGINE = new RFID_DLL_ENGINE;

    connect(pRFID_ENGINE,SIGNAL(sendCardNumber(QString)),
            this,SLOT(recvCardNumberFromEngine(QString)));
}

RFID_DLL::~RFID_DLL()
{
    delete pRFID_ENGINE;
    pRFID_ENGINE = nullptr;
}

void RFID_DLL::getCardNumberFromEngine(void)
{
    pRFID_ENGINE->readRFID();
}

void RFID_DLL::recvCardNumberFromEngine(QString cardNum)
{
    emit sendCardNumberToExe(cardNum);
}

void RFID_DLL::restartEngine()
{
    delete pRFID_ENGINE;
    pRFID_ENGINE = new RFID_DLL_ENGINE;
    connect(pRFID_ENGINE,SIGNAL(sendCardNumber(QString)),
            this,SLOT(recvCardNumberFromEngine(QString)));
    pRFID_ENGINE->readRFID();
}
