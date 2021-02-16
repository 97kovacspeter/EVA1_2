#include <QString>
#include <QtTest>
#include <QThread>
#include "gamemanager.h"

class MazeTester : public QObject
{
    Q_OBJECT

public:
    MazeTester();

private:
    GameManager* _gameManager;

private Q_SLOTS:
    void initTestCase();
    void cleanupTestCase();
    void testNewGame();
    void testStep();
    void testStepErrors();
};

MazeTester::MazeTester()
{
}

void MazeTester::initTestCase()
{
    _gameManager = new GameManager();
}

void MazeTester::cleanupTestCase()
{
    delete _gameManager;
}

void MazeTester::testNewGame()
{
        _gameManager->newGame(9);

        for(int i=0;i<2;++i){
            for(int j=0;j<9;++j){
                QCOMPARE(_gameManager->getGridData(j,i),GameManager::WALL);
            }
        }
        for(int i=7;i<9;++i){
            for(int j=0;j<9;++j){
                QCOMPARE(_gameManager->getGridData(j,i),GameManager::WALL);
            }
        }
        for(int j=0;j<2;++j){
            for(int i=0;i<9;++i){
                QCOMPARE(_gameManager->getGridData(j,i),GameManager::WALL);
            }
        }
        for(int j=7;j<9;++j){
            for(int i=0;i<9;++i){
                QCOMPARE(_gameManager->getGridData(j,i),GameManager::WALL);
            }
        }

        QCOMPARE(_gameManager->getGridData(20,20),GameManager::WALL);//way out of grid

        QCOMPARE(_gameManager->getGridData(3,3),GameManager::WALL);
        QCOMPARE(_gameManager->getGridData(4,3),GameManager::WALL);
        QCOMPARE(_gameManager->getGridData(5,3),GameManager::WALL);
        QCOMPARE(_gameManager->getGridData(6,3),GameManager::WALL);
        QCOMPARE(_gameManager->getGridData(2,5),GameManager::WALL);
        QCOMPARE(_gameManager->getGridData(3,5),GameManager::WALL);
        QCOMPARE(_gameManager->getGridData(5,5),GameManager::WALL);
        QCOMPARE(_gameManager->getGridData(6,6),GameManager::WALL);

        QCOMPARE(_gameManager->getGridData(3,6),GameManager::LIGHT);
        QCOMPARE(_gameManager->getGridData(4,6),GameManager::LIGHT);


        QCOMPARE(_gameManager->getGridData(2,6),GameManager::PLAYER);

}

