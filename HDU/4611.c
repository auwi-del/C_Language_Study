#include <stdio.h>
#include <math.h>

#include <string.h>
#include <stdlib.h>

/*
��ʼ����ʱ��: 2023 08 10 00:21
��������ʱ��: 2023 08 10 01:33

����:

��Ŀ��
[���ܸ���] [A�����ж��ٸ�] [B�����ж��ٸ�]

˼·:
����: 

*/

int main()
{
    long long N, A, B;
    long long times, pa, pb, i, ZuiXiaoGongBeiShu, UseZuixiaoGongBeiShu;
    long long score = 0;
    scanf( "%d", &times );
    for( ; times > -1; times-- )
    {
        // ��ʼ��
        scanf( "%lld %lld %lld", &N ,&A, &B );
        pa = 0;         // ָ���ʼ��
        pb = 0;
        UseZuixiaoGongBeiShu = 0;

        // ʹ�ù���������
        if( !( B / A ) )            // ������� B �� A �ı�����
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