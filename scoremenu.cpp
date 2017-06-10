#include <QGridLayout>
#include <QLabel>
#include <QSqlDatabase>
#include <QSqlDriver>
#include <QSqlError>
#include <QSqlQuery>
#include <QDebug>
#include <QPushButton>

#include "startgame.h"
#include "scoremenu.h"

ScoreMenu::ScoreMenu(QWidget *parent) : QWidget(parent)
{
    this->setWindowTitle("Scores");
    this->setWindowIcon(QIcon("genboard.png"));

    QGridLayout *layout = new QGridLayout();

    this->setLayout(layout);

    connectFour = new QLabel("Number of Connect Four game : ",this);
    othello = new QLabel("Number of Othello game : ",this);
    tictactoe = new QLabel("Number of Tictactoe game : ",this);

    scoreConnect = new QLabel("0",this);
    scoreOthello = new QLabel("0",this);
    scoreTictactoe = new QLabel("0",this);

    toMenu = new QPushButton("Main menu", this);

    layout->addWidget(connectFour,0,0);
    layout ->addWidget(othello,1,0);
    layout->addWidget(tictactoe,2,0);
    layout->addWidget(scoreConnect,0,2);
    layout ->addWidget(scoreOthello,1,2);
    layout->addWidget(scoreTictactoe,2,2);
    layout->addWidget(toMenu,3,0,1,3);
    layout->setHorizontalSpacing(200);
    layout->setVerticalSpacing(50);

    connect(toMenu, &QPushButton::clicked, this, &ScoreMenu::goMenu);
}

void ScoreMenu::goMenu(){
    mainMenu = new StartGame();
    mainMenu->show();
    this->close();
}
