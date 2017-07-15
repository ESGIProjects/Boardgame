#include <QWidget>
#include <QPushButton>
#include <QLabel>
#include <QRadioButton>
#include <QStackedWidget>
#include <QVBoxLayout>
#include <QSqlDatabase>
#include <QSqlDriver>
#include <QSqlError>
#include <QSqlQuery>

class StartWindow : public QWidget {
    Q_OBJECT

public:
    StartWindow(QWidget *parent = 0);
    QLabel *welcome;
    QPushButton *start;
    QPushButton *score;
    QRadioButton *connectfour;
    QRadioButton *othello;
    QRadioButton *tictactoe;
    QWidget *scoreMenu;
    QStackedWidget *sw;
    QVBoxLayout *layout;

    QSqlQuery query;

private slots:
    void onStartGame();
    void goScoreMenu();

private:

};
