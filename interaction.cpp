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

#define LEFT 1
#define RIGHT 2
#define UP 3
#define DOWN 4

////游戏进行中观察变量 
//int watchUp = 0;
//int watchDown = 0;
//int watchLeft = 0;
//int watchRight = 0; 



//判断是否撞墙 
int isWall(int isBlockCol,int isBlockRow)
{
	if(pMap[isBlockRow][isBlockCol]==5)
		return 1;
	else
		return 0;
}

int isTouch(int dir)
{
	int judge=0;
	
	if(dir==RIGHT)
	{
		if(((rx+UNIT)>(blockCol_Next+1)*UNIT)&& 
				(isWall(blockCol_Next+1,blockRow_Next)||//右上有墙
				(isWall(blockCol_Next+1,blockRow_Next+1)&&(ry+UNIT>(blockRow_Next+1)*UNIT)))//右下有墙 
		  ) 
			judge=1;
	}
	else if(dir==LEFT)
	{
		if(((rx)<((blockCol_Next+1)*UNIT))&& 
				( isWall(blockCol_Next,blockRow_Next)||//左上有墙
				 (isWall(blockCol_Next,blockRow_Next+1)&&((ry+UNIT)>(blockRow_Next+1)*UNIT)))//左下有墙 
		  ) 
			judge=1;
	}
	else if(dir==UP)
	{
		if(((ry)<(blockRow_Next+1)*UNIT)&& 
				((isWall(blockCol_Next+1,blockRow_Next)&&((rx+UNIT)>((blockCol_Next+1)*UNIT)))||//上右有墙
				 (isWall(blockCol_Next,blockRow_Next)))//上左有墙 
		  ) 
			judge=1;
	}
	else if(dir==DOWN)
	{
		if(((ry+UNIT)>(blockRow_Next+1)*UNIT)&& 
				((isWall(blockCol_Next+1,blockRow_Next+1)&&((rx+UNIT)>((blockCol_Next+1)*UNIT)))||//下右有墙
				 (isWall(blockCol_Next,blockRow_Next+1)))//下左有墙 
		  ) 
			judge=1;
	}
	
	return judge;
} 




//人物移动
int roleMove(int ldir)  //ldir时上次的朝向 
{
    PIMAGE pUpd = newimage();
    key_msg kMsg ={0};
    int dir=0;
    
    while(kbmsg())
        {
            kMsg = getkey();
        }
    blockRow_Now=ry/UNITCOL;
    blockCol_Now=rx/UNITCOL; 
    //左
	if(kMsg.key==65&&kMsg.msg==key_msg_down)//
    {
        dir=LEFT;
        rx-=10;
		blockRow_Next = ry/UNIT;
		blockCol_Next = rx/UNITCOL;
        if(isTouch(dir))
			rx+=10;
        getimage(pUpd, "img\\renL.jpg");
        putimage(rx,ry,pUpd);/**/
        
    }
    //右
    else if(kMsg.key==68&&kMsg.msg==key_msg_down)
    {
        dir=RIGHT;
        rx+=10;
        blockRow_Next = ry/UNIT;
		blockCol_Next = rx/UNITCOL;
		if(isTouch(dir))
			rx-=10;
        getimage(pUpd, "img\\renR.jpg");
        putimage(rx,ry,pUpd);/**/
        
    }
    //上
    else if(kMsg.key==87&&kMsg.msg==key_msg_down)//&&kMsg.msg==key_msg_up&&(pMap[row-1][col]==0||pMap[row-1][col]==9||pMap[row-1][col]==3))
    {
    	dir=UP;
        ry-=10;
        blockRow_Next = ry/UNIT;
		blockCol_Next = rx/UNITCOL;
		if(isTouch(dir))
			ry+=10;
        getimage(pUpd, "img\\renU.jpg");
        putimage(rx,ry,pUpd);/**/
    }
    //下
    else if(kMsg.key==83&&kMsg.msg==key_msg_down)//&&kMsg.msg==key_msg_up&&(pMap[row+1][col]==0||pMap[row+1][col]==9||pMap[row+1][col]==3))
    {
        dir=DOWN;
        ry+=10;
        blockRow_Next = ry/UNIT;
		blockCol_Next = rx/UNITCOL;
		if(isTouch(dir))
			ry-=10;
        getimage(pUpd, "img\\renD.jpg");
        putimage(rx,ry,pUpd);/**/
    }
    else
    {
    	if(ldir==LEFT)
    	{
    		getimage(pUpd, "img\\renL.jpg");
            putimage(rx,ry,pUpd);
            dir=LEFT;
		}
    	else if(ldir==RIGHT)
    	{
    		getimage(pUpd, "img\\renR.jpg");
            putimage(rx,ry,pUpd);
            dir=RIGHT;
		}
		else if(ldir==UP)
    	{
    		getimage(pUpd, "img\\renU.jpg");
            putimage(rx,ry,pUpd);
            dir=UP;
		}
		else if(ldir==DOWN)
    	{
    		getimage(pUpd, "img\\renD.jpg");
            putimage(rx,ry,pUpd);
            dir=DOWN;
		}
		else  //刚开始时方向为正 
		{
			getimage(pUpd, "img\\ren.jpg");
            putimage(rx,ry,pUpd);	                
		}
		
	}
    //}
    delimage(pUpd);
    
    return dir;
}

