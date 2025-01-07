#include <stdio.h>

int main()
{
    float num, a;
    for(int n=0; n<=100; n++)       //一定是小于等于100
    {
        num += n;
    }

    for(int k=0; k<=50; k++)        //注意小于等于
    {
        num += k*k;
    }
    for(float m=1; m<10; m++)
    {
        a = (float)(1/m);
        num += a;
    }

    printf("经过计算, 结果为: %f", num);
}