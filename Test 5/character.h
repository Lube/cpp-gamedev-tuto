#ifndef CHARACTER_H
#define CHARACTER_H

#include "conio.h"
#include "point.h"
#include "particle.h"
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
    SMovingObject Position;
    SCharacterLevelValues MaxPoints;
    SCharacterLevelValues CurrentPoints;
}; 

void updateEnemies (std::vector<SCharacter>*, SCharacter*, float); 

void refreshPosFromDeltas (SMovingObject*);

#endif