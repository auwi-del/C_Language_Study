#include <stdio.h>

void zuhe(int a[],int b[],int x,int n)
{
    // ԭ���������û�� return ���!
    // ���ڵݹ��㷨����, return ��ζ�ŷ�����һ���ݹ�!
    // �����ݹ������!
	if(x==n)
	{
		for(int i=0;i<n;i++)
		{
			if(b[i]==1)
			{
				printf("%d",a[i]);
			}
		}
        putchar( '\n' );
        return;             // ���������ݹ�., ԭ��û�е�
	}

	b[x]=1;
	zuhe(a,b,x+1,n);
	b[x]=0;
	zuhe(a,b,x+1,n);
	
}
int main()
{
	int n,x,j;
	int a[100];
	int b[100];
	scanf("%d %d", &x, &n);
	for(j=0;j<n;j++)
	{
		a[j]=j+1;
		b[j]=0;
	}
	zuhe(a,b,x,n);
	system("pause");
}
