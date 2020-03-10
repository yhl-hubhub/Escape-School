#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <graphics.h>

#include "Map.h"
#include "constant.h"
#include "interaction.h"

#define LEFT 1
#define RIGHT 2
#define UP 3
#define DOWN 4


int isWall(int isBlockCol,int isBlockRow); 
int isTouchWall(int dir,int x,int y);
int isTouchElement(int dir,int x,int y);
MUSIC music1;
int stepCnt=0;
//void roleImage(int dir)
//{
//	if(dir!=ldir)  stepCnt=1;
//	if(crash_image%2==1)
//	{
//		switch(stepCnt)
//		case 1:
//	}
//	
//	
//}


/*******************************
  *Description：人物移动
  *Last edited by: 王晓宇
  *Edit time：2020/3/8 18:45 
*********************************/
int roleMove(int ldir,int crash_image)  //ldir是上次的朝向,crash_image：撞怪时人的图片会闪，奇数亮偶数灭
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
    //MOVE MUSIC
    music1.OpenFile("move1.mp3");
    if(kMsg.msg==key_msg_down && (kMsg.key==65 || kMsg.key==68 || kMsg.key==87 || kMsg.key==83)
    {
    	music1.Play();
	if(kMsg.msg==key_msg_down && music1.GetPlayStatus() == MUSIC_MODE_STOP)
	{
		music1.play(0)
	}
    }
    //左
	if(kMsg.key==65&&kMsg.msg==key_msg_down)
    {
        dir=LEFT;
        rx-=rSpeed;
        if(isTouchWall(dir,rx,ry)||isTouchElement(dir,rx,ry))
			rx+=rSpeed;
        if(crash_image%2==1)
		{
			getimage(pUpd, "img\\renL.jpg");
            putimage(rx,ry,pUpd);/**/
		}
        
    }
    //右
    else if(kMsg.key==68&&kMsg.msg==key_msg_down)
    {
        dir=RIGHT;
        rx+=rSpeed;
		if(isTouchWall(dir,rx,ry)||isTouchElement(dir,rx,ry))
			rx-=rSpeed;
        
		if(crash_image%2==1)
		{
			getimage(pUpd, "img\\renR.jpg");
            putimage(rx,ry,pUpd);/**/
		}
        
    }
    //上
    else if(kMsg.key==87&&kMsg.msg==key_msg_down)
    {
    	dir=UP;
        ry-=rSpeed;
		if(isTouchWall(dir,rx,ry)||isTouchElement(dir,rx,ry))
			ry+=rSpeed;
        if(crash_image%2==1)
		{
			getimage(pUpd, "img\\renU.jpg");
            putimage(rx,ry,pUpd);/**/
		}
    }
    //下
    else if(kMsg.key==83&&kMsg.msg==key_msg_down)
    {
        dir=DOWN;
        ry+=rSpeed;
		if(isTouchWall(dir,rx,ry)||isTouchElement(dir,rx,ry))
			ry-=rSpeed;
        if(crash_image%2==1)
		{
			getimage(pUpd, "img\\renD.jpg");
            putimage(rx,ry,pUpd);/**/
		}
    }
    else  //没移动 
    {
    	if(ldir==LEFT)
    	{
    		if(crash_image%2==1)
		{
			getimage(pUpd, "img\\renL.jpg");
            putimage(rx,ry,pUpd);/**/
		}
            dir=LEFT;
		}
    	else if(ldir==RIGHT)
    	{
    		if(crash_image%2==1)
		{
			getimage(pUpd, "img\\renR.jpg");
            putimage(rx,ry,pUpd);/**/
		}
            dir=RIGHT;
		}
		else if(ldir==UP)
    	{
    		if(crash_image%2==1)
		{
			getimage(pUpd, "img\\renU.jpg");
            putimage(rx,ry,pUpd);/**/
		}
            dir=UP;
		}
		else if(ldir==DOWN)
    	{
    		if(crash_image%2==1)
		{
			getimage(pUpd, "img\\renD.jpg");
            putimage(rx,ry,pUpd);/**/
		}
            dir=DOWN;
		}
		else  //刚开始时方向为正 
		{
			if(crash_image%2==1)
		{
			getimage(pUpd, "img\\ren.jpg");
            putimage(rx,ry,pUpd);/**/
		}	                
		}
		
	}
    //}
    delimage(pUpd);
    
    return dir;
}



/*******************************
  *Description：限定怪物的活动范围
  *Last edited by: 王晓宇
  *Edit time：2020/3/8 18:11 
*********************************/
int isOutRange()
{
	if(mstx>(MST_START_X+75)||mstx<(MST_START_X-75)||
	   msty>(MST_START_Y+75)||msty<(MST_START_Y-75)
	)
		return 1;
	else
		return 0;
 } 
 
 int isOutRange_struct(CHARACTER mst)
{
	if(mst.x>(mst.start.x+75)||mst.x<(mst.start.x-75)||
	   mst.y>(mst.start.y+75)||mst.y<(mst.start.y-75)
	)
		return 1;
	else
		return 0;
 } 

