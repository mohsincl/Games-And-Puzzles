/*Tic-Tac-Toe Game (R) (Player VS Player)
Developer:ABDUL MOHSIN SIDDIQI
(Tested on Turbo C compiler)*/

#include<stdio.h>
#include<time.h>        //delay()
#include<conio.h>       //gotoxy(),getch(),clrscr()
char a[3][3],name[2][20];
int x=7,y=9,c=0,i1=1,j1=1,flag=0;

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

void playername()   //Asks Respective Player's name
{
   int i;
   clrscr();
   for(i=1;i<=2;i++)
   {    printf("~ TIC-TAC-TOE ~\n\nEnter Player %d name: ",i);
        scanf("%s",name[i-1]);
        strupr(name[i-1]);  //Converts To Uppercase
        clrscr();
   }
}

void arrowmove()    //For Cursor Movement
{
    char arrow,ch[2]={42,248};
    print();
    printf("\n\n%s's turn...",name[c%2]);
    gotoxy(x,y);
    printf("%c",ch[c%2]);
    arrow=getch();
    while(arrow!=13)    //Until Enter Key is pressed
    {
        arrow=getch();
        printf("\b%c\b",a[i1][j1]);
        if(arrow==72 && y>7)    //Up arrow key
            y-=2,i1--;
        else if(arrow==75 && x>3)   //Left arrow key
            x-=4,j1--;
        else if(arrow==80 && y<11)  //Down Arrow key
            y+=2,i1++;
        else if(arrow==77 && x<11)  //Right Arrow Key
            x+=4,j1++;
        gotoxy(x,y);
        printf("%c",ch[c%2]);
        arrow=getch();
        while(arrow!=0 && arrow!=13)    //If any other key is pressed
            arrow=getch();
    }
}
void insert()   //Insertion into grid for Corresponding Player
{
    if(c%2==0)
	{   a[i1][j1]='X';
        printf("\bX");}
    else
	{   a[i1][j1]='O';
        printf("\bO");}
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
    playername();
    while(c<9)
    {
        arrowmove();
        if(a[i1][j1]==' ')  //Empty Slot
        {   insert();
            delay(500);}
        else
        {   print();
            printf("\n\nAlready Filled slot!");
            delay(500);
            continue;}
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
