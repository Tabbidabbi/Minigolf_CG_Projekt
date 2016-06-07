#-------------------------------------------------
#
# Project created by QtCreator 2016-03-04T23:07:51
#
#-------------------------------------------------

QT       += core gui opengl

LIBS    += -lOpengl32

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = opengl1
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    oglwidget.cpp \
    kugel.cpp \
    viereck.cpp \
    dreieck.cpp \
    zylinder.cpp \
    kreis.cpp \
    minigolftrack.cpp

HEADERS  += mainwindow.h \
    oglwidget.h \
    kugel.h \
    viereck.h \
    dreieck.h \
    zylinder.h \
    kreis.h \
    minigolftrack.h

FORMS    += mainwindow.ui
