#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "dburl.h"

#include <QMainWindow>
#include <loginmenu.h>
#include <QDebug>
#include <QtNetwork>
#include <QNetworkAccessManager>
#include <QJsonDocument>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_btn_sendCardNum_clicked();
    void cardNumberSlot(QNetworkReply *reply);

private:
    Ui::MainWindow *ui;
    loginMenu *objectloginMenu;
    dbUrl *objectdbUrl;
    QString baseurl;
    QString cardnum="22001133";

    QNetworkAccessManager *cardNumberManager;
    QNetworkReply *reply;
    QByteArray response_data;
};
#endif // MAINWINDOW_H
