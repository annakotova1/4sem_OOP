#ifndef MYMAINWINDOW_H
#define MYMAINWINDOW_H

#include <QMainWindow>
#include <QWidget>
#include <QDoubleValidator>
#include "MyGraphicsView.hpp"
#include "../../my_domens_interaction.hpp"

class MyMainWindow : public QMainWindow
{
public:
	MyMainWindow(QWidget *parent = 0);
	~MyMainWindow();
private:
	void configValidator();
	void setValidator();
	void setConnet();
	void setSplitter();
	MyGraphicsView *myPicture;
	Ui::MainWindow *ui;
	QDoubleValidator *myValidator;
	QLocale *myLocale;
public slots:
	void slotDownload();
	void slotTransfer();
	void slotRotate();
	void slotScale();
};

#endif