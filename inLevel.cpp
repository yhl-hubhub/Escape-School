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
        //�����ƶ�
        //��������ƶ�
        //�ж��Ƿ���ײ
		dir=roleMove();
		mstdir=mstMove();
        crashJudge(dir,mstdir);
        
        
        
        //�ж��Ƿ�������ж��ӣ����������һ�ؿ�
        if(cntJudge==0)
        {
            //showScore();
            //������һ�ؿ�
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
