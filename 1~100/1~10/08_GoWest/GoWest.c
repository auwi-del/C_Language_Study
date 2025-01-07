#include <stdio.h>

int main()
{
    char ch;

     scanf("%c", &ch);
    while(ch != 'g');
    {
        printf("%c", ch);
        scanf("%C", &ch);
        return 0;
    }
}