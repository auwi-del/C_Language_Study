//本程序来自书P154, 2022年10月18日 
#include <stdio.h>
#define SPACE ' '

int main(){
    char ch;
    ch = getchar();
    
    while(ch != '\n')
    {
        if(ch == SPACE)
            putchar(ch);
        else
            putchar(ch+1);
        ch = getchar();

    }
    putchar(ch);

    return 0;
}