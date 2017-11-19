#include "map.h"

void initMap(SMap* activeMap, int width, int height) {
    activeMap->Width = width;      
    activeMap->Depth = height;

    for( int z=0; z< activeMap->Depth; z = z+1 ) {
        for( int x=0; x< activeMap->Width; x++ ) {
            activeMap->FloorCells[z][x] = TILE_GRASS;
        }
    }

    for( int x=0; x< activeMap->Width; x++ ) {
        activeMap->FloorCells[0][x] = TILE_WALL; 
    }

    for( int x=0; x< activeMap->Width; x++ ) {
        activeMap->FloorCells[activeMap->Depth-1][x] = TILE_WALL;
    }

    for( int z=0; z< activeMap->Depth; z++ ) {
        activeMap->FloorCells[z][0] = TILE_WALL; 
    }

    for( int z=0; z< activeMap->Depth; z++ ) {
        activeMap->FloorCells[z][activeMap->Width-1] = TILE_WALL;
    }    
 }