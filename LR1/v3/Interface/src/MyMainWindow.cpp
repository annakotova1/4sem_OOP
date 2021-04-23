#include "../inc/MyMainWindow.hpp"

MyMainWindow::MyMainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
	ui->setupUi(this);
	myPicture = new MyGraphicsView();
	ui->graphicsLayout->addWidget(myPicture);
	setValidator();
	setConnet();
	setSplitter();
}

MyMainWindow::~MyMainWindow()
{
	delete ui;
	delete myPicture;
	delete myLocale;
	delete myValidator;
}

void MyMainWindow::configValidator()
{
	myValidator = new QDoubleValidator();
	myLocale = new QLocale();

	QLocale::setDefault(*myLocale);

	myValidator->setNotation(QDoubleValidator::StandardNotation);
	myValidator->setLocale(*myLocale);
}

void MyMainWindow::setValidator()
{
	configValidator();

	ui->transfer_x->setValidator(myValidator);
	ui->transfer_y->setValidator(myValidator);
	ui->transfer_z->setValidator(myValidator);
	ui->rotate_x->setValidator(myValidator);
	ui->rotate_y->setValidator(myValidator);
	ui->rotate_z->setValidator(myValidator);
	ui->scale_x->setValidator(myValidator);
	ui->scale_y->setValidator(myValidator);
	ui->scale_z->setValidator(myValidator);

}

void MyMainWindow::setConnet()
{
	connect(ui->transferButton, SIGNAL(released()), this, SLOT(slotTransfer()));
	connect(ui->rotateButton, SIGNAL(released()), this, SLOT(slotRotate()));
	connect(ui->scaleButton, SIGNAL(released()), this, SLOT(slotScale()));
	connect(ui->download, SIGNAL(triggered()), this, SLOT(slotDownload()));
}

void MyMainWindow::setSplitter()
{
	QList<int> s1;
	s1.push_back(20);
	s1.push_back(1000);
	ui->splitter->setSizes(s1);
}

void MyMainWindow::slotDownload()
{
	domens_interaction data;
	QString fileName = QFileDialog::getOpenFileName();
	std::string s = fileName.toStdString();
	char *filename = (char *)s.data();

	data.filename = filename;
	data.command = DOWNLOAD;

	mission_main(data);
}
void MyMainWindow::slotTransfer()
{
	domens_interaction data;
	data.command = TRANSFORM;
	data.settings.x = myLocale->toDouble(ui->transfer_x->text());
	data.settings.y = myLocale->toDouble(ui->transfer_y->text());
	data.settings.z = myLocale->toDouble(ui->transfer_z->text());
	data.settings.operation = TRANSFER;
	delete myPicture->object;
	myPicture->object = new QGraphicsItemGroup();
	myPicture->scene->addItem(myPicture->object);
	data.group = myPicture->object;

	mission_main(data);
	data.command = DRAW;
	//mission_main(data);
}
void MyMainWindow::slotRotate()
{}
void MyMainWindow::slotScale()
{}