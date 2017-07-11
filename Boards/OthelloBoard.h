#ifndef OTHELLOBOARD_H
#define OTHELLOBOARD_H

#include <QVector>

#include "../Coordinates.h"
#include "Board.h"

class OthelloBoard : public Board {
public:
    OthelloBoard();
    OthelloBoard(const Board&);
    //~OthelloBoard();

    virtual int score(int) const;
    virtual bool isPlayableMove(int, int) const;
    virtual void move(int, int);
    virtual QVector<Coordinates> *neighbors(int, int) const;
    virtual int* startBoard() const;
    virtual int* heuristicBoard() const;
};

#endif // OTHELLOBOARD_H
