#include <stdio.h>

int main()
{
    int total = 0;                      //每一个数的因子之和
    int x = 0;                          //正在处理的横坐标

    for(int i=1; i<=1000000; i++)
    {
        total = 0;                      //初始化
        //计算因子和(其实只用算前边一半, 因为后边是一样的)
        //9 = 1x9, 3x3, 3x3, 9x1(这是对称的!!!)
        for(int j=1; j<i/2+1; j++)
            if(i%j == 0)
                total += j;
        
        //如果因子和与本身不相等, 直接跳过此数(i)
        if(total != i)
            continue;

        //输出
        if(x < 5-1)
        {
            printf("%6d", i);
            x++;
        }
        else
        {
            printf("%6d\n", i);
            x=0;
        }
    }    
}