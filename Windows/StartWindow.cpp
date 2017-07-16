#include <QApplication>
#include <QFont>
#include <QGroupBox>
#include <QComboBox>
#include <QDebug>
#include <QDir>

#include "StartWindow.h"
#include "ConnectFourWindow.h"
#include "OthelloWindow.h"
#include "TicTacToeWindow.h"
#include "ScoresWindow.h"
#include "../Boards/ConnectFourBoard.h"
#include "../Boards/OthelloBoard.h"
#include "../Boards/TicTacToeBoard.h"

StartWindow::StartWindow(QWidget *parent) : QWidget(parent){

    setWindowFlags(Qt::MSWindowsFixedSizeDialogHint);
    setWindowTitle("GenBoard");
    setWindowIcon(QIcon(":/resources/genboard.png"));

    QGridLayout *layout = new QGridLayout();

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
    fontTitle->setPixelSize(30);

    welcome = new QLabel("Welcome to GenBoard !", this);
    welcome->setFont(*fontTitle);

    start = new QPushButton("Start game !", this);
    score = new QPushButton("Score",this);

    layout->addWidget(welcome,0,1);
    layout->addWidget(group,1,1);
    layout->addWidget(score,2,0);
    layout->addWidget(start,2,2);

    this->setLayout(layout);

    connect(score, &QPushButton::clicked, this, &StartWindow::goScoreMenu);
    connect(start, &QPushButton::clicked, this, &StartWindow::onStartGame);

    // Fixing size issue when back from game
    this->setMaximumHeight(480);
    this->setMaximumWidth(640);
}

void StartWindow::onStartGame(){

    if(connectfour->isChecked()) {
        ConnectFourBoard *board = new ConnectFourBoard();
        ConnectFourWindow *widget = new ConnectFourWindow(*board);
        widget->show();

        this->close();
    }
    else if(othello->isChecked()) {
        OthelloBoard *board = new OthelloBoard();
        OthelloWindow *widget = new OthelloWindow(*board);
        widget->show();

        this->close();
    }
    else if(tictactoe->isChecked()){
        TicTacToeBoard *board = new TicTacToeBoard();
        TicTacToeWindow *widget = new TicTacToeWindow(*board);
        widget->show();

        this->close();
    }
}

void StartWindow::goScoreMenu(){
    scoreMenu = new ScoresWindow();
    scoreMenu->show();
    this->close();
}
