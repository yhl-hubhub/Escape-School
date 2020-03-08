#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <graphics.h>

#include "constant.h"
#include "interaction.h"
#include "Interface.h"
#include "Map.h"

#define BLR 15
#define BLC1 0
#define BLC2 1
#define BLC3 2


/*******************************
  *Description： 进入关卡后的控制函数
  *Last edited by: 王晓宇 
  *Edit time: 2020/3/7 20:50
*********************************/
void inLevel()
{  
    int dir,mstdir;//人怪的方向 
    int lcrash=0,//撞怪后一段时间内不再撞
	crash_image=1;//撞怪时人的图片会闪，奇数亮偶数灭 
    PIMAGE img=newimage();
    roleBlood=3;
    score=0;
	drawMap();
	getimage(img, "img\\ren.jpg");
	putimage(rx,ry,img);
	getimage(img, "img\\59分卷子.jpg");
	putimage(mstx,msty,img);
	
    for ( ; is_run(); delay_fps(10))//
    {
        //清空界面 
		cleardevice();
		//绘制地图 
		drawMap();
		//判断是否相撞
		if(lcrash) crash_image++;
		else crash_image=1;
		//人物移动
		dir=roleMove(dir,crash_image);
		//怪物随机移动
		mstdir=mstMove();
        
        //扣血 
        if(!lcrash&&crashJudge())
        {
        	if(roleBlood==3)
            {
                pMap[BLR][BLC3]=9;      
            }
            else if (roleBlood==2)
            {
                pMap[BLR][BLC2]=9;
            }
            else if (roleBlood==1)
            {
                pMap[BLR][BLC1]=9;
            }
            roleBlood--;
		}
	    lcrash=crashJudge();
         
        //判断是否吃完所有豆子，吃完进入下一关卡
//        if(cntJudge==0)
//        {
//            //进入下一关卡
//            delay_ms(60);
//            enterNext();
//        }
        if(roleBlood==0)
        {
            dieOver();
        }
        
        if(rx>=50&&rx<=100&&ry>=700&&ry<=750)
        {
        	gameOver();
		}
        
    }

}