//怪物移动
//怪物坐标pMap[mstrow][mstcol]
int mstMove()
{
	PIMAGE pUpd = newimage();
    //showScore();
    //delay_ms(120);
    //for(int i=1;i<=10;i++);
    srand((unsigned) time(NULL));
    int inum,flag=1;
    while(flag)
	{
    	inum=(rand()%4)+1;
        //左
        if(inum==LEFT&&pMap[(mstx-11)/UNIT][msty/UNITCOL]!=2&&pMap[(mstx-11)/UNIT][(msty-1)/UNITCOL+1]!=2)//&&(pMap[mstrow][mstcol-1]==9
                 //||pMap[mstrow][mstcol-1]==5||pMap[mstrow][mstcol-1]==6||pMap[mstrow][mstcol-1]==7||pMap[mstrow][mstcol-1]==8)
        {
        /*pMap[mstrow][mstcol-1]=3;
        pMap[mstrow][mstcol]=9;
        */
            
            mstx-=11;
	        getimage(pUpd,"img\\guaiwu1.jpg");
	        putimage(mstx,msty,pUpd);/**/
	        flag=0;
        }
        //右
        else if(inum==RIGHT&&pMap[(mstx+10)/UNIT+1][msty/UNITCOL]!=2&&pMap[(mstx+10)/UNIT+1][(msty-1)/UNITCOL+1]!=2)//&&(pMap[mstrow][mstcol+1]==9
                    //||pMap[mstrow][mstcol+1]==5 ||pMap[mstrow][mstcol+1]==6||pMap[mstrow][mstcol+1]==7||pMap[mstrow][mstcol+1]==8)
        {
            cleardevice();
            drawMap();
            mstx+=11;
	        getimage(pUpd,"img\\guaiwu1.jpg");
	        putimage(mstx,msty,pUpd);/**/
            flag=0;
    }
        //上
        else if(inum==UP&&pMap[mstx/UNIT][(msty-10)/UNITCOL]!=2&&pMap[mstx/UNIT+1][(msty-10)/UNITCOL]!=2)//(pMap[mstrow-1][mstcol]==9
                      //||pMap[mstrow-1][mstcol]==5||pMap[mstrow-1][mstcol]==6||pMap[mstrow-1][mstcol]==7||pMap[mstrow-1][mstcol]==8)
        {
            
            msty-=10;
	        getimage(pUpd,"img\\guaiwu1.jpg");
	        putimage(mstx,msty,pUpd);/**/
            flag=0;
        }
        //下
        else if(inum==4&&pMap[mstx/UNIT][(msty+10)/UNITCOL+1]!=2&&pMap[mstx/UNIT+1][(msty+10)/UNITCOL+1]!=2)//&&(pMap[mstrow+1][mstcol]==9
                    //  ||pMap[mstrow+1][mstcol]==5 ||pMap[mstrow+1][mstcol]==6||pMap[mstrow+1][mstcol]==7||pMap[mstrow+1][mstcol]==8))
        {
            
            msty+=10;
	        getimage(pUpd,"img\\guaiwu1.jpg");
	        putimage(mstx,msty,pUpd);/**/
            flag=0;
        }
    }
    delimage(pUpd);
    return inum;
}

//碰撞判断
int crashJudge(int dir,int mstdir)
{
	int judge=0;
	if(pMap[row][col]==3) judge=1;
	else if(row==mstrow&&col==mstcol-1&&dir==LEFT&&mstdir==RIGHT) judge=1;
	else if(row==mstrow&&col==mstcol+1&&mstdir==LEFT&&dir==RIGHT) judge=1;
	else if(row==mstrow+1&&col==mstcol&&dir==DOWN&&mstdir==UP) judge=1;
	else if(row==mstrow-1&&col==mstcol&&dir==UP&&mstdir==DOWN) judge=1;
	if(judge==1)
	{   
	    pMap[row][col]=4;
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
    
    return 0;
}
