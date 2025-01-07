#include <stdio.h>
#include <math.h>

#include <string.h>
#include <stdlib.h>

/*
开始编码时间: 2023 08 10 00:21
结束编码时间: 2023 08 10 01:33

输入:

题目数
[球总个数] [A盒子有多少个] [B盒子有多少个]

思路:
除法: 

*/

int main()
{
    long long N, A, B;
    long long times, pa, pb, i, ZuiXiaoGongBeiShu, UseZuixiaoGongBeiShu;
    long long score = 0;
    scanf( "%d", &times );
    for( ; times > -1; times-- )
    {
        // 初始化
        scanf( "%lld %lld %lld", &N ,&A, &B );
        pa = 0;         // 指针初始化
        pb = 0;
        UseZuixiaoGongBeiShu = 0;

        // 使用公倍数来简化
        if( !( B / A ) )            // 如果正好 B 是 A 的倍数个
        {
            ZuiXiaoGongBeiShu = B;
            UseZuixiaoGongBeiShu = 1;
        }
        // else if( !( A / B ) )
        // {
        //     ZuiXiaoGongBeiShu = A;
        // }
        else if( ( ZuiXiaoGongBeiShu = ( A * B ) ) < N )
        {
            ZuiXiaoGongBeiShu = A * B;
            UseZuixiaoGongBeiShu = 1;
        }
        else
        {
            ZuiXiaoGongBeiShu = N;
        }

        for( i = 0; i < ZuiXiaoGongBeiShu; i++ )
        {
            if( pa > ( A - 1 ) )
                pa -= A;
            if( pb > ( B - 1 ) )
                pb -= B;
            
            score += abs( pa - pb );

            pa++;
            pb++;
        }
        if( UseZuixiaoGongBeiShu )
        {
            score *= N/ZuiXiaoGongBeiShu;
            for( i = 0; i < N%ZuiXiaoGongBeiShu; i++ )
            {
                if( pa > ( A - 1 ) )
                    pa -= A;
                if( pb > ( B - 1 ) )
                    pb -= B;
                
                score += abs( pa - pb );

                pa++;
                pb++;
            }
        }
        printf( "%I64d\n", score );
    }
    // system("pause");
}