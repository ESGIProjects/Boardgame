#include <iostream>
#include <QDebug>
#include <QList>
#include <QDir>
#include <QString>
#include <QSignalMapper>

#include "StartWindow.h"
#include "TicTacToeWindow.h"
#include "../Strategies/TicTacToeStrategy.h"
#include "../constants.h"

TicTacToeWindow::TicTacToeWindow(TicTacToeBoard &board) : QWidget(0) {

    // Base requirements
    QString title = "BoardWindow";
    this->board = &board;
    int rows = board.getRows();
    int cols = board.getCols();

    // Music launch
    playList = new QMediaPlaylist();
    playList->addMedia(QUrl("qrc:/resources/music.mp3"));
    playList->addMedia(QUrl("qrc:/resources/music.mp3"));
    playList->addMedia(QUrl("qrc:/resources/music.mp3"));
    playList->setPlaybackMode(QMediaPlaylist::PlaybackMode::Random);

    music = new QMediaPlayer;
    music->setPlaylist(playList);
    music->setVolume(100);
    music->play();

    // Window parameters
    setWindowIcon(QIcon(":/resources/genboard.png"));

    // Debug
    qDebug() << "Creation of the board !";
    qDebug() << "Rows : " + QString::number(rows);
    qDebug() << "Cols : " + QString::number(cols);

    // Menu buttons
    restartButton = new QPushButton("Restart", this);
    backButton = new QPushButton("Menu",this);

    connect(backButton, &QPushButton::clicked, this, &TicTacToeWindow::goMenu);
    connect(restartButton, &QPushButton::clicked, this, &TicTacToeWindow::restart);

    // Window layout
    QGridLayout *layout = new QGridLayout();

    QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
    sizePolicy.setHorizontalStretch(0);
    sizePolicy.setVerticalStretch(0);

    buttons = new QPushButton*[rows*cols];
    QGridLayout *boardLayout = new QGridLayout;
    QSignalMapper *signalMapper = new QSignalMapper(this);

    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
                buttons[i*cols+j] = new QPushButton("", this);
                buttons[i*cols+j]->setSizePolicy(sizePolicy);
                signalMapper->setMapping(buttons[i*cols+j], i*cols+j);
                connect(buttons[i*cols+j], SIGNAL(clicked(bool)), signalMapper, SLOT(map()));
                boardLayout->addWidget(buttons[i*cols+j], i, j);
        }
    }

    connect(signalMapper, SIGNAL(mapped(int)), this, SLOT(handleButton(int)));

    boardLayout->setHorizontalSpacing(1);
    boardLayout->setVerticalSpacing(1);

    layout->addLayout(boardLayout,0,0,1,1);
    layout->addWidget(backButton,1,0);
    layout->addWidget(restartButton,1,1);

    // Action text block
    actionTextEdit = new QTextEdit();
    actionTextEdit->insertHtml("<span style=\"font-weight: bold\">Début de la partie !</span><br /><br />");
    actionTextEdit->setReadOnly(true);

    layout->addWidget(actionTextEdit, 0, 1);
    layout->setColumnStretch(0, 2);

    this->setWindowTitle(title);
    this->setLayout(layout);
    this->resize(1280,720);
    this->setMaximumSize(1280, 720);

    // IA configuration
    strategy = new TicTacToeStrategy(this);

    // Correctly displaying board
    restart();
}

void TicTacToeWindow::goMenu() {
    menu = new StartWindow();
    music->stop();

    menu->show();
    this->close();
}

void TicTacToeWindow::restart(){
    board->reset();
    currentPlayer = SQUARE_PLAYER;

    displayBoard();

    actionTextEdit->clear();
    actionTextEdit->insertHtml("<span style=\"font-weight: bold\">Début de la partie !</span><br /><br />");
}

void TicTacToeWindow::handleButton(int position) {
    // 1. Peut-on toujours jouer ?
    if (board->isGameOver()) return;

    // 2. Conversion de la position UI vers position de jeu
    int boardPosition = convertPositionFromUIToBoard(position);
    qDebug() << "Handle Button : " << QString::number(boardPosition);

    // 3. Jeu
    if (board->isPlayableMove(currentPlayer, boardPosition)) {
        board->move(currentPlayer, boardPosition);
        qDebug() << "Playable move";
        displayBoard();
        insertAction(currentPlayer, position);
        currentPlayer = -currentPlayer;

        // 4. Jeu terminé?
        if (board->isGameOver()) {
            actionTextEdit->insertHtml("<span style=\"font-weight: bold\">Fin de la partie !</span><br /><br />");
            // TODO afficher score
            return;
        }

        // Let IA decide its next move
        if (currentPlayer == SQUARE_OPPONENT) {
            strategy->computeMove(*board);
        }
    } else {
        qDebug() << "Not a valid move";
    }
}

int TicTacToeWindow::convertPositionFromUIToBoard(int position) {
    int x = position / board->getRows();
    int y = position % board->getCols();

    return board->coordinates2Array(x+1, y+1);
}

void TicTacToeWindow::displayBoard() {
    QColor white(Qt::white);
    QColor black(Qt::black);

    QPalette playerPalette;
    playerPalette.setColor(QPalette::Background, white);

    QPalette opponentPalette;
    opponentPalette.setColor(QPalette::Background, black);

    for (int i = 0; i < board->getRows(); i++) {
        for (int j = 0; j < board->getCols(); j++) {

            int squareState = board->getSquareState(i+1, j+1);
            QPushButton *button = buttons[i * board->getCols() + j];
            //button->setAutoFillBackground(true);

            if (squareState == SQUARE_PLAYER) {
                button->setText("P");
                button->setPalette(playerPalette);
            }
            if (squareState == SQUARE_OPPONENT) {
                button->setText("O");
                button->setPalette(opponentPalette);
            }

            if (squareState == SQUARE_EMPTY) {
                button->setText("");
            }

            button->update();
        }
    }
}

void TicTacToeWindow::insertAction(int player, int position) {
    int x = position % board->getCols() + 1;
    int y = position / board->getRows() + 1;

    QString str = "";

    if (player == SQUARE_PLAYER)
        str += "<span style=\"color: #0000FF\">- Joueur";
    else
        str += "<span style=\"color: #FF0000\">- Ordinateur";

    str += " a placé un pion sur la case " + QString::number(y) + "," + QString::number(x) + "</span><br />";

    actionTextEdit->insertHtml(str);
}

void TicTacToeWindow::pass() {
    currentPlayer = -currentPlayer;

    if (currentPlayer == SQUARE_OPPONENT) {
        strategy->computeMove(*board);
    }
}
