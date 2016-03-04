#ifndef BALL_H
#define BALL_H

#include <QGraphicsRectItem>
#include <QPainter>
#include <QTimer>
#include <QBrush>

class Ball: public QObject, public QGraphicsRectItem{
    Q_OBJECT
public:
    // constructor
    Ball(QGraphicsItem* parent=NULL);

    //metodos publicos
    double getCenterX();

public slots:

    void move();

private:
    // Atributos privados
    double xVelocity;
    double yVelocity;

    //Metodos privados
    void reverseVelocityIfOutOfBounds();
    void handlePaddleCollision();
    void handleBlockCollision();
    void handleBlockDoubleCollision();
};

#endif // BALL_H
