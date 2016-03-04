#include "blockinternal.h"

blockInternal::blockInternal(QGraphicsItem *parent): QGraphicsRectItem(parent)
{
    setRect(0,0,25,25);
    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    brush.setColor(Qt::yellow);
    setBrush(brush);
}
