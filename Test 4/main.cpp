#include <stdio.h>   
#include <math.h>
#include <vector>

#include "conio.h"  
#include "character.h"
#include "map.h"
#include "game.h"
#include "timer.h"
#include "player.h"

void setup( SGame* gameObject ) {   
    setTerminalCONIOMode();
    initMap(&gameObject->Map, 15, 15);
    setupEnemies(gameObject);
    setupPlayer(&gameObject->Player);
};  

void update(SGame* gameObject, int lastKeyPress, float lastFrameTime) {
    for( int z = 0; z < gameObject->Map.Depth; z++ ) // clear each row
       memset( gameObject->Map.EnemyCells[z], INVALID_ENEMY, sizeof(int)*gameObject->Map.Width );

    for( unsigned int iEnemy=0; iEnemy < gameObject->Enemy.size(); iEnemy++ ) {
        SCharacter currentEnemy = gameObject->Enemy[iEnemy];
        gameObject->Map.EnemyCells[currentEnemy.z][currentEnemy.x] = iEnemy;
    }

    updateEnemies(&gameObject->Enemy, &gameObject->Player, lastFrameTime);
    updatePlayer(&gameObject->Player, lastFrameTime, lastKeyPress);
}; 
 

void draw(SGame gameObject) {
    drawMap(gameObject.Map, gameObject.Player); 
};
 
int main( void )
{
    SMap gameMap;
    double timer;
    SCharacter playerCharacter;

    SGame game = { gameMap, playerCharacter };

    setup(&game);
    
    int frameCounter=0;
    int lastKeyPress=0;
    float lastFrameTime = frame(&timer);

    while( true ) {
        lastFrameTime = frame(&timer);
        SVector2D dirVector = SVector2D(1, 0).getVector(game.Player.Direction);
        float degrees = game.Player.Direction * (float)180 / M_PI; 

        printf("Current player hp: %d\r\n", game.Player.CurrentPoints.HP); 
        printf("Current frame number: %i\r\n"
        "Last frame time: %f\r\n", frameCounter, lastFrameTime); 
        printf( "Player direction: (%f, %f)\r\n"
            "Player angle: %f radians or %f degrees\r\n",
            dirVector.x, dirVector.y, game.Player.Direction, degrees );
          
        lastKeyPress = getAsyncKeyState(); 

        update(&game, lastKeyPress, lastFrameTime);
        draw(game);
        
        if(lastKeyPress == 27) {
            break; 
        }

        usleep(50000);
  
        frameCounter = frameCounter+1;
    };
    
    return 0;
}