/*T-Rex Chrome based Game v3.0(C)
Developer: ABDUL MOHSIN SIDDIQI
(Tested on Turbo C compiler) */

#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include<conio.h>
int x=20,y=31,cn=0,flag=0,high=0,score=0,dl=90,col=0,cc=0,r=0,f=0,ob[10],sz[10],v=-1,d;

void display()  //Display function
{
    int i;
    gotoxy(0,2);
    clrscr();
    printf("\n\t\t\t\t %c%c%c%c%c%c%c%c%c%c%c%c\n",201,205,205,205,205,205,205,205,205,205,205,187);
    printf("\t\t\t\t %cTyREX v3.0%c\n",186,186);
    printf("\t\t\t\t %c%c%c%c%c%c%c%c%c%c%c%c",200,205,205,205,205,205,205,205,205,205,205,188);
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
    gotoxy(52,6);
    printf("HI: %d",high);
    gotoxy(11,32);
    for(i=0;i<63;i++)
    if(i%2==0)
	printf("%c",219);
    else
	printf("%c",223);
    gotoxy(10,39);
    printf("TyREX v3.0 (C) by ABDUL MOHSIN SIDDIQI");
}

void dinodisp()     //Dispalys the Dinosaur
{
    gotoxy(x-1,y-3); printf("%c",221);
    gotoxy(x-1,y-2); printf("%c",221);
    gotoxy(x-5,y-1); printf("%c%c%c%c%c",223,223,219,219,221);
    gotoxy(x-3,y);   printf("%c%c",221,221);
    gotoxy(x-1,y-4); printf("%c%c\b",220,220);
}

void dinoclear()    //Clears the Dinosaur
{
    gotoxy(x-1,y-3); printf(" ");
    gotoxy(x-1,y-2); printf(" ");
    gotoxy(x-5,y-1); printf("     ");
    gotoxy(x-3,y);   printf("  ");
    gotoxy(x-1,y-4); printf("  \b");
}
void obsdisp() //Displays the obstacles
{
    int j,i=f;
    while(i!=r)
    {
	j=sz[i];
	while(j--)
	{gotoxy(ob[i],31-j);
	printf("%c",178);}
	gotoxy(ob[i],30);
	if(i==9)	i=0;
	else   i++;
    }
}
void base()     //Displays the ground
{
    int i,i1;
    if(cc==2)
	cc=0;
    gotoxy(11,32);
    i1=cc%2;
    for(i=i1;i<63+i1;i++)
    if(i%2==0) printf("%c",219);
    else printf("%c",223);
}

void obsclear()    //Clears the obstacles
{
    int j,i=f;
    while(i!=r)
    {
	j=sz[i];
	while(j--)
	{gotoxy(ob[i],31-j);
	printf(" ");}
	ob[i]--;
	if(i==9)	i=0;
	else 	i++;
    }
}
void obstacle()     //Logic behind the Obstacle frequency
{
    if(v==-1)
    {d=10+rand()%20;
    v=0;}
    v++;
    if(v==d)
    {v=-1;
    ob[r]=73;
    sz[r]=1+(rand()%3);
    if(r==9)	r=0;
    else r++;
    }
    if(ob[f]==10)
    {  if(f==9) f=0;
       else	f++;
    }
    obsdisp();
}

void check()    //Checks If Dino Collides with obstacle
{
    int i=f,j,k;
    while(i!=r)
    {
	for(k=1;k<=4;k++)
	{
		for(j=0;j<sz[i];j++)
		{
			if(x-k==ob[i] && y-1==31-j) {col=1; break;}
			if(k>=1 && k<=3 && x-k==ob[i] && y==31-j) {col=1; break;}
		}

		if(col==1) break;
	}
	if(i==9)	i=0;
	else 	i++;
    }
}

void operations()   //Sequence of operations during the gameplay
{
    base();
    obsclear();
    obstacle();
    dinodisp();
    check();
}

int main()
{
    char c,ch;
    srand(time(NULL));
    while(1)
    {display();
    gotoxy(28,21);   printf("Press any key to START.......");
    getch();
    display();
    gotoxy(62,6);	printf("SCORE: %d",score);

    while(1)
    {oper();
    if(col==1)      //Dino Collides with an obstacle
	break;
    if(kbhit())     //Until a key is pressed
    {
	c=getch();
	if(c==0)
	{
	    c=getch();
	    if(c==72) flag=1;      //up
	}
    }
    delay(dl);
    if(score%100==0 && dl>40)	dl-=5;
    cc++;
    if(flag==1)
    {
	cn++;
	cdis();
	if(cn<=4) y--;
	else if(cn>5) y++;
    }
    if(cc==2)
    {score++;}
    gotoxy(62,6);
    printf("SCORE: %d",score);
    if(cn==9)
	cn=0,flag=0;}  //For Relative Dino movement
    gotoxy(37,17);
    printf("GAME OVER!");
    delay(1000);
    gotoxy(35,19);
    if(score>high)
    printf("HIGH SCORE: %d",score);
    else
    printf("Your Score: %d",score);
    gotoxy(31,21);
    printf("Play Again? (Enter/Esc) ");
    delay(1000);
    ch=getch();
    while(ch!=13 && ch!=27)
    {ch=getch();}
    if(ch==27)
	break;
    if(high<score)
    {high=score;}
    x=20,y=31,cn=0,flag=0,dl=90,score=0,col=0,cc=0,r=0,f=0,v=-1;
    memset(ob,0,sizeof(ob));
    memset(sz,0,sizeof(sz));
    }
    return 0;
}
