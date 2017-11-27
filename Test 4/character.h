#ifndef CHARACTER_H
#define CHARACTER_H

#include "conio.h"
#include "point.h"
#include <stdlib.h>
#include <vector>

#define INVALID_ENEMY 99

struct SCharacterLevelValues {
    int HP;
    int MP; 
    int XP;
};

struct SCharacter
{
    SCharacterLevelValues MaxPoints;
    SCharacterLevelValues CurrentPoints;
    SVector2D PositionDeltas;
    int x, z;
    float speed;
}; 

void updateEnemies (std::vector<SCharacter>*, SCharacter*, float); 
void refreshPosFromDeltas (SCharacter*);

#endif