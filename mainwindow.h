#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "circlemenuinterface.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

    CircleMenuInterface *_circleMenu;

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void resizeEvent(QResizeEvent *);
    void paintEvent(QPaintEvent *);

private:
    Ui::MainWindow *ui;

    void init();

    // QWidget interface
protected:
    void mousePressEvent(QMouseEvent *event);
};
#endif // MAINWINDOW_H
