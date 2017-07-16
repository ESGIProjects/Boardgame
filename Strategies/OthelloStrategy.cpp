#include <limits>
#include "OthelloStrategy.h"
#include "constants.h"
#include "Windows/OthelloWindow.h"

OthelloStrategy::OthelloStrategy(OthelloWindow* window)
{
    this->window = window;
}

void OthelloStrategy::computeMove(OthelloBoard board) const {
    QVector<Coordinates>* playableMoves = board.playableMoves(SQUARE_OPPONENT);

    if (playableMoves->empty()) {
        pass();
    } else {
        Coordinates *bestMove = nullptr;
        int bestValue;

        for (int i = 0; i < playableMoves->size(); i++) {

            OthelloBoard* newGameBoard = newBoard(board, playableMoves->at(i));
            int value = alphabeta(*newGameBoard, SQUARE_OPPONENT, 3, -std::numeric_limits<int>::max(),  std::numeric_limits<int>::max());

            if (!bestMove || value > bestValue) {
                bestMove = new Coordinates(playableMoves->at(i));
                bestValue = value;
            }
        }
        move(*bestMove);
    }
}

void OthelloStrategy::move(Coordinates move) const {
    int row = move.row - 1;
    int col = move.col -1;

    int positionUI = row * window->board->getCols() + col;

    window->handleButton(positionUI);
}

void OthelloStrategy::pass() const {
    window->pass();
}

OthelloBoard* OthelloStrategy::newBoard(OthelloBoard board, Coordinates move) const {
    OthelloBoard* newBoard = new OthelloBoard(board);
    newBoard->move(SQUARE_OPPONENT, newBoard->coordinates2Array(move));
    return newBoard;
}


int OthelloStrategy::evaluate(OthelloBoard board, int player) const {
    int utility = 0;

    int *heuristics = board.heuristicBoard();

    for (int i = 1; i < (board.getCols()+1); i++) {
        for (int j = 1; j < (board.getRows()+1); j++) {
            int currentSquare = board.getSquareState(board.coordinates2Array(i, j));

            if (currentSquare == player) {
                utility += heuristics[board.coordinates2Array(i, j)];
            } else if (currentSquare == -player) {
                utility -= heuristics[board.coordinates2Array(i, j)];
            }
        }
    }

    return utility;
}

int OthelloStrategy::alphabeta(OthelloBoard board, int player, int depth, int A, int B) const {
    QVector<Coordinates>* playableMoves = board.playableMoves(SQUARE_OPPONENT);
    int a = A, b = B;

    if (depth == 0 || playableMoves->empty()) {
        return evaluate(board, SQUARE_OPPONENT);
    }

    for (int i = 0; i < playableMoves->size(); i++) {
        OthelloBoard* newGameBoard = newBoard(board, playableMoves->at(i));
        int index = alphabeta(*newGameBoard, -player, depth-1, A, B);

        if (player != SQUARE_OPPONENT) {
            if (index < b) {
                b = index;
            }
        } else {
            if (index > a) {
                a = index;
            }
        }
    }

    return (player != SQUARE_OPPONENT) ? b : a;
}
