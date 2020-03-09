#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <graphics.h>

#include "Interface.h"
#include "constant.h"
#include "inLevel.h"

#define t1 20
#define t2 12
#define t3 10


/*******************************
  *Description： 初始化程序 
  *Last edited by: 席诗祺 
  *Edit time: 2020/3/8 15:17 
*********************************/
void initialize()
{	
	initgraph(750, 800);
    PIMAGE pLoad = newimage();
    getimage(pLoad, "img\\loading.jpg",0,0);
    putimage(0, 0, pLoad);
    delimage(pLoad);
    delay_ms(500); 
    music.OpenFile("background music.mp3");
    music.Play();
    if (music.GetPlayStatus() == MUSIC_MODE_STOP) 
	{
	    music.Play(0);
    } 
	/*    mouse_msg mMsg = {0};
	PIMAGE background = newimage();
    
    getimage(background,"img\\shu.jpg",0,0);
    putimage(0, 0, background);
    
    
    for ( ; is_run(); delay_fps(60))
    {
    	while(mousemsg())
        {
        	mMsg = getmouse();
            
        }
        if(mMsg.is_up()&&mMsg.is_left())
		{
			getimage(background,"img\\ren.jpg",0,0);
            putimage(0, 0, background);
            break;
		}
    }
    mMsg = getmouse();
    
	for ( ; is_run(); delay_fps(60))
    {
    	while(mousemsg())
        {
        	mMsg = getmouse();
            
        }
        if(mMsg.is_up()&&mMsg.is_left())
		{
			getimage(background,"img\\renD.jpg",0,0);
            putimage(0, 0, background);
            break;
		}
    } 
	mMsg = getmouse();
	
    for ( ; is_run(); delay_fps(60))
    {
    	while(mousemsg())
        {
        	mMsg = getmouse();
            
        }
        if(mMsg.is_up()&&mMsg.is_left())
		{
			getimage(background,"img\\renU.jpg",0,0);
            putimage(0, 0, background);
            break;
		}
    }
*/   
    /*for ( ; is_run(); delay_fps(60))
    {
    	while(mousemsg())
        {
        	mMsg = getmouse();
            
        }
        if(mMsg.is_up()&&mMsg.is_left())
		{*/
			//homeMenu();
			/*break;
        }
    }*/
 } 


/*******************************
  *Description： 主界面
  *Last edited by: 王晓宇
  *Edit time: 2020/3/8 11:17 
*********************************/
void homeMenu()
{
    mouse_msg mMsg = {0};
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
    mMsg = getmouse();
   
    for ( ; is_run(); delay_fps(60))
    {
        //获取鼠标消息，这个函数会等待，等待到有消息为止
        while(mousemsg())
        {
            mMsg = getmouse();
        }
        
        //开始游戏 
		if(mMsg.is_up()&&mMsg.is_left()&&mMsg.x>81&&mMsg.x<232&&mMsg.y>613&&mMsg.y<648)//
        {
        	rx=0;ry=0;
            mstx=MST_START_X;msty=MST_START_Y;
            lvFlag=1; 
            //复制地图 
            for(int i=0;i<NUM_COL;i++)
            {
                for(int j=0;j<NUM_ROW;j++)
                    pMap[i][j]=pMap1[i][j];
            }
            
            inLevel();//choice();
            
        }
        else if(mMsg.is_up()&&mMsg.is_left()&&mMsg.x>533&&mMsg.x<684&&mMsg.y>613&&mMsg.y<648)
        {
        	music.Close();
        	cleardevice();
        	closegraph();
		}
    }    
}        
        //游戏说明（这个还没做） 
        /*else if(mMsg.is_up()&&mMsg.is_left()&&mMsg.x>140&&mMsg.x<335&&mMsg.y>340&&mMsg.y<370)
        {
            introduce();
        }
        
        //退出
        else if(mMsg.is_up()&&mMsg.is_left()&&mMsg.x>140&&mMsg.x<335&&mMsg.y>400&&mMsg.y<435)
        {
            cleardevice();
            closegraph();
        }*/

    
    //getch();
//&&mMsg.x>140&&mMsg.x<335&&mMsg.y>260&&mMsg.y<300
       /*{
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
    
}*/


