#include "../inc/MyGraphicsView.hpp"

MyGraphicsView::MyGraphicsView(QWidget *parent) : QGraphicsView(parent)
{
	scene = new QGraphicsScene();
	object = new QGraphicsItemGroup();
}

MyGraphicsView::~MyGraphicsView()
{
	delete scene;
	delete object;
}
