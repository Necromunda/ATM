#include "login_dll.h"

Login_dll::Login_dll()
{
    qDebug() << "Login Dll, the early years";
    plEngine = new lEngine;
}

Login_dll::~Login_dll()
{
    qDebug() << "Login Dll, into the grave 0_o";
    delete plEngine;
    plEngine=nullptr;
}
