#include "circlemenuinterface.h"

#include "petalbutton.h"
#include "centralbutton.h"

#include <QtMath>

CircleMenuInterface::CircleMenuInterface(QWidget *mainWindow)
{
    m_mainWindow = mainWindow;
}

CircleMenuInterface::~CircleMenuInterface()
{
    delete m_centralButton;

    while(m_buttonsCount > 0)
    {
        deletePetalButton(m_buttonsCount);
    }
}

bool CircleMenuInterface::addPetalButton(QString name, QIcon icon)
{
    PetalButton * petal = new PetalButton(m_mainWindow);
    petal->setWindowTitle(name);


    if(petal)
    {
        ++m_buttonsCount;
        m_petalButton.append(petal);

        petal->setId(m_buttonsCount);
        updateMenu();
        return true;
    }

    return false;
}

void CircleMenuInterface::deletePetalButton(int id)
{
    delete m_petalButton.at(id);
    --m_buttonsCount;

    for(int i = id; i < m_buttonsCount; ++i)
    {
        PetalButton * petal = m_petalButton.at(i);
        if(petal->getId() != i)
            petal->setId(i);
    }
}

bool CircleMenuInterface::addCentralButton(QString name, QIcon icon)
{
    if(m_centralButton)
    {
        deleteCentralButton();
    }

    m_centralButton = new CentralButton(m_mainWindow);
    m_centralButton->setWindowTitle(name);
    updateMenu();

    if(!m_centralButton)
        return false;

    return true;
}

void CircleMenuInterface::deleteCentralButton()
{
    if(m_centralButton)
    {
        delete m_centralButton;
        m_centralButton = nullptr;
    }
}

void CircleMenuInterface::setSizeMenu(int sizeMenu)
{
    if(sizeMenu <= m_sizeCentralButton)
    {
        qDebug("The size of the menu is smaller than the center button");
        return;
    }

    m_sizeMenu = sizeMenu;
}

void CircleMenuInterface::setSizeCentralButton(int sizeCentralButton)
{
    if(sizeCentralButton >= m_sizeMenu/2)
    {
        qDebug("Center button size larger than menu size / 2");
        return;
    }

    m_sizeCentralButton = sizeCentralButton;
}

void CircleMenuInterface::setSizeIndents(int sizeIndents)
{
    if(sizeIndents >= (m_sizeMenu - m_sizeCentralButton)/4)
    {
        qDebug("Too large indents");
    }

    m_sizeIndents = sizeIndents;
}

void CircleMenuInterface::showCircleMenu(bool show)
{

}

void CircleMenuInterface::updateMenu()
{
    //setMenuGeometry(m_centralButton);

    foreach(PetalButton * petal, m_petalButton)
    {
        setMenuGeometry(petal);
    }
}

void CircleMenuInterface::deineArea()
{
    if(m_buttonsCount == 0)
        return;

    double center = m_sizeMenu/2;      //центр меню
    double radiusCenterHole = m_sizeCentralButton/2 + m_sizeIndents;
    QRegion centerHole,                 //центральный вырез
            mainCircle,                 //основной круг, для формирования кнопок
            complexForm,
            petal;                      //форма лепестка

    QPoint  centralPoint,             //  |\    /|
            leftTopPoint,             //  | \  / |
            rightTopPoint,            //  |  \/  |
            leftPoint,                //  |      |
            rightPoint;               //  |______|

    QPoint topLeft(0, 0);
    QPoint topRight(m_sizeMenu, 0);
    QPoint botLeft(0, m_sizeMenu);
    QPoint botRight(m_sizeMenu, m_sizeMenu);

    mainCircle = QRegion(0, 0, m_sizeMenu, m_sizeMenu);
    centerHole = QRegion(center-radiusCenterHole, center-radiusCenterHole, center+radiusCenterHole, center+radiusCenterHole);

    double petalAngle = 360/m_buttonsCount;

    if(petalAngle > 180)
        petalAngle = 180;

    double previousAngle = m_angelSimmetry;
    double halfPetalAngle = petalAngle/2;       //половин угла лепестка, для отсчёёт от угла симметрии в обе стороны

    double x,y;

    //определим первую точку в сложном вырезе (centralPoint)
    centralPoint = QPoint(m_sizeMenu/2, m_sizeMenu/2);
    //затем надо прибавить по координатам отступы так, чтобы  они были перпендикулярный
    //линнии огрничевающей лепесток и лежали на линии симметрии данного лепестка
    //TODO отступы сделю потом, когда проверю что работает правильно

    y = center * qTan(qDegreesToRadians(previousAngle - halfPetalAngle));
    if(y > center) y = center;
    if(y < -center) y = -center;

    x = center / qTan(qDegreesToRadians(previousAngle - halfPetalAngle));
    if(x > center) x = center;
    if(x < -center) x = -center;

    leftTopPoint = QPoint(center + x, center + y);

    y = center * qTan(qDegreesToRadians(previousAngle + halfPetalAngle));
    if(y > center) y = center;
    if(y < -center) y = -center;

    x = center / qTan(qDegreesToRadians(previousAngle + halfPetalAngle));
    if(x > center) x = center;
    if(x < -center) x = -center;

    rightTopPoint = QPoint(center + x, center + y);

    if(45 > previousAngle+halfPetalAngle && 45 < previousAngle-halfPetalAngle)
    {
        rightPoint = topRight;
    }
    if(135 > previousAngle+halfPetalAngle && 135 < previousAngle-halfPetalAngle)
    {
        if(rightPoint.isNull()) rightPoint = topLeft;
        else leftPoint = topLeft;
    }
    if(225 > previousAngle+halfPetalAngle && 225 < previousAngle-halfPetalAngle)
    {
        if(rightPoint.isNull()) rightPoint = botLeft;
        else leftPoint = botLeft;
    }
    if(315 > previousAngle+halfPetalAngle && 315 < previousAngle-halfPetalAngle)
    {
        if(rightPoint.isNull()) rightPoint = botRight;
        else leftPoint = botRight;
    }

    if(rightPoint.isNull()) rightPoint = rightTopPoint;
    if(leftPoint.isNull()) leftPoint = leftTopPoint;

    QPolygon complexPoligon;
    complexPoligon << centralPoint<<leftTopPoint<<leftPoint<<rightPoint<<rightTopPoint;
    complexForm = QRegion(complexPoligon);

    petal = mainCircle.subtracted(centerHole);
    petal = petal.intersected(complexForm);

}

void CircleMenuInterface::setMenuGeometry(PetalButton * button)
{
    button->setGeometry(QRect(0,0,m_sizeMenu,m_sizeMenu));
}

void CircleMenuInterface::setCentralButtonMask(PetalButton *button)
{

}

void CircleMenuInterface::setPetalButtonMask(PetalButton *button)
{

}
