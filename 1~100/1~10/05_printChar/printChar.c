#include <stdio.h>

int main()
{
    putchar(65);
    putchar(66);

    for(int i=0;i<200;i++)
    {
        printf("i = %7d,   (  ", i);
        putchar(i);
        printf("   )\n");
    }
    while(0){}
    return 0;
}