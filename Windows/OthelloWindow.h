#ifndef OTHELLOWINDOW_H
#define OTHELLOWINDOW_H

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
#include "../Boards/OthelloBoard.h"

class OthelloStrategy;

class OthelloWindow : public QWidget {
    Q_OBJECT

public:
    OthelloWindow(OthelloBoard&);
    QPushButton *backButton;
    QPushButton *restartButton;
    QWidget *menu;

    QMediaPlaylist *playList;
    QMediaPlayer *music;

    OthelloBoard *board;
    OthelloStrategy *strategy;
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

#endif // OTHELLOWINDOW_H
