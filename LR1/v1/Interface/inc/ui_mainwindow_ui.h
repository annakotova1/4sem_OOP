/********************************************************************************
** Form generated from reading UI file 'mainwindow_uijQzNDD.ui'
**
** Created by: Qt User Interface Compiler version 5.12.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef MAINWINDOW_UIJQZNDD_H
#define MAINWINDOW_UIJQZNDD_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *download;
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QSplitter *splitter;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QVBoxLayout *verticalLayout_4;
    QLabel *label;
    QHBoxLayout *horizontalLayout;
    QLabel *label_11;
    QLineEdit *transfer_x;
    QLabel *label_10;
    QLineEdit *transfer_y;
    QLabel *label_12;
    QLineEdit *transfer_z;
    QPushButton *transferButton;
    QVBoxLayout *verticalLayout_6;
    QLabel *label_2;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_9;
    QLineEdit *rotate_x;
    QLabel *label_8;
    QLineEdit *rotate_y;
    QLabel *label_7;
    QLineEdit *rotate_z;
    QPushButton *rotateButton;
    QVBoxLayout *verticalLayout_5;
    QLabel *label_3;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_6;
    QLineEdit *scale_x;
    QLabel *label_5;
    QLineEdit *scale_y;
    QLabel *label_4;
    QLineEdit *scale_z;
    QPushButton *scaleButton;
    QSpacerItem *verticalSpacer;
    QWidget *verticalLayoutWidget_2;
    QVBoxLayout *graphicsLayout;
    QMenuBar *menubar;
    QMenu *menu;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(800, 600);
        download = new QAction(MainWindow);
        download->setObjectName(QString::fromUtf8("download"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        splitter = new QSplitter(centralwidget);
        splitter->setObjectName(QString::fromUtf8("splitter"));
        splitter->setOrientation(Qt::Horizontal);
        verticalLayoutWidget = new QWidget(splitter);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        label = new QLabel(verticalLayoutWidget);
        label->setObjectName(QString::fromUtf8("label"));

        verticalLayout_4->addWidget(label);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label_11 = new QLabel(verticalLayoutWidget);
        label_11->setObjectName(QString::fromUtf8("label_11"));

        horizontalLayout->addWidget(label_11);

        transfer_x = new QLineEdit(verticalLayoutWidget);
        transfer_x->setObjectName(QString::fromUtf8("transfer_x"));

        horizontalLayout->addWidget(transfer_x);

        label_10 = new QLabel(verticalLayoutWidget);
        label_10->setObjectName(QString::fromUtf8("label_10"));

        horizontalLayout->addWidget(label_10);

        transfer_y = new QLineEdit(verticalLayoutWidget);
        transfer_y->setObjectName(QString::fromUtf8("transfer_y"));

        horizontalLayout->addWidget(transfer_y);

        label_12 = new QLabel(verticalLayoutWidget);
        label_12->setObjectName(QString::fromUtf8("label_12"));

        horizontalLayout->addWidget(label_12);

        transfer_z = new QLineEdit(verticalLayoutWidget);
        transfer_z->setObjectName(QString::fromUtf8("transfer_z"));

        horizontalLayout->addWidget(transfer_z);


        verticalLayout_4->addLayout(horizontalLayout);

        transferButton = new QPushButton(verticalLayoutWidget);
        transferButton->setObjectName(QString::fromUtf8("transferButton"));

        verticalLayout_4->addWidget(transferButton);


        verticalLayout->addLayout(verticalLayout_4);

        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        label_2 = new QLabel(verticalLayoutWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        verticalLayout_6->addWidget(label_2);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_9 = new QLabel(verticalLayoutWidget);
        label_9->setObjectName(QString::fromUtf8("label_9"));

        horizontalLayout_2->addWidget(label_9);

        rotate_x = new QLineEdit(verticalLayoutWidget);
        rotate_x->setObjectName(QString::fromUtf8("rotate_x"));

        horizontalLayout_2->addWidget(rotate_x);

        label_8 = new QLabel(verticalLayoutWidget);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        horizontalLayout_2->addWidget(label_8);

        rotate_y = new QLineEdit(verticalLayoutWidget);
        rotate_y->setObjectName(QString::fromUtf8("rotate_y"));

        horizontalLayout_2->addWidget(rotate_y);

        label_7 = new QLabel(verticalLayoutWidget);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        horizontalLayout_2->addWidget(label_7);

        rotate_z = new QLineEdit(verticalLayoutWidget);
        rotate_z->setObjectName(QString::fromUtf8("rotate_z"));

        horizontalLayout_2->addWidget(rotate_z);


        verticalLayout_6->addLayout(horizontalLayout_2);

        rotateButton = new QPushButton(verticalLayoutWidget);
        rotateButton->setObjectName(QString::fromUtf8("rotateButton"));

        verticalLayout_6->addWidget(rotateButton);


        verticalLayout->addLayout(verticalLayout_6);

        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        label_3 = new QLabel(verticalLayoutWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        verticalLayout_5->addWidget(label_3);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label_6 = new QLabel(verticalLayoutWidget);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        horizontalLayout_3->addWidget(label_6);

        scale_x = new QLineEdit(verticalLayoutWidget);
        scale_x->setObjectName(QString::fromUtf8("scale_x"));

        horizontalLayout_3->addWidget(scale_x);

        label_5 = new QLabel(verticalLayoutWidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        horizontalLayout_3->addWidget(label_5);

        scale_y = new QLineEdit(verticalLayoutWidget);
        scale_y->setObjectName(QString::fromUtf8("scale_y"));

        horizontalLayout_3->addWidget(scale_y);

        label_4 = new QLabel(verticalLayoutWidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        horizontalLayout_3->addWidget(label_4);

        scale_z = new QLineEdit(verticalLayoutWidget);
        scale_z->setObjectName(QString::fromUtf8("scale_z"));

        horizontalLayout_3->addWidget(scale_z);


        verticalLayout_5->addLayout(horizontalLayout_3);

        scaleButton = new QPushButton(verticalLayoutWidget);
        scaleButton->setObjectName(QString::fromUtf8("scaleButton"));

        verticalLayout_5->addWidget(scaleButton);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_5->addItem(verticalSpacer);


        verticalLayout->addLayout(verticalLayout_5);

        splitter->addWidget(verticalLayoutWidget);
        verticalLayoutWidget_2 = new QWidget(splitter);
        verticalLayoutWidget_2->setObjectName(QString::fromUtf8("verticalLayoutWidget_2"));
        graphicsLayout = new QVBoxLayout(verticalLayoutWidget_2);
        graphicsLayout->setObjectName(QString::fromUtf8("graphicsLayout"));
        graphicsLayout->setContentsMargins(0, 0, 0, 0);
        splitter->addWidget(verticalLayoutWidget_2);

        gridLayout->addWidget(splitter, 0, 0, 1, 1);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 28));
        menu = new QMenu(menubar);
        menu->setObjectName(QString::fromUtf8("menu"));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        menubar->addAction(menu->menuAction());
        menu->addAction(download);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        download->setText(QApplication::translate("MainWindow", "\320\227\320\260\320\263\321\200\321\203\320\267\320\270\321\202\321\214", nullptr));
        label->setText(QApplication::translate("MainWindow", "\320\237\320\265\321\200\320\265\320\275\320\276\321\201", nullptr));
        label_11->setText(QApplication::translate("MainWindow", "x:", nullptr));
        label_10->setText(QApplication::translate("MainWindow", "y:", nullptr));
        label_12->setText(QApplication::translate("MainWindow", "z:", nullptr));
        transferButton->setText(QApplication::translate("MainWindow", "\320\237\320\265\321\200\320\265\320\275\320\265\321\201\321\202\320\270", nullptr));
        label_2->setText(QApplication::translate("MainWindow", "\320\237\320\276\320\262\320\276\321\200\320\276\321\202", nullptr));
        label_9->setText(QApplication::translate("MainWindow", "x:", nullptr));
        label_8->setText(QApplication::translate("MainWindow", "y:", nullptr));
        label_7->setText(QApplication::translate("MainWindow", "z:", nullptr));
        rotateButton->setText(QApplication::translate("MainWindow", "\320\237\320\276\320\262\320\265\321\200\320\275\321\203\321\202\321\214", nullptr));
        label_3->setText(QApplication::translate("MainWindow", "\320\234\320\260\321\201\321\210\321\202\320\260\320\261\320\270\321\200\320\276\320\262\320\260\320\275\320\270\320\265", nullptr));
        label_6->setText(QApplication::translate("MainWindow", "x:", nullptr));
        label_5->setText(QApplication::translate("MainWindow", "y:", nullptr));
        label_4->setText(QApplication::translate("MainWindow", "z:", nullptr));
        scaleButton->setText(QApplication::translate("MainWindow", "\320\234\320\260\321\201\321\210\321\202\320\260\320\261\320\270\321\200\320\276\320\262\320\260\321\202\321\214", nullptr));
        menu->setTitle(QApplication::translate("MainWindow", "\320\244\320\260\320\271\320\273", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // MAINWINDOW_UIJQZNDD_H
