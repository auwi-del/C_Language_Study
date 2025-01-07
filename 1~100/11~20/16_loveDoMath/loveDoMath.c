#include <stdio.h>

void lolo(void);
void delay(long);

int main()
{
    for(int i=0;i<10000;i++)
        lolo();
}



void lolo()
{   
    /*
        60 <
        61 =
        62 >
        43 +
        45 -
        42 *
        47 /
    */

    printf("%6d  ", rand());
    int a = ((rand()/10)/2.5);
    switch(a/250)
    {
        case 0: printf("/"); break;
        case 1: printf("+"); break;
        case 2: printf("-"); break;
        case 3: printf("*"); break;
        case 4: printf("/"); break;
        default : printf("/"); break;
    }

    printf(" %6d =\n", rand());
    delay(100);
}


void delay(long num)
{
    long i;
    for(i=0;i<2000000*num;i++);

}