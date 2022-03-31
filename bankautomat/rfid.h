#ifndef RFID_H
#define RFID_H

#include <QDialog>

namespace Ui {
class RFID;
}

class RFID : public QDialog
{
    Q_OBJECT

public:
    explicit RFID(QWidget *parent = nullptr);
    ~RFID();

private:
    Ui::RFID *ui;
};

#endif // RFID_H
