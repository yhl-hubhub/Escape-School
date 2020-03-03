#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <graphics.h>

#include "Map.h"
#include "constant.h"
#include "interaction.h"

#define BLR 9
#define BLC1 0
#define BLC2 1
#define BLC3 2


//人物移动
void roleMove()
{
    PIMAGE pUpd = newimage();
    key_msg kMsg ={0};

    //for ( ; is_run(); delay_fps(60))
    //{
        while(kbmsg())
        {
            kMsg = getkey();
        }
            //左
           if(kMsg.key==65&&kMsg.msg==key_msg_up&&(pMap[row][col-1]==0||pMap[row][col-1]==9||pMap[row][col-1]==3))
            {
	            //outtextxy(50, 0, "A左");
	            //将上一个位置的图片处理了
	            //人物移动
	            pMap[row][col-1]=5;
	            pMap[row][col]=9;
	            col=col-1;
	            drawMap();
            }
            //右
            else if(kMsg.key==68&&kMsg.msg==key_msg_up&&(pMap[row][col+1]==0||pMap[row][col+1]==9||pMap[row][col+1]==3))
            {
                //outtextxy(150, 0, "D右");
                pMap[row][col+1]=6;
                pMap[row][col]=9;
                col=col+1;
                drawMap();
            }
            //上
            else if(kMsg.key==87&&kMsg.msg==key_msg_up&&(pMap[row-1][col]==0||pMap[row-1][col]==9||pMap[row-1][col]==3))
            {
                //outtextxy(0, 0, "W上");
                pMap[row-1][col]=7;
                pMap[row][col]=9;
                row=row-1;
                drawMap();
            }
            //下
            else if(kMsg.key==83&&kMsg.msg==key_msg_up&&(pMap[row+1][col]==0||pMap[row+1][col]==9||pMap[row+1][col]==3))
            {
                //outtextxy(100, 0, "S下");
                pMap[row+1][col]=8;
                pMap[row][col]=9;
                row=row+1;
                drawMap();
            }
    //}
    delimage(pUpd);
}

//怪物移动
//怪物坐标pMap[mstrow][mstcol]
void mstMove()
{
    //showScore();
    delay_ms(600);
    srand((unsigned) time(NULL));
    int inum=(rand()%4)+1;
    //左
    if(inum==1&&(pMap[mstrow][mstcol-1]==9
                 ||pMap[mstrow][mstcol-1]==5||pMap[mstrow][mstcol-1]==6||pMap[mstrow][mstcol-1]==7||pMap[mstrow][mstcol-1]==8))
    {
        pMap[mstrow][mstcol-1]=3;
        pMap[mstrow][mstcol]=9;
        drawMap();

    }
    //右
    else if(inum==2&&(pMap[mstrow][mstcol+1]==9
                      ||pMap[mstrow][mstcol+1]==5 ||pMap[mstrow][mstcol+1]==6||pMap[mstrow][mstcol+1]==7||pMap[mstrow][mstcol+1]==8))
    {
        pMap[mstrow][mstcol+1]=3;
        pMap[mstrow][mstcol]=9;
        drawMap();

    }
    //上
    else if(inum==3&&(pMap[mstrow-1][mstcol]==9
                      ||pMap[mstrow-1][mstcol]==5||pMap[mstrow-1][mstcol]==6||pMap[mstrow-1][mstcol]==7||pMap[mstrow-1][mstcol]==8))
    {
        pMap[mstrow-1][mstcol]=3;
        pMap[mstrow][mstcol]=9;
        drawMap();

    }
    //下
    else if(inum==4&&(pMap[mstrow+1][mstcol]==9
                      ||pMap[mstrow+1][mstcol]==5 ||pMap[mstrow+1][mstcol]==6||pMap[mstrow+1][mstcol]==7||pMap[mstrow+1][mstcol]==8))
    {
        pMap[mstrow+1][mstcol]=3;
        pMap[mstrow][mstcol]=9;
        drawMap();

    }
}

//碰撞判断
int crashJudge()
{
    if(pMap[row][col]==3&&roleBlood==3)
    {
        pMap[BLR][BLC3]=9;
    }
    else if (pMap[row][col]==3&&roleBlood==2)
    {
        pMap[BLR][BLC2]=9;
    }
    else if (pMap[row][col]==3&&roleBlood==1)
    {
        pMap[BLR][BLC1]=9;
    }
    
    return 0;
}
