#ifndef TRUM_H
#define TRUM_H

#include <QGraphicsRectItem>
#include <QObject>
#include <QKeyEvent>

class Trum:public QObject,public QGraphicsRectItem
{
    Q_OBJECT
public:
    Trum();
    void keyPressEvent(QKeyEvent * event);
};

#endif // TRUM_H
