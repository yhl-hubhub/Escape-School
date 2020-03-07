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
	for(int i=0;i<NUM_COL;i++){
		y=i*50;
		for(int j=0;j<NUM_ROW;j++)
		{
		    x=j*55;
			if(pMap[i][j]==0)
            {
                getimage(imgMap,"img\\food.jpg",0,0);
                putimage(x,y,imgMap);

                //������ʣ��������������������
                cntFood++;
            }
			
			else if(pMap[i][j]==1)
            {
                getimage(imgMap,"img\\shu.jpg",0,0);
                putimage(x,y,imgMap);

            }
            //ǽ
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
            
            //����
            if(pMap[i][j]==0)
            {
                getimage(imgMap,"img\\food.jpg",0,0);
                putimage(x,y,imgMap);

                //������ʣ��������������������
                cntFood++;
            }

            //cntJudge=cntFood;
            //��
            
            //����
            /*else if(pMap[i][j]==3)
            {
                getimage(imgMap,"img\\guaiwu1.jpg",0,0);
                putimage(x,y,imgMap);
                //�����������ڵ�λ��
                mstrow=i;
                mstcol=j;
                //��������ƶ����������ǣ�i,j��==(mstrow,mstcol)
                //ÿ�α�����ͨ����������pMap[mstrow][mstcol]��ֵ��ͼ�������꣨i,j������(mstrow,mstcol)
                //���Բ���Ҫ�޸�pMap[mstrow][mstcol]�ĺ�������
            }*/

            /*else if(pMap[i][j]==5)  //��
            {
                getimage(imgMap,"img\\renL.jpg",0,0);
                putimage(x,y,imgMap);
            }
            else if(pMap[i][j]==6)  //��
            {
                getimage(imgMap,"img\\renR.jpg",0,0);
              putimage(x,y,imgMap);
            }
            else if(pMap[i][j]==7) //��
            {
                getimage(imgMap,"img\\renU.jpg",0,0);
                putimage(x,y,imgMap);
            }
            else if(pMap[i][j]==8) //��
            {
                getimage(imgMap,"img\\renD.jpg",0,0);
                putimage(x,y,imgMap);
            }*/
            /*else if(pMap[i][j]==9)  //��
            {
                getimage(imgMap,"img\\white.jpg",0,0);
                putimage(x,y,imgMap);	
            }*/
            //Ѫ��
           /* else if(pMap[i][j]==10)
            {
                getimage(imgMap,"img\\blood.jpg",0,0);
                putimage(x,y,imgMap);
                
            }

            //����
            else if(pMap[i][j]==4)
            {
                getimage(imgMap,"img\\ren.jpg",0,0);
                putimage(x,y,imgMap);
                row=i;
                col=j;*/

                /*pMap[i][j]==6;------->�ÿգ�����ͼ��ʵ�ָ��º�ԭλ�õ�ͼƬ��ʧ
                �������ɵ�ͼ
                    row=i;
                    col=j;
                    �� pMap[row][col-1] ����һ��λ����Ϊ pMap[row][col]==9 �������������ɵ�ͼ�ĺ���updMap
                                        ����λ����Ϊ pMap[row][col-1]==5
                    �� pMap[row][col+1]  ��Ϊ6
                    �� pMap[row-11][col]     7
                    �� pMap[row+1][col]      8
                */
        /*    }
            

        }*/
        
		delimage(imgMap);
        //��������֮���ʣ�ඹ����Ŀ
        cntJudge=cntFood;
       
        
        //������������
        score=(TOTAL-cntJudge)*5;
    /*}*/
    
    return 0;
}

//�������
void showScore()
{
    char s[5];
    sprintf(s, "%d", score);
    setfont(-30, 0, "����");
    outtextxy(430, 510, s);
}
