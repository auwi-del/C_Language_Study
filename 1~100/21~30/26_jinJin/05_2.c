#include <stdio.h>

int main()
{   
    int isSuShu = 1;            //1为素数, 0为非
    int x = 0;                  //正在运算的的横坐标

    for(int i=3; i<=200; i++)
    {
        for(int j=2; j<i/2+1; j++)
        {
            if(i%j == 0)
            {
                //说明i不是素数
                isSuShu = 0;
                break;
            }
        }
        //初始化, 进行下一个数的检测
        if(isSuShu == 0){
            isSuShu = 1;
            continue;
        }
        //程序来到这里说明都是素数了
        if(x < 5-1)
        {
            printf("%4d", i);
            x++;
        }
        else
        {
            printf("%4d\n", i);
            x=0;
        }
    }
}