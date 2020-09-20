#include "petalbutton.h"

int PetalButton::getId() const
{
    return id;
}

void PetalButton::setId(int value)
{
    id = value;
}

PetalButton::PetalButton(QWidget *parent) :
    QWidget(parent)
{

}

QSize PetalButton::sizeHint() const
{
    return QSize(200, 200);
}

void PetalButton::mousePressEvent(QMouseEvent *event)
{

}

void PetalButton::mouseReleaseEvent(QMouseEvent *event)
{

}

void PetalButton::focusInEvent(QFocusEvent *event)
{

}

void PetalButton::focusOutEvent(QFocusEvent *event)
{

}

void PetalButton::enterEvent(QEvent *event)
{

}

void PetalButton::leaveEvent(QEvent *event)
{

}

void PetalButton::paintEvent(QPaintEvent *event)
{

}

void PetalButton::resizeEvent(QResizeEvent *event)
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
