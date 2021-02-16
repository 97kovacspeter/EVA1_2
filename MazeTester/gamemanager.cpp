#include "gamemanager.h"
#include <fstream>


GameManager::GameManager(){

    _timer = new QTimer();
    connect(_timer, SIGNAL(timeout()), this, SLOT(timerUpdate()));
}

void GameManager::filereader(std::string filename, int size){

    std::ifstream in (filename.c_str());
    int temp=0;
    for(int i=0;i<2;++i){
        for(int j=0;j<size;++j){
            grid[j][i]=WALL;
        }
    }
    for(int i=size-2;i<size;++i){
        for(int j=0;j<size;++j){
            grid[j][i]=WALL;
        }
    }
    for(int j=0;j<2;++j){
        for(int i=0;i<size;++i){
            grid[j][i]=WALL;
        }
    }
    for(int j=size-2;j<size;++j){
        for(int i=0;i<size;++i){
            grid[j][i]=WALL;
        }
    }
    for(int i=2;i<size-2;++i){
        for(int j=2;j<size-2;++j){
            in>>temp;
            if(temp==1){
                grid[j][i]=WALL;
            }
            else if(temp==0){
                grid[j][i]=DARK;
            }
        }
    }
    grid[2][size-3]=PLAYER;

    stepGame(0,0);

}

void GameManager::newGame(int size){

    _timer->start(1000);

    gameTime  = 0;

    grid = std::vector<std::vector<Cell> >(size, std::vector<Cell>(size, DARK));

    position.x=2;
    position.y=size-3; //positioning to left bottom corner

    if(size==9){

        filereader("../five.txt",9);
    }
    else if(size==14){

        filereader("../ten.txt",14);
    }
    else if(size==19){

        filereader("../fifteen.txt",19);
    }

}

void GameManager::pauseGame(){

    if (_timer->isActive()){
        _timer->stop();
        pause();
    }
    else
        _timer->start();
}

