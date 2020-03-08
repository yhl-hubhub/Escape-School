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
  *Description�� ����ؿ���Ŀ��ƺ���
  *Last edited by: ������ 
  *Edit time: 2020/3/7 20:50
*********************************/
void inLevel()
{  
    int dir,mstdir;//�˹ֵķ��� 
    int lcrash=0,//ײ�ֺ�һ��ʱ���ڲ���ײ
	crash_image=1;//ײ��ʱ�˵�ͼƬ������������ż���� 
    PIMAGE img=newimage();
    roleBlood=3;
    score=0;
	drawMap();
	getimage(img, "img\\ren.jpg");
	putimage(rx,ry,img);
	getimage(img, "img\\59�־���.jpg");
	putimage(mstx,msty,img);
	
    for ( ; is_run(); delay_fps(10))//
    {
        //��ս��� 
		cleardevice();
		//���Ƶ�ͼ 
		drawMap();
		//�ж��Ƿ���ײ
		if(lcrash) crash_image++;
		else crash_image=1;
		//�����ƶ�
		dir=roleMove(dir,crash_image);
		//��������ƶ�
		mstdir=mstMove();
        
        //��Ѫ 
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
        
        if(rx>=50&&rx<=100&&ry>=700&&ry<=750)
        {
        	gameOver();
		}
        
    }

}
