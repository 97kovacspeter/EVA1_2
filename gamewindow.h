#ifndef GAMEWINDOW_H
#define GAMEWINDOW_H

#include <QWidget>
#include <QPushButton>
#include <QLabel>
#include <QVector>
#include <QHBoxLayout>
#include <QGridLayout>
#include "gamemanager.h"

class GameWindow : public QWidget{

    Q_OBJECT

public:
    explicit GameWindow(QWidget *parent = 0);
    void keyPressEvent (QKeyEvent *event);
    ~GameWindow();

private slots:
    void startNewGame();
    void gameManager_gameOver(int seconds);
    void doTimerUpdate();
    void viewUpdate();
    void pauseMsg();

private:
    GameManager* _gameManager;

    QGridLayout* _sightGrid;

    QLabel* _timerLabel;

    QPushButton* _fiveButton;
    QPushButton* _tenButton;
    QPushButton* _fifteenButton;

    QPushButton* _pauseButton;

    std::vector<std::vector<QPushButton*> > buttonGrid;

};

#endif // GAMEWINDOW_H
