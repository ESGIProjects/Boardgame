#include "startgame.h"
#include <QApplication>
#include <QPushButton>
#include <QIcon>
#include <QDir>
#include <QSqlQuery>
#include <QSqlDatabase>
#include <QSqlDriver>
#include <QSqlError>
#include <QDebug>

int main(int argc, char *argv[])
{
    const QString DRIVER("QSQLITE");

    if(QSqlDatabase::isDriverAvailable(DRIVER)){
        qDebug() << "Driver available !";
    }
    else{
        qDebug() << "Driver is missing !";
    }

    QSqlDatabase db = QSqlDatabase::addDatabase(DRIVER);
    db.setDatabaseName(":memory:");

    if(!db.open()){
         qDebug() << "ERROR: " << db.lastError();
    }
    else{
        qDebug() << "Connection is a success !";
    }

    QSqlQuery query;

    // we excute some query in order to create and insert some data and ensure it's done correctly

    if(!query.exec("CREATE TABLE games (id INTEGER PRIMARY KEY, name TEXT, numberPlay INTEGER)")){
        qDebug() << "ERROR : " << query.lastError().text();
    }
    if(!query.exec("INSERT INTO games(name,numberPlay) VALUES('Connect Four',0)")){
        qDebug() << "ERROR : " << query.lastError().text();
    }
    if(!query.exec("INSERT INTO games(name,numberPlay) VALUES('Othello',0)")){
        qDebug() << "ERROR : " << query.lastError().text();
    }
    if(!query.exec("INSERT INTO games(name,numberPlay) VALUES('Tic Tac Toe',0)")){
        qDebug() << "ERROR : " << query.lastError().text();
    }

    QApplication a(argc, argv);
    StartGame w;
    w.show();
    return a.exec();
}
