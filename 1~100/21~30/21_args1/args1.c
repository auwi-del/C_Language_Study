#include <stdio.h>

int main()
{
    //注意这边各种奇葩的定义方式.
    int a[10][10] = {
        {1, 2, 3}, 
        {[5]=11, 12, 14}, 
        [5]= 10, 11, 12, 13,
-    };

    for(int i=0;i<10;i++)
    {
        for(int j=0;j<10;j++)
        {
            printf("%d\t", a[i][j]);
        }
        printf("\n");
    }
}