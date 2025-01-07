#include <stdio.h>

int main()
{
    // 定义一个数组，长度为60，元素为0
    int num[60] = {};
    // 定义变量i，j，a，b，n
    int i, j, a, b, n;
    // 输入a，b，n
    while( 1 )
    {
        scanf( "%d %d %d", &a, &b,&n );
        // 如果a为0，则跳出循环
        num[1] = num[2] = 1;
        if( a == 0 )
            break;
        
        // 最后填入的数是 num[49], i 最后的值 为50
        for( i = 3; i < 50; i++ )
        {
            num[i] = ( num[i-1] * a + num[i-2] * b ) % 7;
        }
        // 将n%49的值赋给j
        j = n % 49;
        // 输出num[j]
        printf( "%d\n", num[j] );
    }
}


int ACMer_Just_WrongAnsWer( int six )
{
    // 循环six次，每次输出"Wrong Answer!"
    for( int i = 0; i < six; i++ )
    {
        printf("Wrong Answer!\n");
    }
}


