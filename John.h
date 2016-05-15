#ifndef JOHN_H
#define JOHN_H

#include <QGraphicsRectItem>
#include <QObject>
#include <QGraphicsPixmapItem>
class John: public QObject, public QGraphicsPixmapItem{
    Q_OBJECT
public:
    John(QGraphicsItem * parent=0);
public slots:
    void move();

};

#endif
