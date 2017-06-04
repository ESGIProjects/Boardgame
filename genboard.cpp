#include "genboard.h"
#include <iostream>
#include <QDebug>
GenBoard::GenBoard(QWidget *parent, int rows, int cols, QString title) : QWidget(parent){
    //this->resize(1280,720);
    //grid = new QGridLayout();
    //QWidget *centralWidget = new QWidget;

    //Creation of the board
    qDebug() << "Creation of the board !";
    qDebug() << "Rows : " + QString::number(rows);
    qDebug() << "Cols : " + QString::number(cols);
    int count=1, i, j;
    QPushButton *button[rows][cols];
    QGridLayout *boardLayout = new QGridLayout;
    for(i=0;i< rows;i++){
        for(j=0;j<cols;j++){
            if(count<=rows*cols){
                button[i][j] = new QPushButton("");
                boardLayout->addWidget(button[i][j], i, j);
                count++;
            }
        }
    }
    boardLayout->setHorizontalSpacing(1);
    boardLayout->setVerticalSpacing(1);

    this->setWindowTitle(title);
    this->setLayout(boardLayout);

    //centralWidget->setLayout(controlsLayout);

    //setCentralWidget(centralWidget);
}

