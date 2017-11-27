#include "character.h"

void updatePlayer (SCharacter* Player, int keyPress) {
    if(keyPress == 65)
        Player->z -= 1;
    if(keyPress == 66)
        Player->z += 1;
    if(keyPress == 67)
        Player->x ++;
    if(keyPress == 68)
        Player->x --;
}

void updateEnemy (SCharacter* Enemy, SCharacter* Player) { 
    if(Player->x < Enemy->x )
        Enemy->x -=1; 
    else if( Player->x > Enemy->x )
        Enemy->x +=1; 
    if(Player->z < Enemy->z )
        Enemy->z -= 1; 
    else if(Player->z > Enemy->z )
        Enemy->z += 1;

    if(Player->z == Enemy->z 
        && Player->x == Enemy->x )
    {
        Player->CurrentPoints.HP    -= 1;  
        Enemy->x = rand() % 15;
        Enemy->z = rand() % 15; 
    }
}

void updateEnemies (std::vector<SCharacter>* Enemies, SCharacter* Player) {
    for( unsigned int iEnemy=0; iEnemy < Enemies->size(); iEnemy++ ) {
        updateEnemy(&Enemies->at(iEnemy), Player);
    }
}