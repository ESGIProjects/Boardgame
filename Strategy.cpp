#include <limits>
#include "Strategy.h"
#include "constants.h"

Strategy::Strategy()
{
    // TODO à connecter avec l'UI
}

void Strategy::computeMove(OthelloBoard board) const {
    QVector<Coordinates>* playableMoves = board.playableMoves(SQUARE_OPPONENT);

    if (playableMoves->empty()) {
        pass();
    } else {
        Coordinates* bestMove = nullptr;
        int bestValue;

        for (int i = 0; i < playableMoves->size(); i++) {
            OthelloBoard* newGameBoard = newBoard(board, playableMoves->at(i));
            int value = minimax(*newGameBoard, SQUARE_OPPONENT, 2);

            if (!bestMove || value > bestValue) {
                *bestMove = playableMoves->at(i);
                bestValue = value;
            }
        }

        move(*bestMove);
    }
}

void Strategy::move(Coordinates move) const {
    // TODO à connecter avec l'UI
}

void Strategy::pass() const {
    // TODO à connecter avec l'UI
}

OthelloBoard* Strategy::newBoard(OthelloBoard board, Coordinates move) const {
    OthelloBoard* newBoard = new OthelloBoard(board);
    newBoard->move(SQUARE_OPPONENT, newBoard->coordinates2Array(move));
    return newBoard;
}

int Strategy::evaluate(OthelloBoard board, int player) const {
    int utility = 0;

    for (int i = 1; i < (board.getCols()+1); i++) {
        for (int j = 1; j < (board.getRows()+1); j++) {
            int currentSquare = board.getSquareState(board.coordinates2Array(i, j));

            if (currentSquare == player) {
                utility += 1; // REMPLACER PAR LES HEURISTIQUES
            } else if (currentSquare == -player) {
                utility -= 1; // REMPLACER PAR LES HEURISTIQUES
            }
        }
    }

    return utility;
}

int Strategy::minimax(OthelloBoard board, int player, int depth) const {
    QVector<Coordinates>* playableMoves = board.playableMoves(SQUARE_OPPONENT);

    if (depth == 0 || playableMoves->empty()) {
        return evaluate(board, SQUARE_OPPONENT);
    }

    int bestValue = std::numeric_limits<int>::min();

    for (int i = 0; i < playableMoves->size(); i++) {
        OthelloBoard* newGameBoard = newBoard(board, playableMoves->at(i));
        int index = minimax(*newGameBoard, -player, depth-1);

        if (index > bestValue) {
            bestValue = index;
        }
    }

    return bestValue;
}
