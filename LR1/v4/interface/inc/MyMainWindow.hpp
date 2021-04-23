#ifndef MYMAINWINDOW_H
#define MYMAINWINDOW_H

#include <QMainWindow>
#include "ui_form.h"
#include "MyGraphicsView.hpp"
#include "MyLocale.hpp"
#include <QFileDialog>

class MyMainWindow : public QMainWindow
{
    Q_OBJECT
private:
    MyLocale *myLocale;
    MyGraphicsView *myPicture;
    Ui::MainWindow *ui;
public:
    explicit MyMainWindow(QMainWindow *parent = 0);
    ~MyMainWindow();
    void setValidator();
    void setConnection();
    void exit();
    void setSplitters();
    
public slots:
	void slotDownload();
    void slotTransfer();
    void slotRotate();
    void slotScale();
};

#endif