#include "TicTacToeBoard.h"
#include "../constants.h"

TicTacToeBoard::TicTacToeBoard() : Board(3, 3) {}

TicTacToeBoard::TicTacToeBoard(const Board &board) : Board(board) {}

//TicTacToeBoard::~TicTacToeBoard() {
//    delete boardState;
//}

int TicTacToeBoard::winner() const {

    for (int i = 1; i <= 3; i++) {
        // Test en ligne
        if (boardState[coordinates2Array(i, 1)] == SQUARE_PLAYER && boardState[coordinates2Array(i, 2)] == SQUARE_PLAYER && boardState[coordinates2Array(i, 3)] == SQUARE_PLAYER) {
            return 1;
        }

        if (boardState[coordinates2Array(i, 1)] == SQUARE_OPPONENT && boardState[coordinates2Array(i, 2)] == SQUARE_OPPONENT && boardState[coordinates2Array(i, 3)] == SQUARE_OPPONENT) {
            return -1;
        }

        // Test en colonne
        if (boardState[coordinates2Array(1, i)] == SQUARE_PLAYER && boardState[coordinates2Array(2, i)] == SQUARE_PLAYER && boardState[coordinates2Array(3, i)] == SQUARE_PLAYER) {
            return 1;
        }

        if (boardState[coordinates2Array(1, i)] == SQUARE_OPPONENT && boardState[coordinates2Array(2, i)] == SQUARE_OPPONENT && boardState[coordinates2Array(3, i)] == SQUARE_OPPONENT) {
            return -1;
        }
    }

    // Test en diagonale
    if (boardState[coordinates2Array(1, 1)] == SQUARE_PLAYER && boardState[coordinates2Array(2, 2)] == SQUARE_PLAYER && boardState[coordinates2Array(3, 3)] == SQUARE_PLAYER) {
        return 1;
    }

    if (boardState[coordinates2Array(1, 1)] == SQUARE_OPPONENT && boardState[coordinates2Array(2, 2)] == SQUARE_OPPONENT && boardState[coordinates2Array(3, 3)] == SQUARE_OPPONENT) {
        return -1;
    }

    if (boardState[coordinates2Array(1, 3)] == SQUARE_PLAYER && boardState[coordinates2Array(2, 2)] == SQUARE_PLAYER && boardState[coordinates2Array(3, 1)] == SQUARE_PLAYER) {
        return 1;
    }

    if (boardState[coordinates2Array(1, 3)] == SQUARE_OPPONENT && boardState[coordinates2Array(2, 2)] == SQUARE_OPPONENT && boardState[coordinates2Array(3, 1)] == SQUARE_OPPONENT) {
        return -1;
    }

    return 0;
}

bool TicTacToeBoard::isPlayableMove(int player, int position) const {
    return boardState[position] == SQUARE_EMPTY;
}

void TicTacToeBoard::move(int player, int position) {
    boardState[position] = player;
}

QVector<Coordinates> *TicTacToeBoard::neighbors(int row, int col) const {
    QVector<Coordinates> *neighbors = new QVector<Coordinates>();
    // Pas utile ici
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

int *TicTacToeBoard::heuristicBoard() const {
    int* heuristicBoard = new int[25] {
            0, 0, 0, 0, 0,
            0, 3, 2, 3, 0,
            0, 2, 4, 2, 0,
            0, 3, 2, 3, 0,
            0, 0, 0, 0, 0
};

    return heuristicBoard;
}

bool TicTacToeBoard::isGameOver() const {
    for (int i = 1; i <= 3; i++) {
        // Test en ligne
        if (boardState[coordinates2Array(i, 1)] == SQUARE_PLAYER && boardState[coordinates2Array(i, 2)] == SQUARE_PLAYER && boardState[coordinates2Array(i, 3)] == SQUARE_PLAYER) {
            return true;
        }

        if (boardState[coordinates2Array(i, 1)] == SQUARE_OPPONENT && boardState[coordinates2Array(i, 2)] == SQUARE_OPPONENT && boardState[coordinates2Array(i, 3)] == SQUARE_OPPONENT) {
            return true;
        }

        // Test en colonne
        if (boardState[coordinates2Array(1, i)] == SQUARE_PLAYER && boardState[coordinates2Array(2, i)] == SQUARE_PLAYER && boardState[coordinates2Array(3, i)] == SQUARE_PLAYER) {
            return true;
        }

        if (boardState[coordinates2Array(1, i)] == SQUARE_OPPONENT && boardState[coordinates2Array(2, i)] == SQUARE_OPPONENT && boardState[coordinates2Array(3, i)] == SQUARE_OPPONENT) {
            return true;
        }
    }

    // Test en diagonale
    if (boardState[coordinates2Array(1, 1)] == SQUARE_PLAYER && boardState[coordinates2Array(2, 2)] == SQUARE_PLAYER && boardState[coordinates2Array(3, 3)] == SQUARE_PLAYER) {
        return true;
    }

    if (boardState[coordinates2Array(1, 1)] == SQUARE_OPPONENT && boardState[coordinates2Array(2, 2)] == SQUARE_OPPONENT && boardState[coordinates2Array(3, 3)] == SQUARE_OPPONENT) {
        return true;
    }

    if (boardState[coordinates2Array(1, 3)] == SQUARE_PLAYER && boardState[coordinates2Array(2, 2)] == SQUARE_PLAYER && boardState[coordinates2Array(3, 1)] == SQUARE_PLAYER) {
        return true;
    }

    if (boardState[coordinates2Array(1, 3)] == SQUARE_OPPONENT && boardState[coordinates2Array(2, 2)] == SQUARE_OPPONENT && boardState[coordinates2Array(3, 1)] == SQUARE_OPPONENT) {
        return true;
    }

    // Personne n'a gagné : on vérifie qu'on peut toujours jouer
    QVector<Coordinates>* playerMoves = playableMoves(SQUARE_PLAYER);
    return playerMoves->isEmpty();
}
