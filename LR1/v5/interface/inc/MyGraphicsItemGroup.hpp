#ifndef MYGRAPHICSITEMGROUP_H
#define MYGRAPHICSITEMGROUP_H

#include <QPen>
#include <QGraphicsItemGroup>

class MyGraphicsItemGroup : public QGraphicsItemGroup
{
private:
    QVector<QGraphicsItem *> data_pointers;
    
    QPen currentPen;
    QColor currentColor;

    void addItem(QGraphicsItem *new_item);
public:
    explicit MyGraphicsItemGroup(QGraphicsItemGroup *parent = 0);
    ~MyGraphicsItemGroup();
    void clean();
    QGraphicsLineItem *getPoint(qreal x, qreal y);
    QGraphicsLineItem *getPoint(qreal x, qreal y, qreal color);
    QGraphicsLineItem *getLine(qreal start_x, qreal start_y, qreal end_x, qreal end_y);

    void setCurrentColor();
    void makePen();
};

#endif