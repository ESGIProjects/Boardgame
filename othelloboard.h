#pragma once

#include <QWidget>
#include <QApplication>
#include <QPushButton>
#include <QLabel>
#include "genboard.h"

class OthelloBoard : virtual public GenBoard
{

public:
    OthelloBoard();
    int heuristiques[100] = {
            0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
            0, 500, -150, 30, 20, 20, 30, -150, 500, 0,
            0, -150, -250, 0, 0, 0, 0, -250, -150, 0,
            0, 30, 0, 1, 2, 2, 1, 0, 30, 0,
            0, 10, 0, 2, 16, 16, 2, 0, 10, 0,
            0, 10, 0, 2, 16, 16, 2, 0, 10, 0,
            0, 30, 0, 1, 2, 2, 1, 0, 30, 0,
            0, -150, -250, 0, 0, 0, 0, -250, -150, 0,
            0, 500, -150, 30, 20, 20, 30, -150, 500, 0,
            0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    };
    int corners[4] = {11, 18, 81, 88};

public slots:
    virtual void handleButton(int);
};

