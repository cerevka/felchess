#-------------------------------------------------
#
# Project created by QtCreator 2010-11-17T10:33:46
#
#-------------------------------------------------

QT += opengl

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
    controller/network/network.cpp \
    view/widgets/boardwidget.cpp \
    view/widgets/infowidget.cpp \
    view/widgets/chatwidget.cpp \
    view/widgets/centerwidget.cpp \
    view/painters/painter.cpp \
    view/painters/painter2d.cpp \
    view/painters/painter3d.cpp

HEADERS += \
    model/chessboard.h \
    view/mainwindow.h \
    controller/game/game.h \
    controller/network/network.h \
    globals.h \
    view/widgets/boardwidget.h \
    view/widgets/infowidget.h \
    view/widgets/chatwidget.h \
    view/widgets/centerwidget.h \
    view/painters/painter.h \
    view/painters/apainter.h \
    view/painters/painter2d.h \
    view/painters/painter3d.h

RESOURCES += \
    resource.qrc
