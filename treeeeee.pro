#-------------------------------------------------
#
# Project created by QtCreator 2017-10-03T18:32:46
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
INCLUDEPATH += "C:\pr\winpcap\WpdPack\include"
INCLUDEPATH +="C:\pr\winpcap\WpdPack\Lib"
LIBS +=-L"C:\pr\winpcap\WpdPack\Lib" -lwpcap -lws2_32


TARGET = treeeeee
TEMPLATE = app

DEFINES += QT_DEPRECATED_WARNINGS
SOURCES += \
        main.cpp \
        mainwindow.cpp \
    pop.cpp \
    pro.cpp

HEADERS += \
        mainwindow.h \
    pop.h \
    pro.h \
    pacet.h

FORMS += \
        mainwindow.ui \
    pop.ui \
    pro.ui

RESOURCES += \
    kek.qrc \
    pp.qrc
