#include <stdio.h>

void prtArg(int *, int);
void buubbleSort(int *p, int);

int main()
{
    int a[] = { 7, 3, 5, 6, 12, 4, 3, 2, 7};            // a中最大的下标为 9
    int i, j, k, size;
    size = sizeof(a)/sizeof(int);

    // 测试指针用的
    int *q = a;
    printf("q=%d\n", q);                                // 指针指向的地址
    printf("q+1=%d\n", q+1);                            // 指针偏移的位数取决于指针的类型
    printf("*q=%d\n", *q);                              // 取值
    printf("*(q+1)=%d\n", *(q+1));                      // 取a[1]
    printf("*(q+9)=%d\n", *(q+9));                      // 取a[9]
    printf("*(q+10)=%d\n", *(q+10));                    // 溢出, 结果为首地址值<---------------为啥
    printf("*(q+11)=%d\n", *(q+11));                    // 结果为0            <---------------为啥
    printf("*(q+12)=%d\n", *(q+12));                    // 结果为随机值
    // printf("sizeof(*q)=%d\n", sizeof(*q));
    // printf("q[3]=%d\n\n", q[3]);                        // 证明: 指针就是数组!


    // bubbleSort(a, size);
}

void prtArg(int *p, int size)
{
    int i;
    for(i = 0; i<size; i++)
        printf("%d  ", *(p+i));
    printf("\n");
}

void bubbleSort(int *p, int size)
{
    int i, j, k;
    for( i=0; i<size-1; i++)                               // 可以理解为双窗口, 所以外层应该有len-1次
    {
        for(j = 0; j<size-1-i; j++)                        // 内层循环比外层少i次
        {
            if( p[j] < p[j+1] )
            {
                k = p[j];
                p[j] = p[j+1];
                p[j+1] = k;
            }
            prtArg( p, size);
        }
    }
}
