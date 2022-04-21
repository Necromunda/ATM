#ifndef DRAWMONEY_H
#define DRAWMONEY_H

#include <QDialog>

namespace Ui {
class drawMoney;
}

class drawMoney : public QDialog
{
    Q_OBJECT

public:
    explicit drawMoney(QWidget *parent = nullptr);
    ~drawMoney();

private slots:
    void on_btn_draw20_clicked();

    void on_btn_draw40_clicked();

    void on_btn_draw60_clicked();

    void on_btn_draw100_clicked();

    void on_btn_draw200_clicked();

    void on_btn_draw500_clicked();

    void on_btn_drawConfirm_clicked();

    void on_btn_closeWindow_clicked();

private:
    Ui::drawMoney *ui;
};

#endif // DRAWMONEY_H
