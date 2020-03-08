#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <graphics.h>
#include "constant.h"
#include "Interface.h"


int main()
{
	//initialize game
    initialize();
    
	homeMenu();
    

    //end game 
    cleardevice();
    music.Close();
    closegraph();
    return 0;
}

