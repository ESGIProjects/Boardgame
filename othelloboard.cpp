#include <QSignalMapper>
#include "othelloboard.h"

OthelloBoard::OthelloBoard() : GenBoard(NULL,8,8,"Othello"){
    qDebug() << "Othello board loaded";
}

void OthelloBoard::handleButton(int position) {
    GenBoard::handleButton(position);
    qDebug() << "Othello board handling";

    qDebug() << QString::number(heuristiques[position+11]);
}
