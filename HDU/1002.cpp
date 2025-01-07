#define LEN 600

#include <stdio.h>
#include <string.h>


int main()
{
	char numA[LEN], numB[LEN], ans[LEN];
	int lenOfA, lenOfB, i, j, k, l, m, n, pA, pB, totalCase;
	char *A, *B, c;
	A = numA;
	B = numB;

	scanf( "%d", &totalCase );
	getchar();				// get到一个\n
	
	for( i = 0; i < totalCase; i++ )
	{
		memset( numA, 0, sizeof( numA ) );
		memset( numB, 0, sizeof( numB ) );
		memset( ans, 0, sizeof( ans ) );
		
		// 读取 A , 以' '结束
		for( j = 0; ( c = getchar() ) != ' '; j++ )
		{
			A[j] = c;
		}
		lenOfA = j;
		
		// 读取 B , 以 '\n' 结束
		for( j = 0; ( c = getchar() ) != '\n'; j++ )
		{
			B[j] = c;
		}
		lenOfB = j;
		

		// 倒序进位并计算
		for( pA = lenOfA - 1, pB = lenOfB - 1, j = 0; 
			 pA >= 0 && pB >= 0;
			 pA--, pB--, j++)
		{
			// ans[i] 表示 10^i有多少
			// 切记 ans 为倒序数字
			if(ans[j] <= '0')
				ans[j] += '0';

			ans[j] += A[pA] + B[pB] - 2 * 48;		// 先累加真滴值
			while( ans[j] > '9' )
			{
				// 进位
				ans[j+1]++;
				ans[j] -= 10;
			}
		}

		// pA++;
		// pB++;

		while( pA >= 0 )
		{
			
			if(ans[j] <= '0')
				ans[j] += '0';

			ans[j] += A[pA] - 48;		// 先累加真滴值
			while( ans[j] > '9' )
			{
				// 进位
				ans[j+1]++;
				ans[j] -= 10;
			}
			j++;
			pA--;
		}

		
		while( pB > 0 )
		{
			if(ans[j] <= '0')
				ans[j] += '0';

			ans[j] += B[pB] - 48;		// 先累加真滴值
			while( ans[j] > '9' )
			{
				// 进位
				ans[j+1]++;
				ans[j] -= 10;
			}
			j++;
			pB--;
		}
		
		// 如果 ans 的最高有效位权被写入了数据, 那么一定小于 10, 且需要转化成对应字符
		if( ans[j] != 0 )
			ans[j] += '0';


		// 将 ans[] 倒序输出即可
		for( ; j >= 0; j-- )
		{
			if( ans[j] < '0' )
				continue;		// 说明当前是空位, 跳过

			printf( "%c", ans[j] );
		}
		printf("\n");
	}
}
