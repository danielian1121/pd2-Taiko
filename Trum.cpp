#include "Trum.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QList>
#include "John.h"
#include <typeinfo>
#include <QDebug>
#include "Chair.h"
#include "CGlobal.h"
Trum::Trum()
{
    setPos(275,290);
    setRect(0,0,50,50);
}
void Trum::keyPressEvent(QKeyEvent *event)
{
    if(event->key() == Qt::Key_F)
    {
        QList<QGraphicsItem *> colliding_items = collidingItems();
        for (int i = 0, n = colliding_items.size(); i < n; ++i){
            if (typeid(*(colliding_items[i])) == typeid(John)){
                scene()->removeItem(colliding_items[i]);
                delete colliding_items[i];
                CGlobal::score++;
            }
        }
    }
    if(event->key() == Qt::Key_J)
    {
        QList<QGraphicsItem *> colliding_items = collidingItems();
        for (int i = 0, n = colliding_items.size(); i < n; ++i){
            if (typeid(*(colliding_items[i])) == typeid(Chair)){
                scene()->removeItem(colliding_items[i]);
                delete colliding_items[i];
                CGlobal::score++;
            }
        }
    }
}
