#include <stdio.h>

void zuhe(int a[],int b[],int x,int n)
{
    // 原先你的这里没有 return 语句!
    // 对于递归算法而言, return 意味着返回上一级递归!
    // 本级递归结束了!
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
        return;             // 跳出本级递归., 原来没有的
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
