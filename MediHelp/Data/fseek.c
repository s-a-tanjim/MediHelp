#include<stdio.h>
main()
{
    FILE *x;
    char t[30];
    x=fopen("ttt.txt","r");
    fseek(x,20,0);
    fscanf(x,"%s",t);
    printf("%s",t);
}