void MazeTester::testStep(){

    _gameManager->newGame(9);
    _gameManager->stepRight();//test step to right

    for(int i=0;i<2;++i){
        for(int j=0;j<9;++j){
            QCOMPARE(_gameManager->getGridData(j,i),GameManager::WALL);
        }
    }
    for(int i=7;i<9;++i){
        for(int j=0;j<9;++j){
            QCOMPARE(_gameManager->getGridData(j,i),GameManager::WALL);
        }
    }
    for(int j=0;j<2;++j){
        for(int i=0;i<9;++i){
            QCOMPARE(_gameManager->getGridData(j,i),GameManager::WALL);
        }
    }
    for(int j=7;j<9;++j){
        for(int i=0;i<9;++i){
            QCOMPARE(_gameManager->getGridData(j,i),GameManager::WALL);
        }
    }

    QCOMPARE(_gameManager->getGridData(20,20),GameManager::WALL);//way out of grid

    QCOMPARE(_gameManager->getGridData(3,3),GameManager::WALL);
    QCOMPARE(_gameManager->getGridData(4,3),GameManager::WALL);
    QCOMPARE(_gameManager->getGridData(5,3),GameManager::WALL);
    QCOMPARE(_gameManager->getGridData(6,3),GameManager::WALL);
    QCOMPARE(_gameManager->getGridData(2,5),GameManager::WALL);
    QCOMPARE(_gameManager->getGridData(3,5),GameManager::WALL);
    QCOMPARE(_gameManager->getGridData(5,5),GameManager::WALL);
    QCOMPARE(_gameManager->getGridData(6,6),GameManager::WALL);

    QCOMPARE(_gameManager->getGridData(2,6),GameManager::LIGHT);
    QCOMPARE(_gameManager->getGridData(4,6),GameManager::LIGHT);
    QCOMPARE(_gameManager->getGridData(5,6),GameManager::LIGHT);
    QCOMPARE(_gameManager->getGridData(4,5),GameManager::LIGHT);


    QCOMPARE(_gameManager->getGridData(3,6),GameManager::PLAYER);



    _gameManager->stepRight();//test step to right

    for(int i=0;i<2;++i){
        for(int j=0;j<9;++j){
            QCOMPARE(_gameManager->getGridData(j,i),GameManager::WALL);
        }
    }
    for(int i=7;i<9;++i){
        for(int j=0;j<9;++j){
            QCOMPARE(_gameManager->getGridData(j,i),GameManager::WALL);
        }
    }
    for(int j=0;j<2;++j){
        for(int i=0;i<9;++i){
            QCOMPARE(_gameManager->getGridData(j,i),GameManager::WALL);
        }
    }
    for(int j=7;j<9;++j){
        for(int i=0;i<9;++i){
            QCOMPARE(_gameManager->getGridData(j,i),GameManager::WALL);
        }
    }


    QCOMPARE(_gameManager->getGridData(3,3),GameManager::WALL);
    QCOMPARE(_gameManager->getGridData(4,3),GameManager::WALL);
    QCOMPARE(_gameManager->getGridData(5,3),GameManager::WALL);
    QCOMPARE(_gameManager->getGridData(6,3),GameManager::WALL);
    QCOMPARE(_gameManager->getGridData(2,5),GameManager::WALL);
    QCOMPARE(_gameManager->getGridData(3,5),GameManager::WALL);
    QCOMPARE(_gameManager->getGridData(5,5),GameManager::WALL);
    QCOMPARE(_gameManager->getGridData(6,6),GameManager::WALL);

    QCOMPARE(_gameManager->getGridData(2,6),GameManager::LIGHT);
    QCOMPARE(_gameManager->getGridData(3,6),GameManager::LIGHT);
    QCOMPARE(_gameManager->getGridData(3,4),GameManager::LIGHT);
    QCOMPARE(_gameManager->getGridData(4,4),GameManager::LIGHT);
    QCOMPARE(_gameManager->getGridData(4,5),GameManager::LIGHT);
    QCOMPARE(_gameManager->getGridData(5,4),GameManager::LIGHT);
    QCOMPARE(_gameManager->getGridData(5,6),GameManager::LIGHT);

    QCOMPARE(_gameManager->getGridData(6,5),GameManager::DARK);//blocked square
    QCOMPARE(_gameManager->getGridData(2,4),GameManager::DARK);//blocked too


    QCOMPARE(_gameManager->getGridData(4,6),GameManager::PLAYER);


    _gameManager->stepUp();//test step upwards


    for(int i=0;i<2;++i){
        for(int j=0;j<9;++j){
            QCOMPARE(_gameManager->getGridData(j,i),GameManager::WALL);
        }
    }
    for(int i=7;i<9;++i){
        for(int j=0;j<9;++j){
            QCOMPARE(_gameManager->getGridData(j,i),GameManager::WALL);
        }
    }
    for(int j=0;j<2;++j){
        for(int i=0;i<9;++i){
            QCOMPARE(_gameManager->getGridData(j,i),GameManager::WALL);
        }
    }
    for(int j=7;j<9;++j){
        for(int i=0;i<9;++i){
            QCOMPARE(_gameManager->getGridData(j,i),GameManager::WALL);
        }
    }



    QCOMPARE(_gameManager->getGridData(3,3),GameManager::WALL);
    QCOMPARE(_gameManager->getGridData(4,3),GameManager::WALL);
    QCOMPARE(_gameManager->getGridData(5,3),GameManager::WALL);
    QCOMPARE(_gameManager->getGridData(6,3),GameManager::WALL);
    QCOMPARE(_gameManager->getGridData(2,5),GameManager::WALL);
    QCOMPARE(_gameManager->getGridData(3,5),GameManager::WALL);
    QCOMPARE(_gameManager->getGridData(5,5),GameManager::WALL);
    QCOMPARE(_gameManager->getGridData(6,6),GameManager::WALL);

    QCOMPARE(_gameManager->getGridData(2,4),GameManager::LIGHT);
    QCOMPARE(_gameManager->getGridData(2,6),GameManager::LIGHT);
    QCOMPARE(_gameManager->getGridData(3,4),GameManager::LIGHT);
    QCOMPARE(_gameManager->getGridData(3,6),GameManager::LIGHT);
    QCOMPARE(_gameManager->getGridData(4,4),GameManager::LIGHT);
    QCOMPARE(_gameManager->getGridData(4,6),GameManager::LIGHT);
    QCOMPARE(_gameManager->getGridData(5,4),GameManager::LIGHT);
    QCOMPARE(_gameManager->getGridData(5,6),GameManager::LIGHT);
    QCOMPARE(_gameManager->getGridData(6,4),GameManager::LIGHT);

    QCOMPARE(_gameManager->getGridData(6,5),GameManager::DARK);//blocked square


    QCOMPARE(_gameManager->getGridData(4,5),GameManager::PLAYER);


    _gameManager->stepDown();//steping down should make it back as it was


    for(int i=0;i<2;++i){
        for(int j=0;j<9;++j){
            QCOMPARE(_gameManager->getGridData(j,i),GameManager::WALL);
        }
    }
    for(int i=7;i<9;++i){
        for(int j=0;j<9;++j){
            QCOMPARE(_gameManager->getGridData(j,i),GameManager::WALL);
        }
    }
    for(int j=0;j<2;++j){
        for(int i=0;i<9;++i){
            QCOMPARE(_gameManager->getGridData(j,i),GameManager::WALL);
        }
    }
    for(int j=7;j<9;++j){
        for(int i=0;i<9;++i){
            QCOMPARE(_gameManager->getGridData(j,i),GameManager::WALL);
        }
    }


    QCOMPARE(_gameManager->getGridData(3,3),GameManager::WALL);
    QCOMPARE(_gameManager->getGridData(4,3),GameManager::WALL);
    QCOMPARE(_gameManager->getGridData(5,3),GameManager::WALL);
    QCOMPARE(_gameManager->getGridData(6,3),GameManager::WALL);
    QCOMPARE(_gameManager->getGridData(2,5),GameManager::WALL);
    QCOMPARE(_gameManager->getGridData(3,5),GameManager::WALL);
    QCOMPARE(_gameManager->getGridData(5,5),GameManager::WALL);
    QCOMPARE(_gameManager->getGridData(6,6),GameManager::WALL);

    QCOMPARE(_gameManager->getGridData(2,6),GameManager::LIGHT);
    QCOMPARE(_gameManager->getGridData(3,6),GameManager::LIGHT);
    QCOMPARE(_gameManager->getGridData(3,4),GameManager::LIGHT);
    QCOMPARE(_gameManager->getGridData(4,4),GameManager::LIGHT);
    QCOMPARE(_gameManager->getGridData(4,5),GameManager::LIGHT);
    QCOMPARE(_gameManager->getGridData(5,4),GameManager::LIGHT);
    QCOMPARE(_gameManager->getGridData(5,6),GameManager::LIGHT);

    QCOMPARE(_gameManager->getGridData(6,5),GameManager::DARK);//blocked square
    QCOMPARE(_gameManager->getGridData(2,4),GameManager::DARK);//blocked too


    QCOMPARE(_gameManager->getGridData(4,6),GameManager::PLAYER);


    _gameManager->stepUp();
    _gameManager->stepUp();//two upwards stepping because of the downstep before



    for(int i=0;i<2;++i){
        for(int j=0;j<9;++j){
            QCOMPARE(_gameManager->getGridData(j,i),GameManager::WALL);
        }
    }
    for(int i=7;i<9;++i){
        for(int j=0;j<9;++j){
            QCOMPARE(_gameManager->getGridData(j,i),GameManager::WALL);
        }
    }
    for(int j=0;j<2;++j){
        for(int i=0;i<9;++i){
            QCOMPARE(_gameManager->getGridData(j,i),GameManager::WALL);
        }
    }
    for(int j=7;j<9;++j){
        for(int i=0;i<9;++i){
            QCOMPARE(_gameManager->getGridData(j,i),GameManager::WALL);
        }
    }



    QCOMPARE(_gameManager->getGridData(3,3),GameManager::WALL);
    QCOMPARE(_gameManager->getGridData(4,3),GameManager::WALL);
    QCOMPARE(_gameManager->getGridData(5,3),GameManager::WALL);
    QCOMPARE(_gameManager->getGridData(6,3),GameManager::WALL);
    QCOMPARE(_gameManager->getGridData(2,5),GameManager::WALL);
    QCOMPARE(_gameManager->getGridData(3,5),GameManager::WALL);
    QCOMPARE(_gameManager->getGridData(5,5),GameManager::WALL);
    QCOMPARE(_gameManager->getGridData(6,6),GameManager::WALL);

    QCOMPARE(_gameManager->getGridData(2,3),GameManager::LIGHT);
    QCOMPARE(_gameManager->getGridData(2,4),GameManager::LIGHT);
    QCOMPARE(_gameManager->getGridData(2,6),GameManager::DARK); //should not see anymore
    QCOMPARE(_gameManager->getGridData(3,4),GameManager::LIGHT);
    QCOMPARE(_gameManager->getGridData(3,6),GameManager::LIGHT);
    QCOMPARE(_gameManager->getGridData(4,5),GameManager::LIGHT);
    QCOMPARE(_gameManager->getGridData(4,6),GameManager::LIGHT);
    QCOMPARE(_gameManager->getGridData(5,4),GameManager::LIGHT);
    QCOMPARE(_gameManager->getGridData(5,6),GameManager::LIGHT);
    QCOMPARE(_gameManager->getGridData(6,4),GameManager::LIGHT);

    QCOMPARE(_gameManager->getGridData(6,5),GameManager::LIGHT);//should not be blocked anymore


    QCOMPARE(_gameManager->getGridData(4,4),GameManager::PLAYER);



}

