/*Rat in a Maze (Interactive without trail)(C)
Developer: ABDUL MOHSIN SIDDIQI
(Tested on GCC Compiler (Codeblocks)) */

#include<stdio.h>
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
    printf("\t\t\t\t\t\t\t\t%c",201);
    for(i=0;i<15;i++) printf("%c",205);
    printf("%c\n\t\t\t\t\t\t\t\t%c RAT IN A MAZE %c\n\t\t\t\t\t\t\t\t%c",187,186,186,200);
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
        printf("%c\n     ->  ",191);
    for (i=0; i<9; i++)
    {
        if(i!=0)
            printf("\t%c",222);
        for (j=0 ; j<19; j++)
        {
            if(maze[i][j] <= 0)
                printf(" ");
            else
                printf("%c",219);}
        if(i<8)
            printf("%c\n",221);
    }
    if(x==0 && y==-1)
        printf("  -> %c\n\t%c",148,192);
    else
        printf("  ->  \n\t%c",192);
    for(i=0;i<19;i++)
        printf("%c",223);
    printf("%c\n\n",217);
    printf("\n~(C) by ABDUL MOHSIN SIDDIQI~\n");
}

void mouse(int x,int y)
{
    gotoxy(9+y,7+x);
    printf("%c",148);
    delay(100);
    gotoxy(9+y,7+x);
    printf(" ",148);
}

bool isSafe(int x, int y)
{
    if(x >= 0 && x < 9 && y >= 0 && y < 19 && maze[x][y]<=0 )
        {maze[x][y]--;
        mouse(x,y);
        return true;}
    return false;
}
bool solveMaze()
{
    if(solveMazeUtil(0,0) == false)
    {
        printf("Solution doesn't exist");
        return false;
    }
    system("CLS");
    printSolution(0,-1);
    return true;
}

/* A recursive utility function to solve Maze problem */
bool solveMazeUtil(int x, int y)
{
    if(x == 8 && y == 18)
        return true;

    if(isSafe(x, y) == true && maze[x][y]!=-3)
    {
        int u=0,d=0,l=0,r=0;
        // mark x,y as part of solution path
        if(x >= -1 && x < 8 && y >= 0 && y < 19  && maze[x+1][y]==0) d=1;
        if(x >= 1 && x < 10 && y >= 0 && y < 19  && maze[x-1][y]==0) u=1;
        if(x >= 0 && x < 9 && y >= -1 && y < 18  && maze[x][y+1]==0) r=1;
        if(x >= 0 && x < 9 && y >= 1 && y < 20  && maze[x][y-1]==0) l=1;

        if(d==0 && u==0 && l==0 && r==0)
        {
            maze[x][y]--;
            if(x >= -1 && x < 8 && y >= 0 && y < 19  && maze[x+1][y]==-1) d=1;
            if(x >= 1 && x < 10 && y >= 0 && y < 19  && maze[x-1][y]==-1) u=1;
            if(x >= 0 && x < 9 && y >= -1 && y < 18  && maze[x][y+1]==-1) r=1;
            if(x >= 0 && x < 9 && y >= 1 && y < 20  && maze[x][y-1]==-1) l=1;
        }

        /* Move right in y direction */
        if (r==1 && solveMazeUtil(x, y+1) == true)
            return true;

        /* Move down in x direction */
        if (d==1 && solveMazeUtil(x+1, y) == true)
            return true;

        /* Move up in x direction */
        if (u==1 && solveMazeUtil(x-1, y) == true)
            return true;

        /* Move left in y direction */
        if (l==1 && solveMazeUtil(x, y-1) == true)
            return true;
    }

    return false;
}
int main()
{
    system("CLS");
    printSolution(-1,0);
    printf("\nPress any key to begin..........");
    getchar();
    system("CLS");
    printSolution(0,0);
    solveMaze();
    return 0;
}
