#include "game.h"

void setupEnemies( SGame* gameObject ) {
    for( int iEnemy=0; iEnemy < INITIAL_ENEMY_COUNT; iEnemy++ )
    {
        SCharacter newEnemy;  
        newEnemy.MaxPoints        = { 100, 50, 1000000 };
        newEnemy.CurrentPoints    = { 100, 50, 0 };
        newEnemy.x = rand() % gameObject->Map.Width;
        newEnemy.z = rand() % gameObject->Map.Depth;

        gameObject->Enemy.push_back( newEnemy );
    }
};