void GameManager::stepGame(int dirx, int diry){

   if (_timer->isActive()){
        grid[position.x][position.y]=DARK;
        position.x+=dirx;
        position.y+=diry;
        grid[position.x][position.y]=PLAYER;


        if(position.x==grid.size()-3 && position.y==2){

            _timer->stop();
            gameOver(gameTime);

        }
        //line of sight
        for(int i=2;i<grid.size()-2;++i){
            for(int j=2;j<grid.size()-2;++j){
                if(grid[j][i]!=WALL && grid[j][i]!=PLAYER){
                    grid[j][i]=DARK;
                }
            }
        }
        if(grid[position.x+1][position.y]==DARK){
            grid[position.x+1][position.y]=LIGHT;
            if(grid[position.x+2][position.y]==DARK){
                grid[position.x+2][position.y]=LIGHT;
                if(grid[position.x+2][position.y+1]==DARK){
                    grid[position.x+2][position.y+1]=LIGHT;
                }
                if(grid[position.x+2][position.y-1]==DARK){
                    grid[position.x+2][position.y-1]=LIGHT;
                }
            }
            if(grid[position.x+1][position.y+1]==DARK){
                grid[position.x+1][position.y+1]=LIGHT;
                if(grid[position.x+2][position.y+2]==DARK){
                    grid[position.x+2][position.y+2]=LIGHT;
                }
                if(grid[position.x+2][position.y+1]==DARK){
                    grid[position.x+2][position.y+1]=LIGHT;
                }
                if(grid[position.x+1][position.y+2]==DARK){
                    grid[position.x+1][position.y+2]=LIGHT;
                }
            }
            if(grid[position.x+1][position.y-1]==DARK){
                grid[position.x+1][position.y-1]=LIGHT;
                if(grid[position.x+2][position.y-2]==DARK){
                    grid[position.x+2][position.y-2]=LIGHT;
                }
                if(grid[position.x+2][position.y+1]==DARK){
                    grid[position.x+2][position.y+1]=LIGHT;
                }
                if(grid[position.x+2][position.y+2]==DARK){
                    grid[position.x+2][position.y+2]=LIGHT;
                }
            }
        }
        if(grid[position.x-1][position.y]==DARK){
            grid[position.x-1][position.y]=LIGHT;
            if(grid[position.x-2][position.y]==DARK){
                grid[position.x-2][position.y]=LIGHT;
                if(grid[position.x-2][position.y+1]==DARK){
                    grid[position.x-2][position.y+1]=LIGHT;
                }
                if(grid[position.x-2][position.y-1]==DARK){
                    grid[position.x-2][position.y-1]=LIGHT;
                }
            }
            if(grid[position.x-1][position.y+1]==DARK){
                grid[position.x-1][position.y+1]=LIGHT;
                if(grid[position.x-2][position.y+2]==DARK){
                    grid[position.x-2][position.y+2]=LIGHT;
                }
                if(grid[position.x-2][position.y+1]==DARK){
                    grid[position.x-2][position.y+1]=LIGHT;
                }
                if(grid[position.x-2][position.y+2]==DARK){
                    grid[position.x-2][position.y+2]=LIGHT;
                }
            }
            if(grid[position.x-1][position.y-1]==DARK){
                grid[position.x-1][position.y-1]=LIGHT;
                if(grid[position.x-2][position.y-2]==DARK){
                    grid[position.x-2][position.y-2]=LIGHT;
                }
                if(grid[position.x-1][position.y-2]==DARK){
                    grid[position.x-1][position.y-2]=LIGHT;
                }
                if(grid[position.x-2][position.y-1]==DARK){
                    grid[position.x-2][position.y-1]=LIGHT;
                }
            }
        }
        if(grid[position.x][position.y-1]==DARK){
            grid[position.x][position.y-1]=LIGHT;
            if(grid[position.x][position.y-2]==DARK){
                grid[position.x][position.y-2]=LIGHT;
                if(grid[position.x-1][position.y-2]==DARK){
                    grid[position.x-1][position.y-2]=LIGHT;
                }
                if(grid[position.x+1][position.y-2]==DARK){
                    grid[position.x+1][position.y-2]=LIGHT;
                }
            }
            if(grid[position.x+1][position.y-1]==DARK){
                grid[position.x+1][position.y-1]=LIGHT;
                if(grid[position.x+2][position.y-2]==DARK){
                    grid[position.x+2][position.y-2]=LIGHT;
                }
                if(grid[position.x+2][position.y-1]==DARK){
                    grid[position.x+2][position.y-1]=LIGHT;
                }
                if(grid[position.x+1][position.y-2]==DARK){
                    grid[position.x+1][position.y-2]=LIGHT;
                }
            }
            if(grid[position.x-1][position.y-1]==DARK){
                grid[position.x-1][position.y-1]=LIGHT;
                if(grid[position.x-2][position.y-2]==DARK){
                    grid[position.x-2][position.y-2]=LIGHT;
                }
                if(grid[position.x-1][position.y-2]==DARK){
                    grid[position.x-1][position.y-2]=LIGHT;
                }
                if(grid[position.x-2][position.y-1]==DARK){
                    grid[position.x-2][position.y-1]=LIGHT;
                }
            }

        }
        if(grid[position.x][position.y+1]==DARK){
            grid[position.x][position.y+1]=LIGHT;
            if(grid[position.x][position.y+2]==DARK){
                grid[position.x][position.y+2]=LIGHT;
                if(grid[position.x-1][position.y+2]==DARK){
                    grid[position.x-1][position.y+2]=LIGHT;
                }
                if(grid[position.x+1][position.y+2]==DARK){
                    grid[position.x+1][position.y+2]=LIGHT;
                }
            }
            if(grid[position.x+1][position.y+1]==DARK){
                grid[position.x+1][position.y+1]=LIGHT;
                if(grid[position.x+2][position.y+2]==DARK){
                    grid[position.x+2][position.y+2]=LIGHT;
                }
                if(grid[position.x+2][position.y+1]==DARK){
                    grid[position.x+2][position.y+1]=LIGHT;
                }
                if(grid[position.x+1][position.y+2]==DARK){
                    grid[position.x+1][position.y+2]=LIGHT;
                }
            }
            if(grid[position.x-1][position.y+1]==DARK){
                grid[position.x-1][position.y+1]=LIGHT;
                if(grid[position.x-2][position.y+2]==DARK){
                    grid[position.x-2][position.y+2]=LIGHT;
                }
                if(grid[position.x-1][position.y+2]==DARK){
                    grid[position.x-1][position.y+2]=LIGHT;
                }
                if(grid[position.x-2][position.y+1]==DARK){
                    grid[position.x-2][position.y+1]=LIGHT;
                }
            }
        }

    viewSignal();
   }
}

void GameManager::stepRight(){
    if(position.x<grid.size()-3 && grid[position.x+1][position.y]!=WALL)
         GameManager::stepGame(1,0);
}

void GameManager::stepLeft(){
    if(position.x>2 && grid[position.x-1][position.y]!=WALL)
        GameManager::stepGame(-1,0);
}

void GameManager::stepDown(){
    if(position.y<grid.size()-3 && grid[position.x][position.y+1]!=WALL)
         GameManager::stepGame(0,+1);
}

void GameManager::stepUp(){
    if(position.y>2 && grid[position.x][position.y-1]!=WALL)
         GameManager::stepGame(0,-1);
}

int GameManager::gridSize(){
    return grid.size();
}

GameManager::Cell GameManager::getGridData(int x,int y){
    if(x<0 || x>=grid.size())
        return WALL;
    if(y<0 || y>=grid.size())
        return WALL;
    else
        return grid[x][y];
}

void GameManager::timerUpdate(){

     gameTime++;
     update();
}

GameManager::~GameManager(){

    _timer->stop();
    delete _timer;
}
