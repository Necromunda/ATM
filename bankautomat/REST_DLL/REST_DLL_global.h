#ifndef REST_DLL_GLOBAL_H
#define REST_DLL_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(REST_DLL_LIBRARY)
#  define REST_DLL_EXPORT Q_DECL_EXPORT
#else
#  define REST_DLL_EXPORT Q_DECL_IMPORT
#endif

#endif // REST_DLL_GLOBAL_H
