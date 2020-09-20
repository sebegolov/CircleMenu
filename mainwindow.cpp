#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QMouseEvent>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    init();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::resizeEvent(QResizeEvent *)
{

}

void MainWindow::paintEvent(QPaintEvent *)
{

}

void MainWindow::init()
{
    _circleMenu = new CircleMenuInterface(this);

    if(!_circleMenu->addPetalButton("First", QIcon())  ) qDebug("Не удалось создать кнопку");
    if(!_circleMenu->addPetalButton("Second", QIcon()) ) qDebug("Не удалось создать кнопку");
    if(!_circleMenu->addPetalButton("New", QIcon())    ) qDebug("Не удалось создать кнопку");
    if(!_circleMenu->addCentralButton("Close", QIcon())) qDebug("Не удалось создать кнопку");
}

void MainWindow::mousePressEvent(QMouseEvent *event)
{
    if(event->button() == Qt::RightButton){
        _circleMenu->showCircleMenu(true);
//        PetalButton *petalBtn = new PetalButton(this);
//        petalBtn->move(mapFromGlobal(QCursor::pos()));
//        petalBtn->show();

//        CentralButton * centralBtn = new CentralButton(this);
//        centralBtn->move(mapFromGlobal(QCursor::pos()));
//        centralBtn->show();
    }
}

