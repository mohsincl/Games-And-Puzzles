/*2-D Snake Game v1.0(C)
Developer: ABDUL MOHSIN SIDDIQI
(Tested on GCC Compiler (Codeblocks)) */

#include<stdio.h>
#include<windows.h>
#include<time.h>
#include<stdlib.h>
#include<conio.h>
int x1[1001],y1[1001],f=0,r=5,d=4,fd=0,x=55,y=20,col=0,score=0;

COORD coordinate = {0,0};
void gotoxy(int xx, int yy){
   coordinate.X = xx; coordinate.Y =  yy;
   SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coordinate);
}

void delay(unsigned int mseconds)
{
    clock_t goal = mseconds + clock();
    while (goal > clock());
}


void display()
{
    int i;
    system("CLS");
    gotoxy(1,1);
    printf("\t\t\t\t  -----------\n");
    printf("\t\t\t\t  SNAKES v1.0\n");
    printf("\t\t\t\t  -----------\n");
    printf("\n\t  ");
    for(i=0;i<63;i++)
    printf("_");
    for(i=0;i<30;i++)
    printf("\n\t |\t\t\t\t\t\t\t\t |");
    printf("\n\t |");
    for(i=0;i<63;i++)
    printf("_");
    printf("|");
    gotoxy(9,39);
    printf("Snakes v1.0 (C) by ABDUL MOHSIN SIDDIQI");
}
void ds()
{
  int i;
  i=f;
  while(i!=r)
    {gotoxy(x1[i],y1[i]);
    printf("o");
    if(i==1000)
	i=0;
    else
	i++;}
}

void food()
{
  int i,fl=0;
    if((r==0 && x1[1000]==x && y1[1000]==y) || (r!=0 && x1[r-1]==x && y1[r-1]==y) )
    {score+=100;
    gotoxy(63,4);
    printf("SCORE: %d",score);
    fd=1;
    while(1)
    {
	x=10+(rand())%63;
	y=6+(rand())%30;
	i=f;
	while(i!=r)
	{if(x1[i]==x && y1[i]==y) fl=1;
	if(i==1000)	i=0;
	else	i++;}
	if(fl==0) break;
	else fl=0;
    }
    }
}
int collision()
{
    int i=f,c=0,b;
    if(r==0)
	b=1000;
    else
	b=r-1;
    while(i!=r)
    {
    if(x1[i]==x1[b] && y1[i]==y1[b])
	c++;
    if(i==1000)
	i=0;
    else
	i++;}
    if(c==2)
    return 1;
    else
    return 0;
}

void queue()
{
    int l;
    if(fd==0)
    {gotoxy(x1[f],y1[f]);
    printf(" ");
    if(f==1000)
	f=0;
    else
	f++;}
    else
	fd=0;

    if(d==1)
	{if(r==0)
		{if(y1[1000]==6) l=36;
		else l=y1[1000];
		x1[0]=x1[1000],y1[0]=l-1;}
	 else
		{if(y1[r-1]==6) l=36;
		else l=y1[r-1];
		x1[r]=x1[r-1],y1[r]=l-1;}}
    else if(d==2)
	{if(r==0)
		{if(x1[1000]==10) l=73;
		else l=x1[1000];
		x1[0]=l-1,y1[0]=y1[1000];}
	 else
		{if(x1[r-1]==10) l=73;
		else l=x1[r-1];
		x1[r]=l-1,y1[r]=y1[r-1];}}
    else if(d==3)
	{if(r==0)
		{if(y1[1000]==35) l=5;
		else l=y1[1000];
		x1[0]=x1[1000],y1[0]=l+1;}
	else
		{if(y1[r-1]==35) l=5;
		else l=y1[r-1];
		x1[r]=x1[r-1],y1[r]=l+1;}}
    else if(d==4)
	{if(r==0)
		{if(x1[1000]==72) l=9;
		else l=x1[1000];
		x1[0]=l+1,y1[0]=y1[1000];}
	else
		{if(x1[r-1]==72) l=9;
		else l=x1[r-1];
		x1[r]=l+1,y1[r]=y1[r-1];}}

    if(r==1000)
	r=0;
    else
	r++;
}

void sm()
{
    ds();
    food();
    queue();
    col=collision();
    gotoxy(x,y);
    printf("*\b");
}

int main()
{
    char c,c1=77;
    int i,j,k,flag=0;
    system("CLS");
    srand(time(NULL));
    for(i=f;i<r;i++)
        x1[i]=35+i,y1[i]=20;
    display();
    gotoxy(9,41);
    printf("Press any key to start..........");
    getch();
    display();
    gotoxy(x,y);
    printf("*\b");
    gotoxy(63,4);
    printf("SCORE: 0");
    while(1)
    {sm();
    if(col==1) break;
    if(_kbhit())
    {
    c=_getch();
	if(c==72 && c1!=80) d=1;      //up
	else if(c==75 && c1!=77) d=2; //left
	else if(c==80 && c1!=72) d=3; //down
	else if(c==77 && c1!=75) d=4; //right
	else flag=1;
       if(flag==0)
	   c1=c;
       flag=0;
    }
    delay(50);}
    if(col==1)
    {
	gotoxy(9,41);
	printf("GAME OVER!\n");
    }
    getch();
    return 0;
}
