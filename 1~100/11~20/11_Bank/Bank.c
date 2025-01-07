#include <stdio.h>

int main()
{
    float money;
    float out;
    printf("\n\n\n\n\n\n\n\n\n\n");                      //清屏
    printf("  _______________________________\n"); 
    printf(" /                              /*\n");
    printf("*==============================* |\n");
    printf("|请输入存款金额:               | |");
    printf("\b\b\b\b\b\b\b\b\b\b\b\b\b");
    scanf("%f", &money);
    printf("*==============================* |_________\n");
    printf("|您存了:%20.2f!! |/         /*\n", money);
    printf("*==============================*=========* |\n");

    //活期存5年0.3%
    out = money + money*(5*0.0030);
    printf("|活期存5年后的存款:\t%16.2f | |\n", out);

    //一年期连续存5年,一年1.75%
    out = money;
    out = out * 1.0175;
    out = out * 1.0175;
    out = out * 1.0175;
    out = out * 1.0175;
    out = out * 1.0175;
    printf("|1年连续存5年后的存款:\t%16.2f | |\n", out);

    //3+两次一年
    out = money;
    out = out*(1+0.0275*3);  //如此, 三年期已满
    out = out*(1+0.0175*2);  //如此, 又过两年单独的
    printf("|3+2*1方案后的存款:\t%16.2f | /\n", out);

    //直接5年
    out = money;
    out = out*(1+0.0175*5);

    printf("|直接存5年后:\t\t%16.2f |/\n", out);
    printf("*========================================*\n");
}