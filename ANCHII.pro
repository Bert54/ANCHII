#-------------------------------------------------
#
# Project created by QtCreator 2018-11-13T08:14:15
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = ANCHII
TEMPLATE = app


SOURCES += main.cpp\
        anchii.cpp \
    ecranmenuprincipal.cpp \
    ecranmenupaquet.cpp \
    paquet.cpp \
    ecranajoutcarte.cpp

HEADERS  += anchii.h \
    ecranmenuprincipal.h \
    ecranmenupaquet.h \
    observateur.h \
    event.h \
    observable.h \
    paquet.h \
    ecranajoutcarte.h

FORMS    += anchii.ui
