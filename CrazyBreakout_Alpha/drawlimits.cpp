#include "drawlimits.h"

DrawLimits::DrawLimits(QGraphicsItem *parent): QGraphicsRectItem(parent)
{
    setRect(0,0,2,700);
    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    brush.setColor(Qt::white);
    setBrush(brush);
}
