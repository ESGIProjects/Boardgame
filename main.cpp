#include "startgame.h"
#include <QApplication>
#include <QPushButton>
#include <QIcon>
#include <QDir>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    StartGame w;

    w.setWindowTitle("GenBoard Beta v1");
    w.setWindowIcon(QIcon("genboard.png"));
    w.resize(640,360);
    w.show();

    return a.exec();
}
