#ifndef GAMEMANAGER_H
#define GAMEMANAGER_H

#include <QTimer>
#include <string>
#include <vector>

class GameManager : public QObject{

    Q_OBJECT
public:
    GameManager();
    ~GameManager();

    enum Cell{

        WALL,DARK,LIGHT,PLAYER
    };

    void stepLeft();
    void stepRight();
    void stepUp();
    void stepDown();
    int gameTime;
    int gridSize();
    Cell getGridData(int x,int y);

public slots:
    void newGame(int size);
    void pauseGame();
    void stepGame(int dirx,int diry);

private slots:
   void timerUpdate();

signals:
    void gameOver(int seconds); //passing the seconds played to the player
    void update(); //timer updating signal
    void viewSignal();
    void pause();

private:
    std::vector<std::vector<Cell> > grid;
    void filereader(std::string filename,int size);
    struct Position{

        int x;
        int y;
    } position;

    QTimer* _timer;
};

#endif // GAMEMANAGER_H
