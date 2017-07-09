#include <QDebug>

#include "Board.h"
#include "constants.h"

Board::Board(int rows, int cols)
{
    this->rows = rows;
    this->cols = cols;
    boardState = new int[(rows+2)*(cols+2)];
}

Board::Board(const Board &board) : Board(board.rows, board.cols) {
    int total = (getRows()+2) * (getCols()+2);

    for (int i = 0; i < total; i++) {
        this->boardState[i] = board.boardState[i];
    }
}

//Board::~Board() {
//    delete boardState;
//}

int Board::getSquareState(int row, int col) const {
    return getSquareState(coordinates2Array(row, col));
}

int Board::getSquareState(int position) const {
    return boardState[position];
}

int Board::getRows() const {
    return rows;
}

int Board::getCols() const {
    return cols;
}

int Board::coordinates2Array(Coordinates coordinates) const {
    return coordinates2Array(coordinates.row, coordinates.col);
}

int Board::coordinates2Array(int row, int col) const {
    return row * (cols+2) + col;
}

void Board::reset() {
    qDebug() << "Restart";
    int *start = startBoard();

    int total = (getRows()+2) * (getCols()+2);

    for (int i = 0; i < total; i++) {
        boardState[i] = start[i];
    }
}