//选择关卡界面
/*void choice()
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
            rx=0;ry=0;
            mstx=275;msty=250;
            //复制地图 
            for(int i=0;i<NUM_COL;i++)
            {
                for(int j=0;j<NUM_ROW;j++)
                    pMap[i][j]=pMap1[i][j];
            }
            
            inLevel();

        }
        
        //02
        else if(mMsg.is_up()&&mMsg.is_left()&&mMsg.x>295&&mMsg.x<401&&mMsg.y>120&&mMsg.y<365)
        {
            lvFlag=2;
            TOTAL=t2;
            for(int i=0;i<NUM_COL;i++)
            {
                for(int j=0;j<NUM_ROW;j++)
                    pMap[i][j]=pMap2[i][j];
            }
            
            inLevel();
        }
        
        //03
        else if(mMsg.is_up()&&mMsg.is_left()&&mMsg.x>424&&mMsg.x<528&&mMsg.y>120&&mMsg.y<365)
        {
            lvFlag=3;
            TOTAL=t3;
            for(int i=0;i<NUM_COL;i++)
            {
                for(int j=0;j<NUM_ROW;j++)
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
        // 
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
            for(int i=0;i<NUM_COL;i++)
            {
                for(int j=0;j<NUM_ROW;j++)
                    pMap[i][j]=pMap2[i][j];
            }
            inLevel();
        
			} 
			else if(lvFlag==3)
			{
            lvFlag=3;
            TOTAL=t3;
            for(int i=0;i<NUM_COL;i++)
            {
                for(int j=0;j<NUM_ROW;j++)
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
        else if(mMsg.is_up()&&mMsg.is_left()&&mMsg.x>50&&mMsg.x<135&&mMsg.y>350&&mMsg.y<450)
        {
            gameOver();
        }

    }
}*/


//死亡游戏结束界面
void dieOver()
{
	
    delay_ms(600);
    cleardevice(); 
    PIMAGE pOver = newimage();
    getimage(pOver, "img\\dieover.jpg",0,0);
    putimage(0, 0, pOver);
    delimage(pOver);
    /*MUSIC music3;
    music3.OpenFile("death.mp3");
    f (music.IsOpen()) {
	music3.Play;
    }
    */
    mouse_msg mMsg = {0};
    for ( ; is_run(); delay_fps(60))
    {
        //获取鼠标消息，这个函数会等待，等待到有消息为止
        while(mousemsg())
        {
            mMsg = getmouse();
        }
        //重新开始
        if(mMsg.is_up()&&mMsg.is_left()&&mMsg.x>115&&mMsg.x<295&&mMsg.y>320&&mMsg.y<360)
        {
            //判断在第几关重新开始？？？
            if(lvFlag==1)
            {
                for(int i=0;i<NUM_COL;i++)
                {
                    for(int j=0;j<NUM_ROW;j++)
                        pMap[i][j]=pMap1[i][j];
                }
                rx=55;ry=100;
                mstx=MST_START_X;msty=MST_START_Y;//设置怪物的初始位置 
                inLevel();//进入关卡控制程序 
            }
            else if (lvFlag==2)
            {
                for(int i=0;i<NUM_COL;i++)
                {
                    for(int j=0;j<NUM_ROW;j++)
                        pMap[i][j]=pMap2[i][j];
                }
                inLevel();
            }
            else if (lvFlag==3)
            {
                for(int i=0;i<NUM_COL;i++)
                {
                    for(int j=0;j<NUM_ROW;j++)
                        pMap[i][j]=pMap3[i][j];
                }
                inLevel();
            }
        }
        //退出
        else if(mMsg.is_up()&&mMsg.is_left()&&mMsg.x>440&&mMsg.x<660&&mMsg.y>320&&mMsg.y<360)
        {
            homeMenu();
        }
    }
}

        /*else if(mMsg.is_up()&&mMsg.is_left()&&mMsg.x>40&&mMsg.x<140&&mMsg.y>390&&mMsg.y<520)
        {
            gameOver();
        }*/
    

//游戏结束界面
void gameOver()
{
    PIMAGE pgover = newimage();
    getimage(pgover, "img\\win.jpg",0,0);
    putimage(0, 0, pgover);
    delimage(pgover);
    //显示分数
    char s[5];
    sprintf(s, "你的分数：%d", score);
    setfont(-30, 0, "宋体");
    outtextxy(145, 250, s);

    mouse_msg mMsg = {0};
    for ( ; is_run(); delay_fps(60))
    {
        //获取鼠标消息，这个函数会等待，等待到有消息为止
        while(mousemsg())
        {
            mMsg = getmouse();
        }
        //重新开始
       /*if(mMsg.is_up()&&mMsg.is_left()&&mMsg.x>32&&mMsg.x<179&&mMsg.y>392&&mMsg.y<431)
        {
            homeMenu();
        }*/
        //退出
        if(mMsg.is_up()&&mMsg.is_left()&&mMsg.x>440&&mMsg.x<660&&mMsg.y>320&&mMsg.y<360)
        {
        	homeMenu();
        }
    }
}


