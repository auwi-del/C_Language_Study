#include <stdio.h>

int main()
{   
    char mode; //输入进制模式
    printf("==================\n");
    printf("欢迎使用进制转换.\n");
    printf("==================");
    printf("输入进制:\n");
    printf("二进制: b\n");
    printf("八进制: o\n");
    printf("十进制: d\n");
    printf("十六制: x\n");
    printf("我选则:___项.");
    printf("\b\b\b\b\b"); //光标倒退 5 格, 汉字在终端里算两个字符!

    scanf("%c", &mode); //获取输入

    //检测输入
    while(1)
    {
        if(mode == 'b')
        {
            int inputNum;
            printf("二进制模式");
            scanf("%b", &inputNum);
            printf("你输入的是: %", inputNum);
            break;
        }
        if(mode == 'o')
        {
            printf("八进制模式");

            break;
        }
        if(mode == 'd')
        {
            printf("十进制模式");

            break;
        }
        if(mode == 'x')
        {
            printf("十六制模式");

            break;
        }
    }
    char[] getBin(int theNum)
    {
        char[9] back; //返回一个字符串
        while(theNum >= 0)
        {
            if(theNum >= 2^7) {char[1] = 1;theNum -= 2^7;} else{char[1] = 0;}
            if(theNum >= 2^6) {char[2] = 1;theNum -= 2^6;} else{char[2] = 0;}
            if(theNum >= 2^5) {char[3] = 1;theNum -= 2^5;} else{char[3] = 0;}
            if(theNum >= 2^4) {char[4] = 1;theNum -= 2^4;} else{char[4] = 0;}
            if(theNum >= 2^3) {char[5] = 1;theNum -= 2^3;} else{char[5] = 0;}
            if(theNum >= 2^2) {char[6] = 1;theNum -= 2^2;} else{char[6] = 0;}
            if(theNum >= 2^1) {char[7] = 1;theNum -= 2^1;} else{char[7] = 0;}
            if(theNum >= 2^0) {char[8] = 1;theNum -= 2^0;} else{char[8] = 0;}
        }

        return back;
    }
}