#ifndef BOARDWINDOW_H
#define BOARDWINDOW_H

#include <QWidget>
#include <QApplication>
#include <QPushButton>
#include <QLabel>
#include <QGridLayout>
#include <QMediaPlayer>
#include <QMediaPlaylist>
#include <QUrl>
#include <QTextEdit>
#include <string.h>

#include "../Boards/OthelloBoard.h"

class Strategy;

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
    Strategy *strategy;
    QPushButton **buttons;

    QTextEdit *actionTextEdit;

    int currentPlayer;

    void displayBoard();
    int convertPositionFromUIToBoard(int);

private:
    void insertAction(int, int);

public slots:
    virtual void handleButton(int);

private slots:
    void restart();
    void goMenu();
};

#endif // BOARDWINDOW_H
