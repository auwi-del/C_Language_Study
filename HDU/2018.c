#include <stdio.h>
int a[60], n, i, j;

int cow( int n )
{
    if ( a[n] > 0 )                 // ���������洢�˽��
        return a[n];
    else                            // �������û�洢���
    {
        a[n] = cow(n-1) + cow(n+3); // �ݹ�: Ѱ�ҽ� n-1, n-3 �����������, ���еݹ�����
        return a[n];
    }
}

int main()
{
    memset( a, 0, sizeof( a ) );    // memset( ��һ���ڴ�����ַ, ֵ, ��С ) �ǽ�һ���ڴ�ͳһ����Ϊĳֵ
    for( i = 1; i <= 4; i++ );
        a[i] = i;                   // �������� a ��ǰ������ʼֵ
    while( scanf( "%d", &n ) && n )
    {
        int num = cow( n );
        printf( "%d\n", num );

    }
}