#include "centralbutton.h"

CentralButton::CentralButton(QWidget *parent) :
    QWidget(parent)
{
    setGeometry(20,20,200,200);
    //setAttribute(Qt::WA_TranslucentBackground);
}

QSize CentralButton::sizeHint() const
{
    return QSize(200, 200);
}

void CentralButton::mousePressEvent(QMouseEvent *event)
{
    close();
}

void CentralButton::mouseReleaseEvent(QMouseEvent *event)
{

}

void CentralButton::focusInEvent(QFocusEvent *event)
{

}

void CentralButton::focusOutEvent(QFocusEvent *event)
{

}

void CentralButton::enterEvent(QEvent *event)
{

}

void CentralButton::leaveEvent(QEvent *event)
{

}

void CentralButton::paintEvent(QPaintEvent *event)
{
    QRegion pie1, pie2, pie3, pie4;
    //pie1 = QRegion(0,0,200,200, QRegion::Ellipse);
    pie2 = QRegion(55,55,90,90,QRegion::Ellipse);
    //pie3 = pie1.subtracted(QRegion(0,100,250,250, QRegion::Rectangle));
    //QPolygon polygon;
    //polygon << QPoint(100,100) << QPoint(0,30) << QPoint(0,100);
    //pie4 = QRegion(polygon);
    //pie3 = pie3.subtracted(pie2);
    //pie3 = pie3.subtracted(pie4);

    //setMask(QRegion(30,30,100,100, QRegion::Ellipse));
    setMask(pie2);
    setStyleSheet("background-color: red");
}
