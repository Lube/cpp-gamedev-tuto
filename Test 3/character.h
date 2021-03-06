#ifndef CHARACTER_H
#define CHARACTER_H

#include "conio.h"
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
    int x, z;
}; 

void updatePlayer (SCharacter*, int);
void updateEnemies (std::vector<SCharacter>*, SCharacter*); 

#endif