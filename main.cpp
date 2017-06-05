#include "startgame.h"
#include <QApplication>
#include <QPushButton>
#include <QIcon>
#include <QDir>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    StartGame w;

    w.show();

    return a.exec();
}
