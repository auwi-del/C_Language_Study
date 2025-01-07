#include <stdio.h>
void printArgs(int *, int, int);

int main()
{
    int ar[10][10] =
    {10,11,23};
    for(int i=0;i<10;i++)   
        for(int j=0;j<10;j++)
                ar[i][j] = 10*i + j;

    // int  * pt1 = ar;
    // printArgs(ar, 10, 10);
}

void printArgs(int * pt, int length, int width)
{
    printf("%d\n", *pt+10);

    for(int i=0;i<=width;i++)
    {
        for(int j=0;j<=length;j++)
            printf("%d\t" , ((*(pt+j))+i));
        printf("\n");
    }
}