#-------------------------------------------------
#
# Project created by QtCreator 2017-04-30T23:43:53
#
#-------------------------------------------------

QT       += core gui
QT       += sql
QT       += core gui sql
QT       += multimedia
QT       += core

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = GenBoard
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += main.cpp\
    Coordinates.cpp \
    Boards/OthelloBoard.cpp \
    Boards/Board.cpp \
    Windows/StartWindow.cpp \
    Windows/ScoresWindow.cpp \
    Boards/TicTacToeBoard.cpp \
    Boards/ConnectFourBoard.cpp \
    Windows/ConnectFourWindow.cpp \
    Windows/OthelloWindow.cpp \
    Windows/TicTacToeWindow.cpp \
    Strategies/OthelloStrategy.cpp \
    Strategies/TicTacToeStrategy.cpp \
    Strategies/ConnectFourStrategy.cpp

HEADERS  += \
    Coordinates.h \
    constants.h \
    Boards/OthelloBoard.h \
    Boards/Board.h \
    Windows/StartWindow.h \
    Windows/ScoresWindow.h \
    Boards/TicTacToeBoard.h \
    Boards/ConnectFourBoard.h \
    Windows/OthelloWindow.h \
    Windows/ConnectFourWindow.h \
    Windows/TicTacToeWindow.h \
    Strategies/OthelloStrategy.h \
    Strategies/TicTacToeStrategy.h \
    Strategies/ConnectFourStrategy.h
