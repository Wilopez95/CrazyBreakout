#ifndef BLOCKINTERNAL_H
#define BLOCKINTERNAL_H
#include <QBrush>
#include <QGraphicsRectItem>

class blockInternal: public QGraphicsRectItem{
public:

    blockInternal(QGraphicsItem* parent=NULL);
    int rest=0;
    int pts =30;
};

#endif // BLOCKINTERNAL_H
