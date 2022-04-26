#ifndef DEBITCREDITWINDOW_H
#define DEBITCREDITWINDOW_H

#include <QDialog>

namespace Ui {
class debitCreditWindow;
}

class debitCreditWindow : public QDialog
{
    Q_OBJECT

public:
    explicit debitCreditWindow(QWidget *parent = nullptr);
    ~debitCreditWindow();

private slots:
    void on_debitButton_clicked();
    void on_creditButton_clicked();

signals:
    void sendCardType(QString);

private:
    Ui::debitCreditWindow *ui;
};

#endif // DEBITCREDITWINDOW_H
