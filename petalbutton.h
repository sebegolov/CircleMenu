#ifndef PETALBUTTON_H
#define PETALBUTTON_H

#include <QWidget>

class PetalButton : public QWidget
{
private:
    int id = 0;
public:
    PetalButton(QWidget *parent = nullptr);

    QSize sizeHint() const;

    int getId() const;
    void setId(int value);

protected:
    void mousePressEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);
    void focusInEvent(QFocusEvent *event);
    void focusOutEvent(QFocusEvent *event);
    void enterEvent(QEvent *event);
    void leaveEvent(QEvent *event);
    void paintEvent(QPaintEvent *event);
    void resizeEvent(QResizeEvent *event);
};

#endif // PETALBUTTON_H
