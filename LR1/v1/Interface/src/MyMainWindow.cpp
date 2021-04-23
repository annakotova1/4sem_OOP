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
	connect(ui->download, SIGNAL(released()), this, SLOT(slotDownload()));
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
	mission_main();
}
void MyMainWindow::slotTransfer()
{}
void MyMainWindow::slotRotate()
{}
void MyMainWindow::slotScale()
{}