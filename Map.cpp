#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <graphics.h>
#include "Map.h"
#include "constant.h"


/*******************************
  *Description：生成地图 
  *Last edited by: 席诗祺
  *Edit time：2020/3/7 20:45 
*********************************/
int drawMap()
{	
	//每次重置地图都将数据归零
	PIMAGE imgMap = newimage();
	int i,j;//pMap中的坐标 
    int x,y;//实际坐标    
    
    if(lvFlag==1)
	{
		getimage(imgMap, "img\\map1.jpg");
        putimage(0, 0, imgMap);
    }
        for(i=0;i<NUM_COL;i++)//遍历地图的元素 
        {
        	y=i*UNIT;
        	
        	for(j=0;j<NUM_ROW;j++)
        	{
        		x=j*UNIT;
        		
        		switch(pMap[i][j])
        		{
        			case 11:
        				getimage(imgMap, "img\\校徽.jpg"); 
        				putimage_transparent(NULL,imgMap,x,y,EGERGB(0xff, 0xff, 0xff));
        				break;
        			case 12:
        				getimage(imgMap, "img\\咖啡.jpg"); 
						putimage_transparent(NULL,imgMap,x,y,EGERGB(0xff, 0xff, 0xff));
        				break;
        			case 13:
        				getimage(imgMap, "img\\蛋糕.jpg"); 
						putimage_transparent(NULL,imgMap,x,y,EGERGB(0xff, 0xff, 0xff));
        				break;
        			/*case 31:
        				getimage(imgMap, "img\\鹅.jpg"); 
						putimage_transparent(NULL,imgMap,x,y,EGERGB(0xff, 0xff, 0xff));
        				break;
					case 32:
        				getimage(imgMap, "img\\59分卷子.jpg"); 
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
        //遍历数组之后的剩余豆子数目
        
        //在这里计算分数
    score=isFoodEaten*5;//(TOTAL-cntJudge)*5;
    /*}*/
    
    return 0;
}


/*******************************
  *Description： 输出分数,也用于观察变量 
  *Last edited by: 席诗祺 
  *Edit time: 2020/3/7 16:50
*********************************/
void showScore()
{
    char s[15];
    sprintf(s, "%d",score);
    setfont(-30, 0, "宋体");
    outtextxy(500, 10, s);
}
