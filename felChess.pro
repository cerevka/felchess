#-------------------------------------------------
#
# Project created by QtCreator 2010-11-17T10:33:46
#
#-------------------------------------------------

TARGET = felChess
CONFIG   += console
CONFIG   -= app_bundle

TRANSLATIONS = felchess_en.ts \
    felchess_cs.ts

TEMPLATE = app


SOURCES += main.cpp \
    model/chessboard.cpp \
    view/mainwindow.cpp \
    controller/game/game.cpp \
    controller/network/network.cpp

HEADERS += \
    model/chessboard.h \
    view/mainwindow.h \
    controller/game/game.h \
    controller/network/network.h

RESOURCES += \
    resource.qrc
