#ifndef INDUCTION_H
#define INDUCTION_H
#include <QGraphicsRectItem>
#include <QObject>

class Induction:public QObject,public QGraphicsRectItem
{
    Q_OBJECT
public:
    Induction();
public slots:
    void Delete();
};

#endif // INDUCTION_H
