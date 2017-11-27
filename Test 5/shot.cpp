#include "shot.h"
#include "game.h"
#include "point.h"

void shoot( SGame* gameObject, SVector2D origin, float direction )
{
    SShot newShot;
    newShot.Damage           = 10; 
    newShot.Position.Speed            = 10.0f; 
    newShot.Position.PositionDeltas   = origin;
    newShot.Position.Direction        = direction;
    newShot.Position.x = newShot.Position.z = 0;
    refreshPosFromDeltas( &newShot.Position ); 
    gameObject->Shots.push_back( newShot );
}

void updateShots(SMap Mapa, SCharacter* Player, std::vector<SShot>* Shots, std::vector<SCharacter>* Enemys, float lastTimeFrame) {

    std::vector<SShot>::iterator iShot = Shots->begin();
    int indexShot = 0; 
    while( iShot != Shots->end() ) 
    {
        SShot* currentShot = &(*Shots)[indexShot];

        if( currentShot->Position.x < 0 || currentShot->Position.z < 0 
            || currentShot->Position.x >= Mapa.Width || currentShot->Position.z >= Mapa.Depth
        )
        {
            iShot = Shots->erase( iShot ); 
            continue; 
        }

        if( Mapa.EnemyCells[currentShot->Position.z][currentShot->Position.x] != INVALID_ENEMY )
        {
            (*Enemys)[Mapa.EnemyCells[currentShot->Position.z][currentShot->Position.x]].CurrentPoints.HP -= iShot->Damage; 
            Player->CurrentPoints.XP += iShot->Damage;
            iShot = Shots->erase( iShot ); 
            continue; 
        }

        SVector2D dirVector = SVector2D(1, 0).getVector( currentShot->Position.Direction );

        currentShot->Position.PositionDeltas.x += currentShot->Position.Speed*lastTimeFrame*dirVector.x; 
        currentShot->Position.PositionDeltas.y += currentShot->Position.Speed*lastTimeFrame*dirVector.y; 

        refreshPosFromDeltas( &currentShot->Position ); 

        iShot++;
        indexShot++; 
    }  
}

void createShot(SCharacter Player, std::vector<SShot>* Shots, int lastKeyPressed) {
    if (lastKeyPressed == 120) {
        SShot newShot;

        memcpy( &newShot.Position, &Player.Position, sizeof(SMovingObject));
        newShot.Damage = 10; 

        Shots->push_back( newShot );
    }
}
