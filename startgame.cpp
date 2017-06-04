#include "startgame.h"
#include "connectfourboard.h"
#include "othelloboard.h"
#include "tictactoeboard.h"
#include <QApplication>
#include <QFont>
#include <QVBoxLayout>
#include <QGroupBox>
#include <QComboBox>

StartGame::StartGame(QWidget *parent) : QWidget(parent){

    setWindowFlags(Qt::MSWindowsFixedSizeDialogHint);

    QGroupBox *group = new QGroupBox("Select a game ", this);
    connectfour = new QRadioButton("Connect Four");
    othello = new QRadioButton("Othello");
    tictactoe = new QRadioButton("Tic Tac Toe");

    connectfour-> setChecked(true);
    QVBoxLayout *list = new QVBoxLayout;
    list->addWidget(connectfour);
    list->addWidget(othello);
    list->addWidget(tictactoe);
    group->setLayout(list);

    QFont *fontTitle = new QFont("Courier New");
    fontTitle->setBold(true);
    fontTitle->setPixelSize(20);

    welcome = new QLabel("Welcome to GenBoard !", this);
    welcome->setFont(*fontTitle);

    start = new QPushButton("Start game !", this);
    exit = new QPushButton("Exit",this);

    welcome->setGeometry(200,20,250,25);
    group->setGeometry(230,100,200,200);
    exit->setGeometry(20,300,100,30);
    start->setGeometry(520,300,100,30);

    connect(exit, &QPushButton::clicked, this, &QApplication::quit);
    connect(start, &QPushButton::clicked, this, &StartGame::onStartGame);
}

void StartGame::onStartGame(){
    if(connectfour->isChecked()){
        connectfourWidget = new ConnectfourBoard();
        connectfourWidget->show();
        this->close();
    }
    else if(othello->isChecked()){
        othelloWidget = new OthelloBoard();
        othelloWidget->show();
        this->close();
    }
    else if(tictactoe->isChecked()){
        tictactoeWidget = new TictactoeBoard();
        tictactoeWidget->show();
        this->close();
    }
}
