#-------------------------------------------------
#
# Project created by QtCreator 2016-04-07T08:55:35
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = spsat_file
TEMPLATE = app


SOURCES += main.cpp\
    file_parse.cpp \
        mainwindow.cpp

HEADERS  += mainwindow.h \
    file_parse.h

FORMS    += mainwindow.ui
