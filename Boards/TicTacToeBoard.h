#ifndef TICTACTOEBOARD_H
#define TICTACTOEBOARD_H

#include <QVector>

#include "../Coordinates.h"
#include "Board.h"

class TicTacToeBoard : public Board {
public:
    TicTacToeBoard();
    TicTacToeBoard(const Board&);
    //~TicTacToeBoard();

    virtual int score(int) const;
    virtual bool isPlayableMove(int, int) const;
    virtual void move(int, int);
    virtual QVector<Coordinates> *neighbors(int, int) const;
    virtual int* startBoard() const;
    virtual int* heuristicBoard() const;
};

#endif // TICTACTOEBOARD_H
