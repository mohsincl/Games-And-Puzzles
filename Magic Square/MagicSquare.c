/*Displays a Magic Square (R) for a given order.
Developer : ABDUL MOHSIN SIDDIQI          */

#include<stdio.h>

int a[100][100],b[100][100];

void prn(int n,int ar[100][100])    //Prints the Magic Square
{
    int i,j;
    for(i=0;i<n;i++)
    {   printf("\n");
        for(j=0;j<n;j++)
        {   if((ar[i][j])/10==0)
                printf(" ");
            printf("%d ",ar[i][j]);
        }
    }
    printf("\n\nSum of any particular row or column or diagonal elements = %d\n",n*(n*n+1)/2);
}

void odd(int m,int n)  //Computes For n=1,3,5,7,......
{
    int i=1,j=n/2-1,k;
    for(k=m;k<m+n*n;k++)
    {
        i=(i+n-1)%n;
        j=(j+1)%n;
        if(a[i][j]==0)
            a[i][j]=k;
        else
            {i=(i+2)%n;
            j=(j+n-1)%n;
            a[i][j]=k;}
    }
}

void eve2(int n)        //Computes For n=4,8,12,......
{
    int k,i,j;
    for(k=0;k<n*n;k++)
        a[k/n][k%n]=k+1;

    for(i=0;i<n/4;i++)
        for(j=n/4;j<3*n/4;j++)
            swp(&a[i][j],&a[n-i-1][j]);

    for(i=n/4;i<n/2;i++)
        for(j=0;j<n;j++)
            if(j<n/4 || j>=3*n/4)
                swp(&a[i][j],&a[n-i-1][j]);
    prn(n,a);
}

void eveins(int i1,int j1,int mf,int n) //Extension for function eve1
{
    int i,j;
    odd(mf+1,n/2);
    for(i=0;i<n/2;i++)
        for(j=0;j<n/2;j++)
            {b[i+i1][j+j1]=a[i][j];
            a[i][j]=0;}
}
void eve1(int n)        //Computes For n=6,10,14,......
{
    int i=0,j=0;
    eveins(0,0,0,n);
    eveins(n/2,n/2,(n*n/4),n);
    eveins(0,n/2,(n*n/2),n);
    eveins(n/2,0,(3*n*n/4),n);

    for(i=0;i<n/2;i++)
        for(j=0;j<n;j++)
            if(j<n/4 || j>=(3*n/4)+2)
                swp(&b[i][j],&b[i+n/2][j]);

    swp(&b[n/4][n/4],&b[n-n/4-1][n/4]);
    swp(&b[n/4][n/4-1],&b[n-n/4-1][n/4-1]);

    prn(n,b);
}

int swp(int *x,int *y)  //Swap the values of specified locations
{
    int t=*x;
    *x=*y;
    *y=t;
}

int main(void)
{
    int n;
    memset(a,0,sizeof(a));
    printf("Enter the order of the magic square: ");
    scanf("%d",&n);
    if(n<1 || n==2)        //Not Possible for order 2
        printf("\nMagic Square of order %d does not exist!\n",n);
    else if(n%2==1)  //Odd Order
        {odd(1,n);
        prn(n,a);}
    else if(n%4==0)  //Order Thats Multiple of 4
        eve2(n);
    else            //n=6,10,14.......
        eve1(n);
    return 0;
}
