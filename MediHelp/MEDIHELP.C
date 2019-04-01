#include<stdio.h>
#include<windows.h>
#include<time.h>
#include<conio.h>
#include<unistd.h> //For Sleep

#define totalDisease 34

//input1[][] = just input from user
//input[][] = edited input(lower, space removed, comma/ and removed)
//x[] = scan file array
//searched_count[]= How many time the symptom was found
//word_file=Symptoms file pointer

//Global Variables:...
char input[35][35],wrongInput[35][35];
char diseaseList[50][35]={"Anemia", "Cancer", "Chickenpox", "Chikungunya", "Cholera", "Chronic Obstructive Pulmonary", "Cirrhosis", "Dengue Fever", "Diabetes",
"Diarrhea", "Gastroenteritis", "Hepatitis A", "Hepatitis B", "Hepatitis C", "Herpes", "Influenza Flu", "Ischemic Cardiomyopathy", "Malaria", "Measles", "Meningitis", "Mumps",
"Neonatal Encephalopathy", "Pneumonia", "Polio", "Preterm Birth Complications", "Rabies", "Respiratory Infection", "Stroke", "Swineflu", "Tuberculosis", "Typhoid", "Urinary Tract Infections",
"Viral Fever", "Yellow Fever", "0"};
int chance[50];
int topchance[10]={-1,-1,-1,-1,-1,-1,-1,-1,-1,-1};
char patientName[30], patientSex[10],patientAge[10];




//Functions:...
int search(FILE *disease_file);
int word_currector(int row);
void file_openar();
void need_help();
void gotoxy (int x, int y);
void admin();
void feedback(int wrongInputRow);
void thanks();

