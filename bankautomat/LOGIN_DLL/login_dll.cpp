#include "login_dll.h"

LOGIN_DLL::LOGIN_DLL()
{
    pLOGIN_ENGINE = new LOGIN_ENGINE;
}

LOGIN_DLL::~LOGIN_DLL()
{
    delete pLOGIN_ENGINE;
    pLOGIN_ENGINE = nullptr;
}
