#include "character.h"

void updateEnemy( SCharacter* enemyCharacter, float fLastFrameTime, SCharacter* playerCharacter  ) {
    SVector2D* enemyDelta = &enemyCharacter->PositionDeltas; 
    float deltaP = enemyCharacter->speed * fLastFrameTime; 

    if(playerCharacter->x < enemyCharacter->x )
        enemyDelta->x -= deltaP; 
    else if( playerCharacter->x > enemyCharacter->x )
        enemyDelta->x += deltaP; 
    if(playerCharacter->z < enemyCharacter->z )
        enemyDelta->y -= deltaP; 
    else if(playerCharacter->z > enemyCharacter->z )
        enemyDelta->y += deltaP;

    refreshPosFromDeltas( enemyCharacter );

    if (playerCharacter->x == enemyCharacter->x && playerCharacter->z == enemyCharacter->z) {
        playerCharacter->CurrentPoints.HP -= 1;
    }
}

void refreshPosFromDeltas (SCharacter* playerCharacter) {
    SVector2D* charDeltas = &playerCharacter->PositionDeltas;
    
    while( charDeltas->x >= 1.0f ) {
        playerCharacter->x += 1.0f;
        charDeltas->x -= 1.0f; 
    }

    while( charDeltas->x < 0.0f ) {
        playerCharacter->x -= 1;
        charDeltas->x += 1.0f;
    }  

    while( charDeltas->y >= 1.0f ) {
        playerCharacter->z += 1.0f;
        charDeltas->y -= 1.0f; 
    }

    while( charDeltas->y < 0.0f ) {
        playerCharacter->z -= 1;
        charDeltas->y += 1.0f;
    }

}

void updateEnemies (std::vector<SCharacter>* Enemies, SCharacter* Player,float fLastFrameTime) {
    for( unsigned int iEnemy=0; iEnemy < Enemies->size(); iEnemy++ ) {
        updateEnemy(&Enemies->at(iEnemy), fLastFrameTime, Player);
    }
}