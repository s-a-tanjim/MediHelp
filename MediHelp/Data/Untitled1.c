#include<stdio.h>
//input1[][] = just input from user
//input[][] = edited input(lower, space removed, comma/ and removed)
//x[] = scan file array
char input[30][30];
int search(int disease_file);
int main()
{
  int i,j,k,lenInput1,total_symptoms;
  char input1[100];
  printf("Welcome!!!\nEnter Your symptoms please:\n>>");
  gets(input1);
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

//............................................Search Complete(Before finding errors)..... variables: X_chance(int)






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
                  chance++;
              }
          }
      }
  }
  return chance;
}

