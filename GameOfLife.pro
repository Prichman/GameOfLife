#-------------------------------------------------
#
# Project created by QtCreator 2015-06-11T18:27:33
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

QMAKE_CXXFLAGS += -std=c++11

TARGET = GameOfLife
TEMPLATE = app


SOURCES += main.cpp\
        MainWindow.cpp \
    LifeScene.cpp

HEADERS  += MainWindow.h \
    LifeScene.h
