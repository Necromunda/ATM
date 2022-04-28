#include "login_dll.h"

LOGIN_DLL::LOGIN_DLL(QObject *parent) : QObject(parent)
{
    pLOGIN_ENGINE = new LOGIN_ENGINE();
    connect(this,SIGNAL(sendCardNumberToLoginEngine(QString)),
            pLOGIN_ENGINE,SLOT(recvCardNumber(QString)));
    connect(pLOGIN_ENGINE,SIGNAL(sendTokenToLogin(QByteArray, QString)),
            this,SLOT(recvTokenFromEngine(QByteArray, QString)));
    connect(pLOGIN_ENGINE,SIGNAL(loginFailedInEngine(void)),
            this,SLOT(loginFailed(void)));
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
    emit sendCardNumberToLoginEngine(num);
}

void LOGIN_DLL::recvTokenFromEngine(QByteArray token, QString type)
{
    emit sendTokenToExe(token, type);
}
