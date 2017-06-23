#ifndef BOARD_H
#define BOARD_H

#include <QVector>
#include "Coordinates.h"

class Board {
public:
    Board();
    //Board(Board);
    int getSquareState(int, int);
    bool isPlayableMove(int, int, int);
    QVector<Coordinates> *playableMoves(int);
    void move(int, int, int);
    void reset();
    int score(int);
    QVector<Coordinates> *neighbors(int, int);

//private:
    int boardState[100];
};

#endif // BOARD_H
