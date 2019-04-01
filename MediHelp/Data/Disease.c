#include<stdio.h>
main()
{
    char x[]="All symptoms 1",t[30],d[35];
    int i;
    for(i=0;x[i]!='\0';i++)
    {
        d[i]=x[i];
    }
    d[i++]='.';
    d[i++]='t';
    d[i++]='x';
    d[i++]='t';
    d[i++]='\0';
    printf("%s\n",d);
    FILE *y;
    y=fopen(d,"r");
    fscanf(y,"%s",t);
    printf("%s",t);



}
