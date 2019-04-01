#include<stdio.h>
char symptoms[250][50];

void samefinder()
{
    int i,j,k,same,lensym,flag=0,row=0,countsame=0,countdiff=0;
    char word[50];
    FILE *file;
    //FILE *new_file;
    //new_file=fopen("uniquesymptom.txt","a");
    file=fopen("symptomm.txt","r");
    fscanf(file,"%s",word);
    //printf("%s\n",word);
    for(i=0;word[0]!='0';i++)
    {
        flag=0;
        for(j=0;j<row;j++)
        {
            same=0;
            for(k=0;word[k]!='\0' && symptoms[j][k]!='\0';k++)
            {
                if(word[k]==symptoms[j][k]) same++;
            }
            for(lensym=0;symptoms[j][lensym]!='\0';lensym++);
            if(same==lensym)
            {
                countsame++;
                flag=1;
                //printf("same: %d  len: %d w: %s       s: %s\n",same,lensym,word,symptoms[j]);
                break;
            }
        }
        if(flag==0)
        {
            countdiff++;
            for(j=0;word[j]!='\0';j++)
            {
                symptoms[row][j]=word[j];

            }
            symptoms[row][j]='\0';
            //printf("In Symptom: %s\n",symptoms[row]);
            row++;
        }
        fscanf(file,"%s",word);
        //printf("%s\n",word);
    }
    symptoms[row][0]='0';

    //printf("\n\n\n\n\n");
    printf("Same:  %d    Diff:  %d\n",countsame,countdiff);
    //for(i=0;symptoms[i][0]!='0';i++)
    //{
     //   printf("%s\n",symptoms[i]);
        //fprintf(new_file,"%s\n",symptoms[i]);
   // }
    //fprintf(new_file,"%s\n",symptoms[i]);
    //fprintf(new_file,"\n\n\nTotal Unique Symptoms: %d\n",countdiff);
}



main()
{
    int i,j,l,row,colm,rs=0,count=0;
    char a='a',b='a',c,d;
    char sortedlist[230][50],word[50];
    samefinder();
    FILE *sortfile;

    sortfile=fopen("Sortedsymtom.txt","a");


        for(a='a' ;a<='z'; a++ )
        {
            for(b='a';b<='z';b++)
            {
                for(c='a'; c<='z' ; c++)
                {

                    for(row=0;symptoms[row][0]!='0'; row++ )
                    {
                        if(symptoms[row][0]==a && symptoms[row][1]==b && symptoms[row][2]==c )
                            {
                                for(i=0;symptoms[row][i]!='\0';i++)
                                {
                                    sortedlist[rs][i]=symptoms[row][i];
                                }
                                sortedlist[rs][i]='\0';
                                rs++;
                                count++;
                            }
                    }

                }
            }
        }
        sortedlist[rs][0]='0';


    for(i=0;sortedlist[i][0]!='0';i++)
    {
        //fprintf(sortfile,"%s\n",sortedlist[i]);
    }
    //fprintf(sortfile,"0");
    printf("Total found: %d\n",count);



}
