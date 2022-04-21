#ifndef RFID_DLL_H
#define RFID_DLL_H

#include <QObject>
#include <QDebug>
#include "RFID_DLL_global.h"
#include "rfid_dll_engine.h"

class RFID_DLL_EXPORT RFID_DLL : public QObject
{
    Q_OBJECT
public:
    RFID_DLL(QObject *parent = nullptr);
    ~RFID_DLL();

private:
    RFID_DLL_ENGINE *pRFID_ENGINE;
    QString cardNumber;

signals:
    void sendCardNumberToExe(QString);

private slots:
    void getCardNumberFromEngine(void);
    void recvCardNumberFromEngine(QString);
    void restartEngine(void);
};

#endif // RFID_DLL_H
