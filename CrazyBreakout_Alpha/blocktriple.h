#ifndef BLOCKTRIPLE_H
#define BLOCKTRIPLE_H
#include <QBrush>
#include <QGraphicsRectItem>

class blocktriple: public QGraphicsRectItem{
public:
    blocktriple(QGraphicsItem* parent=NULL);
    int rest=3;
    int pts =12;
};

#endif // BLOCKTRIPLE_H
