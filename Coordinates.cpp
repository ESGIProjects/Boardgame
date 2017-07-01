#include "Coordinates.h"

Coordinates::Coordinates() : Coordinates(0, 0) {}

Coordinates::Coordinates(int row, int col) {
    this->row = row;
    this->col = col;
}
