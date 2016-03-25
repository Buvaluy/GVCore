#-------------------------------------------------
#
# Project created by QtCreator 2016-01-08T18:28:13
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = GVModule
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    GVCore/gvexeption.cpp \
    GVCore/gvobject.cpp \
    GVCore/gvpolyline.cpp \
    GVCore/gvpoint.cpp \
    GVCore/gvgrid.cpp \
    GVCore/gvgistagram.cpp \
    GVCore/gvgistragramitem.cpp \
    GVCore/gvquarter.cpp

HEADERS  += mainwindow.h \
    GVCore/gvexeption.h \
    GVCore/gvobject.h \
    GVCore/gvpolyline.h \
    GVCore/gvpoint.h \
    GVCore/gvgrid.h \
    GVCore/gvgistagram.h \
    GVCore/gvgistragramitem.h \
    GVCore/gvquarter.h

FORMS    += mainwindow.ui

DISTFILES += \
    GraphicView.js
