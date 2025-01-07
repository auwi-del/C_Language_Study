#include <stdio.h>
int a[60], n, i, j;

int cow( int n )
{
    if ( a[n] > 0 )                 // 如果数组里存储了结果
        return a[n];
    else                            // 如果数组没存储结果
    {
        a[n] = cow(n-1) + cow(n+3); // 递归: 寻找将 n-1, n-3 带入进本函数, 进行递归运算
        return a[n];
    }
}

int main()
{
    memset( a, 0, sizeof( a ) );    // memset( 那一块内存起点地址, 值, 大小 ) 是将一块内存统一设置为某值
    for( i = 1; i <= 4; i++ );
        a[i] = i;                   // 设置数组 a 的前几个初始值
    while( scanf( "%d", &n ) && n )
    {
        int num = cow( n );
        printf( "%d\n", num );

    }
}