#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <graphics.h>

#include "constant.h"
#include "interaction.h"
#include "Interface.h"
#include "Map.h"
/*******************************
  *Description������ؿ���Ŀ��ƺ���
  *Last edited by: ϯʫ��
*********************************/
void inLevel()
{  
    int dir,mstdir;//�˹ֵķ��� 
    PIMAGE img=newimage();
    roleBlood=3;
    
	drawMap();
	getimage(img, "img\\ren.jpg");
	putimage(rx,ry,img);
	getimage(img, "img\\guaiwu1.jpg");
	putimage(mstx,msty,img);
	
    for ( ; is_run(); delay_fps(10))//
    {
        //�����ƶ�
        //��������ƶ�
        //�ж��Ƿ���ײ
		//delay_ms(1000);
		
		cleardevice();
		drawMap();
	
		mstdir=mstMove();
		
		dir=roleMove(dir);
		
        crashJudge(dir,mstdir);
        
        
        
        //�ж��Ƿ�������ж��ӣ����������һ�ؿ�
//        if(cntJudge==0)
//        {
//            //������һ�ؿ�
//            delay_ms(60);
//            enterNext();
//        }
        if(roleBlood==0)
        {
            dieOver();
        }
        
    }

}
