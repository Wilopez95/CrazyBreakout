#include "Game.h"


Game::Game(QWidget *parent): QGraphicsView(parent){
    // inicia la pantalla
    scene = new QGraphicsScene(0,0,400,600);
    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    brush.setColor(Qt::black);
    scene->setBackgroundBrush(brush);
    setScene(scene);
    setWindowTitle("CrazyBreakout");


    // sigue el movimiento del mouse
    setMouseTracking(true);


}

void Game::start(){
    // crea la bola
    Ball* ball = new Ball();
    ball->setPos(200,500);
    scene->addItem(ball);

    // crea la barra
    Paddle* paddle = new Paddle();
    paddle->setPos(150,575);
    scene->addItem(paddle);
    paddle->grabMouse();

    //Crea el texto en pantalla
    QGraphicsTextItem * io = new QGraphicsTextItem;
    io->setPos(600,50);
    io->setPlainText("PUNTOS :");
    io->setDefaultTextColor(Qt::white);
    scene->addItem(io);

    //Dibuja limites
    DrawLimits *limitIzq = new DrawLimits();
    limitIzq->setPos(0,0);
    scene->addItem(limitIzq);
    DrawLimits *limitDer = new DrawLimits();
    limitDer->setPos(537,0);
    scene->addItem(limitDer);

    // crea los bloques
    creatBlockGrid();
    creatBlockGridDoubles();
    creatBlockGridTriples();
    creatBlockGridInternal();
    creatBlockGridSorpres();
}
//crea los bloques horizontales
void Game::createBlockCol(double x){
    for (size_t i = 6, n =8; i < n; ++i){
        Block* block = new Block();
        block->setPos(x,i*27);
        scene->addItem(block);
    }
}
//Crea los bloques verticales
void Game::creatBlockGrid(){
    for (size_t i = 0, n = 20; i < n; ++i){
        createBlockCol(i*27);
    }
}
//Dobles
void Game::createBlockColDoubles(double x){
    for(size_t i=4, n=6;i<n; i++){
        BlockDouble* BlockD = new BlockDouble();
        BlockD->setPos(x,i*27);
        scene->addItem(BlockD);
    }
}
void Game ::creatBlockGridDoubles(){
    for(size_t i = 0, n = 20; i < n; ++i){
           createBlockColDoubles(i*27);
    }
}
//Triples
void Game::createBlockColTriples(double x){
    for(size_t i=3, n=4;i<n; i++){
        blocktriple* Blockt = new blocktriple();
        Blockt->setPos(x,i*27);
        scene->addItem(Blockt);
    }
}
void Game ::creatBlockGridTriples(){
    for(size_t i = 0, n = 20; i < n; ++i){
           createBlockColTriples(i*27);
    }
}
//Internos
void Game::createBlockColInternal(double x){
    for(size_t i=2, n=3;i<n; i++){
        blockInternal* BlockI = new blockInternal();
        BlockI->setPos(x,i*27);
        scene->addItem(BlockI);
    }
}
void Game ::creatBlockGridInternal(){
    for(size_t i = 0, n = 20; i < n; ++i){
           createBlockColInternal(i*27);
    }
}
//Sorpresa
void Game::createBlockColSorpres(double x){
    for(size_t i=0, n=2;i<n; i++){
        blocksorpres* BlockS = new blocksorpres();
        BlockS->setPos(x,i*27);
        scene->addItem(BlockS);
    }
}
void Game ::creatBlockGridSorpres(){
    for(size_t i = 0, n = 20; i < n; ++i){
           createBlockColSorpres(i*27);
    }
}

