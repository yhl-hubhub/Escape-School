#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <graphics.h>

#include "Interface.h"













int main()
{
	//initialize game
    initgraph(550, 550);
    loadMenu();
    delay_ms(800); 
    homeMenu();
    
    //
    
    
    //end game 
    cleardevice();
    closegraph();
    return 0;
}

