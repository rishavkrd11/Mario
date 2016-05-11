#include<windows.h>
#include <stdio.h>
#include<conio.h>
#include<time.h>
#include<process.h>
#include<stdlib.h>
//mukularoradce@gmail.com
void gotoxy(int x,int y);
void delay(unsigned int mseconds);
void Right();
void Left();
void Up();
void Down();
void BaseLine();
void ObstacleLeft();
void UpDelay(); //Needs Correction
void ObstacleRight();

COORD coord={0,0};
extern int x=0;
extern int y=8;
extern int o=0;

int main()
{
    int i;
    BaseLine();
    gotoxy(0,8);
    printf("$");
    while(1){
    //system("cls");
    char a=getch();
    if(x!=o-1 && x!=o+1){
    switch(a)
    {
    case 'a':
       Left();
       break;
    case 'd':
        Right();
        break;
    case 'w':
        Up();
        UpDelay();
        Down();
        break;

    }
    }
    else if (x==o-1)
        ObstacleLeft();
    else if (x==o+1)
        ObstacleRight();
    if (a=='m')
        break;
    }
    //system("cls");
    //printf("%d",x);
    //getch();
    return 0;
}
void ObstacleLeft()
{
    char a=getch();
    if (a=='a')
        Left();
    if(a=='w')
    {
        Up();
        UpDelay();
        if(y!=8&&x!=o)
        {
            Down();
        }

    }
}
void ObstacleRight()
{
    char a=getch();
    if(a=='d')
        Right();
    if(a=='w')
    {
        Up();
        UpDelay();
        if(y!=8&&x!=o)
        {
            Down();
        }

    }
}
void Left()
{
    BaseLine();
    x--;
    gotoxy(x,y);

    printf("$");
    delay(70);
}

void Right()
{
    BaseLine();
    x++;
    gotoxy(x,y);

    printf("$");
    delay(70);
}


void Up()
{

y--;
int i;
BaseLine();
//delay(70);
gotoxy(x,y);
printf("$");


}
void Down()
{
    y++;
    //delay(2000);
    BaseLine();
    gotoxy(x,y);
    printf("$");
}
void UpDelay()
{
    clock_t start =700+ clock();
        while(start>clock())
            {
            char a=getch();
            if (a=='a')
                Left();
            if(a=='d')
                Right();

            }
}
void BaseLine()
{
    int i;
    o=7;
    system("cls");
    for (i=0;i<80;i++){
        gotoxy(i,9);
        printf("_");}
    gotoxy(o,8);
    printf("O");
}

void gotoxy(int x,int y)
{
    coord.X=x; coord.Y=y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);

}
void delay(unsigned int mseconds)
{
    clock_t goal = mseconds + clock();
    while (goal > clock());
}
