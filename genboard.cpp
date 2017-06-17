#include "genboard.h"
#include <iostream>
#include <QDebug>
#include <QList>
#include <QDir>
#include <QString>
#include <QSignalMapper>

#include "startgame.h"

GenBoard::GenBoard(QWidget *parent, int rows, int cols, QString title) : QWidget(parent){

    playList = new QMediaPlaylist();
    playList->addMedia(QUrl::fromLocalFile("Ressources" + QString(QDir::separator()) + "music.mp3"));
    playList->addMedia(QUrl::fromLocalFile("Ressources" + QString(QDir::separator()) + "music2.mp3"));
    playList->addMedia(QUrl::fromLocalFile("Ressources" + QString(QDir::separator()) + "music3.mp3"));
    playList->setPlaybackMode(QMediaPlaylist::PlaybackMode::Random);

    music = new QMediaPlayer;
    music->setPlaylist(playList);
    music->setVolume(100);
    music->play();

    setWindowFlags(Qt::MSWindowsFixedSizeDialogHint);
    setWindowFlags(Qt::MacWindowToolBarButtonHint);
    setWindowIcon(QIcon("Ressources" + QString(QDir::separator()) + "genboard.png"));

    //Creation of the board
    qDebug() << "Creation of the board !";
    qDebug() << "Rows : " + QString::number(rows);
    qDebug() << "Cols : " + QString::number(cols);
    int count = 0, i, j;

    restartButton = new QPushButton("Restart", this);
    backButton = new QPushButton("Menu",this);

    QGridLayout *layout = new QGridLayout();

    QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
    sizePolicy.setHorizontalStretch(0);
    sizePolicy.setVerticalStretch(0);

    QPushButton *buttons[rows][cols];
    QGridLayout *boardLayout = new QGridLayout;
    QSignalMapper *signalMapper = new QSignalMapper(this);

    for(i=0;i<rows;i++){
        for(j=0;j<cols;j++){
            if(count<rows*cols){
                buttons[i][j] = new QPushButton("", this);
                buttons[i][j]->setSizePolicy(sizePolicy);
                signalMapper->setMapping(buttons[i][j], i*cols+j);
                connect(buttons[i][j], SIGNAL(clicked(bool)), signalMapper, SLOT(map()));
                boardLayout->addWidget(buttons[i][j], i, j);
                count++;
            }
        }
    }

    connect(signalMapper, SIGNAL(mapped(int)), this, SLOT(handleButton(int)));

    boardLayout->setHorizontalSpacing(1);
    boardLayout->setVerticalSpacing(1);

    layout->addLayout(boardLayout,0,0,1,1);
    layout->addWidget(backButton,1,0);
    layout->addWidget(restartButton,1,1);

    this->setWindowTitle(title);
    this->setLayout(layout);
    this->resize(1280,720);

    connect(backButton, &QPushButton::clicked, this, &GenBoard::goMenu);
    connect(restartButton, &QPushButton::clicked, this, &GenBoard::restart);
}

void GenBoard::goMenu(){
    menu = new StartGame();
    menu->show();
    this->close();
    music->stop();
}

void GenBoard::restart(){
    // TODO
}

void GenBoard::handleButton(int position) {
    qDebug() << "Handle Button : " + QString::number(position);
}
