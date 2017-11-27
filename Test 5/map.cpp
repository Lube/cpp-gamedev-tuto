#include "map.h"
  
void drawMap(SMap activeMap, SCharacter Player) { 
    char imageMap[4096]={}; 
    int  nImageCursor = 0;

    for( int z=0; z< activeMap.Depth; z++ ) {
        for( int x=0; x< activeMap.Width; x++ ) { 
            if( Player.Position.x == x && Player.Position.z == z )
                imageMap[nImageCursor++] = 'P'; 
            else if( activeMap.EnemyCells[z][x] != INVALID_ENEMY ) 
                imageMap[nImageCursor++] = 'R';
            else if( activeMap.ShootCells[z][x] )  
                imageMap[nImageCursor++] = 'X';
            else
                imageMap[nImageCursor++] = activeMap.FloorCells[z][x] ?  activeMap.FloorCells[z][x] : ' ';
        }
        imageMap[nImageCursor++] = '\r';
        imageMap[nImageCursor++] = '\n';
    }
    imageMap[nImageCursor] = 0;
    printf( "%s", imageMap );
};

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