//怪物移动
int mstMove()
{
	PIMAGE pUpd = newimage();
	getimage(pUpd,"img\\59分卷子.jpg");
    srand((unsigned) time(NULL));
    int inum,flag=1;
    while(flag)
	{
    	inum=(rand()%4)+1;
        //左
        if(inum==LEFT)
		{
            mstx-=rSpeed;
            if(isTouchWall(LEFT,mstx,msty)||isOutRange())
            {
            	mstx+=rSpeed;
			}
			else
			{
				flag=0;
	            putimage(mstx,msty,pUpd);/**/
			}
			
	        
        }
        //右
        else if(inum==RIGHT)
		{
           mstx+=rSpeed;
            if(isTouchWall(RIGHT,mstx,msty)||isOutRange())
				mstx-=rSpeed;
			else
			{
				flag=0;
	            putimage(mstx,msty,pUpd);/**/
			}	
            
    	}
        //上
        else if(inum==UP)       
        {
            msty-=rSpeed;
            if(isTouchWall(UP,mstx,msty)||isOutRange())
				msty+=rSpeed;
			else
			{
				flag=0;
	            putimage(mstx,msty,pUpd);/**/
			}	
            
        }
        //下
        else if(inum==DOWN)
        {
            msty+=rSpeed;
            if(isTouchWall(DOWN,mstx,msty)||isOutRange())
				msty-=rSpeed;
			else
			{
	            putimage(mstx,msty,pUpd);/**/
                flag=0;
			}
	        
        }
    }
    delimage(pUpd);
    return inum;
}

//怪物移动
int mstMove_struct(CHARACTER* mst)
{
	PIMAGE pUpd = newimage();
	getimage(pUpd,"img\\59分卷子.jpg");
    srand((unsigned) time(NULL));
    int inum,flag=1;
    while(flag)
	{
    	inum=(rand()%4)+1;
        //左
        if(inum==LEFT)
		{
            mst->x-=rSpeed;
            if(isTouchWall(LEFT,mst->x,mst->y)||isOutRange_struct(*mst))
            {
            	mst->x+=rSpeed;
			}
			else
			{
				flag=0;
	            putimage(mst->x,mst->y,pUpd);/**/
			}
			
	        
        }
        //右
        else if(inum==RIGHT)
		{
           mst->x+=rSpeed;
            if(isTouchWall(RIGHT,mst->x,mst->y)||isOutRange_struct(*mst))
				mst->x-=rSpeed;
			else
			{
				flag=0;
	            putimage(mst->x,mst->y,pUpd);/**/
			}	
            
    	}
        //上
        else if(inum==UP)       
        {
            mst->y-=rSpeed;
            if(isTouchWall(UP,mst->x,mst->y)||isOutRange_struct(*mst))
				mst->y+=rSpeed;
			else
			{
				flag=0;
	            putimage(mst->x,mst->y,pUpd);/**/
			}	
            
        }
        //下
        else if(inum==DOWN)
        {
            mst->y+=rSpeed;
            if(isTouchWall(DOWN,mst->x,mst->y)||isOutRange_struct(*mst))
				mst->y-=rSpeed;
			else
			{
	            putimage(mst->x,mst->y,pUpd);/**/
                flag=0;
			}
	        
        }
    }
    delimage(pUpd);
    return inum;
}

/*******************************
  *Description：碰撞判断
  *Last edited by: 王晓宇
  *Edit time：2020/3/8 17:45 
*********************************/
int crashJudge(CHARACTER mst)
{
	if((mst.x-rx<50&&mst.x-rx>-50)&&(mst.y-ry<50&&mst.y-ry>-50)) 
	{   
	   return 1;     
	}
	else
	    return 0;
}



/*******************************
  *Description：判断是否是墙
  *Last edited by: 王晓宇
  *Edit time：2020/3/8 15:45 
*********************************/
int isWall(int isBlockCol,int isBlockRow)
{
	if(pMap[isBlockRow][isBlockCol]==2)
		return 1;
	else
		return 0;
}


/*******************************
  *Description：判断是否是元素
  *Last edited by: 王晓宇
  *Edit time：2020/3/8 15:45 
*********************************/
int isElement(int isBlockCol,int isBlockRow)
{
	if(pMap[isBlockRow][isBlockCol]==11||pMap[isBlockRow][isBlockCol]==12||pMap[isBlockRow][isBlockCol]==13)
		return 1;
	else
		return 0;
}


