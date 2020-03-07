#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <graphics.h>

#include "Interface.h"













int main()
{
	MUSIC music; 
	//initialize game
    initgraph(750, 800);
    PIMAGE pLoad = newimage();
    getimage(pLoad, "img\\loading.jpg",0,0);
    putimage(0, 0, pLoad);
    delimage(pLoad);
    delay_ms(500); 
    music.OpenFile("background music.mp3");
    music.Play();
    if (music.GetPlayStatus() == MUSIC_MODE_STOP) {
	music.Play(0);
    }
    homeMenu();
    
    //
    
    
    //end game 
    cleardevice();
    closegraph();
    return 0;
}

