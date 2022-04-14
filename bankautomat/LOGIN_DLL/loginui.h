#ifndef LOGINUI_H
#define LOGINUI_H

#include <QObject>
#include <QDialog>
#include <QDebug>
#include <QCloseEvent>

namespace Ui {
class LoginUi;
}

class LoginUi : public QDialog
{
    Q_OBJECT

public:
    explicit LoginUi(QWidget *parent = nullptr);
    ~LoginUi();

private:
    Ui::LoginUi *ui;
    QString pin;

signals:
    void sendPinToEngine(QString);
    void aboutToQuit();

private slots:
    void closeEvent(QCloseEvent*);
    void wrongPin(QString);
    void on_pushButton_Ok_clicked();
    void on_pushButton_Clear_clicked();
    void on_pushButton_0_clicked();
    void on_pushButton_1_clicked();
    void on_pushButton_2_clicked();
    void on_pushButton_3_clicked();
    void on_pushButton_4_clicked();
    void on_pushButton_5_clicked();
    void on_pushButton_6_clicked();
    void on_pushButton_7_clicked();
    void on_pushButton_8_clicked();
    void on_pushButton_9_clicked();

};

#endif // LOGINUI_H
