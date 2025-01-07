#include <stdio.h>

int main()
{
    float x,y;
    for (y =5;y>=5; y-=1)
    {
        for(x=-5;x<=5;x+=1)
        {
            if( x * x == y )
            {
                printf("#");
            }
            else
            {
                printf(" ");
            }
                

            // printf("(%d,%d)   ",x,y);
        }
        printf("\n");


    }
    
}