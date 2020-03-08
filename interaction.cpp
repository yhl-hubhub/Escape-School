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


//�����ƶ�
int roleMove(int ldir,int crash_image)  //ldir���ϴεĳ���,crash_image��ײ��ʱ�˵�ͼƬ������������ż����
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
    //��
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
    //��
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
    //��
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
    //��
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
    else  //û�ƶ� 
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
		else  //�տ�ʼʱ����Ϊ�� 
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


//�޶�����Ļ��Χ
int isOutRange()
{
	if(mstx>(MST_START_X+75)||mstx<(MST_START_X-75)||
	   msty>(MST_START_Y+75)||msty<(MST_START_Y-75)
	)
		return 1;
	else
		return 0;
 } 

//�����ƶ�
int mstMove()
{
	PIMAGE pUpd = newimage();
    //showScore();
    //delay_ms(120);
    //for(int i=1;i<=rSpeed;i++);
    srand((unsigned) time(NULL));
    int inum,flag=1;
    while(flag)
	{
    	inum=(rand()%4)+1;
        //��
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
				getimage(pUpd,"img\\59�־���.jpg");
	            putimage(mstx,msty,pUpd);/**/
			}
			
	        
        }
        //��
        else if(inum==RIGHT)
		{
           mstx+=rSpeed;
            if(isTouchWall(RIGHT,mstx,msty)||isOutRange())
				mstx-=rSpeed;
			else
			{
				flag=0;
	            getimage(pUpd,"img\\59�־���.jpg");
	            putimage(mstx,msty,pUpd);/**/
			}	
            
    	}
        //��
        else if(inum==UP)       
        {
            msty-=rSpeed;
            if(isTouchWall(UP,mstx,msty)||isOutRange())
				msty+=rSpeed;
			else
			{
				flag=0;
	            getimage(pUpd,"img\\59�־���.jpg");
	            putimage(mstx,msty,pUpd);/**/
			}	
            
        }
        //��
        else if(inum==DOWN)
        {
            msty+=rSpeed;
            if(isTouchWall(DOWN,mstx,msty)||isOutRange())
				msty-=rSpeed;
			else
			{
				getimage(pUpd,"img\\59�־���.jpg");
	            putimage(mstx,msty,pUpd);/**/
                flag=0;
			}
	        
        }
    }
    delimage(pUpd);
    return inum;
}

//��ײ�ж�
int crashJudge()
{
	if((mstx-rx<50&&mstx-rx>-50)&&(msty-ry<50&&msty-ry>-50)) 
	{   
	   return 1;     
	}
	else
	    return 0;
}


//�ж��Ƿ�ײǽ 
int isWall(int isBlockCol,int isBlockRow)
{
	if(pMap[isBlockRow][isBlockCol]==2)
		return 1;
	else
		return 0;
}

int isElement(int isBlockCol,int isBlockRow)
{
	if(pMap[isBlockRow][isBlockCol]==11||pMap[isBlockRow][isBlockCol]==12||pMap[isBlockRow][isBlockCol]==13)
		return 1;
	else
		return 0;
}

int isTouchWall(int dir,int x,int y)
{
	
	blockRow_Next = y/UNIT;
	blockCol_Next = x/UNITCOL;
	
	int judge=0;
	
	if(dir==RIGHT)
	{
		if(((x+UNIT)>(blockCol_Next+1)*UNIT)&& 
				(isWall(blockCol_Next+1,blockRow_Next)||//������ǽ
				(isWall(blockCol_Next+1,blockRow_Next+1)&&(y+UNIT>(blockRow_Next+1)*UNIT)))//������ǽ 
		  )
		  	judge=1;
		   
			
	}
	else if(dir==LEFT)
	{
		if((x<(blockCol_Next+1)*UNIT)&& 
				(isWall(blockCol_Next,blockRow_Next)||//������ǽ
				(isWall(blockCol_Next,blockRow_Next+1)&&((y+UNIT)>(blockRow_Next+1)*UNIT)))//������ǽ 
		  ) 
			judge=1;
	}
	else if(dir==UP)
	{
		if((y<(blockRow_Next+1)*UNIT)&& 
				((isWall(blockCol_Next+1,blockRow_Next)&&((x+UNIT)>((blockCol_Next+1)*UNIT)))||//������ǽ
				 (isWall(blockCol_Next,blockRow_Next)))//������ǽ 
		  ) 
			judge=1;
	}
	else if(dir==DOWN)
	{
		if(((y+UNIT)>(blockRow_Next+1)*UNIT)&& 
				((isWall(blockCol_Next+1,blockRow_Next+1)&&((x+UNIT)>((blockCol_Next+1)*UNIT)))||//������ǽ
				 (isWall(blockCol_Next,blockRow_Next+1)))//������ǽ 
		  ) 
			judge=1;
	}
	
	return judge;
} 


int isTouchElement(int dir,int x,int y)
{
	
	blockRow_Next = y/UNIT;
	blockCol_Next = x/UNITCOL;
	
	int judge=0;
	
	if(dir==RIGHT)
	{
		if(((rx+UNIT)>(blockCol_Next+1)*UNIT)&& 
				(isElement(blockCol_Next+1,blockRow_Next)||//������ǽ
				(isElement(blockCol_Next+1,blockRow_Next+1)&&(ry+UNIT>(blockRow_Next+1)*UNIT)))//������ǽ 
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
				( isElement(blockCol_Next,blockRow_Next)||//������ǽ
				 (isElement(blockCol_Next,blockRow_Next+1)&&((ry+UNIT)>(blockRow_Next+1)*UNIT)))//������ǽ 
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
				((isElement(blockCol_Next+1,blockRow_Next)&&((rx+UNIT)>((blockCol_Next+1)*UNIT)))||//������ǽ
				 (isElement(blockCol_Next,blockRow_Next)))//������ǽ 
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
				((isElement(blockCol_Next+1,blockRow_Next+1)&&((rx+UNIT)>((blockCol_Next+1)*UNIT)))||//������ǽ
				 (isElement(blockCol_Next,blockRow_Next+1)))//������ǽ 
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
