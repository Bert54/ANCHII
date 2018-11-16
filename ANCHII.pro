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

HEADERS  += \
    anchii.hpp \
    ecranmenupaquet.hpp \
    ecranmenuprincipal.hpp \
    event.hpp \
    observable.hpp \
    observateur.hpp \
    paquet.hpp

FORMS    += anchii.ui