int main()
{
  int i, j, k, lenInput1, total_symptoms, row=0, colm=0, gotoflag=0,wrngAnsFlag=0,wrongInputRow=0;
  char input1[100];
  gotoxy(35,2);
  printf("Welcome!!!\n\n");
  printf("Name Please: ");
  scanf("%s",patientName);
  printf("\nAge: ");
  scanf("%s",&patientAge);
  printf("\nSex: ");
  scanf("%s",patientSex);
  printf("\n\n");
  getchar();
  start:
  if(gotoflag==1)
  {
      system("cls");
      printf("\n\n");
      getchar();
  }
  printf("Enter Your symptom(s) please:\n\n>>");
  gets(input1);
  { //Updating User File...
      FILE *user_file;
      time_t rawtime;
      struct tm * timeinfo;
      time ( &rawtime );
      timeinfo = localtime(&rawtime);
      user_file=fopen("User_info.txt","a");
      fprintf(user_file,"Name: %s   Age: %d   Sex: %s\n",patientName,patientAge,patientSex);
      fprintf(user_file,"%s \n",input1);
      fprintf(user_file,"Time of Input: %s\n\n",asctime(timeinfo));
      fclose(user_file);
  }
  system("cls");
  printf("Searching Result:");
  printf("\n\n");
{   //Input Modification Section...


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
  row=0;colm=0;
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
  //printf("Total Symptoms: %d\n",total_symptoms);
}

//......................................Input Completed..... Variable: input[][], total_symptoms...................

 //Administrative section...
  if(input[0][0]=='a' &&  input[0][1]=='d' && input[0][2]=='m' &&  input[0][3]=='i' &&  input[0][4]=='n' &&  input[0][5]=='l' &&  input[0][6]=='o' &&  input[0][7]=='g' &&  input[0][8]=='i' && input[0][9]=='n'  )
  {
      char username_input[15],pw[15],usrname[20] = "pinpoint",password[20]="123456";
      int lenusrname=8,lenpw=6,same=0;
      system("cls");
      gotoxy(25,3);
      printf("User Name: ");
      scanf("%s",username_input);
      for(i=0;username_input[i]!='\0';i++)
      {
          if(username_input[i]==usrname[i]) same++;
      }
      if(same==lenusrname)
      {
          same=0;
          gotoxy(25,5);
          printf("Password: ");
          for(i=0;i<15;)
          {
            pw[i]=getch();
            if(pw[i]==13) break;   //13=Enter
            if(pw[i]==8)     //8=Backspace
            {
                i--;
            }
            else{
            putch('*');
            i++;
            }
          }
          pw[i]='\0';
          for(i=0;pw[i]!='\0';i++)
          {
              if(pw[i]==password[i]) same++;
          }
          if(same==lenpw)
          {
              admin();
          }
          else
          {
              gotoxy(25,5);
              printf("Wrong Password!");
          }
      }
      else
      {
          gotoxy(25,5);
          printf("Invalid Username!\n");
      }
  }


//...............................Administrative works................................................................................................................
  else
{        //User Section...
{      //Word Correction Section...

  FILE *word_file;
  int same=0,returned,flag=0;
  char file_word[30];  //file_word=take word from symptoms.txt
  row=0,colm=0;
  for(i=0;i<total_symptoms;i++)
  {
      flag=0;
      word_file=fopen("symptoms.txt","r");
      fscanf(word_file,"%s",file_word);
      //printf("Scanned file: %s\n",file_word);
      while(file_word[0]!='0')
      {
          same=0;
          for(j=0;file_word[j]!='\0' && input[i][j]!='\0';j++)
          {
              //printf("%c     %c  \n",file_word[j],input[i][j]);
              if(file_word[j]==input[i][j]) same++;
              //printf("%d\n",same);
          }
          for(j=0;file_word[j]!='\0';j++);   //J = len of file_word
          if(same==j)
          {
              flag=1;
            //printf("%d  for %s\n ",same,file_word );
            break;
          }
          fscanf(word_file,"%s",file_word);
          //printf("Scanned file: %s\n",file_word);
      }
      if(flag==0)
      {
          returned=word_currector(i);
            if(returned==-1)
            {
                wrngAnsFlag=1;
                printf("%s is Invalid Input!!!\n",input[i]);
                for(k=0;input[i][k]!='\0';k++)
                {
                    wrongInput[wrongInputRow][k]=input[i][k];
                }
                wrongInput[wrongInputRow][k]='\0';
                wrongInputRow++;

                for(j=i;j<total_symptoms-1;j++)
                {
                    for(k=0;input[j+1][k]!='\0';k++)
                    {
                        input[j][k]=input[j+1][k];
                    }
                    input[j][k]='\0';
                }
                input[j][0]='\0';
                total_symptoms--;
                i--;
                //printf("after removed: %s     %s    %s total symptoms: %d\n",input[0],input[1],input[2],total_symptoms);
            }
            else
            {
                    continue;
            }
      }
  }
  //printf("After correcting: %s\n",input[0]);
 // printf("After correcting: %s\n",input[1]);
  //printf("After correcting: %s\n",input[2]);
  //printf("After correcting: %s\n",input[3]);
  fclose(word_file);
}

//............................................Input Corrected.................... Variable: input[][].......

{      //Helpline Section...

    for(row=0;input[row][0]!='\0';row++)
    {
        if(input[row][0]=='n' && input[row][1]=='e' && input[row][2]=='e' && input[row][3]=='d' && input[row][4]=='h' && input[row][5]=='e' && input[row][6]=='l' && input[row][7]=='p')
        {
            need_help();
        }
    }

}

//.............................................Helpline Completed...............................................

{    //Searching Section...
    file_openar();
    //system("cls");
    int max,index;
    //for(i=0;i<totalDisease;i++)printf("%d   ",chance[i]);
    for(j=0;j<10;j++)
    {
        max=0;
        index=-1;
        for(i=0;i<totalDisease;i++)  // 34 disease
        {
            if( i!=topchance[0] && i!=topchance[1] && i!=topchance[2] && i!=topchance[3] && i!=topchance[4] && i!=topchance[5] && i!=topchance[6] && i!=topchance[7] && i!=topchance[8] && i!=topchance[9] )
            {
                if(chance[i]>max)
                {
                    max=chance[i];
                    index=i;
                }
            }
        }
        topchance[j]=index;
        //printf("Index %d\n",index);
        //printf("Topchance: %d\n",topchance[j]);
    }
    if(chance[topchance[0]]!=0)
    {
        printf("\nHey %s, You maybe suffering from:\n\n",patientName);
        for(i=0;i<10;i++)
        {
            if( topchance[i]!=-1 && chance[topchance[i]]!=0 )
            printf("Chance of %s disease is %d out of %d.\n",diseaseList[topchance[i]],chance[topchance[i]],total_symptoms);
        }
        printf("\n\nYou Should not depend on this apps. It's better to go to the nearest hospital. :)\n");
    }
    else
    {
        //...
    }

}

}// User Section End...
    printf("\n\nDo You Wanna Try It Again? (y/n)\n>>");
    char x[5];
    scanf("%s",x);
    for(i=0;x[i]!='\0';i++)
    {
        if(x[i]>=65 && x[i]<=90)
            x[i]=x[i]+32;
    }
    if(x[0]=='y' || x[0]=='y' && x[1]=='e' && x[2]=='s')
    {
        gotoflag=1;
        goto start;
    }
    //Feedback section...
    if(wrngAnsFlag==1)
    {
        printf("\nI received an input that is beyond my knowledge.\nWould you like to enrich me with some information?(y/n)\n>>");
        char ans[10];
        scanf("%s",ans);
        for(i=0;ans[i]!='\0';i++)
        {
            if(ans[i]>=65 && ans[i]<=90)
            ans[i]=ans[i]+32;
        }
        if(ans[0]=='y' || ans[0]=='y' && ans[1]=='e' && ans[2]=='s')
        {
            feedback(wrongInputRow);
        }
    }
thanks();
return 0;
}





