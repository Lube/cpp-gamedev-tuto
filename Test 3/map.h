#ifndef MAP_H
#define MAP_H

#define MAX_MAP_DEPTH 256
#define MAX_MAP_WIDTH 256
#define TILE_GRASS    0 
#define TILE_WALL     1 
#define TILE_WATER    2
#define TILE_LAVA     3

struct SMap {
    int Width; 
    int Depth;    
    int FloorCells[MAX_MAP_DEPTH][MAX_MAP_WIDTH]; 
};

void initMap(SMap*, int, int);

#endif