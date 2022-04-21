#ifndef BANKMAIN_H
#define BANKMAIN_H

#include <QObject>
#include <QDialog>
#include <QDebug>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QCloseEvent>
#include <QTimer>
#include "drawmoney.h"

namespace Ui {
class bankmain;
}

class bankmain : public QDialog
{
    Q_OBJECT

public:
    explicit bankmain(QWidget *parent = nullptr);
    ~bankmain();

private slots:
    void resetTimer();
    void startTimer(void);
    void timeout(void);
    void closeEvent(QCloseEvent*);
    void setName(QByteArray);
    void setBalance(QByteArray);
    void drawMoney(QString);
    void recvTransferLog(QByteArray);
    void on_balanceButton_clicked();
    void on_accountActionsButton_clicked();
    void on_prevActionsButton_clicked();
    void on_nextActionsButton_clicked();
    void on_drawMoneyButton_clicked();
    void on_exitButton_clicked();

signals:
    void loggingOut(void);
    void updateBalance(void);
    void drawMoneySignal(QString);
    void cancelWithdrawal(QString);
    void restartTimer(void);
    void addTransfer(void);
    void getAccId(void);
    void getAllTransfers();
    void disconnectRestSignal(void);

private:
    Ui::bankmain *ui;
    drawmoney *pDrawMoney;
    QTimer *timer;
};

#endif // BANKMAIN_H
