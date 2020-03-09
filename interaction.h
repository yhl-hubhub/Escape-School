typedef struct 
{
    int isGet;
    int start_x;
    int start_y;
    int mstx;
    int msty;
}Monster_TypeDef;

extern int roleMove(int ldir,int crash_image); 
extern int mstMove();
extern int crashJudge(CHARACTER mst);
extern int mstMove_struct(CHARACTER* mst);

