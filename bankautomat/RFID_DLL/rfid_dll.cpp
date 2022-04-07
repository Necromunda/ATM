#include "rfid_dll.h"

RFID_DLL::RFID_DLL(QObject *parent) : QObject(parent)
{
    pRFID_WINDOW = new rfid_window;
    pRFID_ENGINE = new RFID_DLL_ENGINE;

    connect(pRFID_ENGINE,SIGNAL(sendCardNumber(QString)),
            this,SLOT(recvCardNumberFromEngine(QString)));

    pRFID_WINDOW->show();
}

RFID_DLL::~RFID_DLL()
{
    delete pRFID_WINDOW;
    pRFID_WINDOW = nullptr;
    delete pRFID_ENGINE;
    pRFID_ENGINE = nullptr;
}

void RFID_DLL::getCardNumberFromEngine(void)
{
    pRFID_ENGINE->readRFID();
}

void RFID_DLL::recvCardNumberFromEngine(QString cardNum)
{
    cardNumber = cardNum;
    pRFID_WINDOW->displayNumber(cardNum);
    emit sendCardNumberToExe(cardNumber);
}
