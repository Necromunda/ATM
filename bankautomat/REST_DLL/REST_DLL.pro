QT -= gui
QT += network

TEMPLATE = lib
DEFINES += REST_DLL_LIBRARY

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    engine.cpp \
    rest_dll.cpp

HEADERS += \
    REST_DLL_global.h \
    engine.h \
    rest_dll.h

# Default rules for deployment.
unix {
    target.path = /usr/lib
}
!isEmpty(target.path): INSTALLS += target
