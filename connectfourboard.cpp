#include "connectfourboard.h"

ConnectfourBoard::ConnectfourBoard() : GenBoard(NULL,6,7,"Connect Four")
{

}

void ConnectfourBoard::handleButton(int position) {
    GenBoard::handleButton(position);
    qDebug() << "ConnectFour board handling";

    qDebug() << QString::number(position);
}
