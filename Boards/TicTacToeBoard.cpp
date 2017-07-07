#include "TicTacToeBoard.h"
#include "../constants.h"

TicTacToeBoard::TicTacToeBoard() : Board(3, 3) {}

TicTacToeBoard::TicTacToeBoard(const Board &board) : Board(board) {}

TicTacToeBoard::~TicTacToeBoard() {
    delete boardState;
}

int TicTacToeBoard::score(int player) const {
    // TODO
    return 0;
}

bool TicTacToeBoard::isPlayableMove(int player, int position) const {
    // TODO
    return false;
}

QVector<Coordinates> *TicTacToeBoard::playableMoves(int player) const {
    QVector<Coordinates> *moves = new QVector<Coordinates>();
    // TODO
    return moves;
}

void TicTacToeBoard::move(int player, int position) {
    // TODO
}

QVector<Coordinates> *TicTacToeBoard::neighbors(int row, int col) const {
    QVector<Coordinates> *neighbors = new QVector<Coordinates>();
    // TODO
    return neighbors;
}

int *TicTacToeBoard::startBoard() const {
    int* startBoard = new int[25] {
            SQUARE_EDGE, SQUARE_EDGE, SQUARE_EDGE, SQUARE_EDGE, SQUARE_EDGE,
            SQUARE_EDGE, SQUARE_EMPTY, SQUARE_EMPTY, SQUARE_EMPTY, SQUARE_EDGE,
            SQUARE_EDGE, SQUARE_EMPTY, SQUARE_EMPTY, SQUARE_EMPTY, SQUARE_EDGE,
            SQUARE_EDGE, SQUARE_EMPTY, SQUARE_EMPTY, SQUARE_EMPTY, SQUARE_EDGE,
            SQUARE_EDGE, SQUARE_EDGE, SQUARE_EDGE, SQUARE_EDGE, SQUARE_EDGE,
        };

    return startBoard;
}
