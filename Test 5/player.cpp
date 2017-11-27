#include "player.h"

void setupPlayer( SCharacter* playerCharacter ) {
    playerCharacter->Position.PositionDeltas = {0,0};
    playerCharacter->Position.Speed = 8.0f;

    playerCharacter->CurrentPoints.HP = 100;
    playerCharacter->Position.x = 5;
    playerCharacter->Position.z = 5;
}

void updatePlayer( SCharacter* playerCharacter, float fLastFrameTime, int keyPress  ) {
    SVector2D* playerDelta = &playerCharacter->Position.PositionDeltas; 
    float deltaP = playerCharacter->Position.Speed * fLastFrameTime; 

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
        playerCharacter->Position.Direction = SVector2D(1, 0).angleWith(dir);

        if( dir.y < 0 ) // negate rotation if more than 180º
            playerCharacter->Position.Direction *= 1;
 
        float fSpeed =  keyPress == 122 ? playerCharacter->Position.Speed*1.5f : playerCharacter->Position.Speed;    
        dir.Scale(fSpeed*fLastFrameTime);

        playerCharacter->Position.PositionDeltas = playerCharacter->Position.PositionDeltas + dir;
    }

    refreshPosFromDeltas( &playerCharacter->Position );
}
