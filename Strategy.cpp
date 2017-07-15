#include <limits>
#include "Strategy.h"
#include "constants.h"
#include "Windows/BoardWindow.h"
#include <QDebug>

Strategy::Strategy(BoardWindow* window)
{
    this->window = window;
}

void Strategy::computeMove(OthelloBoard board) const {
    QVector<Coordinates>* playableMoves = board.playableMoves(SQUARE_OPPONENT);

    if (playableMoves->empty()) {
        pass();
    } else {
        Coordinates *bestMove = nullptr;
        int bestValue;

        for (int i = 0; i < playableMoves->size(); i++) {

            OthelloBoard* newGameBoard = newBoard(board, playableMoves->at(i));
            int value = minimax(*newGameBoard, SQUARE_OPPONENT, 2);

            if (!bestMove || value > bestValue) {
                bestMove = new Coordinates(playableMoves->at(i));
                bestValue = value;
            }
        }

        move(*bestMove);
    }
}

void Strategy::move(Coordinates move) const {
    qDebug() << "Move called" << QString::number(move.col) << QString::number(move.row);

    int row = move.row - 1;
    int col = move.col -1;

    int positionUI = row * window->board->getCols() + col;

    window->handleButton(positionUI);
}

void Strategy::pass() const {
    window->pass();
}

OthelloBoard* Strategy::newBoard(OthelloBoard board, Coordinates move) const {
    OthelloBoard* newBoard = new OthelloBoard(board);
    newBoard->move(SQUARE_OPPONENT, newBoard->coordinates2Array(move));
    return newBoard;
}


int Strategy::evaluate(OthelloBoard board, int player) const {
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
