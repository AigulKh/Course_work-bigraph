#-------------------------------------------------
#
# Project created by QtCreator 2019-06-03T10:18:30
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = taxi_bigraph
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++17
CONFIG += debug

SOURCES += \
        container/Vertex.cpp \
        container/stdafx.cpp \
        edge.cpp \
        graphwidget.cpp \
        main.cpp \
        node.cpp \
        taxi.cpp

HEADERS += \
        container/AllocatorContainer.h \
        container/Bigraph.h \
        container/Edge.h \
        container/Exceptions.h \
        container/Iterator.h \
        container/Vertex.h \
        container/json.hpp \
        container/stdafx.h \
        container/targetver.h \
        edge.h \
        graphwidget.h \
        node.h \
        taxi.h \
        ui_taxi.h

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

FORMS += \
    taxi.ui
