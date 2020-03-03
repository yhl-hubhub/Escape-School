#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <graphics.h>
#include "Map.h"
#include "constant.h"
#include "interaction.h"
#include "Interface.h"

int drawMap();

//记录豆子的数目
int cntFood;
int cntJudge;
//记录血量
int cntBlood;


/*******************************
  *Description：进入关卡后的控制函数
  *Last edited by: 席诗祺
*********************************/
void inLevel()
{
    PIMAGE img = newimage();
    getimage(img, "img\\di.jpg",0,0);
    putimage(0, 0, img);
    
	drawMap();
	
    for ( ; is_run();delay_fps(10) )
    {
        //人物移动
        roleMove();
        //判断是否相撞
        crashJudge();
        //怪物随机移动
        mstMove();
        
        //判断是否吃完所有豆子，吃完进入下一关卡
        if(cntJudge==0)
        {
            //showScore();
            //进入下一关卡
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


extern int WIDTH;
extern int LENGTH; 


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
    cntBlood=0;
    
	showScore();
	
	for(int i=0;i<WIDTH;i++)
    {
        y=i*55;
        for(int j=0;j<LENGTH;j++)
        {
            x=j*50;
            imgMap=newimage();
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
            //怪物
            else if(pMap[i][j]==3)
            {
                getimage(imgMap,"img\\guaiwu1.jpg",0,0);
                putimage(x,y,imgMap);
                //传出怪物所在的位置
                mstrow=i;
                mstcol=j;
                //怪物随机移动后的坐标就是（i,j）==(mstrow,mstcol)
                //每次遍历都通过怪物坐标pMap[mstrow][mstcol]的值贴图并把坐标（i,j）传给(mstrow,mstcol)
                //所以不需要修改pMap[mstrow][mstcol]的横纵坐标
            }

            else if(pMap[i][j]==5)  //左
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
            }
            else if(pMap[i][j]==9)  //空
            {
                getimage(imgMap,"img\\white.jpg",0,0);
                putimage(x,y,imgMap);
            }
            //血量
            else if(pMap[i][j]==10)
            {
                getimage(imgMap,"img\\blood.jpg",0,0);
                putimage(x,y,imgMap);
                //遍历后剩余血量
                cntBlood++;
            }

            //人物
            else if(pMap[i][j]==4)
            {
                getimage(imgMap,"img\\ren.jpg",0,0);
                putimage(x,y,imgMap);
                row=i;
                col=j;

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
            }
            delimage(imgMap);

        }

        //遍历数组之后的剩余豆子数目
        cntJudge=cntFood;
        //传出数据
        roleBlood=cntBlood;
        //在这里计算分数
        score=(TOTAL-cntJudge)*5;
    }
    
    return 0;
}
