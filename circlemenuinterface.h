#ifndef CIRCLEMENUINTERFACE_H
#define CIRCLEMENUINTERFACE_H

#include <QIcon>
#include <QList>

#include "centralbutton.h"

class PetalButton;
class CentralButton;

/// Интерфейс создания кругового меню
class CircleMenuInterface
{
private:
    CentralButton * m_centralButton = nullptr;

    QList<PetalButton *> m_petalButton;

    QWidget * m_mainWindow = nullptr;

    /// Количество кнопок (лепестков)
    int m_buttonsCount = 0;
    /// Размер меню (диаметр)
    int m_sizeMenu = 200;
    /// Размер центральной кнопки (диаметр)
    int m_sizeCentralButton = 50;
    /// Видимость центральной кнопки
    bool m_showCentralButton = true;
    /// Размер отступов
    int m_sizeIndents = 10;
    ///цвет меню
    QColor m_colorMenu = Qt::green;
    ///угол симметрии перввой кнопки
    double m_angelSimmetry = 90;            //Pi/2
public:
    CircleMenuInterface(QWidget * mainWindow);
    ~CircleMenuInterface();

    ///добавление кнопки (лепестка)
    bool addPetalButton(QString name, QIcon icon);
    ///удалить кнопку
    void deletePetalButton(int id);
    void deletePetalButton(QString name);
    ///добавить группу (раскрывающийся лепесток)
    bool addGroup(QString name, QIcon icon);
    ///удалить группу
    void deleteGroup(int id);
    void deleteGroup(QString name);
    ///добавить центральную кнопку
    bool addCentralButton(QString name, QIcon icon);
    ///удлить центральную кнопку
    void deleteCentralButton();
    ///получить количество кнопок (вместе с группами)
    int getButtonsCount();
    /// задать размер меню
    void setSizeMenu(int sizeMenu);
    /// задать размер центральной кнопки
    void setSizeCentralButton(int sizeCentralButton);
    /// задать видимость центральной кнопки
    void setShowCentralButton(bool showCentralButton);
    /// задать размер отступов
    void setSizeIndents(int sizeIndents);

    ///показать меню
    void showCircleMenu(bool show);

protected:
    void updateMenu();
    void deineArea();
    void setMenuGeometry(PetalButton *button);
    void setCentralButtonMask(PetalButton *button);
    void setPetalButtonMask(PetalButton *button);

};

#endif // CIRCLEMENUINTERFACE_H
