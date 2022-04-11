#include "rfid_dll.h"

RFID_DLL::RFID_DLL(QObject *parent) : QObject(parent)
{
    pRFID_ENGINE = new RFID_DLL_ENGINE;

    connect(pRFID_ENGINE,SIGNAL(sendCardNumber(QString, bool)),
            this,SLOT(recvCardNumberFromEngine(QString, bool)));
}

RFID_DLL::~RFID_DLL()
{
    delete pRFID_ENGINE;
    pRFID_ENGINE = nullptr;
}

void RFID_DLL::getCardNumberFromEngine(void)
{
    pRFID_ENGINE->readRFID();
    qDebug()<<"getting cardnumber f engine";
}

void RFID_DLL::recvCardNumberFromEngine(QString cardNum, bool valid)
{
    if (valid) {
        cardNumber = cardNum;
        emit sendCardNumberToExe(cardNumber);
    } else {
        emit sendCardNumberToExe("Card not valid");
    }
}
