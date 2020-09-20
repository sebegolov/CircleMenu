#include "circlemenuinterface.h"

#include "petalbutton.h"
#include "centralbutton.h"

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
