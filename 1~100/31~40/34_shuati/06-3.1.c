#include <stdio.h>// input output
int main()
{
    /*
    
    1        2 = 2;
    2        22 = 20 + 2
    3        222 = 200 + 20 + 2
    4        2222...
    
    */
    int x=0;
    int y=0;
    while(y<=10)
    {
        x = 0;
        while(x<=10)
        {
            printf("*");
            x++;
        }
        printf("\n");
        y++;
    }
}

        