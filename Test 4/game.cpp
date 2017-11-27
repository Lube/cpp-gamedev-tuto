#include "game.h"

void setupEnemies( SGame* gameObject ) {
    for( int iEnemy=0; iEnemy < INITIAL_ENEMY_COUNT; iEnemy++ )
    {
        SCharacter newEnemy;  
        newEnemy.MaxPoints.HP = 100;
        newEnemy.MaxPoints.MP = 50;
        newEnemy.MaxPoints.XP = 1000000;

        newEnemy.CurrentPoints.HP = 100;
        newEnemy.CurrentPoints.MP = 50;
        newEnemy.CurrentPoints.XP = 0;
        newEnemy.speed = float(iEnemy) + 1;

        newEnemy.x = rand() % gameObject->Map.Width;
        newEnemy.z = rand() % gameObject->Map.Depth;
        newEnemy.PositionDeltas = {0,0};

        gameObject->Enemy.push_back( newEnemy );
    }
};