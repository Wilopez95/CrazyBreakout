#ifndef BLOCKDOUBLE_H
#define BLOCKDOUBLE_H
#include <QBrush>
#include <QGraphicsRectItem>

class BlockDouble: public QGraphicsRectItem{
public:
    BlockDouble(QGraphicsItem* parent=NULL);
    int rest=2;
    int pts =15;
    int getRest() const;
    void setRest(int value);
    int getPts() const;
    void setPts(int value);
};

#endif // BLOCKDOUBLE_H

