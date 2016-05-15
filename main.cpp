#include <QApplication>
#include "MyRect.h"
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QTimer>
#include "Trum.h"
#include <QLCDNumber>
#include <QTimer>
#include <QPushButton>
#include "Finish.h"
#include <ctime>
#include <CGlobal.h>
int CGlobal::score = 0;
int main(int argc, char *argv[]){

    srand(time(NULL));
    QApplication a(argc, argv);
    Finish finish;
    QGraphicsScene *scene = new QGraphicsScene();
    QIcon *btn = new QIcon(QPixmap(":/pic/2.png"));
    QPushButton *start = new QPushButton(*btn,"");
    start->setIconSize(QSize(200,100));
    QGraphicsView * view = new QGraphicsView(scene);
    view->setWindowTitle("John Cena打太鼓");

    scene->addPixmap(QPixmap(":/pic/1.png") );
    start->setFixedSize(200,100);
    start->setGeometry(500,500,200,100);
    scene->addWidget(start);
    view->show();
    view->setFixedSize(1200,600);
    scene->setSceneRect(0,0,1190,590);
    QObject::connect(start,SIGNAL(clicked()),&finish,SLOT(enter()));
    QObject::connect(start,SIGNAL(clicked()),view,SLOT(hide()));


    return a.exec();
}

