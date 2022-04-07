#ifndef RFID_DLL_H
#define RFID_DLL_H

#include "RFID_DLL_global.h"
#include "rfid_dll_engine.h"
#include "rfid_window.h"
#include <QObject>
#include <QDebug>

class RFID_DLL_EXPORT RFID_DLL : public QObject
{
    Q_OBJECT
public:
    RFID_DLL(QObject *parent = nullptr);
    ~RFID_DLL();

private:
    rfid_window *pRFID_WINDOW;
    RFID_DLL_ENGINE *pRFID_ENGINE;
    QString cardNumber;

signals:
    void sendCardNumberToExe(QString);

public slots:
    void getCardNumberFromEngine(void);
    void recvCardNumberFromEngine(QString);
};

#endif // RFID_DLL_H
