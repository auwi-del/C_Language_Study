#include <stdio.h>
#include <math.h>

// 这是使用的判断素数的函数
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

// 这是备用的用来判断素数的函数, 在这里没有调用
int isPrime1(int num)
{
    int i;
    for( i = 2; i * i <= num; i++ )
    {
        if( num % i == 0 )
        {
            return 0;
        }
    }

    return 1;
}


int main()
{
    int x, y, i, judge = 1;
    while( scanf("%d %d", &x, &y ) != EOF )
    {
        if(x==0&&y==0)
			break;
        for( i = x; i <= y; i++ )
        {
            if( !( isPrime( i*i + i + 41 ) ) )
            {
                printf( "Sorry\n" );
                judge = 0;
                break;
            }
        }

        if( judge )
        {
            printf( "OK\n" );
        }
    }
}