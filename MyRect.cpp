#include "MyRect.h"
#include <QGraphicsScene>
#include <QKeyEvent>
#include "Bullet.h"
#include "John.h"
#include <stdlib.h>
#include <QDebug>
#include <Chair.h>

void MyRect::spawn(){
    // create an enemy

    int a = rand()%2;
    John * john = new John();
    Chair * chair = new Chair();
    switch (a) {
    case 0:
        scene()->addItem(john);
        delete chair;
        break;
    case 1:
        scene()->addItem(chair);
        delete john;
        break;
    }
}
