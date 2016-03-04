#include "Block.h"


Block::Block(QGraphicsItem *parent): QGraphicsRectItem(parent){
    // draw rect
    setRect(0,0,25,25);
    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    brush.setColor(Qt::white);
    setBrush(brush);
}
int Block::getPts() const
{
    return pts;
}

void Block::setPts(int value)
{
    pts = value;
}
