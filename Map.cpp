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
	for(int i=0;i<NUM_COL;i++){
		y=i*50;
		for(int j=0;j<NUM_ROW;j++)
		{
		    x=j*55;
			if(pMap[i][j]==0)
            {
                getimage(imgMap,"img\\food.jpg",0,0);
                putimage(x,y,imgMap);

                //遍历后剩余总数，计数豆子总数
                cntFood++;
            }
			
			else if(pMap[i][j]==1)
            {
                getimage(imgMap,"img\\shu.jpg",0,0);
                putimage(x,y,imgMap);

            }
            //墙
            else if(pMap[i][j]==2)
            {
                getimage(imgMap,"img\\wall.jpg",0,0);
                putimage(x,y,imgMap);

            }
            else if(pMap[i][j]==10)
            {
                getimage(imgMap,"img\\blood.jpg",0,0);
                putimage(x,y,imgMap);
                
            }
	}
	}
	

                //delay_ms(1000);
	showScore();
	
	/*for(int i=0;i<NUM_COL;i++)
    {
        y=i*50;
        for(int j=0;j<NUM_ROW;j++)
        {
            x=j*55;
            
            //豆子
            if(pMap[i][j]==0)
            {
                getimage(imgMap,"img\\food.jpg",0,0);
                putimage(x,y,imgMap);

                //遍历后剩余总数，计数豆子总数
                cntFood++;
            }

            //cntJudge=cntFood;
            //树
            
            //怪物
            /*else if(pMap[i][j]==3)
            {
                getimage(imgMap,"img\\guaiwu1.jpg",0,0);
                putimage(x,y,imgMap);
                //传出怪物所在的位置
                mstrow=i;
                mstcol=j;
                //怪物随机移动后的坐标就是（i,j）==(mstrow,mstcol)
                //每次遍历都通过怪物坐标pMap[mstrow][mstcol]的值贴图并把坐标（i,j）传给(mstrow,mstcol)
                //所以不需要修改pMap[mstrow][mstcol]的横纵坐标
            }*/

            /*else if(pMap[i][j]==5)  //左
            {
                getimage(imgMap,"img\\renL.jpg",0,0);
                putimage(x,y,imgMap);
            }
            else if(pMap[i][j]==6)  //右
            {
                getimage(imgMap,"img\\renR.jpg",0,0);
              putimage(x,y,imgMap);
            }
            else if(pMap[i][j]==7) //上
            {
                getimage(imgMap,"img\\renU.jpg",0,0);
                putimage(x,y,imgMap);
            }
            else if(pMap[i][j]==8) //下
            {
                getimage(imgMap,"img\\renD.jpg",0,0);
                putimage(x,y,imgMap);
            }*/
            /*else if(pMap[i][j]==9)  //空
            {
                getimage(imgMap,"img\\white.jpg",0,0);
                putimage(x,y,imgMap);	
            }*/
            //血量
           /* else if(pMap[i][j]==10)
            {
                getimage(imgMap,"img\\blood.jpg",0,0);
                putimage(x,y,imgMap);
                
            }

            //人物
            else if(pMap[i][j]==4)
            {
                getimage(imgMap,"img\\ren.jpg",0,0);
                putimage(x,y,imgMap);
                row=i;
                col=j;*/

                /*pMap[i][j]==6;------->置空，不贴图，实现更新后原位置的图片消失
                重新生成地图
                    row=i;
                    col=j;
                    左 pMap[row][col-1] 将上一个位置置为 pMap[row][col]==9 ，调用重新生成地图的函数updMap
                                        将此位置置为 pMap[row][col-1]==5
                    右 pMap[row][col+1]  置为6
                    上 pMap[row-11][col]     7
                    下 pMap[row+1][col]      8
                */
        /*    }
            

        }*/
        
		delimage(imgMap);
        //遍历数组之后的剩余豆子数目
        cntJudge=cntFood;
       
        
        //在这里计算分数
        score=(TOTAL-cntJudge)*5;
    /*}*/
    
    return 0;
}

//输出分数
void showScore()
{
    char s[5];
    sprintf(s, "%d", score);
    setfont(-30, 0, "宋体");
    outtextxy(430, 510, s);
}
