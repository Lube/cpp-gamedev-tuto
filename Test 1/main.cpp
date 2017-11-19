#include <stdio.h>      
#include "conio.h"

void setup()
{
    setTerminalCONIOMode();
    printf("- setup() called.\r\n");
};

void update()
{
    printf("- update() called.\r\n");
};

void draw()
{
    printf("- draw() called.\r\n");
};

int main( void )
{
    setup();
    
    int frameCounter=0;
    
    while( true )
    {        
        printf("Current frame number: %i\r\n", frameCounter);        

        update();
        draw();
        if(getAsyncKeyState(27))
        {
            break;
        }
        usleep(50000);
  
        frameCounter = frameCounter+1;
    };
    
    return 0;
}