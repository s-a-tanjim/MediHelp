#include<stdio.h>
#include<windows.h>
#include<conio.h>
//#include<unistd.h>



void gotoxy (int x, int y)
{
    COORD coord={0,0};
    coord.X = x; coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}


main()
{
    int i;
    char pw[20];
    gotoxy(25,2);
    printf("xxxx\n");
    Sleep(2000);
    printf("Password: ");

    for(i=0;i<15;)
    {
        pw[i]=getch();
        if(pw[i]==13) break;
        if(pw[i]==8)
        {
            i--;
        }
        else{
        putch('*');
        i++;
        }
    }
    pw[i]='\0';
    printf("\n\n%s",pw);
    printf("\n\n%d",pw[0]);
    printf("\n\n%d",pw[1]);
    printf("\n\n%d",pw[2]);
    printf("\n\n%d",pw[3]);
    printf("\n\n%d",pw[4]);
    printf("\n\n%d",pw[5]);

}
