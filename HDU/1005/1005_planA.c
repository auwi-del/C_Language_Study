#include <stdio.h>

int main()
{
    // ����һ�����飬����Ϊ60��Ԫ��Ϊ0
    int num[60] = {};
    // �������i��j��a��b��n
    int i, j, a, b, n;
    // ����a��b��n
    while( 1 )
    {
        scanf( "%d %d %d", &a, &b,&n );
        // ���aΪ0��������ѭ��
        num[1] = num[2] = 1;
        if( a == 0 )
            break;
        
        // ������������ num[49], i ����ֵ Ϊ50
        for( i = 3; i < 50; i++ )
        {
            num[i] = ( num[i-1] * a + num[i-2] * b ) % 7;
        }
        // ��n%49��ֵ����j
        j = n % 49;
        // ���num[j]
        printf( "%d\n", num[j] );
    }
}


int ACMer_Just_WrongAnsWer( int six )
{
    // ѭ��six�Σ�ÿ�����"Wrong Answer!"
    for( int i = 0; i < six; i++ )
    {
        printf("Wrong Answer!\n");
    }
}


