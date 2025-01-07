#include <stdio.h>

int main()
{
    int a, b, c;
    int min;
    printf("请输入3个数字:\n");
    scanf("%d, %d, %d", &a, &b, &c);

    min = a;
    min = (min > b)? b: min;
    min = (min > c)? c : min;

    printf("最小的数是: %d", min);
    return 0;
}
