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
	getchar();				// get��һ��\n
	
	for( i = 0; i < totalCase; i++ )
	{
		memset( numA, 0, sizeof( numA ) );
		memset( numB, 0, sizeof( numB ) );
		memset( ans, 0, sizeof( ans ) );
		
		// ��ȡ A , ��' '����
		for( j = 0; ( c = getchar() ) != ' '; j++ )
		{
			A[j] = c;
		}
		lenOfA = j;
		
		// ��ȡ B , �� '\n' ����
		for( j = 0; ( c = getchar() ) != '\n'; j++ )
		{
			B[j] = c;
		}
		lenOfB = j;
		

		// �����λ������
		for( pA = lenOfA - 1, pB = lenOfB - 1, j = 0; 
			 pA >= 0 && pB >= 0;
			 pA--, pB--, j++)
		{
			// ans[i] ��ʾ 10^i�ж���
			// �м� ans Ϊ��������
			if(ans[j] <= '0')
				ans[j] += '0';

			ans[j] += A[pA] + B[pB] - 2 * 48;		// ���ۼ����ֵ
			while( ans[j] > '9' )
			{
				// ��λ
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

			ans[j] += A[pA] - 48;		// ���ۼ����ֵ
			while( ans[j] > '9' )
			{
				// ��λ
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

			ans[j] += B[pB] - 48;		// ���ۼ����ֵ
			while( ans[j] > '9' )
			{
				// ��λ
				ans[j+1]++;
				ans[j] -= 10;
			}
			j++;
			pB--;
		}
		
		// ��� ans �������ЧλȨ��д��������, ��ôһ��С�� 10, ����Ҫת���ɶ�Ӧ�ַ�
		if( ans[j] != 0 )
			ans[j] += '0';


		// �� ans[] �����������
		for( ; j >= 0; j-- )
		{
			if( ans[j] < '0' )
				continue;		// ˵����ǰ�ǿ�λ, ����

			printf( "%c", ans[j] );
		}
		printf("\n");
	}
}
