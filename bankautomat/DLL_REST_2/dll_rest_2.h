#ifndef DLL_REST_2_H
#define DLL_REST_2_H

#include "DLL_REST_2_global.h"
#include "engine.h"
#include <QDebug>
#include <QObject>

class DLL_REST_2_EXPORT DLL_REST_2 : public QObject
{
    Q_OBJECT
public:
    DLL_REST_2(QObject *parent = nullptr);
    ~DLL_REST_2();
private:
    Engine *pENGINE;

signals:
    void sendTransfersToExe(QString);
public slots:
    void getTransfersFromEngine(QString);
    void getData(int, QString);

};

#endif // DLL_REST_2_H
