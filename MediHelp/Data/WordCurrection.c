#include<stdio.h>
char words[30][30]={"09highfever","06nausea","09jointpain","04rash","15profusesweating","08vomiting","05fever","08weakness","08headache"};
main()
{
    int i,j,k,r,c,lenW,lenX,correct=0,error=0,max_correct=0,columnnewX=0;      //r=Row  c=Column
    char x[30],newX[30][30];
    printf("Enter Symptom: ");
    gets(x);
    for(lenX=0;x[lenX]!='\0';lenX++);
    // printf("lenX: %d\n",lenX);
    for(r=0;r<9;r++)
    {
        // printf("r: %d\n",r);
        lenW=(words[r][0]-48)*10+words[r][1]-48;
       // printf("lenW: %d\n",lenW);
        if(lenW==lenX)
        {
            correct=0;
            error=0;
            for(c=2,k=0;c<lenW+2;c++,k++)
            {
                //printf("c: %d   ",c);
                //printf("words: %c   X: %c    ",words[r][c],x[k]);
                if(words[r][c]==x[k])
                    correct++;
                else
                    error++;
                //printf("correct:  %d   error: %d\n",correct,error);
            }

            if(correct>max_correct) max_correct=correct;
            if(correct>error)
            {
                for(i=0,k=2;i<lenW;i++,k++)
                {
                    newX[columnnewX][i]=words[r][k];
                    //printf("newX: %c   words: %c   i: %d   columnnewX: %d\n",newX[columnnewX][i],words[r][k],i,columnnewX);
                }
                newX[columnnewX][i]='\0';
                columnnewX++;
            }
        }
    }
    printf("Did you mean \"");
    printf("%s\" ?",newX[0]);

}
