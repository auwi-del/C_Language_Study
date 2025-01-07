#include <stdio.h>

int main()
{
    int out;
    int a = 3;
    int b = 4;
    int c = 5;

    out = !(a+b)+c;
    printf("%d", out);
}