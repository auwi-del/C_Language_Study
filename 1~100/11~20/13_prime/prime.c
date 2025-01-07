#include <stdio.h>
#include <stdbool.h> //有布尔变量了
int main()
{

    unsigned long count = 10000000;
    for (unsigned long i = 0; i < count; i++)
    {
        testThePrime(i);
    }
     
    
    
}

//测试函数, 返回, 输入一个ul, 如果是素数, 打印
void testThePrime(unsigned long num)
{    
    bool isPrime = true;                   // 素数标记    
    for (unsigned long div = 2; (div*div) <= num ; div++)
    {
        if (num % div == 0)
        {
            isPrime = false;
        }
    }    
    if(isPrime)
        printf("%lu 是素数\n", num);
}