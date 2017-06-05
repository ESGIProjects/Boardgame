#pragma once

#include <QWidget>
#include <QLabel>

class ScoreMenu : public QWidget
{

    Q_OBJECT

public:
    ScoreMenu(QWidget *parent = 0);
    QLabel *connect;
    QLabel *scoreConnect;
    QLabel *othello;
    QLabel *scoreOthello;
    QLabel *tictactoe;
    QLabel *scoreTictactoe;
    QWidget *menu;
    
private slots:
    //void goMenu();
};
