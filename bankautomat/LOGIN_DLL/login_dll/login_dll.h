#ifndef LOGIN_DLL_H
#define LOGIN_DLL_H

#include "login_dll_global.h"
#include "lengine.h"

class LOGIN_DLL_EXPORT Login_dll:public QObject
{
    Q_OBJECT
public:
    Login_dll();
    ~Login_dll();

private:
    lEngine * plEngine;
};

#endif // LOGIN_DLL_H
