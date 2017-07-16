#include <limits>
#include "TicTacToeStrategy.h"
#include "constants.h"
#include "Windows/TicTacToeWindow.h"
#include <QDebug>

TicTacToeStrategy::TicTacToeStrategy(TicTacToeWindow* window)
{
    this->window = window;
}

void TicTacToeStrategy::computeMove(TicTacToeBoard board) const {
    QVector<Coordinates>* playableMoves = board.playableMoves(SQUARE_OPPONENT);

    if (playableMoves->empty()) {
        pass();
    } else {
        Coordinates *bestMove = nullptr;
        int bestValue;

        for (int i = 0; i < playableMoves->size(); i++) {

            TicTacToeBoard* newGameBoard = newBoard(board, playableMoves->at(i));
            int value = evaluate(*newGameBoard, SQUARE_OPPONENT);

            if (!bestMove || value > bestValue) {
                bestMove = new Coordinates(playableMoves->at(i));
                bestValue = value;
            }
        }

        move(*bestMove);
    }
}

void TicTacToeStrategy::move(Coordinates move) const {
    qDebug() << "Move called" << QString::number(move.col) << QString::number(move.row);

    int row = move.row - 1;
    int col = move.col -1;

    int positionUI = row * window->board->getCols() + col;

    window->handleButton(positionUI);
}

void TicTacToeStrategy::pass() const {
    window->pass();
}

TicTacToeBoard* TicTacToeStrategy::newBoard(TicTacToeBoard board, Coordinates move) const {
    TicTacToeBoard* newBoard = new TicTacToeBoard(board);
    newBoard->move(SQUARE_OPPONENT, newBoard->coordinates2Array(move));
    return newBoard;
}

int TicTacToeStrategy::evaluate(TicTacToeBoard board, int player) const {
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

int TicTacToeStrategy::minimax(TicTacToeBoard board, int player, int depth) const {
    QVector<Coordinates>* playableMoves = board.playableMoves(SQUARE_OPPONENT);

    if (depth == 0 || playableMoves->empty()) {
        return evaluate(board, SQUARE_OPPONENT);
    }

    int bestValue = std::numeric_limits<int>::min();

    for (int i = 0; i < playableMoves->size(); i++) {
        TicTacToeBoard* newGameBoard = newBoard(board, playableMoves->at(i));
        int index = minimax(*newGameBoard, -player, depth-1);

        if (index > bestValue) {
            bestValue = index;
        }
    }

    return bestValue;
}
