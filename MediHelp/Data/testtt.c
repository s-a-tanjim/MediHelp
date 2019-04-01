#include<stdio.h>
//input1[][] = just input from user
//input[][] = edited input(lower, space removed, comma/ and removed)
//x[] = scan file array
//searched_count[]= How many time the symptom was found

char words[30][20]={"09highfever","06nausea","09jointpain","04rash","15profusesweating","08vomiting","05fever","08weakness","08headache"};
char input[15][20];
int searched_count[30]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

int search(int disease_file);
int word_currector(char x[]);

int main()
{
   unsigned long long int t;
  int i,j,k,lenInput1,total_symptoms;
  char input1[100];
  printf("Welcome!!!\nEnter Your symptoms please:\n>>");
  gets(input1);
  system("cls");
  printf("Searching /..");
  for(t=0;t<=100000000;t++);
  system("cls");
  printf("Searching ..\\");
  for(t=0;t<=100000000;t++);
  system("cls");
  printf("Searching /..");
  for(t=0;t<=100000000;t++);
  system("cls");
  printf("Searching ..\\");
  system("cls");
  printf("Searching Result:");
  printf("\n\n");
  for(i=0;input1[i]!='\0';i++)                //Space remover && Lower case
  {
      if(input1[i]>=65 && input1[i]<=90)
          input1[i]=input1[i]+32;

      if(input1[i]==32)
      {
          for(j=i;input1[j]!='\0';j++)
          {
              input1[j]=input1[j+1];
          }
          --i;
      }
  }
  lenInput1=i;
  int row=0,colm=0;
  j=0;
  for(i=0;i<=lenInput1;i++)                    // "And" , "," removing    "<=" for null checking
  {
      if(input1[i]=='a' && input1[i+1]=='n' && input1[i+2]=='d')
      {
          for(colm=0;j<i;colm++,j++)
          {
              input[row][colm]=input1[j];
          }
          input[row][colm]='\0';
          row++;
          i=i+2;
          j=j+3;

      }
      else if(input1[i]==44)
      {
          for(colm=0;j<i;colm++,j++)
          {
              input[row][colm]=input1[j];
          }
          input[row][colm]='\0';
          j++;
          row++;
      }
      else if(input1[i]=='\0')
      {
          for(colm=0;j<i;colm++,j++)
          {
              input[row][colm]=input1[j];
          }
          input[row][colm]='\0';
          row++;
          break;
      }
  }
  input[row][0]='\0';
  total_symptoms=row;
  //printf("%s\n",input[0]);
  //printf("%s\n",input[1]);
  //printf("%s\n",input[2]);
  //printf("%s\n",input[3]);

//............................. Input Complete.... Variable: input[][],total_symptoms

  FILE *dengue,*viralfever,*malaria;
  int dengue_chance=0,malaria_chance=0,viralfever_chance=0;
  dengue=fopen("dengue.txt","r");
  dengue_chance=search(dengue);
  fclose(dengue);
  viralfever=fopen("viralfever.txt","r");
  viralfever_chance=search(viralfever);
  fclose(viralfever);
  malaria=fopen("malaria.txt","r");
  malaria_chance=search(malaria);
  fclose(malaria);
  printf("chance of dengue: %d out of %d\n",dengue_chance,total_symptoms);
  printf("chance of viral fever: %d out of %d\n",viralfever_chance,total_symptoms);
  printf("chance of malaria: %d out of %d\n",malaria_chance,total_symptoms);
  //printf("%d  %d  %d",searched_count[0],searched_count[1],searched_count[2]);
//........................................Search Complete(Before finding errors)..... variables: X_chance(int)

  char corrected_word[15][30];
  row=0,colm=0;
  for(i=0;i<total_symptoms;i++)
  {
      if(searched_count[i]==0)
      {
        char x[30];
        for(j=0;input[i][j]!='\0';j++)
        {
            x[j]=input[i][j];
        }
        x[j]='\0';
        j=word_currector(x[30]);
        if(j==1)
        {
            for(j=0;x[j]!='\0';j++)
            {

            }
        }
        else
            continue;

      }
  }





}


int search(int disease_file)
{
  int lenf,leni,same,chance=0,row,colm;    //lenf=len of file, leni= len of input
  char x[30];
  while(1)
  {
      fscanf(disease_file,"%s",x);
      if(x[0]=='0')
          break;
      for(lenf=0;x[lenf]!='\0';lenf++);   //len of file array(x)
      for(row=0;input[row][0]!='\0';row++)
      {
          for(leni=0;input[row][leni]!='\0';leni++);   //len of input array
          if(lenf==leni)
          {
              same=0;
              for(colm=0;input[row][colm]!='\0';colm++)
              {
                  if(input[row][colm]==x[colm])
                      same++;
              }
              if(same==lenf)
              {
                  searched_count[row]=searched_count[row]+1;
                  chance++;
              }
          }
      }
  }
  return chance;
}


int word_currector(char x[])
{
    int i,j,k,row,colm,lenW,lenX,correct=0,error=0;
    char ans[10];

    for(lenX=0;x[lenX]!='\0';lenX++);
    // printf("lenX: %d\n",lenX);
    for(row=0;row<9;row++)        //9= total symptoms in words
    {
        // printf("row: %d\n",row);
        lenW=(words[row][0]-48)*10+words[row][1]-48;
       // printf("lenW: %d\n",lenW);
        if(lenW==lenX)
        {
            correct=0;
            error=0;
            for(colm=2,k=0;colm<lenW+2;colm++,k++)
            {
                //printf("colm: %d   ",colm);
                //printf("words: %c   X: %c    ",words[row][colm],x[k]);
                if(words[row][colm]==x[k])
                    correct++;
                else
                    error++;
                //printf("correct:  %d   error: %d\n",correct,error);
            }
            if(correct>error)
            {
                printf("Did you mean \"");
                printf("%s\" by \" %s\" ?(yes/no)\n>>",words[row],x);
                scanf("%s",ans);
                for(i=0;ans[i]!='\0';i++)
                {
                    if(ans[i]>=65 && ans[i]<=90)
                    ans[i]=ans[i]+32;
                }
                if(ans[0]=='y' && ans[1]=='e' && ans[2]=='s' || ans[0]=='y')
                {
                        return row;
                }
                else
                {
                    continue;
                }

            }
        }
    }
    return 0;
}
