#ifndef BLOCK_H
#define BLOCK_H
#include <QBrush>
#include <QGraphicsRectItem>

class Block: public QGraphicsRectItem{
public:
    // constructor
    Block(QGraphicsItem* parent=NULL);
    int pts = 10;

    int getPts() const;
    void setPts(int value);
};

#endif // BLOCK_H
