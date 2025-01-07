#include <stdio.h>

int main()
{
    int num, cost;
    printf("请输入站数: \n"); 
    scanf("%d", &num);

    if(num <= 4)
        cost = 3;

    if(num >= 5)
        if(num <= 10)
            cost = 4;

    if(num >= 10)
        if(num <= 15)
            cost = 5;

    if(num > 15)
        cost = 8;
    
    printf("费用为: %d\n", cost);
}