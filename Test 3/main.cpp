#include <stdio.h>     
#include "conio.h"  
#include "character.h"
#include "map.h"
#include "game.h"
#include <vector>

void setup( SGame* gameObject ) {   
    setTerminalCONIOMode();
    initMap(&gameObject->Map, 15, 15);
    setupEnemies(gameObject);

    gameObject->Player.CurrentPoints.HP = 100;
    gameObject->Player.x = 5;
    gameObject->Player.z = 5;
};  

void update(SGame* gameObject, int lastKeyPress) {
    for( int z = 0; z < gameObject->Map.Depth; z++ ) // clear each row
       memset( gameObject->Map.EnemyCells[z], INVALID_ENEMY, sizeof(int)*gameObject->Map.Width );

    for( unsigned int iEnemy=0; iEnemy < gameObject->Enemy.size(); iEnemy++ ) {
        SCharacter currentEnemy = gameObject->Enemy[iEnemy];
        gameObject->Map.EnemyCells[currentEnemy.z][currentEnemy.x] = iEnemy;
    }

    updateEnemies(&gameObject->Enemy, &gameObject->Player);
    updatePlayer(&gameObject->Player, lastKeyPress);
};
 

void draw(SGame gameObject) {
    drawMap(gameObject.Map, gameObject.Player); 
};
 
int main( void )
{
    SMap gameMap;
    SCharacter playerCharacter;

    SGame game = { gameMap, playerCharacter };

    setup(&game);
    
    int frameCounter=0;
    int lastKeyPress=0;
    
    while( true ) {        
        printf("Current player hp: %d\r\n", game.Player.CurrentPoints.HP); 
        lastKeyPress = getAsyncKeyState();   

        update(&game, lastKeyPress);
        draw(game);
        if(lastKeyPress == 27) {
            break; 
        }

        usleep(50000);
  
        frameCounter = frameCounter+1;
    };
    
    return 0;
}