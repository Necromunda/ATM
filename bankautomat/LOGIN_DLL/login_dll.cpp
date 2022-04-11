#include "login_dll.h"

LOGIN_DLL::LOGIN_DLL()
{
    pLOGIN_ENGINE = new LOGIN_ENGINE;

    connect(this,SIGNAL(sendCardNumberToLoginEngine(QString)),
            pLOGIN_ENGINE,SLOT(recvCardNumber(QString)));

    connect(pLOGIN_ENGINE,SIGNAL(sendTokenToLogin(QByteArray)),
            this,SLOT(recvTokenFromEngine(QByteArray)));
}

LOGIN_DLL::~LOGIN_DLL()
{
    delete pLOGIN_ENGINE;
    pLOGIN_ENGINE = nullptr;
}

void LOGIN_DLL::recvCardNumberFromExe(QString num)
{
    cardNumber = num;
    emit sendCardNumberToLoginEngine(cardNumber);
}

void LOGIN_DLL::recvTokenFromEngine(QByteArray token)
{
    myToken = token;
    emit sendTokenToExe(myToken);
}
