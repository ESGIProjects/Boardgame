#pragma once

#include <QWidget>
#include <QApplication>
#include <QPushButton>
#include <QLabel>
#include "genboard.h"

class ConnectfourBoard : virtual public GenBoard
{
public:
    ConnectfourBoard();
};
