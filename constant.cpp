#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <graphics.h>
#include "constant.h"

int MST_START_X = 650;
int MST_START_Y = 100;

int NUM_COL = 15;
int NUM_ROW = 16;

int UNIT = 50;
int UNITCOL = 50;

int rSpeed=10; 

int blockRowLeftUp;
int blockColLeftUp;
int blockRowRightDown;
int blockColRightDown;

int blockRow_Now;
int blockCol_Now;
int blockRow_Next;
int blockCol_Next;

MUSIC music;

//记录血量
int roleBlood = 0;
//记录分数
int score = 0;
//判断关卡
int lvFlag = 0;
int TOTAL = 0;
//记录人物坐标重置坐标
//(rx,ry)
int rx=0;
int ry=0;
//记录怪物坐标
//(mstx,msty)
int mstx=0;
int msty=0;

//吃掉的东西的数量 
int isFoodEaten = 0;







int pMap[16][15]={0};

/*
0  豆子
1  墙1 
2  墙2
4  出生点
9  空白 
10 血量
*/ 
const int pMap1[16][15] = //迷宫一左上角的地图

{   
        { 6, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 5},
        { 0, 0, 0, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 5},
        { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 32, 5},
        { 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 0, 0, 0, 5},
        { 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 5},
        { 2, 0, 0, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2},
        { 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 5},
        { 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 33, 5},
        { 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 5},
        { 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 0, 0, 0, 5},
        { 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 0, 31, 0, 5},
        { 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 5},
        { 2, 0, 0, 0, 0, 0, 0, 0,11, 0, 2, 0, 0, 0, 5},
        { 2, 0, 0, 2, 2, 2, 2, 2, 0, 0, 2, 0, 0, 0, 5},
        { 2, 5, 5, 2,11, 5,12, 2, 5, 5, 2, 5, 2, 2, 2},
        { 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9}
};

const int pMap2[16][15]=
{
1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
1,0,0,2,0,0,0,0,0,9,9,9,9,9,1,
1,0,9,2,9,9,9,2,2,9,9,9,9,9,1,
1,0,9,2,9,9,9,9,0,9,9,9,9,9,1,
1,0,9,9,3,9,9,9,0,9,9,9,9,9,1,
1,9,9,9,9,9,2,9,9,9,9,9,9,9,1,
1,2,2,9,9,9,2,9,9,9,9,9,9,9,1,
1,9,9,9,9,9,2,9,9,9,9,9,9,9,1,
2,9,9,9,0,0,0,9,9,9,9,9,9,9,2,
2,9,9,9,0,0,0,9,9,9,9,9,9,9,2,
2,9,9,9,0,0,0,9,9,9,9,9,9,9,2,
2,9,9,9,0,0,0,9,9,9,9,9,9,9,2,
2,9,9,9,0,0,0,9,9,9,9,9,9,9,2,
2,9,9,9,0,0,0,9,9,9,9,9,9,9,2,
1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
10,10,10,9,9,9,9,9,9,9,9,9,9,9,
};

const int pMap3[16][15]=
{
1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
1,0,0,2,0,0,0,0,0,9,9,9,9,9,1,
1,0,9,2,9,9,9,2,2,9,9,9,9,9,1,
1,0,9,2,9,9,9,9,0,9,9,9,9,9,1,
1,0,9,9,3,9,9,9,0,9,9,9,9,9,1,
1,9,9,9,9,9,2,9,9,9,9,9,9,9,1,
1,2,2,9,9,9,2,9,9,9,9,9,9,9,1,
1,9,9,9,9,9,2,9,9,9,9,9,9,9,1,
2,9,9,9,0,0,0,9,9,9,9,9,9,9,2,
2,9,9,9,0,0,0,9,9,9,9,9,9,9,2,
2,9,9,9,0,0,0,9,9,9,9,9,9,9,2,
2,9,9,9,0,0,0,9,9,9,9,9,9,9,2,
2,9,9,9,0,0,0,9,9,9,9,9,9,9,2,
2,9,9,9,0,0,0,9,9,9,9,9,9,9,2,
1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
10,10,10,9,9,9,9,9,9,9,9,9,9,9,
};
