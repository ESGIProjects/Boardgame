#include <QWidget>
#include <QPushButton>
#include <QLabel>
#include <QRadioButton>

class StartGame : public QWidget {
    Q_OBJECT

public:
    StartGame(QWidget *parent = 0);

private slots:
    void onStartGame();

private:
   QLabel *welcome;
   QPushButton *start;
   QPushButton *exit;
   QRadioButton *connectfour;
   QRadioButton *othello;
   QRadioButton *tictactoe;
};
