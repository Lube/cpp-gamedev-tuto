#include <stdio.h>     
#include "conio.h"

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

void setup( SMap* activeMap ) {   
    setTerminalCONIOMode();
    
    activeMap->Width = 15;      
    activeMap->Depth = 15;
    SMap* gameMapAddress = activeMap;

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
};

void update(SMap* activeMap) {
};

void draw(SMap activeMap) {
    for( int z=0; z< activeMap.Depth; z++ ) {
        for( int x=0; x< activeMap.Width; x++ ) {
            printf( "%d", activeMap.FloorCells[z][x] );
        }
        printf( "\r\n" );
    }
};

int main( void )
{
    SMap gameMap;
    setup(&gameMap);
    
    int frameCounter=0;
    
    while( true )
    {        
        printf("Current frame number: %i\r\n", frameCounter);        

        update(&gameMap);
        draw(gameMap);
        if(getAsyncKeyState(27))
        {
            break;
        }
        usleep(50000);
  
        frameCounter = frameCounter+1;
    };
    
    return 0;
}