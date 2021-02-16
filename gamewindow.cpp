#include "gamewindow.h"
#include <QMessageBox>
#include <QApplication>
#include <QKeyEvent>

GameWindow::GameWindow(QWidget *parent): QWidget(parent){

    setWindowTitle(trUtf8("Maze"));

    _gameManager = new GameManager();
        connect(_gameManager, SIGNAL(gameOver(int)), this, SLOT(gameManager_gameOver(int)));
        connect(_gameManager,SIGNAL(viewSignal()),this,SLOT(viewUpdate()));
    _fiveButton = new QPushButton(trUtf8("Easy(5)"));
        connect(_fiveButton, SIGNAL(clicked()), this, SLOT(startNewGame()));
        _fiveButton->setFixedSize(130,50);
    _tenButton = new QPushButton(trUtf8("Medium(10)"));
        connect(_tenButton, SIGNAL(clicked()), this, SLOT(startNewGame()));
        _tenButton->setFixedSize(130,50);
    _fifteenButton = new QPushButton(trUtf8("Hard(15)"));
        connect(_fifteenButton, SIGNAL(clicked()), this, SLOT(startNewGame()));
        _fifteenButton->setFixedSize(130,50);
    _pauseButton = new QPushButton(trUtf8("Stop/start"));
        _pauseButton->setEnabled(false);
        connect(_pauseButton, SIGNAL(clicked()), _gameManager, SLOT(pauseGame()));
        _pauseButton->setFixedSize(130,50);
    _timerLabel=new QLabel("Timer: "+ QString::number(0));
        connect(_gameManager,SIGNAL(update()),this,SLOT(doTimerUpdate()));

        connect(_gameManager,SIGNAL(pause()),this,SLOT(pauseMsg()));


    QHBoxLayout *hLayout = new QHBoxLayout();

    QVBoxLayout *vLayout = new QVBoxLayout();
    hLayout->addWidget(_fiveButton);
    hLayout->addWidget(_tenButton);
    hLayout->addWidget(_fifteenButton);
    hLayout->addWidget(_pauseButton);

    vLayout->addLayout(hLayout);
    vLayout->addWidget(_timerLabel);

    buttonGrid = std::vector<std::vector<QPushButton*> >(15, std::vector<QPushButton*>(15, NULL));

    _sightGrid = new QGridLayout();
    _sightGrid->setSpacing(0);
    _sightGrid->setContentsMargins(0,0,0,0);

    for(int i=0;i<15;++i){
        for(int j=0;j<15;++j){
             QPushButton *cell  = new QPushButton();
             buttonGrid[i][j]=cell;
             _sightGrid->addWidget(cell,i,j);
             buttonGrid[i][j]->setEnabled(false);
             buttonGrid[i][j]->setFixedSize(35,30);
             buttonGrid[i][j]->setStyleSheet("background-color:gray");
        }
    }

    vLayout->addLayout(_sightGrid);
    setLayout(vLayout);

    QMessageBox::information(this,trUtf8("Info"), trUtf8("You are the red square."));
    QMessageBox::information(this,trUtf8("Info"), trUtf8("Yellow squares are the parts that your torch's light shows you"));
    QMessageBox::information(this,trUtf8("Info"), trUtf8("Gray squares are either walls or the dark parts you don't see yet"));
    QMessageBox::information(this,trUtf8("Info"), trUtf8("Use the 'wasd' keys to move (w-up,s-down,a-left,d-right)"));
    QMessageBox::information(this,trUtf8("Info"), trUtf8("Press the Stop/start button to pause the game and to continue"));

}

GameWindow::~GameWindow(){

    delete _gameManager;
}

void GameWindow::keyPressEvent(QKeyEvent *event){
    if(event->key() == Qt::Key_A){
        _gameManager->stepLeft();
    }
    else if(event->key() == Qt::Key_D){
        _gameManager->stepRight();
    }
    else if(event->key() == Qt::Key_W){
        _gameManager->stepUp();
    }
    else if(event->key() == Qt::Key_S){
        _gameManager->stepDown();
    }
}

