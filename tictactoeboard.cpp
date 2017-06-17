#include "tictactoeboard.h"

TictactoeBoard::TictactoeBoard() : GenBoard(NULL,3,3,"Tic Tac Toe")
{

}

void TictactoeBoard::handleButton(int position) {
    GenBoard::handleButton(position);
    qDebug() << "TictactoeBoard board handling";

    qDebug() << QString::number(position);
}
