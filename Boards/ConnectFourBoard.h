#ifndef CONNECTFOURBOARD_H
#define CONNECTFOURBOARD_H

#include <QVector>

#include "../Coordinates.h"
#include "Board.h"

class ConnectFourBoard : public Board
{
public:
    ConnectFourBoard();
    ConnectFourBoard(const Board&);
    //~ConnectFourBoard();

    virtual int score(int) const;
    virtual bool isPlayableMove(int, int) const;
    virtual void move(int, int);
    virtual QVector<Coordinates> *neighbors(int, int) const;
    virtual int* startBoard() const;
    virtual int* heuristicBoard() const;
    virtual bool isGameOver() const;
};

#endif // CONNECTFOURBOARD_H
