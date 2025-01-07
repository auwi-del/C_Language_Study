#include <stdio.h>

int main()
{
    //数字输入模块, 将弃用.
    // int inputNum;
    // scanf("%s", &inputNum);
    
    //测试转化二进制模块, 成功
    // getBin(inputNum);

    //测试指数模块, 成功
    // int output = p(2, 8);
    // printf("%d", output);
    
    //测试字符串转化int模块, 
    char input[20];
    scanf("%s", input);

    printf("%d", toInt(input));

}


//将输入转为二进制, 并打印出来
void getBin(int theNum)
{
    int backNum1 = 0;
    int backNum2 = 0;
    int backNum3 = 0;
    int backNum4 = 0;
    int backNum5 = 0;
    int backNum6 = 0;
    int backNum7 = 0;
    int backNum8 = 0;

    while(theNum > 0)
    {
        if(theNum >= p(2, 7)) {backNum1 = 1;theNum -= p(2, 7);} else{backNum1 = 0;}
        if(theNum >= p(2, 6)) {backNum2 = 1;theNum -= p(2, 6);} else{backNum2 = 0;}
        if(theNum >= p(2, 5)) {backNum3 = 1;theNum -= p(2, 5);} else{backNum3 = 0;}
        if(theNum >= p(2, 4)) {backNum4 = 1;theNum -= p(2, 4);} else{backNum4 = 0;}
        if(theNum >= p(2, 3)) {backNum5 = 1;theNum -= p(2, 3);} else{backNum5 = 0;}
        if(theNum >= p(2, 2)) {backNum6 = 1;theNum -= p(2, 2);} else{backNum6 = 0;}
        if(theNum >= p(2, 1)) {backNum7 = 1;theNum -= p(2, 1);} else{backNum7 = 0;}
        if(theNum >= p(2, 0)) {backNum8 = 1;theNum -= p(2, 0);} else{backNum8 = 0;}
    }

    printf("%d%d%d%d %d%d%d%d", backNum1, backNum2, backNum3, backNum4, backNum5, backNum6, backNum7, backNum8);
}

int toInt(char inputChar[20])
{
    printf("%s", inputChar);
    return 0;
}

//多少次方函数:
//用法: p(底数, 指数);
//返回一个int.
int p(int theNum, int times)
{
    int backNum = 1;
    for(int i=0;i<times;i++)
    {
        backNum = backNum * theNum;
    }
    return backNum;
}