//程序来自书P67, 2022年10月19日

#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>
#define STOP '|'
int main(void)
{
    char c;                         //读取的字符
    char prev;                      //读取的前一个字符
    long n_chars = 0L;              //字符数
    int n_lines = 0;                //行数
    int n_words = 0;                //单词数
    int p_lines = 0;                //不完整行数
    bool inword = false;            //如果光标在单词中, inword = true;

    printf("请输入文本: ('|'表示结束)\n");
    prev = '\n';
    while((c = getchar()) != STOP)
    {
        n_chars ++;
        if(c == '\n')
            n_lines ++;             //统计行
        if(!isspace(c) && !inword)
        {
            inword = true;          //说明在单词中
            n_words ++;
        }
        if(isspace(c) && inword)    //说明到达 一个单词 的结尾
            inword = false;
        prev = c;                   //保存字符的值
    }

    if(prev!= 'n')
        p_lines = 1;
    printf("字符数:%ld, 单词数:%d, 行数:%d, ", n_chars, n_words, n_lines);
    printf("不完整行数=%d", p_lines);

    return 0;
}