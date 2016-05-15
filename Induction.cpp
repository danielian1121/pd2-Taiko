#include "Induction.h"
#include "John.h"
#include "Chair.h"
#include <QGraphicsScene>
#include <typeinfo>
Induction::Induction()
{
    setPos(0,220);
    setRect(0,0,1200,180);
}

void Induction::Delete()
{
    QList<QGraphicsItem *> colliding_items = collidingItems();
    for (int i = 0, n = colliding_items.size(); i < n; ++i){
        if (typeid(*(colliding_items[i])) == typeid(John)){
            scene()->removeItem(colliding_items[i]);
            delete colliding_items[i];
        }
    }
    for (int i = 0, n = colliding_items.size(); i < n; ++i){
        if (typeid(*(colliding_items[i])) == typeid(Chair)){
            scene()->removeItem(colliding_items[i]);
            delete colliding_items[i];
        }
    }
}
