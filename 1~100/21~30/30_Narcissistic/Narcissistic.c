#include <stdio.h>

int main()
{
    int x100, x10, x1, output;      // 百位, 十位, 个位.

    for(x100 = 1; x100<10; x100++)
        for(x10 = 0; x10<10; x10++)
            for(x1 = 0; x1<10; x1++){
                output = 100*x100+10*x10+x1;
                if
                ( output == ( x100 * x100 * x100 +x10 * x10 * x10 + x1 * x1 * x1 ) )
                    printf("%d: %d^3 + %d^3 + %d^3 = %d\n", output, x100, x10, x1, output);
            }
}
