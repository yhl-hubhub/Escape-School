#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <graphics.h>
#include "Map.h"
#include "constant.h"


/*******************************
  *Description�����ɵ�ͼ 
  *Last edited by: ϯʫ��
  *Edit time��2020/3/7 20:45 
*********************************/
int drawMap()
{	
	//ÿ�����õ�ͼ�������ݹ���
	PIMAGE imgMap = newimage();
	int i,j;//pMap�е����� 
    int x,y;//ʵ������    
    
    if(lvFlag==1)
	{
		getimage(imgMap, "img\\map1.jpg");
        putimage(0, 0, imgMap);
    }
        for(i=0;i<NUM_COL;i++)//������ͼ��Ԫ�� 
        {
        	y=i*UNIT;
        	
        	for(j=0;j<NUM_ROW;j++)
        	{
        		x=j*UNIT;
        		
        		switch(pMap[i][j])
        		{
        			case 11:
        				getimage(imgMap, "img\\У��.jpg"); 
        				putimage_transparent(NULL,imgMap,x,y,EGERGB(0xff, 0xff, 0xff));
        				break;
        			case 12:
        				getimage(imgMap, "img\\����.jpg"); 
						putimage_transparent(NULL,imgMap,x,y,EGERGB(0xff, 0xff, 0xff));
        				break;
        			case 13:
        				getimage(imgMap, "img\\����.jpg"); 
						putimage_transparent(NULL,imgMap,x,y,EGERGB(0xff, 0xff, 0xff));
        				break;
        			/*case 31:
        				getimage(imgMap, "img\\��.jpg"); 
						putimage_transparent(NULL,imgMap,x,y,EGERGB(0xff, 0xff, 0xff));
        				break;
					case 32:
        				getimage(imgMap, "img\\59�־���.jpg"); 
						putimage_transparent(NULL,imgMap,x,y,EGERGB(0xff, 0xff, 0xff));
        				break;
					case 33:
        				getimage(imgMap, "img\\ddl.jpg"); 
						putimage_transparent(NULL,imgMap,x,y,EGERGB(0xff, 0xff, 0xff));
        				break;	*/
				}
			}
		}
 
    
    
	showScore();
	
        
	delimage(imgMap);
        //��������֮���ʣ�ඹ����Ŀ
        
        //������������
    score=isFoodEaten*5;//(TOTAL-cntJudge)*5;
    /*}*/
    
    return 0;
}


/*******************************
  *Description�� �������,Ҳ���ڹ۲���� 
  *Last edited by: ϯʫ�� 
  *Edit time: 2020/3/7 16:50
*********************************/
void showScore()
{
    char s[15];
    sprintf(s, "%d",score);
    setfont(-30, 0, "����");
    outtextxy(500, 10, s);
}
