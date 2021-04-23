######################################################################
# Automatically generated by qmake (3.1) Wed Mar 24 17:07:05 2021
######################################################################

TEMPLATE = app
TARGET = app.exe
INCLUDEPATH += .

# The following define makes your compiler warn you if you use any
# feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

# Input
HEADERS += Interface/inc/MyGraphicsView.hpp \
           Interface/inc/MyMainWindow.hpp \
           Interface/inc/ui_mainwindow_ui.h \
           Mission/inc/download_points.hpp \
           Mission/inc/draw_picture.hpp \
           Mission/inc/errors.hpp \
           Mission/inc/my_domens_interaction.hpp \
           Mission/inc/my_matrix.hpp \
           Mission/inc/my_points_list.hpp \
           Mission/inc/my_shape_point.hpp \
           Mission/inc/transform_shape.hpp
SOURCES += Interface/src/main.cpp \
           Interface/src/MyGraphicsView.cpp \
           Interface/src/MyMainWindow.cpp \
           Mission/src/download_points.cpp \
           Mission/src/draw_picture.cpp \
           Mission/src/mission_main.cpp \
           Mission/src/my_matrix.cpp \
           Mission/src/my_points_list.cpp \
           Mission/src/my_shape_point.cpp \
           Mission/src/transform_shape.cpp
           
QT += core gui
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

