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


const int MST_START_X = 650;//�����ʼ���� 
const int MST_START_Y = 100;

const int NUM_COL = 15;//���� 
const int NUM_ROW = 16;//���� 

const int UNIT = 50;//��Ԫ�񳤿� 
const int UNITCOL = 50;

extern int rSpeed;
extern int mstSpeed;

extern int pMap[16][15];

extern const int pMap1[16][15];
extern const int pMap2[16][15];
extern const int pMap3[16][15];

//extern CHARACTER mst1;

extern MUSIC music;

extern int rx;//�������� 
extern int ry;

extern int mstx;//�������� 
extern int msty;



extern int isFoodEaten;
