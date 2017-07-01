#pragma once

#include <QWidget>
#include <QApplication>
#include <QPushButton>
#include <QLabel>
#include <QGridLayout>
#include <QMediaPlayer>
#include <QMediaPlaylist>
#include <QUrl>
#include <string.h>

#include "../Boards/OthelloBoard.h"

class BoardWindow : public QWidget {
    Q_OBJECT

public:
    BoardWindow(Board&);
    QPushButton *backButton;
    QPushButton *restartButton;
    QWidget *menu;

    QMediaPlaylist *playList;
    QMediaPlayer *music;

    Board *board;
    QPushButton **buttons;

    int currentPlayer;

    void displayBoard();
    int convertPositionFromUIToBoard(int);

public slots:
    virtual void handleButton(int);

private slots:
    void restart();
    void goMenu();
};
