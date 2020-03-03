#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <graphics.h>
#include "Interface.h"
#include "constant.h"
#include "Map.h"

#define t1 20
#define t2 12
#define t3 10

void loadMenu();
void homeMenu();
void choice();
void introduce();
void enterNext();
void showScore();
void gameOver();
void showScore();


//加载界面
void loadMenu()
{
    PIMAGE pLoad = newimage();
    getimage(pLoad, "img\\load.jpg",0,0);
    putimage(0, 0, pLoad);
    delimage(pLoad);

}


//主界面
void homeMenu()
{
    PIMAGE istart = newimage();
    getimage(istart, "img\\start.jpg",0,0);
    putimage(0, 0, istart);
    delimage(istart);

    // 画帧率文字
    char str[20];
    sprintf(str, "fps %.02f", getfps()); //调用getfps取得当前帧率
    setcolor(WHITE);
    outtextxy(0, 0, str);

    //鼠标点击
    mouse_msg mMsg = {0};
    for ( ; is_run(); delay_fps(60))
    {
        //获取鼠标消息，这个函数会等待，等待到有消息为止
        while(mousemsg())
        {
            mMsg = getmouse();
        }
        
        //选择关卡
		if(mMsg.is_up()&&mMsg.is_left())//&&mMsg.x>140&&mMsg.x<335&&mMsg.y>260&&mMsg.y<300
        {
            choice();
        }
        
        //游戏说明（这个还没做） 
        else if(mMsg.is_up()&&mMsg.is_left()&&mMsg.x>140&&mMsg.x<335&&mMsg.y>340&&mMsg.y<370)
        {
            introduce();
        }
        
        //退出
        else if(mMsg.is_up()&&mMsg.is_left()&&mMsg.x>140&&mMsg.x<335&&mMsg.y>400&&mMsg.y<435)
        {
            cleardevice();
            closegraph();
        }

    }
    getch();
}


//选择关卡界面
void choice()
{
    PIMAGE pChioce = newimage();
    getimage(pChioce, "img\\choice.jpg",0,0);
    putimage(0, 0, pChioce);
    delimage(pChioce);
    mouse_msg mMsg = {0};
    for ( ; is_run(); delay_fps(60))
    {
        //获取鼠标消息，这个函数会等待，等待到有消息为止
        while(mousemsg())
        {
            mMsg = getmouse();
        }
        //选择关卡01
        if(mMsg.is_up()&&mMsg.is_left()&&mMsg.x>166&&mMsg.x<272&&mMsg.y>120&&mMsg.y<365)
        {
            lvFlag=1;
            TOTAL=t1;
            
            //复制地图 
            for(int i=0;i<WIDTH;i++)
            {
                for(int j=0;j<LENGTH;j++)
                    pMap[i][j]=pMap1[i][j];
            }
            
            inLevel();

        }
        
        //02
        else if(mMsg.is_up()&&mMsg.is_left()&&mMsg.x>295&&mMsg.x<401&&mMsg.y>120&&mMsg.y<365)
        {
            lvFlag=2;
            TOTAL=t2;
            for(int i=0;i<WIDTH;i++)
            {
                for(int j=0;j<LENGTH;j++)
                    pMap[i][j]=pMap2[i][j];
            }
            
            inLevel();
        }
        
        //03
        else if(mMsg.is_up()&&mMsg.is_left()&&mMsg.x>424&&mMsg.x<528&&mMsg.y>120&&mMsg.y<365)
        {
            lvFlag=3;
            TOTAL=t3;
            for(int i=0;i<WIDTH;i++)
            {
                for(int j=0;j<LENGTH;j++)
                    pMap[i][j]=pMap3[i][j];
            }
            inLevel();
        }

    }
    getch();
}


//游戏介绍
void introduce()
{
    PIMAGE pIntro = newimage();
    getimage(pIntro, "img\\introduce.bmp",0,0);
    putimage(0, 0, pIntro);
    delimage(pIntro);
    mouse_msg mMsg = {0};
    for ( ; is_run(); delay_fps(60))
    {
        //获取鼠标消息，这个函数会等待，等待到有消息为止
        while(mousemsg())
        {
            mMsg = getmouse();
        }
        //选择关卡01
        if(mMsg.is_up()&&mMsg.is_left()&&mMsg.x>0&&mMsg.x<500&&mMsg.y>0&&mMsg.y<550)
        {
            cleardevice();
            homeMenu();
        }

    }
    getch();
}


