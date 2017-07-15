#ifndef BOARD_H
#define BOARD_H

#include <QVector>

#include "../Coordinates.h"

class Board
{
public:
    Board(int, int);
    Board(const Board&);
    //~Board();

    // Basic board information
    virtual int getSquareState(int, int) const;
    virtual int getSquareState(int) const;
    virtual int winner() const = 0;
    int getRows() const;
    int getCols() const;

    // Coordinates converters
    int coordinates2Array(Coordinates) const;
    int coordinates2Array(int, int) const;

    // Game logic
    virtual bool isPlayableMove(int, int) const = 0;
    QVector<Coordinates> *playableMoves(int) const;
    virtual void move(int, int) = 0;
    virtual QVector<Coordinates> *neighbors(int, int) const = 0;
    virtual bool isGameOver() const = 0;

    // Helpers & data
    virtual int *startBoard() const = 0;
    virtual int *heuristicBoard() const = 0;
    virtual int *directions() const;
    virtual void reset();

protected:
    int *boardState;
    int rows;
    int cols;
};

#endif // BOARD_H
