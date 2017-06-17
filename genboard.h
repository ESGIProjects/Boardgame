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

class GenBoard : public QWidget {
    Q_OBJECT

public:
    GenBoard(QWidget *parent = 0, int rows = 0, int cols = 0, QString title = "");
    QPushButton *backButton;
    QPushButton *restartButton;
    QWidget *menu;

    QMediaPlaylist *playList;
    QMediaPlayer *music;

public slots:
    virtual void handleButton(int);


private slots:
    void restart();
    void goMenu();
};
