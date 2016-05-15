#include "Finish.h"
#include <QGraphicsScene>
#include "MyRect.h"
#include "Trum.h"
#include <QGraphicsView>
#include <QPushButton>
#include <QLCDNumber>
#include <QTimer>
#include "John.h"
#include "Chair.h"
#include "CGlobal.h"
void Finish::enter()
{
    second = 30;

    scene->addPixmap(QPixmap(":/pic/3.png") );


    scene->addItem(trum);

    scene->addItem(rect);

    scene->addItem(player);
    trum->setFlag(QGraphicsItem::ItemIsFocusable);
    trum->setFocus();

    // make rect focusable
  //  player->setFlag(QGraphicsItem::ItemIsFocusable);
   // player->setFocus();

    // create a view to visualize the scene

    view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setWindowTitle("John Cena打太鼓");
    lcd->setSegmentStyle(QLCDNumber::Filled);
    lcd->setFixedSize(100,100);
    lcd->setGeometry(1050,0,100,100);
    get->setSegmentStyle(QLCDNumber::Filled);
    get->setFixedSize(100,100);
    get->setGeometry(1050,100,100,100);
    get->display(0);
    QTimer *time = new QTimer(lcd);
    lcd->display(second);
    time->start(1000);
    scene->addWidget(lcd);
    scene->addWidget(get);
    QObject::connect(time,QTimer::timeout,this,Finish::timechange);



    QTimer *check = new QTimer(get);
    QObject::connect(check,QTimer::timeout,this,Finish::scorechange);
    check->start(50);
    // show the view
    view->show();
    view->setFixedSize(1200,600);
    scene->setSceneRect(0,0,1200,600);
    music->setMedia(QUrl("qrc:/sou/John_Cena-WWE_-_The_Time_Is_Now_John_Cena_Theme_Song_AE_Arena_Effect_mp4.mp3"));
    music->play();
    final->setSegmentStyle(QLCDNumber::Filled);
    final->setFixedSize(100,100);
    final->setGeometry(250,50,100,100);

    view1->setFixedSize(600,300);
    scene1->setSceneRect(0,0,590,290);
    scene1->addPixmap(QPixmap(":/pic/8.png") );
    scene1->addWidget(final);
    end->setIconSize(QSize(200,100));
    end->setFixedSize(200,100);
    end->setGeometry(200,200,200,100);
    scene1->addWidget(end);
    QObject::connect(timer,SIGNAL(timeout()),player,SLOT(spawn()));
    timer->start(600);
    view1->setWindowTitle("總分");

}

void Finish::timechange()
{
    second--;
    if(second>=0)
    {
        lcd->display(second);
    }
    if(second==0)
    {
        timer->stop();
        rect->Delete();

        view1->show();
        final->display(CGlobal::score);

        QObject::connect(end,SIGNAL(clicked()),this,SLOT(restart()));
        music->stop();
    }
}

void Finish::restart()
{
    view1->hide();
    second=30;
    lcd->display(30);
    timer->start(600);
    CGlobal::score=0;
    trum->setFlag(QGraphicsItem::ItemIsFocusable);
    trum->setFocus();
    music->play();

}
void Finish::scorechange()
{
    get->display(CGlobal::score);
}
