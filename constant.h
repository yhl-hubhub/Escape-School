typedef struct 
{
    int isGet;
}Element_TypeDef;

typedef struct 
{
    int x;
    int y;
}COORDS;

typedef struct 
{
    int isGet;
    COORDS start;
    int x,y;
}CHARACTER;

extern int watch;
extern int roleBlood;
extern int score;
extern int lvFlag;
extern int TOTAL;

extern int blockRow_Now;
extern int blockCol_Now;
extern int blockRow_Next;
extern int blockCol_Next;


const int MST_START_X = 650;//怪物初始座标 
const int MST_START_Y = 100;

const int NUM_COL = 15;//列数 
const int NUM_ROW = 16;//行数 

const int UNIT = 50;//单元格长宽 
const int UNITCOL = 50;

extern int rSpeed;
extern int mstSpeed;

extern int pMap[16][15];

extern const int pMap1[16][15];
extern const int pMap2[16][15];
extern const int pMap3[16][15];

//extern CHARACTER mst1;

extern MUSIC music;

extern int rx;//人物坐标 
extern int ry;

extern int mstx;//怪物坐标 
extern int msty;



extern int isFoodEaten;
