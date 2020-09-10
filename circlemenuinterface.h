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
    /// Размер меню
    int m_sizeMenu = 200;
    /// Размер центральной кнопки
    int m_sizeCentralButton = 50;
    /// Видимость центральной кнопки
    bool m_showCentralButton = true;
    /// Размер отступов
    int m_sizeIndents = 10;
    ///цвет меню
    QColor m_colorMenu = Qt::gray;
public:
    CircleMenuInterface(QWidget * mainWindow);
    ~CircleMenuInterface();

    ///добавление кнопки (лепестка)
    bool addButton(QString name, QIcon icon);
    ///удалить кнопку
    void deleteButton(int id);
    void deleteButton(QString name);
    ///добавить группу (раскрывающийся лепесток)
    bool addGroup(QString name, QIcon icon);
    ///удалить группу
    void deleteGroup(int id);
    void deleteGroup(QString name);
    ///добавить центральную кнопку
    bool addCentralButton(QString name, QIcon icon);
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
    void setMenuGeometry(QWidget *button);
    void setCentralButtonMask(QWidget *button);
    void setPetalButtonMask(QWidget *button);

};

#endif // CIRCLEMENUINTERFACE_H
