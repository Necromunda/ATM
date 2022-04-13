#include "login_dll.h"

LOGIN_DLL::LOGIN_DLL()
{
}

LOGIN_DLL::~LOGIN_DLL()
{
    delete pLOGIN_ENGINE;
    pLOGIN_ENGINE = nullptr;
}

void LOGIN_DLL::loginFailed(void)
{
    emit restartRFID();
}

void LOGIN_DLL::recvCardNumberFromExe(QString num)
{
    cardNumber = num;
    if (!engineCreated) {
        createEngine();
    }
    emit sendCardNumberToLoginEngine(cardNumber);
}

void LOGIN_DLL::recvTokenFromEngine(QByteArray token)
{
    myToken = token;
    emit sendTokenToExe(myToken);
}

void LOGIN_DLL::createEngine()
{
    pLOGIN_ENGINE = new LOGIN_ENGINE;

    connect(this,SIGNAL(sendCardNumberToLoginEngine(QString)),
            pLOGIN_ENGINE,SLOT(recvCardNumber(QString)));

    connect(pLOGIN_ENGINE,SIGNAL(sendTokenToLogin(QByteArray)),
            this,SLOT(recvTokenFromEngine(QByteArray)));

    connect(pLOGIN_ENGINE,SIGNAL(loginFailedInEngine(void)),
            this,SLOT(loginFailed(void)));
    engineCreated = true;
}
