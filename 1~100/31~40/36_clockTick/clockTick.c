#include <time.h>

int main()
{
    int i, j, k;
    clock_t start, now, end;        //clock_t 是时间刻变量
    printf("这台机器的时间刻为:%d\n", CLK_TCK);
    for( i = 0; i < 1000; i++)
    {
        printf("time %d \n", clock()/CLK_TCK);
    }
}