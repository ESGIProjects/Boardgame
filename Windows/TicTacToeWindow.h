#ifndef TICTACTOEWINDOW_H
#define TICTACTOEWINDOW_H

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
#include <QSqlQuery>
#include "../Boards/TicTacToeBoard.h"

class TicTacToeStrategy;

class TicTacToeWindow : public QWidget {
    Q_OBJECT

public:
    TicTacToeWindow(TicTacToeBoard&);
    QPushButton *backButton;
    QPushButton *restartButton;
    QWidget *menu;

    QMediaPlaylist *playList;
    QMediaPlayer *music;

    TicTacToeBoard *board;
    TicTacToeStrategy *strategy;
    QPushButton **buttons;

    QTextEdit *actionTextEdit;

    QSqlQuery query;

    int currentPlayer;

    void displayBoard();
    int convertPositionFromUIToBoard(int);
    void pass();

private:
    void insertAction(int, int);

public slots:
    void handleButton(int);

private slots:
    void restart();
    void goMenu();
};

#endif // TICTACTOEWINDOW_H