void file_openar()
{
    FILE *disease_file;
    int i,j;
    char filename[35];

    for(i=0;diseaseList[i][0]!='0';i++)
    {
        for(j=0;diseaseList[i][j]!='\0';j++)
        {
        filename[j]=diseaseList[i][j];
        }
        filename[j++]='.';
        filename[j++]='t';
        filename[j++]='x';
        filename[j++]='t';
        filename[j]='\0';
        //printf("%s\n",filename);
        disease_file=fopen(filename,"r");
        chance[i]=search(disease_file);
        fclose(disease_file);
    }
}

int search(FILE *disease_file)
{
    //printf("%d\n",disease_file);
  int lenf,leni,same,chance=0,row,colm;    //lenf=len of file, leni= len of input
  char x[35];
  while(1)
  {
      fscanf(disease_file,"%s",x);
      //printf("Scanned file:  %s\n",x);
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

int word_currector(int input_row)    //input_row= Row of wrong input
{
    FILE *word_file;
    int i,row,colm,lenWord,lenI,correct=0,error=0;    //lenI= input len
    char ans[10],word[30];
    for(lenI=0;input[input_row][lenI]!='\0';lenI++);
    //printf("lenI: %d\n",lenI);
    word_file=fopen("symptoms.txt","r");
    fscanf(word_file,"%s",word);
    while(word[0]!='0')
    {
        //printf("Scanned Word: %s\n",word);
        for(lenWord=0;word[lenWord]!='\0';lenWord++);
        //printf("lenWord: %d\n",lenWord);
        if(lenWord==lenI || lenWord+1==lenI || lenWord-1==lenI)
        {
            correct=0;
            error=0;
            for(colm=0;colm<lenWord || colm<lenI;colm++)
            {
                //printf("colm: %d   ",colm);
                if(word[colm]==input[input_row][colm])
                    correct++;
                else
                    error++;
                //printf("correct:  %d   error: %d\n",correct,error);
            }
            if(correct>error)
            {
                printf("Did you mean \"");
                printf("%s\" by \" %s\" ?(yes/no)\n>>",word,input[input_row]);
                scanf("%s",ans);
                for(i=0;ans[i]!='\0';i++)
                {
                    if(ans[i]>=65 && ans[i]<=90)
                    ans[i]=ans[i]+32;
                }
                if(ans[0]=='y' && ans[1]=='e' && ans[2]=='s' || ans[0]=='y')
                {
                    //printf("\n %d \n",row);           //input have to be edited
                    for(i=0;word[i]!='\0';i++)
                    {
                        input[input_row][i]=word[i];
                    }
                    input[input_row][i]='\0';
                    return row;
                }
            }
        }
        fscanf(word_file,"%s",word);
    }
    return -1;
}

void need_help()
{
    char help[30];
    system("cls");
    printf("Emergency Contact:\n\n");
    printf("Nearest Blood Bank:\n");
    printf("Ambulance Number:\n");
    printf("Desh Ambulance Service: 01790-509607\n");
    printf("Nearest Hospital List and Location: \n");
    printf(".....\n");
    printf("\n\nNeed any other Help?(yes/no)\n");
    gets(help);
    //........
    printf("%s\n",help);


}

void admin()
{
    int n;
    system("cls");
    printf("Press:\n");
    printf("1 For User Info.\n");
    printf("2 For User Request.\n");
    printf("3 For Edit database.\n");
    scanf("%d",&n);
    if(n==1)
    {
        FILE *file;
        int i;
        char x[80];
        file=fopen("User_info.txt","r");
        for(i=0;fgets(x,80,file)!=NULL && i<40 ;i++)
        {
            printf("%s",x);
            if(i==39)
            {
                printf("Press 1 for next.\nPress 2 for quit\n>>");
                int m;
                scanf("%d",&m);
                if(m==1) i=0;
            }
        }
        printf("Press any key to end...\n");
        getchar();
        getchar();
    }
    else if(n==2)
    {
        FILE *fp;
        fp=fopen("User_req.txt","r");
        char x[100];
        system("cls");
        while(fgets(x,100,fp)!=NULL)
        {
            printf("%s",x);
        }
    }
}

void gotoxy (int x, int y)
{
    COORD coord={0,0};
    coord.X = x; coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void feedback(int wrongInputRow)
{
    system("cls");
    FILE *fp;
    fp=fopen("User_req.txt","a");
    int j,i;
    for(j=0;j<wrongInputRow;j++)
    {
        printf("Are you sure %s is correct input?(y/n)\n",wrongInput[j]);
        char ans[10];
        scanf("%s",ans);
        for(i=0;ans[i]!='\0';i++)
        {
            if(ans[i]>=65 && ans[i]<=90)
            ans[i]=ans[i]+32;
        }
        if(ans[0]=='y' || ans[0]=='y' && ans[1]=='e' && ans[2]=='s')
        {
            fprintf(fp,"%s\n",wrongInput[j]);
        }
        system("cls");
    }
    fclose(fp);
}

void thanks()
{
    system("cls");
    char thanks[]="Thank You!!";
    gotoxy(30,5);
    for(int i=0;thanks[i]!='\0';i++)
    {
        printf("%c",thanks[i]);
        Sleep(200);
    }
}
