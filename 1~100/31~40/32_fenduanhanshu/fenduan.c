#include <stdio.h>

int main()
{
    int a;
    printf("请输入数字:\n");
    scanf("%d", &a);
    (a<0)?printf("-1"):printf("1");
}