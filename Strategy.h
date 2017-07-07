#ifndef STRATEGY_H
#define STRATEGY_H

#include "Coordinates.h"
#include "Boards/Board.h"

class Strategy
{
public:
    Strategy();
    void computeMove(Board) const;
    void move(Coordinates) const;
    void pass() const;
    Board* newBoard(Board, Coordinates) const;
    int evaluate(Board, int) const;
};

#endif // STRATEGY_H
