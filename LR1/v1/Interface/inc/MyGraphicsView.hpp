#ifndef MYGRAPHICSVIEW_H
#define MYGRAPHICSVIEW_H
#include <QWidget>
#include <QGraphicsView>
#include <QGraphicsItemGroup>

#include "ui_mainwindow_ui.h"

class MyGraphicsView : public QGraphicsView
{
public:
	explicit MyGraphicsView(QWidget *parent = 0);
	~MyGraphicsView();

	QGraphicsScene *scene;
	QGraphicsItemGroup *object;
	QTimer *timer;

	//void resizeEvent(QResizeEvent *event);
	//void deleteItemsFromGroup(QGraphicsItemGroup *group);
};
#endif