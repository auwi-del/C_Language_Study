#include <stdio.h>
int main()
{
    float money;
    float out;
    printf("程序运行, 请输入存款金额:\n"); // print 打印  f:格式
    scanf("%f", &money);              // 获取输入
    printf("您存入了 %.2f 元!\n\n", money);

    // 一年,存五年
    out = money;  
    out = out * 1.0175;
    out = out * 1.0175;
    out = out * 1.0175;
    out = out * 1.0175;
    out = out * 1.0175;
    printf("一年期, 存五年: \t%.2f\n", out);

    // 活期存5年0.3%
    out = money + money*(5*0.0030);
    
    printf("活期存5年后的存款: \t%.2f\n", out);
