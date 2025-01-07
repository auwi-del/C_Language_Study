#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define PI 3.14159265354

// һ�¼���, ��ѡ����һ��, ȡ��ע�Ͳ�����, �������Ƕ�Ӧ��Ŀ�Ĵ�
// Ĭ�ϱ��� ��ĿA

// #define A                // �׳�
// #define B                // �׳�֮��
#define C                // C( n, m )
// #define D                // e �Ľ���ֵ
// #define E                // cos( x )

// ����ԭ��
long JieCheng( int x );
long JieChengHe( int x );
double Cnm( int n, int m );
double KouSaiYin( double x );
double FindE();
double DegToReg( double x );
double GetInput();

void main()
{
    double input;


// ��Ŀ: ����һ�����Ľ׳�
#ifdef A
    printf( "----- �׳� -----\n" );
    input = GetInput();         // ��ȡ����
    printf( "������Ľ׳���: %ld\n", JieCheng( (int) input ) );
#endif


// ��Ŀ: ����׳˺�
#ifdef B
    printf( "----- �׳�֮�� -----\n" );
    input = GetInput();         // ��ȡ����
    printf( "������Ľ׳�֮����: %ld\n", JieChengHe( ( int ) input ) );
#endif



// ��Ŀ: ���� c, n, m
/* 
    ***** n
    **
    ***** m               
*/
#ifdef C
    double m;
    printf( "----- C, n, m -----\n" );
    printf( "������n��ֵ: \n" );

    input = GetInput();                                 // ��ȡ����
    
    printf( "��ֵ�Ѿ���¼Ϊn, ������������m��ֵ:\n" );
    
    m = GetInput();

    printf( "C ( %lf, %lf )��ֵΪ: %lf", input, m,Cnm( ( int )input, ( int )m ) );
#endif


// ��Ŀ: -------------------- E�Ľ���ֵ ---------------------------
#ifdef D

    printf( "----- E�Ľ���ֵ -----\n" );
    

    printf( "E = %lf\n\n",  FindE() );


#endif

// ��Ŀ: -------------------- cos(x) ---------------------------
#ifdef E
    double x = 0;
    printf( "----- cos( x ) -----\n" );
    input = GetInput();
    printf( "���������ת���ɻ�����Ϊ: %lf \n", ( x = DegToReg( input ) ) );
    printf( "cos( %lf ) = %lf \n", input, KouSaiYin( x ) );

#endif
    system( "pause" );
}






// ����int, �������int�� (long)�׳�
long JieCheng( int x )
{
    int i;
    long result = 1;
    for(i = 1; i <= x; i++)
    {
        result *= i;
    }
    return result;
}

// ����һ������x, ��ӡ����1��x�Ľ׳˵ĺ�
long JieChengHe(int x)
{   int i;
    long result = 0;
    for(i = 1; i <= x; i++)
        result += JieCheng(i);
    return result;
}

// ���� int �� n, m, ����double��c
double Cnm( int n, int m )
{
    double fenZi = ( double ) JieCheng(n);
    double fenMu = ( double ) ( JieCheng( m ) * JieCheng(n - m) );
    return fenZi / fenMu;
}

// ����һ�� ������ֵ (double), ���ظú��������Һ�������ֵ
double KouSaiYin( double x )
{
    double result = 0, fenzi = 0, fenmu = 0;
    int i, j, k;
    int f = 1;             // ��¼���ŵı��� 
    for( i = 0; i <= 6; i += 2 )
    {
        fenzi = pow( x, i );
        printf("��%d��ķ���Ϊ:%f\n", i, fenzi);
        fenmu = (double)JieCheng( i );
        printf("��%d��ķ�ĸΪ:%f\n", i, fenmu);
        result += f * (fenzi / fenmu);              // ����cos(x)�Ľ��ƹ�ʽ
        f = -f;                                     // ����ת��
    }
    result += 0.00005;                              // ��������

    return result;
}

// �մ���ֵ, ����һ��e�Ľ���ֵ
double FindE()
{
    int i, j, k;
    double result, fenmu;
    for ( i = 1; i <= 7; i++ )
    {
        fenmu = JieCheng( i );
        result += ( 1 / fenmu );
    }
    
    return result;
}

// ����һ�� double, ���ظ�����Ӧ�� double������
double DegToReg( double input )
{
    return ( ( input / 180 ) *PI );
}

// ���ñ�����, ���ն˻��һ�� double�û�����, ����
double GetInput()
{
    double input;
    while( 1 )
    {
        printf( "\n������һ������: \n" );
        scanf( "%lf", &input );
        if(input < 0)
        {   
            printf("�����������������룺\n");
            continue;
        }
        break;
    }
    return input;
}