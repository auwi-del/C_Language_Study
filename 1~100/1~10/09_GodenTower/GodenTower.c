#include <stdio.h>

int main()
{
    char input;
    int i, j, k;
    printf("请输入大写字母:\n");
    input = 'Z';
    scanf("%c", &input);
    printf("经过运算, 一共会有%d 行!", input-64);

    printf("\n");

    //行循环
    for(i=0;i<input-64;i++)
    {
        //先输出左边空格
        for(j=0;j<(input-64)-i;j++)
            printf(" ");

        //计算本行一共有几个字符k
        k = 1+i*2;

        //输出 左半边 字符
        int l=0;                // l 下边还会用到
        for(l=0;l<k/2;l++)
            printf("%c", l+65);

        //输出 右半边 字符
        for(;l>0;l--)
            printf("%c", l+65);

        printf("\n");
    }
}