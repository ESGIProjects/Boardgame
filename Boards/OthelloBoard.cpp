#include <QDebug>

#include "OthelloBoard.h"
#include "../constants.h"

OthelloBoard::OthelloBoard() : Board(8, 8) {}

int OthelloBoard::score(int player) const {
    int score = 0;

    for (int i = 1; i < (cols+1); i++) {
        for (int j = 1; j < (rows+1); j++) {
            if (boardState[coordinates2Array(i, j)] == player) {
                score++;
            }
        }
    }

    return score;
}

bool OthelloBoard::isPlayableMove(int player, int position) const {

    if (boardState[position] != SQUARE_EMPTY) {
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

QVector<Coordinates> *OthelloBoard::playableMoves(int player) const {
    QVector<Coordinates> *moves = new QVector<Coordinates>();

    for (int i = 1; i < 9; i++) {
        for (int j = 1; j < 9; j++) {
            if (isPlayableMove(player, i * cols + j)) {
                const Coordinates *move = new Coordinates(i, j);
                moves->insert(moves->size(), *move);
            }
        }
    }

    return moves;
}

void OthelloBoard::move(int player, int position) {
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

QVector<Coordinates> *OthelloBoard::neighbors(int row, int col) const {
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

int *OthelloBoard::startBoard() const {
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
