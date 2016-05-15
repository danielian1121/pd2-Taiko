#ifndef FINISH_H
#define FINISH_H
#include <QApplication>
#include <QObject>
#include <QProcess>
#include <QLCDNumber>
#include "MyRect.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QGraphicsView>
#include "Trum.h"
#include <QGraphicsRectItem>
#include "Induction.h"
#include <QMediaPlayer>
#include <QPushButton>
class Finish: public QObject
{
    Q_OBJECT

public slots:
    void timechange();
    void enter();
    void restart();
    void scorechange();
private:
    int second ;
    QLCDNumber *lcd = new QLCDNumber(2);
    QLCDNumber *get = new QLCDNumber(2);
    QLCDNumber *final = new QLCDNumber(2);
    MyRect * player = new MyRect();
    QTimer * timer = new QTimer();
    QGraphicsScene * scene = new QGraphicsScene();
    QGraphicsView * view = new QGraphicsView(scene);
    Trum *trum = new Trum();
    Induction *rect = new Induction();
    QMediaPlayer *music = new QMediaPlayer();
    QGraphicsScene * scene1 = new QGraphicsScene();
    QGraphicsView * view1 = new QGraphicsView(scene1);
    QIcon *btn2 = new QIcon(QPixmap(":/pic/7.png"));
    QPushButton *end = new QPushButton(*btn2,"");
};

#endif // FINISH_H
