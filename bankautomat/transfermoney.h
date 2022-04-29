#ifndef TRANSFERMONEY_H
#define TRANSFERMONEY_H

#include <QDialog>
#include <QObject>
#include <QDebug>
#include <QIntValidator>
#include <QCloseEvent>
#include <QTimer>

namespace Ui {
class transfermoney;
}

class transfermoney : public QDialog
{
    Q_OBJECT

public:
    explicit transfermoney(QWidget *parent = nullptr);
    ~transfermoney();

private slots:
    void setIban(QString);
    void timeout(void);
    void resetTimer(void);
    void closeEvent(QCloseEvent*);
    void on_execTransaction_clicked();
    void on_closeButton_clicked();

signals:
    void startBankmainTimer(void);

private:
    Ui::transfermoney *ui;
    QTimer *timer;
};

#endif // TRANSFERMONEY_H