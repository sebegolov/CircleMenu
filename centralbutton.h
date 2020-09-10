#ifndef CENTRALBUTTON_H
#define CENTRALBUTTON_H

#include <QWidget>

class CentralButton : public QWidget
{
public:
    CentralButton(QWidget *parent = nullptr);

    // QWidget interface
public:
    QSize sizeHint() const;

protected:
    void mousePressEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);
    void focusInEvent(QFocusEvent *event);
    void focusOutEvent(QFocusEvent *event);
    void enterEvent(QEvent *event);
    void leaveEvent(QEvent *event);
    void paintEvent(QPaintEvent *event);
};

#endif // CENTRALBUTTON_H
