#include <QGridLayout>
#include <QSqlDatabase>
#include <QSqlDriver>
#include <QSqlError>
#include <QDebug>
#include <QPushButton>
#include <QDir>

#include "StartWindow.h"
#include "ScoresWindow.h"

ScoresWindow::ScoresWindow(QWidget *parent) : QWidget(parent)
{
    this->setWindowTitle("Scores");
    this->setWindowIcon(QIcon("Ressources" + QString(QDir::separator()) + "genboard.png"));

    QGridLayout *layout = new QGridLayout();

    this->setLayout(layout);

    connectFour = new QLabel("Number of Connect Four game / wins: ",this);
    othello = new QLabel("Number of Othello game / wins :",this);
    tictactoe = new QLabel("Number of Tictactoe game / wins: ",this);

    query.exec("SELECT numberPlay FROM games where name = 'Connect Four'");
    if(query.next()){
        scoreConnect = new QLabel(query.value(0).toString(),this);
    }
    else{
        scoreConnect = new QLabel("Error",this);
    }

    query.exec("SELECT numberPlay FROM games where name = 'Othello'");
    if(query.next()){
        scoreOthello = new QLabel(query.value(0).toString(),this);
    }
    else{
        scoreOthello = new QLabel("Error",this);
    }

    query.exec("SELECT numberPlay FROM games where name = 'Tic Tac Toe'");
    if(query.next()){
        scoreTictactoe = new QLabel(query.value(0).toString(),this);
    }
    else{
        scoreTictactoe = new QLabel("Error",this);
    }

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

    connect(toMenu, &QPushButton::clicked, this, &ScoresWindow::goMenu);
}

void ScoresWindow::goMenu(){
    mainMenu = new StartWindow();
    mainMenu->show();
    this->close();
}
