#ifndef GAME_H
#define GAME_H

#include <QGraphicsView>
#include <QGraphicsScene>
#include <QKeyEvent>
#include<QBrush>
#include "Ball.h"
#include "Paddle.h"
#include "Block.h"
#include "blockdouble.h"
#include "blocktriple.h"
#include "blockinternal.h"
#include "blocksorpres.h"
#include "drawlimits.h"

class Game: public QGraphicsView{
public:
    int points=0;
    // constructor
    Game(QWidget* parent=NULL);

    // metodos publicos
    void start();
    //crea los bloques simples
    void createBlockCol(double x);
    void creatBlockGrid();
    //Crea los bloques dobles
    void createBlockColDoubles(double x);
    void creatBlockGridDoubles();
    //crea los bloques triples
    void createBlockColTriples(double x);
    void creatBlockGridTriples();
    //crea los bloques internos
    void createBlockColInternal(double x);
    void creatBlockGridInternal();
    //crea los bloques sorpresa
    void createBlockColSorpres(double x);
    void creatBlockGridSorpres();


    // atributos publicos
    QGraphicsScene* scene;


};

#endif // GAME_H
