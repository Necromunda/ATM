#ifndef MENUOFACTUALITY_H
#define MENUOFACTUALITY_H

#include <QDialog>

namespace Ui {
class menuofactuality;
}

class menuofactuality : public QDialog
{
    Q_OBJECT

public:
    explicit menuofactuality(QWidget *parent = nullptr);
    ~menuofactuality();

private:
    Ui::menuofactuality *ui;
};

#endif // MENUOFACTUALITY_H
