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

void loadMenu();
void homeMenu();
void choice();
void introduce();
void enterNext();
void showScore();
void gameOver();


//���ؽ���
void loadMenu()
{
    PIMAGE pLoad = newimage();
    getimage(pLoad, "img\\load.jpg",0,0);
    putimage(0, 0, pLoad);
    delimage(pLoad);

}


//������
void homeMenu()
{
    mouse_msg mMsg = {0};
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
    /*while(mousemsg())
        {
            getimage(background,"img\\renL.jpg",0,0);
            putimage(0, 0, background); 
        }
        
     */
    
    
    for ( ; is_run(); delay_fps(60))
    {
    	while(mousemsg())
        {
        	mMsg = getmouse();
            
        }
        if(mMsg.is_up()&&mMsg.is_left())
		{
			PIMAGE istart = newimage();
            getimage(istart, "img\\start.jpg",0,0);
            putimage(0, 0, istart);
            delimage(istart);
            break;
		}
    }
		
    

    // ��֡������
    char str[20];
    sprintf(str, "fps %.02f", getfps()); //����getfpsȡ�õ�ǰ֡��
    setcolor(WHITE);
    outtextxy(0, 0, str);

    //�����
    mMsg = getmouse();
   
    for ( ; is_run(); delay_fps(60))
    {
        //��ȡ�����Ϣ�����������ȴ����ȴ�������ϢΪֹ
        while(mousemsg())
        {
            mMsg = getmouse();
        }
        
        //ѡ��ؿ�
		if(mMsg.is_up()&&mMsg.is_left())//&&mMsg.x>140&&mMsg.x<335&&mMsg.y>260&&mMsg.y<300
        {
            choice();
        }
        
        //��Ϸ˵���������û���� 
        /*else if(mMsg.is_up()&&mMsg.is_left()&&mMsg.x>140&&mMsg.x<335&&mMsg.y>340&&mMsg.y<370)
        {
            introduce();
        }
        
        //�˳�
        else if(mMsg.is_up()&&mMsg.is_left()&&mMsg.x>140&&mMsg.x<335&&mMsg.y>400&&mMsg.y<435)
        {
            cleardevice();
            closegraph();
        }*/

    }
    getch();
}


//ѡ��ؿ�����
void choice()
{
    PIMAGE pChioce = newimage();
    getimage(pChioce, "img\\choice.jpg",0,0);
    putimage(0, 0, pChioce);
    delimage(pChioce);
    mouse_msg mMsg = {0};
    for ( ; is_run(); delay_fps(60))
    {
        //��ȡ�����Ϣ�����������ȴ����ȴ�������ϢΪֹ
        while(mousemsg())
        {
            mMsg = getmouse();
        }
        //ѡ��ؿ�01
        if(mMsg.is_up()&&mMsg.is_left()&&mMsg.x>166&&mMsg.x<272&&mMsg.y>120&&mMsg.y<365)
        {
            lvFlag=1;
            TOTAL=t1;
            rx=55;ry=100;
            mstx=275;msty=250;
            //���Ƶ�ͼ 
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


//��Ϸ����
void introduce()
{
    PIMAGE pIntro = newimage();
    getimage(pIntro, "img\\introduce.bmp",0,0);
    putimage(0, 0, pIntro);
    delimage(pIntro);
    mouse_msg mMsg = {0};
    for ( ; is_run(); delay_fps(60))
    {
        //��ȡ�����Ϣ�����������ȴ����ȴ�������ϢΪֹ
        while(mousemsg())
        {
            mMsg = getmouse();
        }
        //ѡ��ؿ�01
        if(mMsg.is_up()&&mMsg.is_left()&&mMsg.x>0&&mMsg.x<500&&mMsg.y>0&&mMsg.y<550)
        {
            cleardevice();
            homeMenu();
        }

    }
    getch();
}


//������һ�ؿ�
void enterNext()
{
    PIMAGE pNext = newimage();
    getimage(pNext, "img\\next.jpg",0,0);
    putimage(0, 0, pNext);
    delimage(pNext);
    mouse_msg mMsg = {0};
    for ( ; is_run(); delay_fps(60))
    {
        //��ȡ�����Ϣ�����������ȴ����ȴ�������ϢΪֹ
        while(mousemsg())
        {
            mMsg = getmouse();
        }
        //����ѡ�� 
        if(mMsg.is_up()&&mMsg.is_left()&&mMsg.x>309&&mMsg.x<375&&mMsg.y>410&&mMsg.y<510)
        {
            cleardevice();
            choice();
        }
        //������һ�ؿ�
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
        //�˳�
        else if(mMsg.is_up()&&mMsg.is_left()&&mMsg.x>211&&mMsg.x<275&&mMsg.y>407&&mMsg.y<511)
        {
            cleardevice();
            closegraph();

        }
        //���뵽
        /*else if(mMsg.is_up()&&mMsg.is_left()&&mMsg.x>50&&mMsg.x<135&&mMsg.y>350&&mMsg.y<450)
        {
            gameOver();
        }*/

    }
}


//������Ϸ��������
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
        //��ȡ�����Ϣ�����������ȴ����ȴ�������ϢΪֹ
        while(mousemsg())
        {
            mMsg = getmouse();
        }
        //���¿�ʼ
        if(mMsg.is_up()&&mMsg.is_left()&&mMsg.x>44&&mMsg.x<200&&mMsg.y>494&&mMsg.y<532)
        {
            //�ж��ڵڼ������¿�ʼ������
            if(lvFlag==1)
            {
                for(int i=0;i<NUM_COL;i++)
                {
                    for(int j=0;j<NUM_ROW;j++)
                        pMap[i][j]=pMap1[i][j];
                }
                rx=55;ry=100;
                mstx=275;
                msty=250;
                inLevel();
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
        //�˳�
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


//��Ϸ��������
void gameOver()
{
    PIMAGE pgover = newimage();
    getimage(pgover, "img\\gover.jpg",0,0);
    putimage(0, 0, pgover);
    delimage(pgover);
    //��ʾ����
    char s[5];
    sprintf(s, "%d", score);
    setfont(-30, 0, "����");
    outtextxy(145, 355, s);

    mouse_msg mMsg = {0};
    for ( ; is_run(); delay_fps(60))
    {
        //��ȡ�����Ϣ�����������ȴ����ȴ�������ϢΪֹ
        while(mousemsg())
        {
            mMsg = getmouse();
        }
        //���¿�ʼ
        if(mMsg.is_up()&&mMsg.is_left()&&mMsg.x>32&&mMsg.x<179&&mMsg.y>392&&mMsg.y<431)
        {
            homeMenu();
        }
        //�˳�
        else if(mMsg.is_up()&&mMsg.is_left()&&mMsg.x>367&&mMsg.x<440&&mMsg.y>400&&mMsg.y<435)
        {
            cleardevice();
            closegraph();
        }
        //
        else
        {

        }
    }
}

