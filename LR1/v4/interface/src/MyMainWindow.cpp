#include "../inc/MyMainWindow.hpp"
#include "../../task/settings/settings.hpp"

MyMainWindow::MyMainWindow(QMainWindow *parent): QMainWindow(parent), 
    myLocale(new MyLocale()), myPicture(new MyGraphicsView()),
    ui(new Ui::MainWindow())
{
    ui->setupUi(this);
    ui->graphics_layout->addWidget(myPicture);
	setConnection();
	setValidator();
	setSplitters();
}

MyMainWindow::~MyMainWindow()
{
    delete myPicture;
	
	task_settings_t data;
	data.command = EXIT;
	task_main(data);

	exit();
}

void MyMainWindow::setSplitters()
{
	QList<int> s1;
	s1.push_back(20);
	s1.push_back(1000);
	ui->splitter->setSizes(s1);
}
void MyMainWindow::setValidator()
{
	ui->transfer_x->setValidator(myLocale->getDoubleValidator());
	ui->transfer_y->setValidator(myLocale->getDoubleValidator());
	ui->transfer_z->setValidator(myLocale->getDoubleValidator());
	
    ui->rotate_x->setValidator(myLocale->getDoubleValidator());
	ui->rotate_y->setValidator(myLocale->getDoubleValidator());
	ui->rotate_z->setValidator(myLocale->getDoubleValidator());


	ui->scale_x->setValidator(myLocale->getDoubleValidator());
	ui->scale_y->setValidator(myLocale->getDoubleValidator());
	ui->scale_z->setValidator(myLocale->getDoubleValidator());
}

void MyMainWindow::setConnection()
{
	connect(ui->download_action, SIGNAL(triggered()), this, SLOT(slotDownload()));
	connect(ui->transfer_button, SIGNAL(pressed()), this, SLOT(slotTransfer()));
	connect(ui->rotate_button, SIGNAL(pressed()), this, SLOT(slotRotate()));
	connect(ui->scale_button, SIGNAL(pressed()), this, SLOT(slotScale()));
}

void MyMainWindow::slotDownload()
{
	task_settings_t data;

	data.command = DOWNLOAD;
	QString fileName = QFileDialog::getOpenFileName();
	std::string s = fileName.toStdString();
	char *filename = (char *)s.data();
	data.command_settings.filename = filename;
	task_main(data);

	data.command = DRAW;
	myPicture->picture->clean();
	myPicture->scene->addItem(myPicture->picture);
	data.command_settings.picture = myPicture->picture;
	task_main(data);
}

void MyMainWindow::slotTransfer()
{
	task_settings_t data;

	data.command = TRANSFORM;
	data.command_settings.transform_settings.x = myLocale->toDouble(ui->transfer_x->text());
	data.command_settings.transform_settings.y = myLocale->toDouble(ui->transfer_y->text());
	data.command_settings.transform_settings.z = myLocale->toDouble(ui->transfer_z->text());
	data.command_settings.transform_settings.command = TRANSFER;
	task_main(data);

	data.command = DRAW;
	myPicture->picture->clean();
	myPicture->scene->addItem(myPicture->picture);
	data.command_settings.picture = myPicture->picture;
	task_main(data);
}
void MyMainWindow::slotRotate()
{
	task_settings_t data;

	data.command = TRANSFORM;
	data.command_settings.transform_settings.x = myLocale->toDouble(ui->rotate_x->text());
	data.command_settings.transform_settings.y = myLocale->toDouble(ui->rotate_y->text());
	data.command_settings.transform_settings.z = myLocale->toDouble(ui->rotate_z->text());
	data.command_settings.transform_settings.command = ROTATE;
	task_main(data);

	data.command = DRAW;
	myPicture->picture->clean();
	myPicture->scene->addItem(myPicture->picture);
	data.command_settings.picture = myPicture->picture;
	task_main(data);
}
void MyMainWindow::slotScale()
{
	task_settings_t data;

	data.command = TRANSFORM;
	data.command_settings.transform_settings.x = myLocale->toDouble(ui->scale_x->text());
	data.command_settings.transform_settings.y = myLocale->toDouble(ui->scale_y->text());
	data.command_settings.transform_settings.z = myLocale->toDouble(ui->scale_z->text());
	data.command_settings.transform_settings.command = SCALE;
	task_main(data);

	data.command = DRAW;
	myPicture->picture->clean();
	myPicture->scene->addItem(myPicture->picture);
	data.command_settings.picture = myPicture->picture;
	task_main(data);
}

void MyMainWindow::exit()
{
	task_settings_t data;

	data.command = EXIT;
	task_main(data);

}