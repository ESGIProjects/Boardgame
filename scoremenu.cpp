#include "scoremenu.h"
#include <QGridLayout>
#include <QLabel>

ScoreMenu::ScoreMenu(QWidget *parent) : QWidget(parent)
{
    this->setWindowTitle("Scores");

    QGridLayout *layout = new QGridLayout();

    this->setLayout(layout);

    connect = new QLabel("Number of Connect Four game : ",this);
    othello = new QLabel("Number of Othello game : ",this);
    tictactoe = new QLabel("Number of Tictactoe game : ",this);

    layout->addWidget(connect,0,0);
    layout ->addWidget(othello,1,0);
    layout->addWidget(tictactoe,2,0);
}
