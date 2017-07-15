#ifndef CONNECTFOURWINDOW_H
#define CONNECTFOURWINDOW_H

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

#include "../Boards/ConnectFourBoard.h"

class ConnectFourStrategy;

class ConnectFourWindow : public QWidget {
    Q_OBJECT

public:
    ConnectFourWindow(ConnectFourBoard&);
    QPushButton *backButton;
    QPushButton *restartButton;
    QWidget *menu;

    QMediaPlaylist *playList;
    QMediaPlayer *music;

    ConnectFourBoard *board;
    ConnectFourStrategy *strategy;
    QPushButton **buttons;

    QTextEdit *actionTextEdit;

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

#endif // CONNECTFOURWINDOW_H
