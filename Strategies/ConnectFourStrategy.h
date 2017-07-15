#ifndef CONNECTFOURSTRATEGY_H
#define CONNECTFOURSTRATEGY_H

#include "Boards/ConnectFourBoard.h"
#include "Coordinates.h"

class ConnectFourWindow;

class ConnectFourStrategy
{
public:
    ConnectFourStrategy(ConnectFourWindow*);
    void computeMove(ConnectFourBoard) const;
    void move(Coordinates) const;
    void pass() const;
    ConnectFourBoard* newBoard(ConnectFourBoard, Coordinates) const;
    int evaluate(ConnectFourBoard, int) const;
    int minimax(ConnectFourBoard, int, int) const;

    ConnectFourWindow *window;
};

#endif // CONNECTFOURSTRATEGY_H
