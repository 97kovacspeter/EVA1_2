#-------------------------------------------------
#
# Project created by QtCreator 2018-04-24T19:58:33
#
#-------------------------------------------------

QT       += testlib

QT       -= gui

TARGET = tst_mazetester
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app


SOURCES += tst_mazetester.cpp \
    gamemanager.cpp
DEFINES += SRCDIR=\\\"$$PWD/\\\"

HEADERS += \
    gamemanager.h
