#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;   // Create mainwindow
    w.show();   // Display mainwindow
    qDebug() << "are we in main?";
    return a.exec();
}
