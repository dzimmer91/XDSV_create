#-------------------------------------------------
#
# Project created by QtCreator 2016-04-07T08:55:35
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = spsat_file
TEMPLATE = app

INCLUDEPATH += include
SOURCES += src/main.cpp\
    src/file_parse.cpp \
        src/mainwindow.cpp

HEADERS  += include/mainwindow.h \
    include/file_parse.h

FORMS    += mainwindow.ui
