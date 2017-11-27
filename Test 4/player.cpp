#include "player.h"

void setupPlayer( SCharacter* playerCharacter ) {
    playerCharacter->PositionDeltas = {0,0};
    playerCharacter->speed = 8.0f;

    playerCharacter->CurrentPoints.HP = 100;
    playerCharacter->x = 5;
    playerCharacter->z = 5;
}

void updatePlayer( SCharacter* playerCharacter, float fLastFrameTime, int keyPress  ) {
    SVector2D* playerDelta = &playerCharacter->PositionDeltas; 
    float deltaP = playerCharacter->speed * fLastFrameTime; 

    SVector2D dir = SVector2D(0,0);
    if(keyPress == 65)
        dir.y--;
    if(keyPress == 66)
        dir.y++;
    if(keyPress == 67)
        dir.x++;
    if(keyPress == 68)
        dir.x--;

    if (dir.x != 0 || dir.y != 0) {
        playerCharacter->Direction = SVector2D(1, 0).angleWith(dir);

        if( dir.y < 0 ) // negate rotation if more than 180º
            playerCharacter->Direction *= -1;
 
        float fSpeed =  keyPress == 90 ? playerCharacter->speed*1.5f : playerCharacter->speed;    
        dir.Scale(fSpeed*fLastFrameTime);

        playerCharacter->PositionDeltas = playerCharacter->PositionDeltas + dir;
    }

    refreshPosFromDeltas( playerCharacter );
}