void MazeTester::testStepErrors(){

    _gameManager->newGame(9);
    _gameManager->stepUp();//test step upwards,should be blocked by wall, so everything remains same

    for(int i=0;i<2;++i){
        for(int j=0;j<9;++j){
            QCOMPARE(_gameManager->getGridData(j,i),GameManager::WALL);
        }
    }
    for(int i=7;i<9;++i){
        for(int j=0;j<9;++j){
            QCOMPARE(_gameManager->getGridData(j,i),GameManager::WALL);
        }
    }
    for(int j=0;j<2;++j){
        for(int i=0;i<9;++i){
            QCOMPARE(_gameManager->getGridData(j,i),GameManager::WALL);
        }
    }
    for(int j=7;j<9;++j){
        for(int i=0;i<9;++i){
            QCOMPARE(_gameManager->getGridData(j,i),GameManager::WALL);
        }
    }

    QCOMPARE(_gameManager->getGridData(20,20),GameManager::WALL);//way out of grid

    QCOMPARE(_gameManager->getGridData(3,3),GameManager::WALL);
    QCOMPARE(_gameManager->getGridData(4,3),GameManager::WALL);
    QCOMPARE(_gameManager->getGridData(5,3),GameManager::WALL);
    QCOMPARE(_gameManager->getGridData(6,3),GameManager::WALL);
    QCOMPARE(_gameManager->getGridData(2,5),GameManager::WALL);
    QCOMPARE(_gameManager->getGridData(3,5),GameManager::WALL);
    QCOMPARE(_gameManager->getGridData(5,5),GameManager::WALL);
    QCOMPARE(_gameManager->getGridData(6,6),GameManager::WALL);

    QCOMPARE(_gameManager->getGridData(3,6),GameManager::LIGHT);
    QCOMPARE(_gameManager->getGridData(4,6),GameManager::LIGHT);


    QCOMPARE(_gameManager->getGridData(2,6),GameManager::PLAYER);
}












QTEST_APPLESS_MAIN(MazeTester)

#include "tst_mazetester.moc"
