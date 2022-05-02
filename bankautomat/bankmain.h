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
#include <QDesktopServices>
#include "drawmoney.h"
#include "transfermoney.h"

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
    void stopTimer(void);
    void timeout(void);
    void closeEvent(QCloseEvent*);
    void setName(QByteArray);
    void setBalance(QByteArray);
    void drawMoney(QString);
    void recvTransferLog(QByteArray);
    void recvCustomTransfers(QByteArray);
    void recvCardType(QString);
    void on_balanceButton_clicked();
    void on_accountActionsButton_clicked();
    void on_prevActionsButton_clicked();
    void on_nextActionsButton_clicked();
    void on_drawMoneyButton_clicked();
    void on_exitButton_clicked();
    void recvSelectedDateTransfers(QByteArray);
    void on_calendarWidget_clicked(const QDate &date);
    void on_transferMoneyButton_clicked();
    void recvIban(QByteArray);
    void execTransaction(QString, QString, QString);
    void recvUserInfo(QByteArray);

signals:
    void loggingOut(void);
    void updateBalance(void);
    void drawMoneySignal(QString);
    void cancelWithdrawal(QString);
    void restartTimer(void);
    void addTransfer(void);
    void getAccId(void);
    void getAllTransfers(void);
    void getCustom(int, int);
    void disconnectRestSignal(void);
    void sendSelectedDate(QString);
    void getIban(void);
    void sendIban(QString);
    void postTransaction(QString, QString, QString);

private:
    Ui::bankmain *ui;
    drawmoney *pDrawMoney;
    transfermoney *pTransferMoney;
    QTimer *timer;
    QString cardType, selectedDate;
    int bot, top;
};

#endif // BANKMAIN_H
