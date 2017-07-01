#ifndef OTHELLOBOARD_H
#define OTHELLOBOARD_H

#include <QVector>

#include "Coordinates.h"
#include "Board.h"

class OthelloBoard : public Board {
public:
    // Constructors
    OthelloBoard(int, int);

    virtual int score(int) const;
    virtual bool isPlayableMove(int, int) const;
    virtual QVector<Coordinates> *playableMoves(int) const;
    virtual void move(int, int);
    virtual QVector<Coordinates> *neighbors(int, int) const;
    virtual int* startBoard() const;
};

#endif // OTHELLOBOARD_H