//进入下一关卡
void enterNext()
{
    PIMAGE pNext = newimage();
    getimage(pNext, "img\\next.jpg",0,0);
    putimage(0, 0, pNext);
    delimage(pNext);
    mouse_msg mMsg = {0};
    for ( ; is_run(); delay_fps(60))
    {
        //获取鼠标消息，这个函数会等待，等待到有消息为止
        while(mousemsg())
        {
            mMsg = getmouse();
        }
        //重新选关 
        if(mMsg.is_up()&&mMsg.is_left()&&mMsg.x>309&&mMsg.x<375&&mMsg.y>410&&mMsg.y<510)
        {
            cleardevice();
            choice();
        }
        //进入下一关卡
        if(mMsg.is_up()&&mMsg.is_left()&&mMsg.x>406&&mMsg.x<514&&mMsg.y>339&&mMsg.y<477)
        {
            cleardevice();
            lvFlag++;
			if(lvFlag==2){
				TOTAL=t2;
            for(int i=0;i<WIDTH;i++)
            {
                for(int j=0;j<LENGTH;j++)
                    pMap[i][j]=pMap2[i][j];
            }
            inLevel();
        
			} 
			else if(lvFlag==3)
			{
            lvFlag=3;
            TOTAL=t3;
            for(int i=0;i<WIDTH;i++)
            {
                for(int j=0;j<LENGTH;j++)
                    pMap[i][j]=pMap3[i][j];
            }
            inLevel();

        }
            else if(lvFlag>3){
            	gameOver();
			}
        }
        //退出
        else if(mMsg.is_up()&&mMsg.is_left()&&mMsg.x>211&&mMsg.x<275&&mMsg.y>407&&mMsg.y<511)
        {
            cleardevice();
            closegraph();

        }
        //进入到
        /*else if(mMsg.is_up()&&mMsg.is_left()&&mMsg.x>50&&mMsg.x<135&&mMsg.y>350&&mMsg.y<450)
        {
            gameOver();
        }*/

    }
}


//死亡游戏结束界面
void dieOver()
{
    delay_ms(600);
    PIMAGE pOver = newimage();
    getimage(pOver, "img\\dieover.jpg",0,0);
    putimage(0, 0, pOver);
    delimage(pOver);

    mouse_msg mMsg = {0};
    for ( ; is_run(); delay_fps(60))
    {
        //获取鼠标消息，这个函数会等待，等待到有消息为止
        while(mousemsg())
        {
            mMsg = getmouse();
        }
        //重新开始
        if(mMsg.is_up()&&mMsg.is_left()&&mMsg.x>44&&mMsg.x<200&&mMsg.y>494&&mMsg.y<532)
        {
            //判断在第几关重新开始？？？
            if(lvFlag==1)
            {
                for(int i=0;i<WIDTH;i++)
                {
                    for(int j=0;j<LENGTH;j++)
                        pMap[i][j]=pMap1[i][j];
                }
                inLevel();
            }
            else if (lvFlag==2)
            {
                for(int i=0;i<WIDTH;i++)
                {
                    for(int j=0;j<LENGTH;j++)
                        pMap[i][j]=pMap2[i][j];
                }
                inLevel();
            }
            else if (lvFlag==3)
            {
                for(int i=0;i<WIDTH;i++)
                {
                    for(int j=0;j<LENGTH;j++)
                        pMap[i][j]=pMap3[i][j];
                }
                inLevel();
            }
        }
        //退出
        else if(mMsg.is_up()&&mMsg.is_left()&&mMsg.x>312&&mMsg.x<473&&mMsg.y>494&&mMsg.y<532)
        {
            cleardevice();
            closegraph();

        }

        else if(mMsg.is_up()&&mMsg.is_left()&&mMsg.x>40&&mMsg.x<140&&mMsg.y>390&&mMsg.y<520)
        {
            gameOver();
        }
    }
}


//游戏结束界面
void gameOver()
{
    PIMAGE pgover = newimage();
    getimage(pgover, "img\\gover.jpg",0,0);
    putimage(0, 0, pgover);
    delimage(pgover);
    //显示分数
    char s[5];
    sprintf(s, "%d", score);
    setfont(-30, 0, "宋体");
    outtextxy(145, 355, s);

    mouse_msg mMsg = {0};
    for ( ; is_run(); delay_fps(60))
    {
        //获取鼠标消息，这个函数会等待，等待到有消息为止
        while(mousemsg())
        {
            mMsg = getmouse();
        }
        //重新开始
        if(mMsg.is_up()&&mMsg.is_left()&&mMsg.x>32&&mMsg.x<179&&mMsg.y>392&&mMsg.y<431)
        {
            homeMenu();
        }
        //退出
        else if(mMsg.is_up()&&mMsg.is_left()&&mMsg.x>367&&mMsg.x<440&&mMsg.y>400&&mMsg.y<435)
        {
            cleardevice();
            closegraph();
        }
        //
        else if(mMsg.is_up()&&mMsg.is_left()&&mMsg.x>35&&mMsg.x<115&&mMsg.y>450&&mMsg.y<530)
        {

        }
    }
}


//输出分数
void showScore()
{
    char s[5];
    sprintf(s, "%d", score);
    setfont(-30, 0, "宋体");
    outtextxy(430, 510, s);
}
