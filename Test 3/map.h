#ifndef MAP_H
#define MAP_H

#include <stdio.h>
#include "character.h"

#define MAX_MAP_DEPTH 256
#define MAX_MAP_WIDTH 256
#define TILE_GRASS    0 
#define TILE_WALL     1 
#define TILE_WATER    2
#define TILE_LAVA     3

struct SMap {
    int Width; 
    int Depth;    
    char FloorCells[MAX_MAP_DEPTH][MAX_MAP_WIDTH]; 
    char EnemyCells[MAX_MAP_DEPTH][MAX_MAP_WIDTH];
};

void drawMap(SMap, SCharacter);  
void initMap(SMap*, int, int);

#endif