/*2-D Snake Game v2.1(C)
Developer: ABDUL MOHSIN SIDDIQI
(Tested on GCC Compiler (Codeblocks)) */

#include<stdio.h>
#include<windows.h> //gotoxy()
#include<time.h>    //delay()
#include<stdlib.h>
#include<conio.h>   //kbhit()

int x1[2001],y1[2001];  //Circular Queues that sequentially stores the
                        //respective coordinate values acquired by snake
int f=0,r=5,d=4,fd=0;   //f-Front,r-Rear,d-Direction (1-up,2-left,3-down,4-right)
int x=55,y=20,col=0,score=0;

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

void display()  //Displays Everything outside the Game Arena (Borderline)
{
    int i;
    system("CLS");
    gotoxy(0,2);
    printf("\t\t\t\t %c%c%c%c%c%c%c%c%c%c%c%c%c\n",201,205,205,205,205,205,205,205,205,205,205,205,187);
    printf("\t\t\t\t %cSNAKES v2.1%c\n",186,186);
    printf("\t\t\t\t %c%c%c%c%c%c%c%c%c%c%c%c%c",200,205,205,205,205,205,205,205,205,205,205,205,188);
    printf("\n\t %c",201);
    for(i=0;i<63;i++)
    printf("%c",205);
    printf("%c",187);
    for(i=0;i<30;i++)
    printf("\n\t %c\t\t\t\t\t\t\t\t %c",186,186);
    printf("\n\t %c",200);
    for(i=0;i<63;i++)
    printf("%c",205);
    printf("%c",188);
    gotoxy(9,39);
    printf("Snakes v2.1 (C) by ABDUL MOHSIN SIDDIQI");
}

void displaysnake()     //Displays the snake
{
  int i;
  i=f;
  while(i!=r)
    {   gotoxy(x1[i],y1[i]);
        printf("%c",1);
        if(i==2000)
            i=0;
        else
            i++;}
}

void food()   //Changes the coordinate value of food if the snake ate the food
{
  int i,fl=0;
    if((r==0 && x1[2000]==x && y1[2000]==y) || (r!=0 && x1[r-1]==x && y1[r-1]==y) )
    {score+=100; //Score Increment
    gotoxy(62,4);
    printf("SCORE: %d",score);
    fd=1;
    while(1)
    {   x=10+(rand())%63;
	y=6+(rand())%30;
	i=f;
	while(i!=r)
	{   if(x1[i]==x && y1[i]==y) fl=1;
	    if(i==2000)	i=0;
	    else	i++;}
	    if(fl==0) break;
	    else fl=0;
	}
    }
}
int collision()     //Checks if snake collides with its own body
{
    int i=f,c=0,b;
    if(r==0)
	b=2000;
    else
	b=r-1;
    while(i!=r)
    {
    if(x1[i]==x1[b] && y1[i]==y1[b])
	c++;
    if(i==2000)
	i=0;
    else
	i++;}
    if(c==2)
	return 1;
    else
	return 0;
}

void snakemove()      //Controls the movement of snake
{
    int l;
    if(fd==0)
    {gotoxy(x1[f],y1[f]);
    printf(" ");
    if(f==2000)
	f=0;
    else
	f++;}
    else
	fd=0;

    if(d==1)    //Moving Up
	{if(r==0)
		{if(y1[2000]==6) l=36;
		else l=y1[2000];
		x1[0]=x1[2000],y1[0]=l-1;}
	 else
		{if(y1[r-1]==6) l=36;
		else l=y1[r-1];
		x1[r]=x1[r-1],y1[r]=l-1;}}
    else if(d==2)   //Moving Left
	{if(r==0)
		{if(x1[2000]==10) l=73;
		else l=x1[2000];
		x1[0]=l-1,y1[0]=y1[2000];}
	 else
		{if(x1[r-1]==10) l=73;
		else l=x1[r-1];
		x1[r]=l-1,y1[r]=y1[r-1];}}
    else if(d==3)   //Moving Down
	{if(r==0)
		{if(y1[2000]==35) l=5;
		else l=y1[2000];
		x1[0]=x1[2000],y1[0]=l+1;}
	else
		{if(y1[r-1]==35) l=5;
		else l=y1[r-1];
		x1[r]=x1[r-1],y1[r]=l+1;}}
    else if(d==4)   //Moving Right
	{if(r==0)
		{if(x1[2000]==72) l=9;
		else l=x1[2000];
		x1[0]=l+1,y1[0]=y1[2000];}
	else
		{if(x1[r-1]==72) l=9;
		else l=x1[r-1];
		x1[r]=l+1,y1[r]=y1[r-1];}}

    if(r==2000)
	r=0;
    else
	r++;
}

void snake()    //Calls the above functions for Gameplay
{
    displaysnake();
    food();
    snakemove();
    col=collision();
    gotoxy(x,y);
    printf("%c\b",4);   //Displays food
}

int main()
{
    char c,c1=77;
    int i,flag=0;   //Flag for Key operation

    srand(time(NULL));
    for(i=f;i<r;i++)    x1[i]=35+i,y1[i]=20;

    display();
    gotoxy(9,41);   printf("Press any key to start............");
    getch();

    display();
    gotoxy(x,y);    printf("*\b");
    gotoxy(62,4);   printf("SCORE: 0");

    while(1)
    {snake();
    if(col==1)      //Snake Collides with its own body
	break;
    if(kbhit())     //Until a key is pressed
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
    delay(50);}  //For Snake movement
    if(col==1)
    {
	gotoxy(9,41);
	printf("boOM! You Scored: %d!",score);
    }
    gotoxy(9,43);
    printf("Press any key to exit....\n");
    getch();
    return 0;
}
