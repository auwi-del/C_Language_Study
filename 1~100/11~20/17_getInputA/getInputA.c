/*
    今天帮大傻牛整他的kali linux, 
    看到命令行有感而发, 
    遂作之.             2022年10月20日
                       01:49
*/

#include <stdio.h>

int main()
{
    char ch;
    printf("输入任意代码, 在-后边加上参数.\n");
    printf("-h help; -d; -v; -c; -l\n");
    printf("\n\n>>> ");
    while((ch = getchar()) != '\n')
    {
        // printf("\n");               // 这行有大用处. 取消注释可以发现, 空格也被算在内.
        if(ch != '-')                  // 检测当前字符为'-'
            continue;                  // 跳过一切非参数
        ch = getchar();
        
        switch(ch)
        {
            case 'h': printf("-可用的参数：-h, -d, -v -c -l\n"); break;
            case 'd': printf("DDDDDDDDDDDD\n");
                      printf("sfjsdfasdfF");
                      break;                 //为了测试能否多行测试, 鉴定为:能.
            case 'v': printf("vvvvvvvvvvvv\n"); break;
            case 'c': printf("cccccccccccc\n"); break;
            case 'l': printf("llllllllllll\n"); break;
            default : printf("未知参数: '-%c'.\n", ch); break;
        }
    }
    printf(">>> 解释结束.\n\n");    
}