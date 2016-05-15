#include "John.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QList>
#include <stdlib.h> // rand() -> really large int
#include "CGlobal.h"
#include <QDebug>
John::John(QGraphicsItem *parent): QObject(), QGraphicsPixmapItem(parent){

    setPos(1200,265);
    setPixmap(QPixmap(":/pic/4.png"));



    QTimer * timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));

    timer->start(30);
}

void John::move(){

    setPos(x()-10,y());
    if (pos().x() + pixmap().width()< 0){
        scene()->removeItem(this);
        delete this;
    }
}

