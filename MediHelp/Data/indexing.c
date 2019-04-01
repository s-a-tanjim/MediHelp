#include<stdio.h>

int chance[5]={1,2,3,0,2};
int topchance[5]={-1,-1,-1,-1,-1};


main()
{
    int max,index,j,i;
    for(j=0;j<5;j++)
    {
        max=0;
        index=-1;
        for(i=0;i<5;i++)  //  disease
        {
            if( i!=topchance[0] && i!=topchance[1] && i!=topchance[2] && i!=topchance[3] && i!=topchance[4] )
            {
                if(chance[i]>max)
                {
                    max=chance[i];
                    index=i;
                    //printf("max: %d  index: %d\n",max,i);
                }
            }
        }
        topchance[j]=index;
       // printf("\n\nmax: %d\n",max);
        //printf("Topchance: %d\n\n",topchance[j]);
    }






}
