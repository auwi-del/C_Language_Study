#include <stdio.h>

int main()
{
    int i = 0;
    int baiwei, shiwei, gewei, output;
    for(i = 100; i<=999; i++)
    {
        baiwei = i / 100;
        shiwei = (i - 100 * baiwei) / 10;
        gewei = i % 10;

        output  = 100 * baiwei + 10 * shiwei + gewei;
        if
        (
            (
                baiwei * baiwei * baiwei +
                shiwei * shiwei * shiwei +
                gewei  * gewei  * gewei
            )
            == output
        )
        {
            printf("%d\n", output);
        }
    }
}