#include "Chair.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QList>
#include <stdlib.h>
#include <CGlobal.h>
#include <QDebug>
Chair::Chair(QGraphicsItem *parent): QObject(), QGraphicsPixmapItem(parent){

    setPos(1200,265);
    setPixmap(QPixmap(":/pic/6.png"));



    QTimer * timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));

    timer->start(30);
}

void Chair::move(){

    setPos(x()-10,y());
    if (pos().x() + pixmap().width()< 0){
        scene()->removeItem(this);
        delete this;
    }
}
