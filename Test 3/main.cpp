#include <stdio.h>     
#include "conio.h"  
#include "character.h"
#include "map.h"

void setup( SMap* activeMap, SCharacter* player, SCharacter* enemy ) {   
    setTerminalCONIOMode();
    initMap(activeMap, 15, 15);

    player->HP = 100; enemy->HP = 100;    
    player->x = 5, player->z = 5;
    enemy->x = 5, enemy->z = 10;
};  

void update(SMap* activeMap, SCharacter* player, SCharacter* enemy) {
    if( player->x < enemy->x )
        enemy->x = enemy->x-1; 
    else if( player->x > enemy->x )
        enemy->x = enemy->x+1; 

    if( player->z < enemy->z )
        enemy->z = enemy->z-1; 
    else if( player->z > enemy->z )
        enemy->z = enemy->z+1;

    if( player->z == enemy->z 
        && player->x == enemy->x )
    {
        player->HP    -= 1; 
        enemy->x = rand()%activeMap->Width, enemy->z = rand()%activeMap->Depth; 
    } 
};

void draw(SMap activeMap, SCharacter player, SCharacter enemy) {
    for( int z=0; z< activeMap.Depth; z++ ) {
        for( int x=0; x< activeMap.Width; x++ ) {
            if( player.x == x && player.z == z )
                    printf( "%c", 'P' ); 
            else if( enemy.x == x && enemy.z == z )
                printf( "%c", 'E' ); 
            else
                printf( "%d", activeMap.FloorCells[z][x] );
        }
        printf( "\r\n" );
    }
};

int main( void )
{
    SMap gameMap;
    SCharacter playerCharacter;
    SCharacter enemyCharacter;

    setup(&gameMap, &playerCharacter, &enemyCharacter);
    
    int frameCounter=0;
    
    while( true ) {        
        printf("Current frame number: %i\r\n", frameCounter);    

        update(&gameMap, &playerCharacter, &enemyCharacter);
        draw(gameMap, playerCharacter, enemyCharacter);

        if(getAsyncKeyState(27)) {
            break;
        }

        usleep(50000);
  
        frameCounter = frameCounter+1;
    };
    
    return 0;
}