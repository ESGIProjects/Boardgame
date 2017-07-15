#include "ConnectFourBoard.h"
#include "../constants.h"
#include <QDebug>

ConnectFourBoard::ConnectFourBoard() : Board(7, 7) {}

ConnectFourBoard::ConnectFourBoard(const Board &board) : Board(board) {}

//ConnectFourBoard::~ConnectFourBoard() {
//    delete boardState;
//}

int ConnectFourBoard::winner() const {
    // TODO
    return 0;
}

bool ConnectFourBoard::isPlayableMove(int player, int position) const {
    if (boardState[position] == SQUARE_EMPTY) {
        return boardState[position+directions()[6]] == SQUARE_PLAYER || boardState[position+directions()[6]] == SQUARE_OPPONENT || boardState[position+directions()[6]] == SQUARE_EDGE;
    }
    return false;
}

void ConnectFourBoard::move(int player, int position) {
    boardState[position] = player;
}

QVector<Coordinates> *ConnectFourBoard::neighbors(int row, int col) const {
    QVector<Coordinates> *neighbors = new QVector<Coordinates>();
    // TODO
    return neighbors;
}

int *ConnectFourBoard::startBoard() const {
    int* startBoard = new int[81] {
            SQUARE_EDGE, SQUARE_EDGE, SQUARE_EDGE, SQUARE_EDGE, SQUARE_EDGE, SQUARE_EDGE, SQUARE_EDGE, SQUARE_EDGE, SQUARE_EDGE,
            SQUARE_EDGE, SQUARE_EMPTY, SQUARE_EMPTY, SQUARE_EMPTY, SQUARE_EMPTY, SQUARE_EMPTY, SQUARE_EMPTY, SQUARE_EMPTY, SQUARE_EDGE,
            SQUARE_EDGE, SQUARE_EMPTY, SQUARE_EMPTY, SQUARE_EMPTY, SQUARE_EMPTY, SQUARE_EMPTY, SQUARE_EMPTY, SQUARE_EMPTY, SQUARE_EDGE,
            SQUARE_EDGE, SQUARE_EMPTY, SQUARE_EMPTY, SQUARE_EMPTY, SQUARE_EMPTY, SQUARE_EMPTY, SQUARE_EMPTY, SQUARE_EMPTY, SQUARE_EDGE,
            SQUARE_EDGE, SQUARE_EMPTY, SQUARE_EMPTY, SQUARE_EMPTY, SQUARE_EMPTY, SQUARE_EMPTY, SQUARE_EMPTY, SQUARE_EMPTY, SQUARE_EDGE,
            SQUARE_EDGE, SQUARE_EMPTY, SQUARE_EMPTY, SQUARE_EMPTY, SQUARE_EMPTY, SQUARE_EMPTY, SQUARE_EMPTY, SQUARE_EMPTY, SQUARE_EDGE,
            SQUARE_EDGE, SQUARE_EMPTY, SQUARE_EMPTY, SQUARE_EMPTY, SQUARE_EMPTY, SQUARE_EMPTY, SQUARE_EMPTY, SQUARE_EMPTY, SQUARE_EDGE,
            SQUARE_EDGE, SQUARE_EMPTY, SQUARE_EMPTY, SQUARE_EMPTY, SQUARE_EMPTY, SQUARE_EMPTY, SQUARE_EMPTY, SQUARE_EMPTY, SQUARE_EDGE,
            SQUARE_EDGE, SQUARE_EDGE, SQUARE_EDGE, SQUARE_EDGE, SQUARE_EDGE, SQUARE_EDGE, SQUARE_EDGE, SQUARE_EDGE, SQUARE_EDGE,
        };

    return startBoard;
}

int *ConnectFourBoard::heuristicBoard() const {
    int* heuristicBoard = new int[81] {
            0, 0, 0, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0, 0, 0, 0, 0
    };

    return heuristicBoard;
}

bool ConnectFourBoard::isGameOver() const {
    // TODO vérification du vainqueur

    // Personne n'a gagné : on vérifie qu'on peut toujours jouer
    QVector<Coordinates>* playerMoves = playableMoves(SQUARE_PLAYER);
    return playerMoves->isEmpty();
}
