#-------------------------------------------------
#
# Project created by QtCreator 2010-11-17T10:33:46
#
#-------------------------------------------------

QT += svg network

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
    model/king.cpp \
    model/apiece.cpp \
    view/painter.cpp \
    model/queen.cpp \
    model/bishop.cpp \
    model/knight.cpp \
    model/rook.cpp \
    model/pawn.cpp \
    view/dialogs/newgamedialog.cpp \
    controller/network/networkinterface.cpp \
    controller/network/server.cpp \
    controller/network/client.cpp

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
    view/painters/painter3d.h \
    model/apiece.h \
    model/king.h \
    view/painter.h \
    model/queen.h \
    model/bishop.h \
    model/knight.h \
    model/rook.h \
    model/pawn.h \
    view/dialogs/newgamedialog.h \
    controller/network/networkinterface.h \
    controller/network/server.h \
    controller/network/client.h

RESOURCES += \
    resource.qrc
