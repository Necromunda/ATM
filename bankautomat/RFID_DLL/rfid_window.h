#ifndef RFID_WINDOW_H
#define RFID_WINDOW_H

#include <QDialog>
#include <QDebug>

namespace Ui {
class rfid_window;
}

class rfid_window : public QDialog
{
    Q_OBJECT

public:
    explicit rfid_window(QWidget *parent = nullptr);
    ~rfid_window();
    void displayNumber(QString);

private:
    Ui::rfid_window *ui;
};

#endif // RFID_WINDOW_H
