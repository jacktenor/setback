QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

RC_ICONS = appicon.ico

TARGET = SetBack
TEMPLATE = app

SOURCES += main.cpp \
           customfiledialog.cpp \
           imagefilterproxymodel.cpp \
           mainwindow.cpp \
           readmedialog.cpp

HEADERS  += mainwindow.h \
    customfiledialog.h \
    imagefilterproxymodel.h \
    readmedialog.h

FORMS    += mainwindow.ui \
    readmedialog.ui

RESOURCES += \
    setback.qrc
