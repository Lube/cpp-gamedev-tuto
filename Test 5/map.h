#ifndef MAP_H
#define MAP_H

#include <stdio.h>
#include "character.h"

#define MAX_MAP_DEPTH 256
#define MAX_MAP_WIDTH 256
#define TILE_GRASS    ' ' 
#define TILE_WALL     'T' 
#define TILE_WATER    'W'
#define TILE_LAVA     'M'

struct SMap {
    int Width; 
    int Depth;    
    char FloorCells[MAX_MAP_DEPTH][MAX_MAP_WIDTH]; 
    char EnemyCells[MAX_MAP_DEPTH][MAX_MAP_WIDTH];
    bool ShootCells[MAX_MAP_DEPTH][MAX_MAP_WIDTH];
};

void drawMap(SMap, SCharacter);  
void initMap(SMap*, int, int);

#endif