#include <stdio.h>
#include <math.h>

// ����Ѱ���� ��˵����ѵ��ж��������㷨. ������, ���㷨׼ȷ����
// ���ܱ�֤fun1�����˱�����, fun2û���ñ�����
// fun1 fun2 �����ȫһ��
// ���� fun 1 ������ôҲ�����˴������
int isPrime(int num) {
    int tmp, i;
    //������С�����⴦��
    if(num==2 || num==3) {
        return 1;
    }
    
    //����6�ı��������һ����������
    if(num%6!=1 && num%6!=5) {
        return 0;
    }
    
    tmp = (int)  sqrt( num );      // ��ȡƽ����
    //��6�ı��������Ҳ���ܲ�������
    for(i=5; i<=tmp; i+=6) {
        if(num%i==0 || num%(i+2)==0) {
            return 0;
        }
    }
    return 1;
}

// fun1 ��ѧ���Լ�д��main����, ��װ����fun1 
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

// fun2 �ǽ����ϵ�����װ����. ��HDU����, �������ͨ�� HDU ����
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

// ר����Ƴ����������Ե�main ����, ���������ҵķ��������ϵķ�������ǲ���һ��
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

            // ����ĸ����������һ��, ��������ͣ����
            if( fun2res != fun1res )
            {
                printf( "\\\\\\\\\\\\\\\\\\\\\\" );
                system("pause");
            }
        }
        system("pause");
    }
    // ���Խ��: fun1 �� fun2 ���κ������������, �����һ��.
}