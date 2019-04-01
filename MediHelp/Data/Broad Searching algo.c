#include<stdio.h>
int len_a,len_b,len_c;

int chance_finder(char a[], char b[], char c[], char s1[], char s2[],char s3[], char s4[], char s5[])
{
    int i, counta=0, countb=0, countc=0, chance=0, aa=0, bb=0, cc=0, len_s1, len_s2, len_s3 ,len_s4 ,len_s5;

    for(len_s1=0;s1[len_s1]!='\0';len_s1++);
    for(len_s2=0;s2[len_s2]!='\0';len_s2++);
    for(len_s3=0;s3[len_s3]!='\0';len_s3++);
    for(len_s4=0;s4[len_s4]!='\0';len_s4++);
    for(len_s5=0;s5[len_s5]!='\0';len_s5++);

    //s1..................................
    for(i=0;i<len_s1;i++)
    {
        if(s1[i]==a[i])
            counta++;
        if(s1[i]==b[i])
            countb++;
        if(s1[i]==c[i])
            countc++;
    }
    if(counta==len_a)
    {
        chance++;
        aa=1;
    }
    if(countb==len_b)
    {
        chance++;
        bb=1;
    }
    if(countc==len_c)
    {
        chance++;
        cc=1;
    }

    //s2...........................
    counta=0;
    countb=0;
    countc=0;
    for(i=0;i<len_s2;i++)
    {
        if(s2[i]==a[i] && aa==0)
            counta++;
        if(s2[i]==b[i] && bb==0)
            countb++;
        if(s2[i]==c[i] && cc==0)
            countc++;
    }
    if(counta==len_a)
    {
        chance++;
        aa=1;
    }
    if(countb==len_b)
    {
        chance++;
        bb=1;
    }
    if(countc==len_c)
    {
        chance++;
        cc=1;
    }
    //s3...........................
    counta=0;
    countb=0;
    countc=0;
    for(i=0;i<len_s3;i++)
    {
        if(s3[i]==a[i] && aa==0)
            counta++;
        if(s3[i]==b[i] && bb==0)
            countb++;
        if(s3[i]==c[i] && cc==0)
            countc++;
    }
    if(counta==len_a)
    {
        chance++;
        aa=1;
    }
    if(countb==len_b)
    {
        chance++;
        bb=1;
    }
    if(countc==len_c)
    {
        chance++;
        cc=1;
    }
    //s4......................................
    counta=0;
    countb=0;
    countc=0;
    for(i=0;i<len_s4;i++)
    {
        if(s4[i]==a[i] && aa==0)
            counta++;
        if(s4[i]==b[i] && bb==0)
            countb++;
        if(s4[i]==c[i] && cc==0)
            countc++;
    }
    if(counta==len_a)
    {
        chance++;
        aa=1;
    }
    if(countb==len_b)
    {
        chance++;
        bb=1;
    }
    if(countc==len_c)
    {
        chance++;
        cc=1;
    }
    //s5..............................
    counta=0;
    countb=0;
    countc=0;
    for(i=0;i<len_s5;i++)
    {
        if(s5[i]==a[i] && aa==0)
            counta++;
        if(s5[i]==b[i] && bb==0)
            countb++;
        if(s5[i]==c[i] && cc==0)
            countc++;
    }
    if(counta==len_a)
    {
        chance++;
        aa=1;
    }
    if(countb==len_b)
    {
        chance++;
        bb=1;
    }
    if(countc==len_c)
    {
        chance++;
        cc=1;
    }
    return chance;
}

int dengue(char a[],char b[],char c[])
{
    int ch;
    char s1[]="headache";
    char s2[]="high fever";
    char s3[]="nausea";
    char s4[]="joint pain";
    char s5[]="rash";
    ch=chance_finder(a,b,c,s1,s2,s3,s4,s5);
    return ch;
}
int malaria(char a[], char b[], char c[])
{
    int ch;
    char s1[]="headache";
    char s2[]="high fever";
    char s3[]="nausea";
    char s4[]="profuse sweating";
    char s5[]="vomiting";
    ch=chance_finder(a,b,c,s1,s2,s3,s4,s5);
    return ch;
}

int viral_fever(char a[], char b[], char c[])
{
    int ch;
    char s1[]="fatigue";
    char s2[]="fever";
    char s3[]="weakness";
    char s4[]="headache";
    char s5[]="joint pain";
    ch=chance_finder(a,b,c,s1,s2,s3,s4,s5);
    return ch;
}


main()
{
    char a[20],b[20],c[20];
    int x,y,z,i;
    printf("1st Symptom: ");
    scanf("%s",a);
    for(len_a=0;a[len_a]!='\0';len_a++)
    {
        if(a[len_a]>=65 && a[len_a]<=90)
        a[len_a]=a[len_a]+32;
    }
    printf("\n2nd Symptom: ");
    scanf("%s",b);
    for(len_b=0;b[len_b]!='\0';len_b++)
    {
        if(b[len_b]>=65 && b[len_b]<=90)
            b[len_b]=b[len_b]+32;
    }
    printf("\n3rd Symptom: ");
    scanf("%s",c);
    for(len_c=0;c[len_c]!='\0';len_c++)
    {
        if(c[len_c]>=65 && c[len_c]<=90)
            c[len_c]=c[len_c]+32;
    }
    x=dengue(a,b,c);
    y=malaria(a,b,c);
    z=viral_fever(a,b,c);
    if(x>0)
    {
        printf("\nChance of Dengue is  %d  out of 3",x);
    }
    if(y>0)
    {
        printf("\nChance of Malaria is  %d  out of 3",y);
    }
    if(z>0)
    {
        printf("\nChance of Viral Fever is  %d  out of 3",z);
    }

}
