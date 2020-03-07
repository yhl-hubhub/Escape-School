#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <graphics.h>
#include "Map.h"
#include "constant.h"


int drawMap();

//记录豆子的数目
int cntFood;
int cntJudge;



/*******************************
  *Description：生成地图 
  *Last edited by: 席诗祺
*********************************/
int drawMap()
{
	PIMAGE imgMap;
	int x =0;
    int y =0;
    
	//每次重置地图都将数据归零
    
    cntFood=0;
    
    imgMap=newimage();
    getimage(imgMap, "img\\di.jpg");
    putimage(0, 0, imgMap);
    
    getimage(imgMap,"img\\shu.jpg",0,0);
    putimage(4*UNIT,1*UNIT,imgMap);
    
//	for(int i=0;i<NUM_COL;i++){
//		y=i*UNITCOL;
//		for(int j=0;j<NUM_ROW;j++)
//		{
//		    x=j*UNIT;
//			if(pMap[i][j]==0)
//            {
//                getimage(imgMap,"img\\food.jpg",0,0);
//                putimage(x,y,imgMap);
//
//                //遍历后剩余总数，计数豆子总数
//                cntFood++;
//            }
//			
//			else if(pMap[i][j]==1)
//            {
//                getimage(imgMap,"img\\shu.jpg",0,0);
//                putimage(x,y,imgMap);
//
//            }
//            //墙
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
        //遍历数组之后的剩余豆子数目
        cntJudge=cntFood;
       
        
        //在这里计算分数
        score=10;//(TOTAL-cntJudge)*5;
    /*}*/
    
    return 0;
}

//输出分数
void showScore()
{
    char s[15];
    sprintf(s, "%d,%d,%d,%d", rx,ry,blockRow_Now,blockCol_Now);
    setfont(-30, 0, "宋体");
    outtextxy(500, 10, s);
}
