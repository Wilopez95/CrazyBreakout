#ifndef PADDLE_H
#define PADDLE_H
#include <QDialog>
#include <QtCore>
#include <QtGui>
#include <iostream>
#include <QGraphicsRectItem>
#include <QGraphicsSceneMouseEvent>

using namespace std;


class Paddle: public QGraphicsRectItem{
public:
    // constructor
    Paddle(QGraphicsItem* parent=NULL);

    // metodos publicos
    double getCenterX();

    // eventos
    void mouseMoveEvent(QGraphicsSceneMouseEvent* event);
};

#endif // PADDLE_H
