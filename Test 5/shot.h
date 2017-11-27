#ifndef SHOT_H
#define SHOT_H

#include "particle.h"
#include "character.h"
#include "map.h"
#include <stdlib.h>
#include <vector>

#define INVALID_SHOT false

struct SShot
{
    SMovingObject Position;
    int Damage;
};

void updateShots(SMap, SCharacter*, std::vector<SShot>*, std::vector<SCharacter>*, float);
void createShot(SCharacter, std::vector<SShot>*, int);

#endif