#ifndef MYGRAPHICSVIEW_H
#define MYGRAPHICSVIEW_H

#include <QGraphicsView>
#include <QGraphicsScene>
#include <QTimer>

#include "MyGraphicsItemGroup.hpp"

class MyGraphicsView : public QGraphicsView
{
    Q_OBJECT

private:
    QTimer *timer;

    void prepeareConfiguration();
    void prepeareTimer();
    void prepeareGroups();

protected:
    void resizeEvent(QResizeEvent *event);

public:
    MyGraphicsItemGroup *picture;
    QGraphicsScene *scene;

    explicit MyGraphicsView(QGraphicsView *parent = 0);
    ~MyGraphicsView();

public slots:
    void slotAlarmTimer();
};

#endif