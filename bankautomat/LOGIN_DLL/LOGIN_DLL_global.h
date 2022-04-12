#ifndef LOGIN_DLL_GLOBAL_H
#define LOGIN_DLL_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(LOGIN_DLL_LIBRARY)
#  define LOGIN_DLL_EXPORT Q_DECL_EXPORT
#else
#  define LOGIN_DLL_EXPORT Q_DECL_IMPORT
#endif

#endif // LOGIN_DLL_GLOBAL_H
