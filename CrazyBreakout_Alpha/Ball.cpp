#include "Ball.h"

#include "Game.h"
#include "Paddle.h"
#include "Block.h"


extern Game* game;

Ball::Ball(QGraphicsItem *parent): QGraphicsRectItem(parent), QObject(){


    setRect(0,0,15,15);
    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    brush.setColor(Qt::red);
    setBrush(brush);

    // movimiento de la bola
    xVelocity = 0;
    yVelocity = -5;

    QTimer* timer = new QTimer();
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));
    timer->start(15);
}

double Ball::getCenterX(){
    return x() + rect().width()/2;
}

void Ball::move(){
    // Si choca con los bordes invierte la direccion!
    reverseVelocityIfOutOfBounds();

    //si hay colicion con la raqueta , este invierte el valor de yVelity y el de xVelocity
    //dependiendo de donde golpee la raqueta

    handlePaddleCollision();

    //Manejador de coliciones con los bloques comunes, lo destruye y invierte la direccion
    handleBlockCollision();
     //Manejador de coliciones con los bloques dobles, lo destruye y invierte la direccion
    handleBlockDoubleCollision();

    moveBy(xVelocity,yVelocity);
}

void Ball::reverseVelocityIfOutOfBounds(){


    double screenW = game->width()-100;
    double screenH = game->height();

    // borde izquierd
    if (mapToScene(rect().topLeft()).x() <= 0){
        xVelocity = -1 * xVelocity;
    }

    // borde derecho
    if (mapToScene(rect().topRight()).x() >= screenW){
        xVelocity = -1 * xVelocity;
    }

    // borde superior
    if (mapToScene(rect().topLeft()).y() <= 0){
        yVelocity = -1 * yVelocity;
    }


}

void Ball::handlePaddleCollision(){
    QList<QGraphicsItem*> cItems = collidingItems();
    for (size_t i = 0, n = cItems.size(); i < n; ++i){
        Paddle* paddle = dynamic_cast<Paddle*>(cItems[i]);
        if (paddle){
            // collicion con la tabla

            // invierte velocidad en Y
            yVelocity = -1 * yVelocity;

            // agrega velocidad dependiendo de donde golpea la tabla
            double ballX = getCenterX();
            double paddleX = paddle->getCenterX();

            double dvx = ballX - paddleX;
            xVelocity = (xVelocity + dvx)/15;

            return;
        }
    }
}

void Ball::handleBlockCollision(){
    QList<QGraphicsItem*> cItems = collidingItems();
    for (size_t i = 0, n = cItems.size(); i < n; ++i){
        Block* block = dynamic_cast<Block*>(cItems[i]);
        // colicion con clocks
        if (block){
            double yPad = 15;
            double xPad = 15;
            double ballx = pos().x();
            double bally = pos().y();
            double blockx = block->pos().x();
            double blocky = block->pos().y();

            // colicion con fondo
            if (bally > blocky + yPad && yVelocity < 0){
                yVelocity = -1 * yVelocity;
            }

            // colicion con el techo
            if (blocky > bally + yPad && yVelocity > 0 ){
                yVelocity = -1 * yVelocity;
            }

            // colicion con la derecha
            if (ballx > blockx + xPad && xVelocity < 0){
                xVelocity = -1 * xVelocity;
            }

            // colicion con la izquierda
            if (blockx > ballx + xPad && xVelocity > 0){
                xVelocity = -1 * xVelocity;
            }

            game->scene->removeItem(block);
            delete block;
        }
    }
}
void Ball::handleBlockDoubleCollision(){
    QList<QGraphicsItem*> cItems = collidingItems();
    for (size_t i = 0, n = cItems.size(); i < n; ++i){
        BlockDouble* Dblock= dynamic_cast<BlockDouble*>(cItems[i]);
        if(Dblock){
            double yPad = 15;
            double xPad = 15;
            double ballx = pos().x();
            double bally = pos().y();
            double blockx = Dblock->pos().x();
            double blocky = Dblock->pos().y();


            if (bally > blocky + yPad && yVelocity < 0){
                yVelocity = -1 * yVelocity;
            }


            if (blocky > bally + yPad && yVelocity > 0 ){
                yVelocity = -1 * yVelocity;
            }

            if (ballx > blockx + xPad && xVelocity < 0){
                xVelocity = -1 * xVelocity;
            }

            if (blockx > ballx + xPad && xVelocity > 0){
                xVelocity = -1 * xVelocity;
            }
            //if(Dblock->getPts()==2){
            game->scene->removeItem(Dblock);
            delete Dblock;
           // }else{
             //   Dblock->setRest(1);
           //}
        }

    }

}
