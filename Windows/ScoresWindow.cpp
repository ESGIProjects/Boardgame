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
    this->setWindowIcon(QIcon(":/resources/genboard.png"));

    QGridLayout *layout = new QGridLayout();

    this->setLayout(layout);

    QString queryConnectFour = "";
    QString queryOthello = "";
    QString queryTictactoe = "";


    connectFour = new QLabel("Number of Connect Four game / wins: ",this);
    othello = new QLabel("Number of Othello game / wins :",this);
    tictactoe = new QLabel("Number of Tictactoe game / wins: ",this);

    //we get the number of games won for each game

    query.exec("SELECT numberPlay FROM games where name = 'Connect Four'");
    if(query.next()){
        queryConnectFour = queryConnectFour + query.value(0).toString() + "/";
    }
    else{
        queryConnectFour = queryConnectFour + "ERROR" + "/";
    }

    query.exec("SELECT numberPlay FROM games where name = 'Othello'");
    if(query.next()){
        queryOthello = queryOthello + query.value(0).toString() + "/";
    }
    else{
        queryOthello = queryOthello + "ERROR" + "/";
    }

    query.exec("SELECT numberPlay FROM games where name = 'Tic Tac Toe'");
    if(query.next()){
        queryTictactoe = queryTictactoe + query.value(0).toString() + "/";
    }
    else{
        queryTictactoe = queryTictactoe + "ERROR" + "/";
    }

    //we get the number of games played for each game

    query.exec("SELECT numberWins FROM games where name = 'Connect Four'");
    if(query.next()){
        queryConnectFour = queryConnectFour + query.value(0).toString();
    }
    else{
        queryConnectFour = queryConnectFour + "ERROR";
    }

    query.exec("SELECT numberWins FROM games where name = 'Othello'");
    if(query.next()){
        queryOthello = queryOthello + query.value(0).toString();
    }
    else{
        queryOthello = queryOthello + "ERROR";
    }

    query.exec("SELECT numberWins FROM games where name = 'Tic Tac Toe'");
    if(query.next()){
        queryTictactoe = queryTictactoe + query.value(0).toString();
    }
    else{
        queryTictactoe = queryTictactoe + "ERROR";
    }

    scoreConnect = new QLabel(queryConnectFour,this);
    scoreOthello = new QLabel(queryOthello,this);
    scoreTictactoe = new QLabel(queryTictactoe,this);

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
