#ifndef STRATEGY_H
#define STRATEGY_H

#include "Boards/OthelloBoard.h"
#include "Coordinates.h"

class Strategy
{
public:
    Strategy();
    void computeMove(OthelloBoard) const;
    void move(Coordinates) const;
    void pass() const;
    OthelloBoard* newBoard(OthelloBoard, Coordinates) const;
    int evaluate(OthelloBoard, int) const;
    int minimax(OthelloBoard, int, int) const;
};

#endif // STRATEGY_H
