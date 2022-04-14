#ifndef DRAWMONEY_H
#define DRAWMONEY_H

#include <QObject>
#include <QDialog>
#include <QDebug>

namespace Ui {
class drawmoney;
}

class drawmoney : public QDialog
{
    Q_OBJECT

public:
    explicit drawmoney(QWidget *parent = nullptr);
    ~drawmoney();

private:
    Ui::drawmoney *ui;
};

#endif // DRAWMONEY_H
