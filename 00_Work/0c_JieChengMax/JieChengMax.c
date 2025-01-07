#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define PI 3.14159265354

// 一下几项, 任选其中一行, 取消注释并编译, 编译结果是对应题目的答案
// 默认编译 题目A

// #define A                // 阶乘
// #define B                // 阶乘之和
#define C                // C( n, m )
// #define D                // e 的近似值
// #define E                // cos( x )

// 函数原型
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


// 题目: 计算一个数的阶乘
#ifdef A
    printf( "----- 阶乘 -----\n" );
    input = GetInput();         // 获取输入
    printf( "这个数的阶乘是: %ld\n", JieCheng( (int) input ) );
#endif


// 题目: 计算阶乘和
#ifdef B
    printf( "----- 阶乘之和 -----\n" );
    input = GetInput();         // 获取输入
    printf( "这个数的阶乘之和是: %ld\n", JieChengHe( ( int ) input ) );
#endif



// 题目: 计算 c, n, m
/* 
    ***** n
    **
    ***** m               
*/
#ifdef C
    double m;
    printf( "----- C, n, m -----\n" );
    printf( "请输入n的值: \n" );

    input = GetInput();                                 // 获取输入
    
    printf( "数值已经记录为n, 接下来请输入m的值:\n" );
    
    m = GetInput();

    printf( "C ( %lf, %lf )的值为: %lf", input, m,Cnm( ( int )input, ( int )m ) );
#endif


// 题目: -------------------- E的近似值 ---------------------------
#ifdef D

    printf( "----- E的近似值 -----\n" );
    

    printf( "E = %lf\n\n",  FindE() );


#endif

// 题目: -------------------- cos(x) ---------------------------
#ifdef E
    double x = 0;
    printf( "----- cos( x ) -----\n" );
    input = GetInput();
    printf( "输入的数字转化成弧度制为: %lf \n", ( x = DegToReg( input ) ) );
    printf( "cos( %lf ) = %lf \n", input, KouSaiYin( x ) );

#endif
    system( "pause" );
}






// 传入int, 返回这个int的 (long)阶乘
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

// 输入一个数字x, 打印出从1到x的阶乘的和
long JieChengHe(int x)
{   int i;
    long result = 0;
    for(i = 1; i <= x; i++)
        result += JieCheng(i);
    return result;
}

// 输入 int 的 n, m, 返回double的c
double Cnm( int n, int m )
{
    double fenZi = ( double ) JieCheng(n);
    double fenMu = ( double ) ( JieCheng( m ) * JieCheng(n - m) );
    return fenZi / fenMu;
}

// 输入一个 弧度制值 (double), 返回该函数的余弦函数近似值
double KouSaiYin( double x )
{
    double result = 0, fenzi = 0, fenmu = 0;
    int i, j, k;
    int f = 1;             // 记录符号的变量 
    for( i = 0; i <= 6; i += 2 )
    {
        fenzi = pow( x, i );
        printf("第%d项的分子为:%f\n", i, fenzi);
        fenmu = (double)JieCheng( i );
        printf("第%d项的分母为:%f\n", i, fenmu);
        result += f * (fenzi / fenmu);              // 计算cos(x)的近似公式
        f = -f;                                     // 符号转换
    }
    result += 0.00005;                              // 浮点修正

    return result;
}

// 空传入值, 返回一个e的近似值
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

// 传入一个 double, 返回该数对应的 double弧度制
double DegToReg( double input )
{
    return ( ( input / 180 ) *PI );
}

// 调用本函数, 从终端获得一个 double用户输入, 返回
double GetInput()
{
    double input;
    while( 1 )
    {
        printf( "\n请输入一个数字: \n" );
        scanf( "%lf", &input );
        if(input < 0)
        {   
            printf("输入有误，请重新输入：\n");
            continue;
        }
        break;
    }
    return input;
}