/*******************************
  *Description：判断是否是墙
  *Last edited by: 席诗祺
  *Edit time：2020/3/7 21:45 
*********************************/
int isTouchWall(int dir,int x,int y)
{
	
	blockRow_Next = y/UNIT;
	blockCol_Next = x/UNITCOL;
	
	int judge=0;
	
	if(dir==RIGHT)
	{
		if(((x+UNIT)>(blockCol_Next+1)*UNIT)&& 
				(isWall(blockCol_Next+1,blockRow_Next)||//右上有墙
				(isWall(blockCol_Next+1,blockRow_Next+1)&&(y+UNIT>(blockRow_Next+1)*UNIT)))//右下有墙 
		  )
		  	judge=1;
		   
			
	}
	else if(dir==LEFT)
	{
		if((x<(blockCol_Next+1)*UNIT)&& 
				(isWall(blockCol_Next,blockRow_Next)||//左上有墙
				(isWall(blockCol_Next,blockRow_Next+1)&&((y+UNIT)>(blockRow_Next+1)*UNIT)))//左下有墙 
		  ) 
			judge=1;
	}
	else if(dir==UP)
	{
		if((y<(blockRow_Next+1)*UNIT)&& 
				((isWall(blockCol_Next+1,blockRow_Next)&&((x+UNIT)>((blockCol_Next+1)*UNIT)))||//上右有墙
				 (isWall(blockCol_Next,blockRow_Next)))//上左有墙 
		  ) 
			judge=1;
	}
	else if(dir==DOWN)
	{
		if(((y+UNIT)>(blockRow_Next+1)*UNIT)&& 
				((isWall(blockCol_Next+1,blockRow_Next+1)&&((x+UNIT)>((blockCol_Next+1)*UNIT)))||//下右有墙
				 (isWall(blockCol_Next,blockRow_Next+1)))//下左有墙 
		  ) 
			judge=1;
	}
	
	return judge;
} 


/*******************************
  *Description：判断是否是墙
  *Last edited by: 席诗祺
  *Edit time：2020/3/7 21:40 
*********************************/
int isTouchElement(int dir,int x,int y)
{
	
	blockRow_Next = y/UNIT;
	blockCol_Next = x/UNITCOL;
	
	int judge=0;
	
	if(dir==RIGHT)
	{
		if(((rx+UNIT)>(blockCol_Next+1)*UNIT)&& 
				(isElement(blockCol_Next+1,blockRow_Next)||//右上有墙
				(isElement(blockCol_Next+1,blockRow_Next+1)&&(ry+UNIT>(blockRow_Next+1)*UNIT)))//右下有墙 
		  ) 
			{
		  	    if(isElement(blockCol_Next+1,blockRow_Next)) pMap[blockRow_Next][blockCol_Next+1]=0;
			    else if(isElement(blockCol_Next+1,blockRow_Next+1)) pMap[blockRow_Next+1][blockCol_Next+1]=0;  
		  	    judge=1;
		    }
	}
	else if(dir==LEFT)
	{
		if(((rx)<((blockCol_Next+1)*UNIT))&& 
				( isElement(blockCol_Next,blockRow_Next)||//左上有墙
				 (isElement(blockCol_Next,blockRow_Next+1)&&((ry+UNIT)>(blockRow_Next+1)*UNIT)))//左下有墙 
		  ) 
			{
		  	    if(isElement(blockCol_Next,blockRow_Next)) pMap[blockRow_Next][blockCol_Next]=0;
			    else if(isElement(blockCol_Next,blockRow_Next+1)) pMap[blockRow_Next+1][blockCol_Next]=0;  
		  	    judge=1;
		    }
	}
	else if(dir==UP)
	{
		if(((ry)<(blockRow_Next+1)*UNIT)&& 
				((isElement(blockCol_Next+1,blockRow_Next)&&((rx+UNIT)>((blockCol_Next+1)*UNIT)))||//上右有墙
				 (isElement(blockCol_Next,blockRow_Next)))//上左有墙 
		  ) 
			{
		  	    if(isElement(blockCol_Next+1,blockRow_Next)) pMap[blockRow_Next][blockCol_Next+1]=0;
			    else if(isElement(blockCol_Next,blockRow_Next)) pMap[blockRow_Next][blockCol_Next]=0;  
		  	    judge=1;
		    }
	}
	else if(dir==DOWN)
	{
		if(((ry+UNIT)>(blockRow_Next+1)*UNIT)&& 
				((isElement(blockCol_Next+1,blockRow_Next+1)&&((rx+UNIT)>((blockCol_Next+1)*UNIT)))||//下右有墙
				 (isElement(blockCol_Next,blockRow_Next+1)))//下左有墙 
		  ) 
			{
		  	    if(isElement(blockCol_Next+1,blockRow_Next+1)) pMap[blockRow_Next+1][blockCol_Next+1]=0;
			    else if(isElement(blockCol_Next,blockRow_Next+1)) pMap[blockRow_Next+1][blockCol_Next]=0;  
		  	    judge=1;
		    }
	}
	if(judge==1)
	{
		isFoodEaten++;
		//pMap[2][2]=9;
	}	
	
	return judge;
} 
