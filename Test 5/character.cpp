#include "character.h"

void refreshPosFromDeltas (SMovingObject* position) {
    SVector2D* charDeltas = &position->PositionDeltas;
    
    while( charDeltas->x >= 1.0f ) {
        position->x += 1.0f;
        charDeltas->x -= 1.0f; 
    }

    while( charDeltas->x < 0.0f ) {
        position->x -= 1;
        charDeltas->x += 1.0f;
    }  

    while( charDeltas->y >= 1.0f ) {
        position->z += 1.0f;
        charDeltas->y -= 1.0f; 
    }

    while( charDeltas->y < 0.0f ) {
        position->z -= 1;
        charDeltas->y += 1.0f;
    }

}

void updateEnemy( SCharacter* enemyCharacter, float fLastFrameTime, SCharacter* playerCharacter  ) {
    SVector2D* enemyDelta = &enemyCharacter->Position.PositionDeltas; 
    float deltaP = enemyCharacter->Position.Speed * fLastFrameTime; 

    if(playerCharacter->Position.x < enemyCharacter->Position.x )
        enemyDelta->x -= deltaP; 
    else if( playerCharacter->Position.x > enemyCharacter->Position.x )
        enemyDelta->x += deltaP; 
    if(playerCharacter->Position.z < enemyCharacter->Position.z )
        enemyDelta->y -= deltaP; 
    else if(playerCharacter->Position.z > enemyCharacter->Position.z )
        enemyDelta->y += deltaP;

    refreshPosFromDeltas( &enemyCharacter->Position );

    if (playerCharacter->Position.x == enemyCharacter->Position.x && playerCharacter->Position.z == enemyCharacter->Position.z) {
        playerCharacter->CurrentPoints.HP -= 1;
    }

}

void updateEnemies (std::vector<SCharacter>* Enemies, SCharacter* Player,float fLastFrameTime) {
    for( unsigned int iEnemy=0; iEnemy < Enemies->size(); iEnemy++ ) {
        updateEnemy(&Enemies->at(iEnemy), fLastFrameTime, Player);

        if( Enemies->at(iEnemy).CurrentPoints.HP <= 0 )
        { 
            Player->CurrentPoints.XP += Enemies->at(iEnemy).MaxPoints.HP;
            Enemies->erase( Enemies->begin() + iEnemy );  
            continue;
        } 
    }
}