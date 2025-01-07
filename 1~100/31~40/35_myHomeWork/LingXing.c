#include <stdio.h>

int main()
{
    int duiJiaoXianChangDu;
    int i, j;
    int xingHaoGeShu;
    printf("请输入菱形的对角线长度:\n");
    scanf("%d", &duiJiaoXianChangDu);
    for(i = 0; i<duiJiaoXianChangDu / 2 + 1; i++)
    {
        for(j = 0; j<=duiJiaoXianChangDu/2-i; j++)
            printf(" ");
        
        for(xingHaoGeShu = 0; xingHaoGeShu <= i*2; xingHaoGeShu++)
            printf("*");
        printf("\n");
    }
    for(i = duiJiaoXianChangDu / 2 + 1;i >= 0;  i--)
    {
        for(j = 0; j<=duiJiaoXianChangDu/2-i; j++)
            printf(" ");
        
        for(xingHaoGeShu = 0; xingHaoGeShu <= i*2; xingHaoGeShu++)
            printf("*");
        printf("\n");
    }
}