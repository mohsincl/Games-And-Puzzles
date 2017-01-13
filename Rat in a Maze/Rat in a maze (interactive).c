/*Rat in a Maze (Interactive with trail)(C)
Developer: ABDUL MOHSIN SIDDIQI
(Tested on GCC Compiler (Codeblocks)) */

#include<stdio.h>
#include<conio.h>
#include<time.h>
#include<windows.h>
#include<stdbool.h>
bool solveMazeUtil(int x, int y);
int maze[9][19] = {{0,0,0,0,0,1,0,0,0,0,0,1,0,0,0,0,0,0,0},
                   {0,1,1,1,0,1,0,1,1,1,0,1,0,1,1,1,1,1,0},
                   {0,1,0,0,0,1,0,0,0,1,0,0,0,1,0,1,0,0,0},
                   {0,1,1,1,1,1,1,1,0,1,1,1,0,1,0,1,0,1,1},
                   {0,0,0,1,0,0,0,1,0,0,0,1,0,0,0,1,0,1,0},
                   {1,1,0,1,0,1,1,1,0,1,0,1,1,1,1,1,0,1,0},
                   {0,0,0,0,0,1,0,0,0,1,0,0,0,1,0,0,0,0,0},
                   {0,1,1,1,1,1,0,1,0,1,1,1,1,1,0,1,1,1,1},
                   {0,0,0,0,0,0,0,1,0,0,0,1,0,0,0,0,0,0,0}};

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

void Banner()                                   //Displays the Top Banner
{
    int i;
    printf("\t\t\t\t\t\t\t%c",201);
    for(i=0;i<15;i++) printf("%c",205);
    printf("%c\n\t\t\t\t\t\t\t%c RAT IN A MAZE %c\n\t\t\t\t\t\t\t%c",187,186,186,200);
    for(i=0;i<15;i++) printf("%c",205);
    printf("%c\n\n",188);
}

void printSolution(int x,int y)
{
    int i,j;
    Banner();
    printf("\n\n\t%c",218);
    for(i=0;i<19;i++)
        printf("%c",220);
    if(x==-1 && y==0)
        printf("%c\n   %c ->  ",191,148);
    else
        printf("%c\nSTART-> .",191);
    for (i=0; i<9; i++)
    {
        if(i!=0)
            printf("\t%c",222);
        for (j=0 ; j<19; j++)
        {
            if(maze[i][j] == -1)
                printf(".");
            else if(maze[i][j] <= 0)
                printf(" ");
            else
                printf("%c",219);}
        if(i<8)
            printf("%c\n",221);
    }
    printf("  -> FINISH\n\t%c",192);
    for(i=0;i<19;i++)
        printf("%c",223);
    printf("%c\n",217);
    printf("\n~(C) by ABDUL MOHSIN SIDDIQI~\n");
}

void mouse(int x,int y)
{
    gotoxy(9+y,7+x);
    printf("%c",148);
    delay(100);
    gotoxy(9+y,7+x);
    if(maze[x][y]==-1)
        printf(".");
    else
        printf(" ");
}

bool safe(int x, int y)
{
    if(x >= 0 && x < 9 && y >= 0 && y < 19 && maze[x][y]<=0 )
        {maze[x][y]--;
        mouse(x,y);
        return true;}
    return false;
}

/* A recursive utility function to solve Maze problem */
bool Maze_main_solver(int x, int y)
{
    if(x == 8 && y == 18)
        return true;

    if(safe(x, y) == true && maze[x][y]!=-3)
    {
        int c=0,u=0,d=0,l=0,r=0;
        // mark x,y as part of solution path
        if(x >= -1 && x < 8 && y >= 0 && y < 19  && maze[x+1][y]==0) d=1,c++;
        if(x >= 1 && x < 10 && y >= 0 && y < 19  && maze[x-1][y]==0) u=1,c++;
        if(x >= 0 && x < 9 && y >= -1 && y < 18  && maze[x][y+1]==0) r=1,c++;
        if(x >= 0 && x < 9 && y >= 1 && y < 20  && maze[x][y-1]==0) l=1,c++;
        if(c==1 && maze[x][y] ==-2)
            {gotoxy(9+y,7+x);
            printf(".");}

        if(d==0 && u==0 && l==0 && r==0)
        {
            maze[x][y]--;
            if(x >= -1 && x < 8 && y >= 0 && y < 19  && maze[x+1][y]==-1) d=1;
            if(x >= 1 && x < 10 && y >= 0 && y < 19  && maze[x-1][y]==-1) u=1;
            if(x >= 0 && x < 9 && y >= -1 && y < 18  && maze[x][y+1]==-1) r=1;
            if(x >= 0 && x < 9 && y >= 1 && y < 20  && maze[x][y-1]==-1) l=1;
            gotoxy(9+y,7+x);
            printf(" ");
        }

        if(d==0 && u==0 && l==0 && r==0)
        {
            gotoxy(9+y,7+x);
            printf("%c",148);
            gotoxy(0,20);
            printf("Rat Can't Reach Destination!!!\n\n");
            exit(0);
        }

        /* Move right in y direction */
        if (r==1 && Maze_main_solver(x, y+1) == true)
            return true;

        /* Move down in x direction */
        if (d==1 && Maze_main_solver(x+1, y) == true)
            return true;

        /* Move up in x direction */
        if (u==1 && Maze_main_solver(x-1, y) == true)
            return true;

        /* Move left in y direction */
        if (l==1 && Maze_main_solver(x, y-1) == true)
            return true;
    }

    return false;
}

bool solve()
{
    if(Maze_main_solver(0,0) == false)
    {
        gotoxy(0,20);
        printf("Rat Can't Reach Destination!!!\n\n");
        return false;
    }
    gotoxy(27,15);
    printf(".. -> %c      ",148);
    gotoxy(0,20);
    printf("\n\nRat Reached The Destination!!!\n\n");
    return true;
}

int main()
{
    system("CLS");
    printSolution(-1,0);
    printf("\nPress any key to begin..........");
    getch();
    system("CLS");
    printSolution(0,0);
    solve();
    getch();
    return 0;
}
