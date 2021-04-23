#include "../inc/MyGraphicsView.hpp"

MyGraphicsView::MyGraphicsView(QGraphicsView *parent) : QGraphicsView(parent), 
    scene(new QGraphicsScene()),
    picture(new MyGraphicsItemGroup()),
    timer(new QTimer())
{
    prepeareConfiguration();
    prepeareGroups();
    prepeareTimer();
    timer->start(50);	
}

MyGraphicsView::~MyGraphicsView()
{
    delete picture;
    delete scene;
    delete timer;
}

void MyGraphicsView::prepeareTimer()
{
    timer->setSingleShot(true);
	connect(timer, SIGNAL(timeout()), this, SLOT(slotAlarmTimer()));
}

void MyGraphicsView::prepeareGroups()
{
    scene->addItem(picture);
}

void MyGraphicsView::prepeareConfiguration()
{
	setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
	setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);  
	setAlignment(Qt::AlignCenter);
	setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
	setMinimumHeight(100);
	setMinimumWidth(100);

    setScene(scene);
}

void MyGraphicsView::slotAlarmTimer()
{
	QSize cur_size = this->size();
	int width = cur_size.width();
	int height = cur_size.height();

	scene->setSceneRect(0,0,width,height);
    //draw();
}

void MyGraphicsView::resizeEvent(QResizeEvent *event)
{
    QGraphicsView::resizeEvent(event);
    timer->start(50);
}
