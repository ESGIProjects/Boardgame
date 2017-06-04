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
};

