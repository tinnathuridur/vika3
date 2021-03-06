#-------------------------------------------------
#
# Project created by QtCreator 2015-12-11T10:51:56
#
#-------------------------------------------------

QT       += core
QT       -= gui
QT       += sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = widgetVerkefniVika3

CONFIG -= app_bundle
CONFIG += C++11

TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    repositories/computerrepository.cpp \
    repositories/linkrepository.cpp \
    repositories/scientistrepository.cpp \
    models/computer.cpp \
    models/scientist.cpp \
    services/computerservice.cpp \
    services/linkservice.cpp \
    services/scientistservice.cpp \
    utilities/utils.cpp \
    addtodatabasedialog.cpp

HEADERS  += mainwindow.h \
    models/computer.h \
    models/scientist.h \
    repositories/computerrepository.h \
    repositories/linkrepository.h \
    repositories/scientistrepository.h \
    services/computerservice.h \
    services/linkservice.h \
    services/scientistservice.h \
    utilities/constants.h \
    utilities/utils.h \
    addtodatabasedialog.h

FORMS    += mainwindow.ui \
    addtodatabasedialog.ui

INCLUDEPATH += models \
    repositories \
    services \
    ui

RESOURCES += \
    recources.qrc
