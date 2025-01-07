#include <stdio.h>
#include <math.h>

// 网上寻来的 据说是最佳的判断素数的算法. 经测试, 本算法准确无误
// 且能保证fun1调用了本函数, fun2没有用本函数
// fun1 fun2 结果完全一致
// 但是 fun 1 就是怎么也过不了代码测试
int isPrime(int num) {
    int tmp, i;
    //两个较小数另外处理
    if(num==2 || num==3) {
        return 1;
    }
    
    //不在6的倍数两侧的一定不是素数
    if(num%6!=1 && num%6!=5) {
        return 0;
    }
    
    tmp = (int)  sqrt( num );      // 获取平方根
    //在6的倍数两侧的也可能不是素数
    for(i=5; i<=tmp; i+=6) {
        if(num%i==0 || num%(i+2)==0) {
            return 0;
        }
    }
    return 1;
}

// fun1 是学生自己写的main函数, 封装成了fun1 
int fun1( int x, int y )
{
    int i, judge = 1;
    // while( scanf("%d %d", &x, &y ) != EOF )
    // {
        if(x==0&&y==0)
			return 0;
        for( i = x; i <= y; i++ )
        {
            if( !( isPrime( i*i + i + 41 ) ) )
            {
                printf( "fun1: Sorry\n" );
                judge = 0;
                break;
            }
        }

        if( judge )
        {
            printf( "fun1: OK\n" );
        }
        return judge;
    // }
}

// fun2 是将网上的题解封装而成. 经HDU测试, 此题解能通过 HDU 测试
int fun2(int x, int y)
{
	int n,N, j;
    if(x == 0 && y == 0)
        return 0;
    N=1;
    for(int i = x; i <= y; i++ )
    {
        n=i*i+i+41;
        for( j = 2; j*j <= n; j++ )
            if(n%j == 0)
            {
                N = 0;
                break;
            }
        if(N == 0)break;
    }
    if(!N)
        printf("fun2: Sorry\n");
    else
        printf("fun2: OK\n");

    return N;
}

// 专门设计出来用来测试的main 函数, 用来测试我的方法与网上的方法输出是不是一致
int main()
{
    int x, y, fun1res, fun2res;
    for( y = 50; y > -36; y-- )
    {
        for( x = -37; x < y; x++ )
        {
            printf( "\nx = %d, y = %d \n", x, y );
            fun1res = fun1( x, y );
            fun2res = fun2( x, y );

            // 如果哪个带入参数不一致, 则立刻暂停程序
            if( fun2res != fun1res )
            {
                printf( "\\\\\\\\\\\\\\\\\\\\\\" );
                system("pause");
            }
        }
        system("pause");
    }
    // 测试结果: fun1 与 fun2 在任何输入的条件下, 输出均一致.
}