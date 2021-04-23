/********************************************************************************
** Form generated from reading UI file 'formFcPxiI.ui'
**
** Created by: Qt User Interface Compiler version 5.12.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef FORMFCPXII_H
#define FORMFCPXII_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *download_action;
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QSplitter *splitter;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QFrame *frame;
    QVBoxLayout *verticalLayout_2;
    QLabel *label;
    QHBoxLayout *horizontalLayout;
    QLabel *label_5;
    QLabel *label_4;
    QLabel *label_6;
    QHBoxLayout *horizontalLayout_2;
    QLineEdit *transfer_x;
    QLineEdit *transfer_y;
    QLineEdit *transfer_z;
    QPushButton *transfer_button;
    QFrame *frame_2;
    QVBoxLayout *verticalLayout_4;
    QLabel *label_2;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_12;
    QLabel *label_11;
    QLabel *label_10;
    QHBoxLayout *horizontalLayout_4;
    QLineEdit *rotate_x;
    QLineEdit *rotate_y;
    QLineEdit *rotate_z;
    QPushButton *rotate_button;
    QFrame *frame_3;
    QVBoxLayout *verticalLayout_3;
    QLabel *label_3;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_9;
    QLabel *label_8;
    QLabel *label_7;
    QHBoxLayout *horizontalLayout_6;
    QLineEdit *scale_x;
    QLineEdit *scale_y;
    QLineEdit *scale_z;
    QPushButton *scale_button;
    QWidget *verticalLayoutWidget_2;
    QVBoxLayout *graphics_layout;
    QMenuBar *menubar;
    QMenu *menu;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(800, 600);
        download_action = new QAction(MainWindow);
        download_action->setObjectName(QString::fromUtf8("download_action"));
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
        frame = new QFrame(verticalLayoutWidget);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        verticalLayout_2 = new QVBoxLayout(frame);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        label = new QLabel(frame);
        label->setObjectName(QString::fromUtf8("label"));

        verticalLayout_2->addWidget(label);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label_5 = new QLabel(frame);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        horizontalLayout->addWidget(label_5);

        label_4 = new QLabel(frame);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        horizontalLayout->addWidget(label_4);

        label_6 = new QLabel(frame);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        horizontalLayout->addWidget(label_6);


        verticalLayout_2->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        transfer_x = new QLineEdit(frame);
        transfer_x->setObjectName(QString::fromUtf8("transfer_x"));

        horizontalLayout_2->addWidget(transfer_x);

        transfer_y = new QLineEdit(frame);
        transfer_y->setObjectName(QString::fromUtf8("transfer_y"));

        horizontalLayout_2->addWidget(transfer_y);

        transfer_z = new QLineEdit(frame);
        transfer_z->setObjectName(QString::fromUtf8("transfer_z"));

        horizontalLayout_2->addWidget(transfer_z);


        verticalLayout_2->addLayout(horizontalLayout_2);

        transfer_button = new QPushButton(frame);
        transfer_button->setObjectName(QString::fromUtf8("transfer_button"));

        verticalLayout_2->addWidget(transfer_button);


        verticalLayout->addWidget(frame);

        frame_2 = new QFrame(verticalLayoutWidget);
        frame_2->setObjectName(QString::fromUtf8("frame_2"));
        frame_2->setFrameShape(QFrame::StyledPanel);
        frame_2->setFrameShadow(QFrame::Raised);
        verticalLayout_4 = new QVBoxLayout(frame_2);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        label_2 = new QLabel(frame_2);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        verticalLayout_4->addWidget(label_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label_12 = new QLabel(frame_2);
        label_12->setObjectName(QString::fromUtf8("label_12"));

        horizontalLayout_3->addWidget(label_12);

        label_11 = new QLabel(frame_2);
        label_11->setObjectName(QString::fromUtf8("label_11"));

        horizontalLayout_3->addWidget(label_11);

        label_10 = new QLabel(frame_2);
        label_10->setObjectName(QString::fromUtf8("label_10"));

        horizontalLayout_3->addWidget(label_10);


        verticalLayout_4->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        rotate_x = new QLineEdit(frame_2);
        rotate_x->setObjectName(QString::fromUtf8("rotate_x"));

        horizontalLayout_4->addWidget(rotate_x);

        rotate_y = new QLineEdit(frame_2);
        rotate_y->setObjectName(QString::fromUtf8("rotate_y"));

        horizontalLayout_4->addWidget(rotate_y);

        rotate_z = new QLineEdit(frame_2);
        rotate_z->setObjectName(QString::fromUtf8("rotate_z"));

        horizontalLayout_4->addWidget(rotate_z);


        verticalLayout_4->addLayout(horizontalLayout_4);

        rotate_button = new QPushButton(frame_2);
        rotate_button->setObjectName(QString::fromUtf8("rotate_button"));

        verticalLayout_4->addWidget(rotate_button);


        verticalLayout->addWidget(frame_2);

        frame_3 = new QFrame(verticalLayoutWidget);
        frame_3->setObjectName(QString::fromUtf8("frame_3"));
        frame_3->setFrameShape(QFrame::StyledPanel);
        frame_3->setFrameShadow(QFrame::Raised);
        verticalLayout_3 = new QVBoxLayout(frame_3);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        label_3 = new QLabel(frame_3);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        verticalLayout_3->addWidget(label_3);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        label_9 = new QLabel(frame_3);
        label_9->setObjectName(QString::fromUtf8("label_9"));

        horizontalLayout_5->addWidget(label_9);

        label_8 = new QLabel(frame_3);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        horizontalLayout_5->addWidget(label_8);

        label_7 = new QLabel(frame_3);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        horizontalLayout_5->addWidget(label_7);


        verticalLayout_3->addLayout(horizontalLayout_5);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        scale_x = new QLineEdit(frame_3);
        scale_x->setObjectName(QString::fromUtf8("scale_x"));

        horizontalLayout_6->addWidget(scale_x);

        scale_y = new QLineEdit(frame_3);
        scale_y->setObjectName(QString::fromUtf8("scale_y"));

        horizontalLayout_6->addWidget(scale_y);

        scale_z = new QLineEdit(frame_3);
        scale_z->setObjectName(QString::fromUtf8("scale_z"));

        horizontalLayout_6->addWidget(scale_z);


        verticalLayout_3->addLayout(horizontalLayout_6);

        scale_button = new QPushButton(frame_3);
        scale_button->setObjectName(QString::fromUtf8("scale_button"));

        verticalLayout_3->addWidget(scale_button);


        verticalLayout->addWidget(frame_3);

        splitter->addWidget(verticalLayoutWidget);
        verticalLayoutWidget_2 = new QWidget(splitter);
        verticalLayoutWidget_2->setObjectName(QString::fromUtf8("verticalLayoutWidget_2"));
        graphics_layout = new QVBoxLayout(verticalLayoutWidget_2);
        graphics_layout->setObjectName(QString::fromUtf8("graphics_layout"));
        graphics_layout->setContentsMargins(0, 0, 0, 0);
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
        menu->addAction(download_action);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        download_action->setText(QApplication::translate("MainWindow", " \320\227\320\260\320\263\321\200\321\203\320\267\320\270\321\202\321\214", nullptr));
        label->setText(QApplication::translate("MainWindow", "\320\237\320\265\321\200\320\265\320\274\320\265\321\211\320\265\320\275\320\270\320\265", nullptr));
        label_5->setText(QApplication::translate("MainWindow", "\321\205:", nullptr));
        label_4->setText(QApplication::translate("MainWindow", "\321\203:", nullptr));
        label_6->setText(QApplication::translate("MainWindow", "z:", nullptr));
        transfer_button->setText(QApplication::translate("MainWindow", "\320\237\320\265\321\200\320\265\320\274\320\265\321\201\321\202\320\270\321\202\321\214", nullptr));
        label_2->setText(QApplication::translate("MainWindow", "\320\237\320\276\320\262\320\276\321\200\320\276\321\202", nullptr));
        label_12->setText(QApplication::translate("MainWindow", "x:", nullptr));
        label_11->setText(QApplication::translate("MainWindow", "y:", nullptr));
        label_10->setText(QApplication::translate("MainWindow", "z:", nullptr));
        rotate_button->setText(QApplication::translate("MainWindow", "\320\237\320\276\320\262\320\265\321\200\320\275\321\203\321\202\321\214", nullptr));
        label_3->setText(QApplication::translate("MainWindow", "\320\234\320\260\321\201\321\210\321\202\320\260\320\261\320\270\321\200\320\276\320\262\320\260\320\275\320\270\320\265", nullptr));
        label_9->setText(QApplication::translate("MainWindow", "x:", nullptr));
        label_8->setText(QApplication::translate("MainWindow", "y:", nullptr));
        label_7->setText(QApplication::translate("MainWindow", "z:", nullptr));
        scale_button->setText(QApplication::translate("MainWindow", "\320\234\320\260\321\201\321\210\321\202\320\260\320\261\320\270\321\200\320\276\320\262\320\260\321\202\321\214", nullptr));
        menu->setTitle(QApplication::translate("MainWindow", "\320\244\320\260\320\271\320\273", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // FORMFCPXII_H
