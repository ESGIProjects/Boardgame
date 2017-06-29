#ifndef BOARD_H
#define BOARD_H

#include <QVector>
#include "Coordinates.h"

class Board {
public:
    // Constructors
    Board(int rows, int cols);
    //Board(Board);

    // Basic board information
    int getSquareState(int, int);
    int getSquareState(int);
    int score(int);
    int getRows();
    int getCols();

    // Coordinates converters
    int coordinates2Array(Coordinates);
    int coordinates2Array(int, int);

    // Game logic
    bool isPlayableMove(int, int);
    QVector<Coordinates> *playableMoves(int);
    void move(int, int);
    QVector<Coordinates> *neighbors(int, int);

    // Start and reset board
    int* startBoard() const;
    void reset();

private:
    int *boardState;
    int rows;
    int cols;
};

#endif // BOARD_H
