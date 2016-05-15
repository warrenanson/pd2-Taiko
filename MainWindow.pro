#-------------------------------------------------
#
# Project created by QtCreator 2016-05-02T19:36:05
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = MainWindow
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    form.cpp \
    dialog.cpp

HEADERS  += mainwindow.h \
    form.h \
    dialog.h

FORMS    += mainwindow.ui \
    form.ui \
    dialog.ui

RESOURCES += \
    pics.qrc
