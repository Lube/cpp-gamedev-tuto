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
        newEnemy.Position.Speed = float(iEnemy) + 1;

        newEnemy.Position.x = rand() % gameObject->Map.Width;
        newEnemy.Position.z = rand() % gameObject->Map.Depth;
        newEnemy.Position.PositionDeltas = {0,0};

        gameObject->Enemy.push_back( newEnemy );
    }
};