#include "mainwindow.h"

#include <QApplication>
#include <QRegion>
#include <QPainter>
#include <QResizeEvent>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
//    w.setWindowFlag(Qt::FramelessWindowHint);


    w.show();


    return a.exec();
}
