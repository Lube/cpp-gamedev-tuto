#ifndef GAME_H
#define GAME_H

#include "character.h"
#include "map.h"
#include <stdlib.h>
#include <vector>

#define INITIAL_ENEMY_COUNT 4

struct SGame
{
    SMap Map;
    SCharacter Player;
    std::vector<SCharacter> Enemy; 
}; 

void setupEnemies( SGame* );

#endif