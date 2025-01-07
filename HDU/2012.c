#include <stdio.h>
#include <math.h>

// ����ʹ�õ��ж������ĺ���
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

// ���Ǳ��õ������ж������ĺ���, ������û�е���
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