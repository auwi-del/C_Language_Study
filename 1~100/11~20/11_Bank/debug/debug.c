#include <stdio.h>
int main()
{
    float a,w,c,d,p;                    //a代表存款金额
    printf("请输入存款金额:");           //显示提示语句
    scanf("%f",&a);                     //读取输入
    
    w=a*(1+0.0155)*(1+0.0155)*(1+0.0155)*(1+0.0155)*(1+0.0155);
    printf("活期五年是%.2f\n", w);       //记得加参数, 所以原来你的输出都是0
    c=a*(1+0.0135)*(1+0.0135)*(1+0.0135)*(1+0.0135)*(1+0.0135);
    printf("活期一年期存五年是%.2f\n", c);      //你问啥事参数?printf("%.2f", c); 中, 那个逗号后边的c就是参数
    d=a*(1+0.0275)*(1+0.0275)*(1+0.0275)*(1+0.0275)*(1+0.0275);
    printf("先三年俩一年是%.2f\n", d);          //原先你的程序是没有参数的
    p=a*(1+0.0275)*(1+0.0275)*(1+0.0275)*(1+0.0275)*(1+0.0275);
    printf("存五年是%.2f\n", p);
    return 0;
}