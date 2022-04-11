#include "login_engine.h"

LOGIN_ENGINE::LOGIN_ENGINE(QObject *parent) : QObject(parent)
{
    pLOGIN_UI = new LoginUi;
    pLOGIN_UI->show();
}
