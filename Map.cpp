#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <graphics.h>
#include "Map.h"
#include "constant.h"


int drawMap();

//��¼���ӵ���Ŀ
int cntFood;
int cntJudge;



/*******************************
  *Description�����ɵ�ͼ 
  *Last edited by: ϯʫ��
*********************************/
int drawMap()
{
	PIMAGE imgMap;
	int x =0;
    int y =0;
    
	//ÿ�����õ�ͼ�������ݹ���
    
    cntFood=0;
    
    imgMap=newimage();
    getimage(imgMap, "img\\di.jpg");
    putimage(0, 0, imgMap);
    
    getimage(imgMap,"img\\food.jpg",0,0);
    putimage(10*UNITROW,10*UNITCOL,imgMap);
    
//	for(int i=0;i<NUM_COL;i++){
//		y=i*UNITCOL;
//		for(int j=0;j<NUM_ROW;j++)
//		{
//		    x=j*UNITROW;
//			if(pMap[i][j]==0)
//            {
//                getimage(imgMap,"img\\food.jpg",0,0);
//                putimage(x,y,imgMap);
//
//                //������ʣ��������������������
//                cntFood++;
//            }
//			
//			else if(pMap[i][j]==1)
//            {
//                getimage(imgMap,"img\\shu.jpg",0,0);
//                putimage(x,y,imgMap);
//
//            }
//            //ǽ
//            else if(pMap[i][j]==2)
//            {
//                getimage(imgMap,"img\\wall.jpg",0,0);
//                putimage(x,y,imgMap);
//
//            }
//            else if(pMap[i][j]==10)
//            {
//                getimage(imgMap,"img\\blood.jpg",0,0);
//                putimage(x,y,imgMap);
//                
//            }
//		}
//	}
	

                //delay_ms(1000);
	showScore();
	
        
		delimage(imgMap);
        //��������֮���ʣ�ඹ����Ŀ
        cntJudge=cntFood;
       
        
        //������������
        score=10;//(TOTAL-cntJudge)*5;
    /*}*/
    
    return 0;
}

//�������
void showScore()
{
    char s[5];
    sprintf(s, "%d", watch);
    setfont(-30, 0, "����");
    outtextxy(750, 10, s);
}
