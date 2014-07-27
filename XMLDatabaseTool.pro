#-------------------------------------------------
#
# Project created by QtCreator 2014-03-31T19:08:24
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = XMLDatabaseTool
TEMPLATE = app


SOURCES += main.cpp \
    mainwindow.cpp \
    xmlio.cpp \
    newtabledialog.cpp \
    dbtablemodel.cpp \
    xmltable.cpp \
    tabwidget.cpp

HEADERS  += mainwindow.h \
    xmlio.h \
    newtabledialog.h \
    dbtablemodel.h \
    xmltable.h \
    ../buttondelegate.h \
    tabwidget.h

FORMS    += mainwindow.ui \
    newtabledialog.ui \
    tabwidget.ui

QMAKE_CXXFLAGS += -std=c++11
