#pragma once

#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include <QSqlQuery>

class ScoreMenu : public QWidget
{

    Q_OBJECT

public:
    ScoreMenu(QWidget *parent = 0);
    QLabel *connectFour;
    QLabel *scoreConnect;
    QLabel *othello;
    QLabel *scoreOthello;
    QLabel *tictactoe;
    QLabel *scoreTictactoe;

    QPushButton *toMenu;
    QWidget *mainMenu;

    QSqlQuery query;
    
private slots:
    void goMenu();
};
