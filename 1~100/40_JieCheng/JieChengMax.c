#include <math.h>
#include <stdio.h>

long JieCheng(int x);
void JieChengHe(int x);
double Cnm(int n, int m);
double KouSaiYin(double x);
double DegToReg(double deg);
int getInput(double *p);

void main()
{
    double input;
	getInput( &input );
	input = DegToReg( input );
	printf("\n转化为弧度制是: %lf\n\n", input);
    // JieChengHe(3);
    // printf("%d", JieCheng(input) );
    printf("该数的余弦值为：%f", KouSaiYin( input ) );
	// printf("该数字的5次方为%lf", pow( input, 5 ) );
}

// 输入int, 返回long
long JieCheng(int x)
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
void JieChengHe(int x)
{
	int i;
	long result = 0;
	for(i = 1; i <= x; i++)
		result += JieCheng(i);
	printf("阶乘和为: %d", result);
}


// 输入 int 的 n, m, 返回double的c
double Cnm(int n, int m)
{
	double fenZi = (double)JieCheng(n);
	double fenMu = (double)JieCheng(n - m);
	return fenZi / fenMu;
}

// 输入一个值(double), 返回该函数的余弦函数近似值
double KouSaiYin( double x )
{
	double result = 0, fenzi = 0, fenmu = 0;
	int i, j, k, f = 1;
	for( i = 0; i <= 10; i+=2 )
	{
		fenzi = pow( x, i );
		// printf("第%d项的分子为 %f\n", i, fenzi);
		fenmu = (double)JieCheng( i );
		// printf("第%d项的分母为 %f\n", i, fenmu);
		// printf("第%d项是     %lf\n", i, fenzi / fenmu);
		result += ( double ) f * (fenzi / fenmu);
		// printf("第%d项符号是 %d\n", i, f );
		// printf("第%d项结果是 %lf\n\n", i, result);
		f = - f;
	}
	return result;
}

// 角度(double) 转换成 弧度(double)
double DegToReg(double deg)
{
	return deg * 3.1415926535 / (double)180;
}

// 传入一个double*, 将用户输入写入
int getInput(double *p)
{
	while(1)
    {
    	printf("请输入一个角度制数：\n");
    	scanf("%lf", p);		// lf 是读取 double 用的
    	if( *p < 0 )
    	{
    		printf("输入有误，请重新输入：\n");
    		continue;
    	}
    	break;
    }
}
