/*Tic-Tac-Toe Game (R) (BOT VS Player)
Developer:ABDUL MOHSIN SIDDIQI
(Tested on Turbo C compiler)*/

#include<stdio.h>
#include<stdlib.h>
#include<time.h>        //delay()
#include<conio.h>       //gotoxy(),getch(),clrscr()
char a[3][3],name[2][20],val[2]={'X','O'};
int x=7,y=9,c=0,i1=1,j1=1,flag=0,pn,cn;

void print()    //Displays the current Grid
{
    int i,j;
    clrscr();
    printf("~ TIC-TAC-TOE ~\n\n%s - X\n%s - O\n\n",name[0],name[1]);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c\n",201,205,205,205,203,205,205,205,203,205,205,205,187);
    for(i=0;i<3;i++)
	{
	    for(j=0;j<3;j++)
	    printf("%c %c ",186,a[i][j]);
	    printf("%c\n",186);
	    if(i<2)
	    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c\n",204,205,205,205,206,205,205,205,206,205,205,205,185);
	}
	printf("%c%c%c%c%c%c%c%c%c%c%c%c%c\n",200,205,205,205,202,205,205,205,202,205,205,205,188);
}

void playername()   //Asks Player's name
{
    clrscr();
    printf("~ TIC-TAC-TOE ~\n\nEnter Your name: ");
    scanf("%s",name[pn]);
    strupr(name[pn]);  //Converts To Uppercase
    clrscr();
}

