#ifndef LOGIN_ENGINE_H
#define LOGIN_ENGINE_H

#include <QObject>
#include "loginui.h"

class LOGIN_ENGINE : public QObject
{
    Q_OBJECT
public:
    explicit LOGIN_ENGINE(QObject *parent = nullptr);

private:
    LoginUi *pLOGIN_UI;
    QString pinCode;

signals:

private slots:
    void recvPin(QString);

};

#endif // LOGIN_ENGINE_H
