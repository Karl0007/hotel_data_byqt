#-------------------------------------------------
#
# Project created by QtCreator 2019-01-23T17:50:51
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = untitled
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

CONFIG += c++11

SOURCES += \
        main.cpp \
        widget.cpp \
    logwindow.cpp \
    Hotel.cpp \
    Room.cpp \
    BookInfo.cpp \
    Data.cpp \
    Admin.cpp \
    table_hotel.cpp \
    table_room.cpp \
    table_book.cpp \
    table_select.cpp

HEADERS += \
        widget.h \
    Hotel.h \
    BookInfo.h \
    Room.h \
    Data.h \
    HEAD.h \
    Admin.h \
    table_hotel.h \
    logwindow.h \
    table_room.h \
    table_book.h \
    table_select.h

FORMS += \
        widget.ui \
    logwindow.ui \
    table_hotel.ui \
    table_room.ui \
    table_book.ui \
    table_select.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

#CONFIG +=console