void arrowmove()    //For Cursor Movement
{
    char arrow;//,ch[2]={42,248};
    gotoxy(x,y);
    //printf("%c",ch[c%2]);
    arrow=getch();
    while(arrow!=13)    //Until Enter Key is pressed
    {
	arrow=getch();
	//printf("\b%c\b",a[i1][j1]);
	if(arrow==72 && y>7)    //Up arrow key
	    y-=2,i1--;
	else if(arrow==75 && x>3)   //Left arrow key
	    x-=4,j1--;
	else if(arrow==80 && y<11)  //Down Arrow key
	    y+=2,i1++;
	else if(arrow==77 && x<11)  //Right Arrow Key
	    x+=4,j1++;
	gotoxy(x,y);
	//printf("%c",ch[c%2]);
	arrow=getch();
	while(arrow!=0 && arrow!=13)    //If any other key is pressed
	    arrow=getch();
    }
}
void insert()   //Insertion into grid for Corresponding Player
{
    if(c%2==0)
	{   a[i1][j1]='X';
	printf("X");}
    else
	{   a[i1][j1]='O';
	printf("O");}
}
int compcheck()     //Check for Computer's Pattern
{
    int i,j,f=0;
    for(i=0;i<3 && f==0;i++)
	if(a[i][0]+a[i][1]+a[i][2]==2*val[cn]+32)
	    for(j=0;j<3 && f==0;j++)
		if(a[i][j]==' ')
		    i1=i,j1=j,f=1;
    for(j=0;j<3 && f==0;j++)
	if(a[0][j]+a[1][j]+a[2][j]==2*val[cn]+32)
	    for(i=0;i<3 && f==0;i++)
		if(a[i][j]==' ')
		    i1=i,j1=j,f=1;
    if(f==0 && a[0][0]+a[1][1]+a[2][2]==2*val[cn]+32)
	    for(i=0,j=0;j<3 && f==0;i++,j++)
	    if(a[i][j]==' ')
		i1=i,j1=j,f=1;
    if(f==0 && a[0][2]+a[1][1]+a[2][0]==2*val[cn]+32)
	for(i=0,j=2;i<3 && f==0;i++,j--)
	    if(a[i][j]==' ')
		i1=i,j1=j,f=1;
    return f;
}
int playercheck()   //Checks for Player's Pattern
{
    int i,j,f=0;
    for(i=0;i<3 && f==0;i++)
	if(a[i][0]+a[i][1]+a[i][2]==2*val[pn]+32)
	    for(j=0;j<3 && f==0;j++)
		if(a[i][j]==' ')
		    i1=i,j1=j,f=1;
    for(j=0;j<3 && f==0;j++)
	if(a[0][j]+a[1][j]+a[2][j]==2*val[pn]+32)
	    for(i=0;i<3 && f==0;i++)
		if(a[i][j]==' ')
		    i1=i,j1=j,f=1;
    if(f==0 && a[0][0]+a[1][1]+a[2][2]==2*val[pn]+32)
	    for(i=0,j=0;j<3 && f==0;i++,j++)
	    if(a[i][j]==' ')
		i1=i,j1=j,f=1;
    if(f==0 && a[0][2]+a[1][1]+a[2][0]==2*val[pn]+32)
	    for(i=0,j=2;i<3 && f==0;i++,j--)
	    if(a[i][j]==' ')
		i1=i,j1=j,f=1;
    return f;
}
void changexy()     //Changes coordinate value to current pointer
{
    if(i1==0)   y=7;
    else if(i1==1)  y=9;
    else if(i1==2)  y=11;
    if(j1==0)   x=3;
    else if(j1==1)  x=7;
    else if(j1==2)  x=11;
}
void compmove()     //Computer's move control
{
    int fp,fc;
    if(a[1][1]==' ')
	{i1=1,j1=1;}
    else if(c==1 && a[1][1]!=' ')
    {
	while(i1==1 || j1==1 || a[i1][j1]!=' ')
	    i1=rand()%3,j1=rand()%3;
    }
    else
    {
    fc=compcheck();
    if(fc==0)
        fp=playercheck();
    if(fc==0 && fp==0 && c==3 && (a[0][0]==val[cn] || a[0][2]==val[cn] || a[2][2]==val[cn] || a[2][0]==val[cn]))
    {
		while(i1==1 || j1==1 || a[i1][j1]!=' ')
	{
	    i1=rand()%3;
	    j1=rand()%3;
	}
    }
	else
    {
	while(a[i1][j1]=='X' || a[i1][j1]=='O')
	    {
		i1=rand()%3;
		j1=rand()%3;
	    }
    }
    }
    changexy();
    fc=0;
    fp=0;
    insert();
}
int check()     //Checks if a Player had won
{
    int i,j;
    for(i=0;i<3;i++)
	if(a[i][0]+a[i][1]+a[i][2]==3*79 || a[i][0]+a[i][1]+a[i][2]==3*88)
	    return 1;
    for(j=0;j<3;j++)
	if(a[0][j]+a[1][j]+a[2][j]==3*79 || a[0][j]+a[1][j]+a[2][j]==3*88)
	    return 1;
    if(a[0][0]+a[1][1]+a[2][2]==3*79 || a[0][0]+a[1][1]+a[2][2]==3*88)
	return 1;
    if(a[0][2]+a[1][1]+a[2][0]==3*79 || a[0][2]+a[1][1]+a[2][0]==3*88)
	return 1;
    return 0;
}

int main(void)
{
    memset(a,' ',sizeof(a));
    srand(time(NULL));
    pn=rand()%2;
    cn=(pn+1)%2;
    strcpy(name[cn],"Computer");
    playername();
    while(c<9)
    {
	print();
	printf("\n\n%s's turn...",name[c%2]);
	if(c%2==pn)
	{   arrowmove();
	    if(a[i1][j1]==' ')  //Empty Slot
	    {   insert();
            delay(500);}
	    else
	    {   print();
		printf("\n\nAlready Filled slot!");
		delay(500);
		continue;}
	}
	else
	    {compmove();
	    delay(500);}
	if(c>=4)    //Checks after 5 moves in all
	    flag=check();
	if(flag==1)
	    break;
	c++;
    }
    print();
    if(flag==0)     //All slots filled and no consecutivity
	printf("\n\nThe Match Ended in a Draw!!!");
    else
	printf("\n\n%s wins!!!",name[c%2]);
    delay(500);
    printf("\n\nPress any key to quit............");
    getch();
    return 0;
}
