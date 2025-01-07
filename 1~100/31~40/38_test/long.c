#include <stdio.h>

int main()
{
    int x=1, y=1, z=0;
    if(z<0)
        if(y>0)
            x=3;
        else        // 无论嵌套关系如何, else遵从就近原则.
            x=5;
    printf("%d\t", x);
    if(z=y<0)
        x=3;
    else 
        if(y==0)   // 然而y=1, 所以会走到下边的else.
            x=5;
        else x=7;

    printf("%d\t", x);
    printf("%d\t", z);
}