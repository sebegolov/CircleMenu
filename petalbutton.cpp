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

}
