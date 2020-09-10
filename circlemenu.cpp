#include "circlemenu.h"

CircleMenu::CircleMenu(QWidget *parent) :
    QWidget(parent)
{
    setGeometry(20,20,200,200);
    //setAttribute(Qt::WA_TranslucentBackground);
}

QSize CircleMenu::sizeHint() const
{
    return QSize(200, 200);
}

void CircleMenu::mousePressEvent(QMouseEvent *event)
{
    close();
}

void CircleMenu::mouseReleaseEvent(QMouseEvent *event)
{

}

void CircleMenu::paintEvent(QPaintEvent *event)
{
    setStyleSheet("background-color: red");
}

void CircleMenu::resizeEvent(QResizeEvent *event)
{
    QRectF rect(10,20,80,60);
    int startAngle = 30*16;
    int spanAngle = 120*16;

    //p.drawLine(0,0,width(),height());

    QRegion pie1, pie2, pie3, pie4;
    pie1 = QRegion(0,0,200,200, QRegion::Ellipse);
    pie2 = QRegion(50,50,100,100,QRegion::Ellipse);
    pie3 = pie1.subtracted(QRegion(0,100,250,250, QRegion::Rectangle));
    QPolygon polygon;
    polygon << QPoint(100,100) << QPoint(0,30) << QPoint(0,100);
    pie4 = QRegion(polygon);
    pie3 = pie3.subtracted(pie2);
    pie3 = pie3.subtracted(pie4);

    //setMask(QRegion(30,30,100,100, QRegion::Ellipse));
    setMask(pie3);
    setStyleSheet("background-color: red");
}
