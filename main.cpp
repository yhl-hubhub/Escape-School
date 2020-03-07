#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <graphics.h>

#include "Interface.h"













int main()
{
	//initialize game
    initgraph(800, 750);
    loadMenu();
    delay_ms(500); 
    homeMenu();
    
    //
    
    
    //end game 
    cleardevice();
    closegraph();
    return 0;
}

