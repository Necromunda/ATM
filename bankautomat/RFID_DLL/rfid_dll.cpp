#include "rfid_dll.h"

RFID_DLL::RFID_DLL(QObject *parent) : QObject(parent)
{
    qDebug() << "RFID_DLL constructor";
    pRFID_ENGINE = new RFID_DLL_ENGINE;
    connect(pRFID_ENGINE,SIGNAL(sendCardNumber(QString)),
            this,SLOT(recvCardNumberFromEngine(QString)));
}

RFID_DLL::~RFID_DLL()
{
    qDebug() << "RFID_DLL destructor";
    delete pRFID_ENGINE;
    pRFID_ENGINE = nullptr;
}

void RFID_DLL::getCardNumberFromEngine()
{
    pRFID_ENGINE->getCardNumber();
}

void RFID_DLL::recvCardNumberFromEngine(QString card)
{
    qDebug() << "RFID_DLL recvCardNumber function";
//    qDebug() << card;
    cardNumber = card;
    emit sendCardNumberToExe(cardNumber);
}
