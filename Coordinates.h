#ifndef COORDINATES_H
#define COORDINATES_H


class Coordinates {
public:
    Coordinates();
    Coordinates(int, int);
    Coordinates(const Coordinates&);
    int row;
    int col;
};

#endif // COORDINATES_H
