#include<stdio.h>

main()
{
    int i, j;
    char x[80];
    FILE *file;
    file=fopen("xx.txt","r");
    while(fgets(x,80,file)!=NULL)
    {
        for(i=0;i<80;i++)
        {
            if(x[i]==10)
            {
                x[i]='\0';
                break;
            }
        }
        printf("%s\n",x);

    }





}
