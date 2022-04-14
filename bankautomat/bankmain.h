#ifndef BANKMAIN_H
#define BANKMAIN_H

#include <QObject>
#include <QDialog>
#include <QDebug>

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
    void on_balanceButton_clicked();
    void on_accountActionsButton_clicked();
    void on_prevActionsButton_clicked();
    void on_nextActionsButton_clicked();
    void on_drawMoneyButton_clicked();
    void on_exitButton_clicked();

signals:
    void loggingOut(void);

private:
    Ui::bankmain *ui;
};

#endif // BANKMAIN_H
