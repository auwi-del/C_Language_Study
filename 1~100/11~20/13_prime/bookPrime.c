#include <stdio.h>
#include <stdbool.h> //有布尔变量了
int main()
{
    unsigned long num;          // 待测的数
    unsigned long div;          // 可能的约数
    bool isPrime;               // 素数标记

    printf("请输入一个整形:\n");
    printf("输入 q 退出程序\n");
    while (scanf("%lu", &num) == 1)
    {
        for (div = 2, isPrime=true; (div*div) <= num ; div++)
        {
            if (num % div == 0)         // 总之进了这个if, 就不是素数了
            {
                if ((div*div) != num)   // 不是完全平方
                    printf("%lu 可以被 %lu 和 %lu 整除.\n", num, div, (num/div));
                else
                    printf("%lu 是 %lu 的平方\n", num, div);
                //总之:
                isPrime = false;        //不是素数
            }
        }
        if(isPrime)
            printf("%lu 是素数\n", num);
        printf("请输入其他待测数字:\n");
        printf("输入 q 退出.\n");
    }
    
}