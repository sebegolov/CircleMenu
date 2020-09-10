#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "circlemenu.h"

#include <QPainter>
#include <QPixmap>
#include <QPolygon>
#include <QMouseEvent>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::resizeEvent(QResizeEvent *)
{
//    QRectF rect(10,20,80,60);
//    int startAngle = 30*16;
//    int spanAngle = 120*16;

//    QPainter p(this);
//    p.setRenderHint(QPainter::Antialiasing);
//    p.setPen(Qt::black);
//    p.setBrush(Qt::black);

//    p.drawPie(rect, startAngle,spanAngle);

//    //p.drawLine(0,0,width(),height());

//    QRegion pie1, pie2, pie3, pie4;
//    pie1 = QRegion(0,0,200,200, QRegion::Ellipse);
//    pie2 = QRegion(50,50,100,100,QRegion::Ellipse);
//    pie3 = pie1.subtracted(QRegion(0,100,250,250, QRegion::Rectangle));
//    QPolygon polygon;
//    polygon << QPoint(100,100) << QPoint(0,50) << QPoint(0,100);
//    pie4 = QRegion(polygon);
//    pie3 = pie3.subtracted(pie2);
//    pie3 = pie3.subtracted(pie4);

//    //setMask(QRegion(30,30,100,100, QRegion::Ellipse));
//    setMask(pie3);

}

void MainWindow::paintEvent(QPaintEvent *)
{
//    QRectF rect(10,20,80,60);
//    int startAngle = 30*16;
//    int spanAngle = 120*16;

//    QPainter p(this);
//    p.setRenderHint(QPainter::Antialiasing);
//    p.setPen(Qt::black);
//    p.setBrush(Qt::black);

//    p.drawPie(rect, startAngle,spanAngle);

//    QRegion pie;
//    pie = p.clipRegion();


}

void MainWindow::mousePressEvent(QMouseEvent *event)
{
    if(event->button() == Qt::RightButton){
        CircleMenu *circ = new CircleMenu(this);
        circ->move(mapFromGlobal(QCursor::pos()));
        circ->show();
    }
}

