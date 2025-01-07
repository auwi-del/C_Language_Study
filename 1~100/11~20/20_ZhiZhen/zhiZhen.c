#include <stdio.h>

int main()
{
    int a = 50;
    // int a_adress = &a;
    int * a_temp = &a;                  // 最标准的定义一个指针的方式, 虽然用a_adress做中转也行, 但是会warning.
    printf("直接使用地址运算, &a= %d\n",&a);
    // printf("*a=%p",*a);
    printf("实际上就是a的值: *(&a)= %d\n",(*(&a)));
    printf("a的16进制地址值: a_adress 0x:= %x\n",&a);
    printf("a的指针指  的值: a_temp= %x\n", a_temp);        // 其实应该用 %p 来输出指针
    printf("a的指针指向的值, 其实就是a: *a_temp= %d\n",*a_temp);
    printf("\n\n\n>>> 结论:\n>>> 指针的值==指向变量的地址值(16进制)\n>>> 对一个指针类型, 可以使用'*'来调用它指向的内容\n>>> '&'能用来定义指针:\n>>> int *temp = &a,是合理的\n>>> 但是*&a是错误的");
}