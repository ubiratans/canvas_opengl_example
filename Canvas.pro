#-------------------------------------------------
#
# Project created by QtCreator 2015-03-04T09:31:55
#
#-------------------------------------------------

QT       += core gui opengl

CONFIG += c++11

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Canvas
TEMPLATE = app


SOURCES += main.cpp\
        main_window.cpp \
    canvas_widget.cpp \
    graphic_element.cpp \
    painter.cpp \
    triangle.cpp \
    element_manager.cpp

HEADERS  += main_window.h \
    canvas_widget.h \
    graphic_element.h \
    painter.h \
    triangle.h \
    element_manager.h
