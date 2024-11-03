QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = setback
TEMPLATE = app

SOURCES += main.cpp \
           mainwindow.cpp \
           readmedialog.cpp

HEADERS  += mainwindow.h \
    readmedialog.h

FORMS    += mainwindow.ui \
    readmedialog.ui

RESOURCES += \
    setbackqt.qrc