void GameWindow::startNewGame(){

    if (QObject::sender() == _fiveButton){

        _gameManager->newGame(9);
        for(int i=0;i<buttonGrid.size();++i){
            for(int j=0;j<buttonGrid.size();++j){
                _sightGrid->removeWidget(buttonGrid[j][i]);
                delete buttonGrid[j][i];
            }
        }

        buttonGrid = std::vector<std::vector<QPushButton*> >(5, std::vector<QPushButton*>(5, NULL));
        for(int i=0;i<5;++i){
            for(int j=0;j<5;++j){
                 QPushButton *cell  = new QPushButton();

                 buttonGrid[j][i]=cell;
                 _sightGrid->addWidget(cell,i,j);
                 buttonGrid[j][i]->setEnabled(false);
                 buttonGrid[j][i]->setFixedSize(110,80);
            }
        }

        GameWindow::adjustSize();
        GameWindow::viewUpdate();
    }
    else if (QObject::sender() == _tenButton){

        _gameManager->newGame(14);

        for(int i=0;i<buttonGrid.size();++i){
            for(int j=0;j<buttonGrid.size();++j){
                _sightGrid->removeWidget(buttonGrid[j][i]);
                delete buttonGrid[j][i];
            }
        }
        buttonGrid = std::vector<std::vector<QPushButton*> >(10, std::vector<QPushButton*>(10, NULL));
        for(int i=0;i<10;++i){
            for(int j=0;j<10;++j){
                 QPushButton *cell  = new QPushButton();

                 buttonGrid[j][i]=cell;
                 _sightGrid->addWidget(cell,i,j);
                 buttonGrid[j][i]->setEnabled(false);
                 //buttonGrid[j][i]->setFixedSize(45,40);
            }
        }
        GameWindow::adjustSize();
        GameWindow::viewUpdate();
    }
    else{

        _gameManager->newGame(19);

        for(int i=0;i<buttonGrid.size();++i){
            for(int j=0;j<buttonGrid.size();++j){
                _sightGrid->removeWidget(buttonGrid[j][i]);
                delete buttonGrid[j][i];
            }
        }
        buttonGrid = std::vector<std::vector<QPushButton*> >(15, std::vector<QPushButton*>(15, NULL));
        for(int i=0;i<15;++i){
            for(int j=0;j<15;++j){
                 QPushButton *cell  = new QPushButton();

                 buttonGrid[j][i]=cell;
                 _sightGrid->addWidget(cell,i,j);
                 buttonGrid[j][i]->setEnabled(false);
                 //buttonGrid[j][i]->setFixedSize(25,20);
            }
        }
        GameWindow::adjustSize();
        GameWindow::viewUpdate();
    }
    _pauseButton->setEnabled(true);
}


void GameWindow::viewUpdate(){
    for(int i=0;i<buttonGrid.size();++i){
        for(int j=0;j<buttonGrid.size();++j){

            if(_gameManager->getGridData(j+2,i+2)==GameManager::PLAYER)
            {
                buttonGrid[j][i]->setStyleSheet("background-color:red");
            }
            if(_gameManager->getGridData(j+2,i+2)==GameManager::DARK)
            {
                buttonGrid[j][i]->setStyleSheet("background-color:gray");
            }
            if(_gameManager->getGridData(j+2,i+2)==GameManager::WALL)
            {
                buttonGrid[j][i]->setStyleSheet("background-color:gray");
            }
            if(_gameManager->getGridData(j+2,i+2)==GameManager::LIGHT)
            {
                buttonGrid[j][i]->setStyleSheet("background-color:yellow");
            }
        }
    }
}

void GameWindow::doTimerUpdate(){

    _timerLabel->setText("Timer: "+ QString::number(_gameManager->gameTime));
}

void GameWindow::gameManager_gameOver(int seconds){

        QMessageBox::information(this, trUtf8("Game over"), trUtf8("You played ") + QString::number(seconds) + trUtf8(" seconds" ));
}
void GameWindow::pauseMsg(){
    QMessageBox::information(this,trUtf8("Game is paused "), trUtf8("Reminder:Use the 'wasd' keys to move (w-up,s-down,a-left,d-right)"));
}
