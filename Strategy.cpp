#include "Strategy.h"

Strategy::Strategy()
{

}

void Strategy::computeMove(Board board) const {

}

void Strategy::move(Coordinates move) const {

}

void Strategy::pass() const {

}

Board* Strategy::newBoard(Board board, Coordinates move) const {
    return &board;
}

int Strategy::evaluate(Board board, int player) const {
    return 0;
}
