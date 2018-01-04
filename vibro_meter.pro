#-------------------------------------------------
#
# Project created by QtCreator 2017-08-28T13:13:06
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = vibro_meter
TEMPLATE = app
INCLUDEPATH += C:/QWT/include
LIBS += -LC:/QWT/lib -lqwt

SOURCES += main.cpp\
        dialog.cpp \
    work.cpp \
    drawing.cpp

HEADERS  += dialog.h \
    work.h \
    drawing.h \
    node.h \
    headers.h

DISTFILES += \

