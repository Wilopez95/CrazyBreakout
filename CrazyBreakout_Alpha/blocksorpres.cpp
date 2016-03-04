#include "blocksorpres.h"

blocksorpres::blocksorpres(QGraphicsItem *parent): QGraphicsRectItem(parent)
{
    setRect(0,0,25,25);
    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    brush.setColor(Qt::blue);
    setBrush(brush);
}
