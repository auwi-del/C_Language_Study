#include "stdio.h"
#include "math.h"
#define pi 3.1415926
int gh(int x)
{
   int sum = 1;
   int i;
   for(i=1;i<=x;i++)
      sum *= i;
   return sum;
}
int main()
{
   int x;
   int i=2;
   int f=-1;         // 符号变量
   double sum1,sum2;
   double sum=1,n;
   printf("请输入想要计算的角度：");
   scanf( "%d", &x );
   n = x * pi / 180;       // 转化为弧度制
   for( i = 2; i < 10; i += 2 )
   {
      sum1 = pow( n, i );
      sum2 = gh( i );
      sum = sum + f * ( sum1 / sum2 );
      f=-f;
   }
   printf("cos%d的计算结果为%lf\n", x, sum);
   system( "pause" );
   return 0;
}