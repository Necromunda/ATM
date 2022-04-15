#ifndef REST_DLL_H
#define REST_DLL_H

#include "REST_DLL_global.h"
#include "engine.h"
#include <QDebug>
#include <QObject>

class REST_DLL_EXPORT REST_DLL : public QObject
{
    Q_OBJECT
public:
    REST_DLL(QObject *parent = nullptr);
    ~REST_DLL();
private:
    Engine *pENGINE;

signals:
    void sendResultToExe(QString);

public slots:
    void getResultsFromEngine(QString);
    void ExecuteRestOperation(QString, QString, QString, QString);
    // Parametrit: Token, metodi tarkenne, body
    // Esim. e1234, GET, transfers/1, ""
    // Tai e12345, POST, transfers, {"amount": -100,"date": "2012-10-20T21:00:00.000","card_number": 1234,"accounts_account_id": 1}
};

#endif // REST_DLL_H
