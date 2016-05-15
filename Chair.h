#ifndef CHAIR_H
#define CHAIR_H

#include <QGraphicsRectItem>
#include <QObject>
#include <QGraphicsPixmapItem>
class Chair: public QObject, public QGraphicsPixmapItem{
    Q_OBJECT
public:
    Chair(QGraphicsItem * parent=0);
public slots:
    void move();
};

#endif
