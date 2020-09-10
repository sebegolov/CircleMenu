#ifndef CIRCLEMENU_H
#define CIRCLEMENU_H

#include <QWidget>

class CircleMenu : public QWidget
{
public:
    CircleMenu(QWidget *parent = nullptr);

    QSize sizeHint() const override;
    // QWidget interface
protected:
    void mousePressEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);
    void paintEvent(QPaintEvent *event);
    void resizeEvent(QResizeEvent *event);
};

#endif // CIRCLEMENU_H
