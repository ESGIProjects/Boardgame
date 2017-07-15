#ifndef TICTACTOESTRATEGY_H
#define TICTACTOESTRATEGY_H

#include "Boards/TicTacToeBoard.h"
#include "Coordinates.h"

class TicTacToeWindow;

class TicTacToeStrategy
{
public:
    TicTacToeStrategy(TicTacToeWindow*);
    void computeMove(TicTacToeBoard) const;
    void move(Coordinates) const;
    void pass() const;
    TicTacToeBoard* newBoard(TicTacToeBoard, Coordinates) const;
    int evaluate(TicTacToeBoard, int) const;
    int minimax(TicTacToeBoard, int, int) const;

    TicTacToeWindow *window;
};

#endif // TICTACTOESTRATEGY_H
