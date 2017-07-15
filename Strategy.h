#ifndef STRATEGY_H
#define STRATEGY_H

#include "Boards/TicTacToeBoard.h"
#include "Coordinates.h"

class BoardWindow;

class Strategy
{
public:
    Strategy(BoardWindow*);
    void computeMove(TicTacToeBoard) const;
    void move(Coordinates) const;
    void pass() const;
    TicTacToeBoard* newBoard(TicTacToeBoard, Coordinates) const;
    int evaluate(TicTacToeBoard, int) const;
    int minimax(TicTacToeBoard, int, int) const;

    BoardWindow *window;
};

#endif // STRATEGY_H
