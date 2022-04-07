#ifndef RFIDWIN_H
#define RFIDWIN_H

#include <QDialog>
#include <QDebug>
#include "rfid_dll.h"
#include "rfid_dll_engine.h"

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = nullptr);
    ~Dialog();

private:
    Ui::Dialog *ui;
};

#endif // RFIDWIN_H
