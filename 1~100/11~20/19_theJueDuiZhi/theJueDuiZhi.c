#include <stdio.h>

int main()
{
    int num;
    printf("请输入一个整数: ");
    scanf("%d", &num);

    if(num<0)
        num = -num;
    printf("它的绝对值为:   %d",num);
}