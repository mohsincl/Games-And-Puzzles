/*----------------------------------------------------------------------
  N-QUEENS SINGLE SOLUTION GENERATOR (USING THE CONCEPT OF BACKTRACKING)

  Source Code Developer: ABDUL MOHSIN SIDDIQI


  DESCRIPTION :
  N-Queens puzzle is a well-known problem of placing 'N'
  number of Queens on an N*N Board (or more often a
  Chessboard) in such a way that no two queens threaten
  each other. Thus the arrangement ensures that no two
  queens shares the same row, column or diagonal. The
  solution exists for all natural numbers with the
  exceptions for N=2 & N=3. It is obvious that there might
  be many possible solutions for a particular order N.

  ALGORITHM :
  The BACKTRACKING way of determining all possible
  solutions to a particular order N implemented here,
  satisfying the above criteria, is primarily featured upon
  the more general depth-first backtracking algorithm developed
  by Edsger Dijkstra.

  IMPLEMENTATION :
  The following Source Code generates one of the possible
  solutions for a given Board of order N. The above concept
  of Backtracking is specifically integrated along with some
  optimizations and improvements on its GUI to make it look
  more fancy.

  ----------------------------------------------------------------------*/

#include<stdio.h>
#include<stdbool.h>
int My_board[1000][1000],n;

void Display_board()                   //Displays the Chessboard with optimally placed Queens
{
    int i,j;
    printf("\nA Possible Solution for %dX%d Chessboard:\n\n",n,n);
    printf("%c",201);                  //These and the subsequent values are just ASCII codes for displaying a grid-like structure
    for(i=0;i<n-1;i++)
        printf("%c%c%c%c",205,205,205,203);
    printf("%c%c%c%c\n",205,205,205,187);

    for(i=0;i<n;i++)
    {
        for (j=0;j<n;j++)
        {
            if(My_board[i][j])
                printf("%c W ",186);
            else
                printf("%c   ",186);
        }
        if(i==n-1)
            break;
        printf("%c\n%c",186,204);
        for(j=0;j<n-1;j++)
            printf("%c%c%c%c",205,205,205,206);
        printf("%c%c%c%c\n",205,205,205,185);
    }

    printf("%c\n%c",186,200);
    for(j=0;j<n-1;j++)
        printf("%c%c%c%c",205,205,205,202);
    printf("%c%c%c%c\n",205,205,205,188);

    printf("\n~(C) by ABDUL MOHSIN SIDDIQI~\n");
}


void Banner()                                   //Displays the Top Banner
{
    int i;
    printf("%c",201);
    for(i=0;i<36;i++) printf("%c",205);
    printf("%c\n%c N-QUEENS SINGLE-SOLUTION GENERATOR %c\n%c",187,186,186,200);
    for(i=0;i<36;i++) printf("%c",205);
    printf("%c\n\n",188);
}

bool To_Place_Or_Not(int row, int col)          //Checks if that particular position is safe from already placed Queens
{
    int i, j;
    for (i=0;i<col;i++)                         //Checks Left Horizontally
        if (My_board[row][i])
            return false;
    for (i=row, j=col; i>=0 && j>=0; i--, j--)  //Checks Top Left Diagonally
        if (My_board[i][j])
            return false;
    for (i=row, j=col; j>=0 && i<n; i++, j--)   //Checks Bottom Left Diagonally
        if (My_board[i][j])
            return false;
    return true;
}

bool Solve(int col)                         //Key Recursive Function for Solving the problem
{
    int i;
    if (col >= n)                           //All Queens Gets Placed Successfully
        return true;
    for (i=0; i<n; i++)
    {
        if ( To_Place_Or_Not(i, col) )      //Checks if the position is safe from already placed queens
        {
            My_board[i][col] = 1;           //Placing a Queen at position referred by indexes i,col
            if ( Solve(col+1) )             //Recursively Solve for subsequent columns
                return true;
            My_board[i][col] = 0;           //Backtrack, Resetting the immediate previously assigned location for queen
        }
    }
    return false;
}

int main()
{
    Banner();
    printf("Enter the order of Chess board: ");
    scanf("%d",&n);
    memset(My_board, 0, sizeof(My_board));    //Setting the board Empty
    if ( !Solve(0) )
    {
      printf("\nNo Possible Solution for %dX%d Chessboard.\n",n,n);
      exit(0);
    }
    Display_board();                          //Displays an N*N board with Queens
    return 0;
}
