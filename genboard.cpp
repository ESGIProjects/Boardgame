#include "genboard.h"
#include <iostream>
#include <QDebug>
#include "startgame.h"

GenBoard::GenBoard(QWidget *parent, int rows, int cols, QString title) : QWidget(parent){

    setWindowFlags(Qt::MSWindowsFixedSizeDialogHint);
    setWindowIcon(QIcon("genboard.png"));

    //Creation of the board
    qDebug() << "Creation of the board !";
    qDebug() << "Rows : " + QString::number(rows);
    qDebug() << "Cols : " + QString::number(cols);
    int count = 1, i, j;

    QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
    sizePolicy.setHorizontalStretch(0);
    sizePolicy.setVerticalStretch(0);

    QPushButton *button[rows][cols];
    QGridLayout *boardLayout = new QGridLayout;
    for(i=0;i< rows;i++){
        for(j=0;j<cols;j++){
            if(count<=rows*cols){
                button[i][j] = new QPushButton("");
                button[i][j]->setSizePolicy(sizePolicy);
                boardLayout->addWidget(button[i][j], i, j); 
                count++;
            }
        }
    }

    boardLayout->setHorizontalSpacing(1);
    boardLayout->setVerticalSpacing(1);

    this->setWindowTitle(title);
    this->setLayout(boardLayout);
    this->resize(1280,720);

    backButton = new QPushButton("Menu",this);

    connect(backButton, &QPushButton::clicked, this, &GenBoard::goMenu);
    connect(restartButton, &QPushButton::clicked, this, &GenBoard::restart);
}

void GenBoard::goMenu(){
    menu = new StartGame(NULL);
    menu->show();
    this->close();
}

void GenBoard::restart(){
    // TODO
}
