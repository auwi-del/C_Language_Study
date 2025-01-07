#include <stdio.h>
int main()
{
    float input, output;
    scanf("%f", &input);
    output = 32 + input*1.8;
    printf("%.2f F", output);
}