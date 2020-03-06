#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <graphics.h>

#include "constant.h"
#include "interaction.h"
#include "Interface.h"
#include "Map.h"
/*******************************
  *Description：进入关卡后的控制函数
  *Last edited by: 席诗祺
*********************************/
void inLevel()
{  
    int dir,mstdir;
    PIMAGE img = newimage();
    getimage(img, "img\\di.jpg");
    putimage(0, 0, img);
    roleBlood=3;
    
	drawMap();
	getimage(img, "img\\ren.jpg");
	putimage(rx,ry,img);
	getimage(img, "img\\guaiwu1.jpg");
	putimage(mstx,msty,img);
	
    for ( ; is_run(); delay_fps(10))
    {
        //人物移动
        //怪物随机移动
        //判断是否相撞
		dir=roleMove();
		mstdir=mstMove();
        crashJudge(dir,mstdir);
        
        
        
        //判断是否吃完所有豆子，吃完进入下一关卡
        if(cntJudge==0)
        {
            //showScore();
            //进入下一关卡
            delay_ms(60);
            enterNext();
        }
        if(roleBlood==0)
        {
            //cleardevice();
            dieOver();
        }
        
    }

}
