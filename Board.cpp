#include "Board.h"
#include "constants.h"
#include <QDebug>


// Constructor
Board::Board(int rows, int cols) {
    this->rows = rows;
    this->cols = cols;
    boardState = new int[(rows+2)*(cols+2)];

    reset();
}


// Basic Board Information
int Board::getSquareState(int row, int col) {
    return boardState[row * 10 + col];
}

int Board::getSquareState(int position) {
    return boardState[position];
}

int Board::score(int player) {
    int score = 0;

    for (int i = 1; i < 9; i++) {
        for (int j = 1; j < 9; j++) {
            if (boardState[i * 10 + j] == player) {
                score++;
            }
        }
    }

    return score;
}

int Board::getRows() {
    return rows;
}

int Board::getCols() {
    return cols;
}

// Coordinates converters
int Board::coordinates2Array(Coordinates coordinates) {
    return coordinates2Array(coordinates.row, coordinates.col);
}

int Board::coordinates2Array(int row, int col) {
    int multiplier = cols + 2;

    return row * multiplier + col;
}

// Game logic
bool Board::isPlayableMove(int player, int position) {
    //int square = row * 10 + col;

    if (boardState[position] != SQUARE_EMPTY) { // remplacer 0 par constantes
        return false;
    }

    int opponent = -player;

    for (int i = 0; i < 8; i++) {
        int neighbor = position + DIRECTIONS[i];

        if (boardState[neighbor] == opponent) {
            do {
                neighbor += DIRECTIONS[i];
            } while (boardState[neighbor] == opponent);

            if (boardState[neighbor] == player) {
                return true;
            }
        }
    }
    return false;
}

QVector<Coordinates> *Board::playableMoves(int player) {
    QVector<Coordinates> *moves = new QVector<Coordinates>();

    for (int i = 1; i < 9; i++) {
        for (int j = 1; j < 9; j++) {
            if (isPlayableMove(player, i * cols + j)) {
                const Coordinates *move = new Coordinates(i, j);
                //qDebug() << i << " " << j;
                moves->insert(moves->size(), *move);
            }
        }
    }

    return moves;
}

void Board::move(int player, int position) {
    //int square = row * 10 + col;
    int opponent = -player;

    boardState[position] = player;

    for (int i = 0; i < 8; i++) {
        int neighbor = position + DIRECTIONS[i];

        if (boardState[neighbor] == opponent) {
            do {
                neighbor += DIRECTIONS[i];
            } while (boardState[neighbor] == opponent);

            if (boardState[neighbor] == player) {
                do {
                    boardState[neighbor] = player;
                    neighbor -= DIRECTIONS[i];
                } while (boardState[neighbor] == opponent);
            }
        }
    }
}



QVector<Coordinates> *Board::neighbors(int row, int col) {
    QVector<Coordinates> *neighbors = new QVector<Coordinates>();
    int square = row * 10 + col;

    for (int i = 0; (unsigned long)i < sizeof(DIRECTIONS)/sizeof(*DIRECTIONS); i++) {
        int neighbor = square + DIRECTIONS[i];

        if (neighbor < 100 && neighbor >= 0 && boardState[neighbor] != SQUARE_EDGE) {
            const Coordinates *neighborCoordinates = new Coordinates(neighbor/10, neighbor%10);
            neighbors->insert(neighbors->size(), *neighborCoordinates);
        }
    }

    return neighbors;
}

// Start and reset board
int *Board::startBoard() const {
    int* startBoard = new int[100] {
            SQUARE_EDGE,   SQUARE_EDGE,   SQUARE_EDGE,   SQUARE_EDGE,   SQUARE_EDGE,   SQUARE_EDGE,   SQUARE_EDGE,   SQUARE_EDGE,   SQUARE_EDGE,   SQUARE_EDGE,
            SQUARE_EDGE,   SQUARE_EMPTY,  SQUARE_EMPTY,  SQUARE_EMPTY,  SQUARE_EMPTY,  SQUARE_EMPTY,  SQUARE_EMPTY,  SQUARE_EMPTY,  SQUARE_EMPTY,  SQUARE_EDGE,
            SQUARE_EDGE,   SQUARE_EMPTY,  SQUARE_EMPTY,  SQUARE_EMPTY,  SQUARE_EMPTY,  SQUARE_EMPTY,  SQUARE_EMPTY,  SQUARE_EMPTY,  SQUARE_EMPTY,  SQUARE_EDGE,
            SQUARE_EDGE,   SQUARE_EMPTY,  SQUARE_EMPTY,  SQUARE_EMPTY,  SQUARE_EMPTY,  SQUARE_EMPTY,  SQUARE_EMPTY,  SQUARE_EMPTY,  SQUARE_EMPTY,  SQUARE_EDGE,
            SQUARE_EDGE,   SQUARE_EMPTY,  SQUARE_EMPTY,  SQUARE_EMPTY,  SQUARE_OPPONENT, SQUARE_PLAYER,SQUARE_EMPTY, SQUARE_EMPTY,  SQUARE_EMPTY,  SQUARE_EDGE,
            SQUARE_EDGE,   SQUARE_EMPTY,  SQUARE_EMPTY,  SQUARE_EMPTY,  SQUARE_PLAYER,  SQUARE_OPPONENT,SQUARE_EMPTY,SQUARE_EMPTY,  SQUARE_EMPTY,  SQUARE_EDGE,
            SQUARE_EDGE,   SQUARE_EMPTY,  SQUARE_EMPTY,  SQUARE_EMPTY,  SQUARE_EMPTY,  SQUARE_EMPTY,  SQUARE_EMPTY,  SQUARE_EMPTY,  SQUARE_EMPTY,      SQUARE_EDGE,
            SQUARE_EDGE,   SQUARE_EMPTY,      SQUARE_EMPTY,      SQUARE_EMPTY,      SQUARE_EMPTY,      SQUARE_EMPTY,      SQUARE_EMPTY,      SQUARE_EMPTY,      SQUARE_EMPTY,      SQUARE_EDGE,
            SQUARE_EDGE,   SQUARE_EMPTY,      SQUARE_EMPTY,      SQUARE_EMPTY,      SQUARE_EMPTY,      SQUARE_EMPTY,      SQUARE_EMPTY,      SQUARE_EMPTY,      SQUARE_EMPTY,      SQUARE_EDGE,
            SQUARE_EDGE,   SQUARE_EDGE,   SQUARE_EDGE,   SQUARE_EDGE,   SQUARE_EDGE,   SQUARE_EDGE,   SQUARE_EDGE,   SQUARE_EDGE,   SQUARE_EDGE,   SQUARE_EDGE
        };

    return startBoard;
}

void Board::reset() {
    int* start = startBoard();

    for (int i = 0; i < rows * cols; i++)
        boardState[i] = start[i];
}
