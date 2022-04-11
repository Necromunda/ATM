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

signals:

};

#endif // LOGIN_ENGINE_H
