#include "Board.h"
#include "constants.h"
#include <QDebug>

Board::Board() {
    reset();
}

int Board::getSquareState(int row, int col) {
    return boardState[row * 10 + col];
}

bool Board::isPlayableMove(int player, int row, int col) {
    int square = row * 10 + col;

    if (boardState[square] != 0) { // remplacer 0 par constantes
        return false;
    }

    int opponent = -player;

    for (int i = 0; (unsigned long)i < sizeof(DIRECTIONS)/sizeof(*DIRECTIONS); i++) {
        int neighbor = square + DIRECTIONS[i];

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
            if (isPlayableMove(player, i, j)) {
                const Coordinates *move = new Coordinates(i, j);
                //qDebug() << i << " " << j;
                moves->insert(moves->size(), *move);
            }
        }
    }

    return moves;
}

void Board::move(int player, int row, int col) {
    int square = row * 10 + col;
    int opponent = -player;

    boardState[square] = player;

    for (int i = 0; (unsigned long)i < sizeof(DIRECTIONS)/sizeof(*DIRECTIONS); i++) {
        int neighbor = square + DIRECTIONS[i];

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

void Board::reset() {
    // Init boardState avec les valeurs de départ
    for (int i = 0; i < 100; i++)
        boardState[i] = OTHELLO_START_BOARD[i];
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
