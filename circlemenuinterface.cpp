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
        deleteButton(m_buttonsCount);
    }
}

bool CircleMenuInterface::addButton(QString name, QIcon icon)
{
    PetalButton * petal = new PetalButton(m_mainWindow);
    petal->setWindowTitle(name);


    if(dynamic_cast<QWidget *>(petal))
    {
        ++m_buttonsCount;
        m_petalButton.append(petal);

        petal->setId(m_buttonsCount);
        updateMenu();
        return true;
    }

    return false;
}

void CircleMenuInterface::deleteButton(int id)
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

void CircleMenuInterface::updateMenu()
{
    setMenuGeometry(m_centralButton);

    foreach(PetalButton * petal, m_petalButton)
    {
        setMenuGeometry(petal);
    }
}

void CircleMenuInterface::setMenuGeometry(QWidget * button)
{
    button->setGeometry(QRect(0,0,m_sizeMenu,m_sizeMenu));
}

void CircleMenuInterface::setCentralButtonMask(QWidget *button)
{

}

void CircleMenuInterface::setPetalButtonMask(QWidget *button)
{

}
