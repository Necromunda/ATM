#ifndef DRAWMONEY_H
#define DRAWMONEY_H

#include <QObject>
#include <QDialog>
#include <QDebug>
#include <QIntValidator>

namespace Ui {
class drawmoney;
}

class drawmoney : public QDialog
{
    Q_OBJECT

public:
    explicit drawmoney(QWidget *parent = nullptr);
    ~drawmoney();
    QString moneyHandler(int);

private slots:
    void negativeBal(QString);
    void on_closeButton_clicked();
    void on_drawButton_clicked();
    void on_amountCustomButton_clicked();
    void on_amount20Button_clicked();
    void on_amount40Button_clicked();
    void on_amount60Button_clicked();
    void on_amount80Button_clicked();
    void on_amount100Button_clicked();
    void on_amount200Button_clicked();
    void on_amount500Button_clicked();

signals:
    void drawThisAmount(QString);

private:
    Ui::drawmoney *ui;
    int amount, cAmount;
    QString drawThis;
};

#endif // DRAWMONEY_H
