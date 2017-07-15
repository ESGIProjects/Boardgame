#ifndef OTHELLOSTRATEGY_H
#define OTHELLOSTRATEGY_H

#include "Boards/OthelloBoard.h"
#include "Coordinates.h"

class OthelloWindow;

class OthelloStrategy
{
public:
    OthelloStrategy(OthelloWindow*);
    void computeMove(OthelloBoard) const;
    void move(Coordinates) const;
    void pass() const;
    OthelloBoard* newBoard(OthelloBoard, Coordinates) const;
    int evaluate(OthelloBoard, int) const;
    int minimax(OthelloBoard, int, int) const;

    OthelloWindow *window;
};

#endif // OTHELLOSTRATEGY_H
