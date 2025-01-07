#include <stdio.h>

int main()
{
    int num = 5;        // 需要算的值
    int OutPut = 1;     // 输出用的变量, 一定不能为0
    for(int i=1; i<=num; i++)
    {
        OutPut = 1;     // 每次运行的时候要初始化, 之前这里有错误
        for(int j=1;j<=i;j++)
        {
            OutPut *= j;
        }
        printf("%d!=%d\n", i, OutPut);
    }
}