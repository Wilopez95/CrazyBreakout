#-------------------------------------------------
#
# Project created by QtCreator 2016-02-29T16:18:36
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = CrazyBreakout_Alpha
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    Ball.cpp \
    Block.cpp \
    Game.cpp \
    Paddle.cpp \
    players.cpp \
    blockdouble.cpp \
    server.cpp \
    blocktriple.cpp \
    blockinternal.cpp \
    blocksorpres.cpp \
    drawlimits.cpp

HEADERS  += mainwindow.h \
    Ball.h \
    Block.h \
    Game.h \
    Paddle.h \
    players.h \
    blockdouble.h \
    server.h \
    blocktriple.h \
    blockinternal.h \
    blocksorpres.h \
    drawlimits.h

FORMS    += mainwindow.ui \
    players.ui

RESOURCES += \
    Imagenes.qrc
