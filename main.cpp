#include <QApplication>
#include <QPushButton>
#include <QIcon>
#include <QDir>
#include <QSqlQuery>
#include <QSqlDatabase>
#include <QSqlDriver>
#include <QSqlError>
#include <QDebug>
#include <QFileInfo>

#include "Windows/StartWindow.h"
#include "Boards/OthelloBoard.h"
#include "constants.h"

bool isDBexists(){
    //we check if bdd file exists
    QFileInfo qfi("Ressources" + QString(QDir::separator()) + "bdd");
    return qfi.exists() && qfi.isFile();
}

void initConnection() {

    const QString DRIVER("QSQLITE");

    if(QSqlDatabase::isDriverAvailable(DRIVER)){
        qDebug() << "Driver available !";
    }
    else{
        qDebug() << "Driver is missing !";
    }

    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("Ressources/bdd");

    if(!db.open()){
         qDebug() << "ERROR: " << db.lastError();
    }
    else{
        qDebug() << "Connection is a success !";
    }
}

void createDB(){
    QSqlQuery query;

    // we execute some query in order to create and insert some data and ensure it's done correctly

    if(!query.exec("CREATE TABLE games (id INTEGER PRIMARY KEY, name TEXT, numberPlay INTEGER, numberWins INTEGER)")){
        qDebug() << "ERROR : " << query.lastError().text();
    }
    if(!query.exec("INSERT INTO games(name,numberPlay,numberWins) VALUES('Connect Four',0,0)")){
        qDebug() << "ERROR : " << query.lastError().text();
    }
    if(!query.exec("INSERT INTO games(name,numberPlay,numberWins) VALUES('Othello',0,0)")){
        qDebug() << "ERROR : " << query.lastError().text();
    }
    if(!query.exec("INSERT INTO games(name,numberPlay,numberWins) VALUES('Tic Tac Toe',0,0)")){
        qDebug() << "ERROR : " << query.lastError().text();
    }
}

int main(int argc, char *argv[])
{
    if(!isDBexists()){
        initConnection();
        createDB();
    }
    else {
        initConnection();
    }

    QApplication a(argc, argv);
    StartWindow w;
    w.show();
    return a.exec();
}
