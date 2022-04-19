#ifndef BANKMAIN_H
#define BANKMAIN_H

#include <QDialog>

namespace Ui {
class bankMain;
}

class bankMain : public QDialog
{
    Q_OBJECT

public:
    explicit bankMain(QWidget *parent = nullptr);
    ~bankMain();

private slots:
    void on_btn_closeBankMain_clicked();

    void on_btn_accountBalance_clicked();

private:
    Ui::bankMain *ui;
};

#endif // BANKMAIN_H
