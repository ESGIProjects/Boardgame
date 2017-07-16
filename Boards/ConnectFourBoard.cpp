#include "ConnectFourBoard.h"
#include "../constants.h"
#include <QDebug>

ConnectFourBoard::ConnectFourBoard() : Board(7, 7) {}

ConnectFourBoard::ConnectFourBoard(const Board &board) : Board(board) {}

//ConnectFourBoard::~ConnectFourBoard() {
//    delete boardState;
//}

int ConnectFourBoard::winner() const {
    // On parcourt toutes les cases
    for (int i = 1; i <= cols; i++) {
        for (int j = 1; j <= cols; j++) {
            int position = coordinates2Array(i, j);

            if (boardState[position] == SQUARE_EMPTY) {
                // On ne commence la vérification que si la case est occupée
                continue;
            }

            // Pour chaque case, on regarde 3 cases dans chaque direction
            // Victoire si les 3 sont de la couleur du joueur
            for (int k = 0; k < 8; k++) {
                int neighbor1 = position + directions()[k];
                int neighbor2 = neighbor1 + directions()[k];
                int neighbor3 = neighbor2 + directions()[k];

                if (boardState[position] == SQUARE_PLAYER && boardState[neighbor1] == SQUARE_PLAYER && boardState[neighbor2] == SQUARE_PLAYER && boardState[neighbor3] == SQUARE_PLAYER) {
                    return 1;
                }

                if (boardState[position] == SQUARE_OPPONENT && boardState[neighbor1] == SQUARE_OPPONENT && boardState[neighbor2] == SQUARE_OPPONENT && boardState[neighbor3] == SQUARE_OPPONENT) {
                    return -1;
                }

            }
        }
    }

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
    // On parcourt toutes les cases
    for (int i = 1; i <= cols; i++) {
        for (int j = 1; j <= rows; j++) {
            int position = coordinates2Array(i, j);

            if (boardState[position] == SQUARE_EMPTY) {
                // On ne commence la vérification que si la case est occupée
                continue;
            }

            // Pour chaque case, on regarde 3 cases dans chaque direction
            // Victoire si les 3 sont de la couleur du joueur

            qDebug() << "";
            qDebug() << "VOISINS DE " << QString::number(position);

            for (int k = 0; k < 8; k++) {
                int neighbor1 = position + directions()[k];
                int neighbor2 = neighbor1 + directions()[k];
                int neighbor3 = neighbor2 + directions()[k];
                qDebug() << QString::number(neighbor1) << "-" << QString::number(neighbor2) << "-" << QString::number(neighbor3);


                if (boardState[position] == SQUARE_PLAYER && boardState[neighbor1] == SQUARE_PLAYER && boardState[neighbor2] == SQUARE_PLAYER && boardState[neighbor3] == SQUARE_PLAYER) {
                    return true;
                }

                if (boardState[position] == SQUARE_OPPONENT && boardState[neighbor1] == SQUARE_OPPONENT && boardState[neighbor2] == SQUARE_OPPONENT && boardState[neighbor3] == SQUARE_OPPONENT) {
                    return true;
                }

            }
        }
    }

    // Personne n'a gagné : on vérifie qu'on peut toujours jouer
    QVector<Coordinates>* playerMoves = playableMoves(SQUARE_PLAYER);
    return playerMoves->isEmpty();
}
