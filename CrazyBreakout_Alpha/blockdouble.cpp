#include "blockdouble.h"


BlockDouble::BlockDouble(QGraphicsItem *parent): QGraphicsRectItem(parent)
{
    setRect(0,0,25,25);
    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    brush.setColor(Qt::red);
    setBrush(brush);
}
int BlockDouble::getPts() const
{
    return pts;
}

void BlockDouble::setPts(int value)
{
    pts = value;
}

int BlockDouble::getRest() const
{
    return rest;
}

void BlockDouble::setRest(int value)
{
    rest = value;
}

