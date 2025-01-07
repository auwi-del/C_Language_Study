#include <stdio.h>
void putAsc(void);
int main()
{
    char a;
    printf("请输入一个字符: ");
    a = getchar();
    // putAsc(); 
    
    if(65<=a && a<=90)
        printf("big\n");        // 经过查表, 得大写字母为65~90
    else if(97<=a && a<=122)
        printf("small");        // 经过查表, 得小写字母为97~122
    else if(48<=a && a<=57)
        printf("digital");      // 经过查表, 得数字为48~57
    else if(a == ' ')
        printf("space");        // 不用查表, 直接判断是不是就行了
    else
        printf("other");        // 啥也不是
}
// 如果你个睿智问表在哪里, 
// 我回答你自己写一个函数不就行了  只要你在main函数里头加上这一句
//      putArc();
// 就会得到一张表.
void putAsc()
{
    for(int i=0; i<256; i++)
        printf("%3d: %c \n", i, i);
}