#include "startgame.h"
#include "plusminus.h"
#include <QApplication>
#include <QPushButton>
#include <QIcon>
#include <QDir>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    StartGame w;

    w.setWindowTitle("GenBoard alpha");
    w.setWindowIcon(QIcon("genboard.png"));
    w.resize(640,360);
    w.show();

    return a.exec();
}
