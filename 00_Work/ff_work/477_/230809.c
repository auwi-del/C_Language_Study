#include <stdio.h>
int used[100];
int use[100];

void digui(int x,int n)
{
    if(x==n)
	{
		for(int i=0;i<n;i++)
		{
			printf("%d ",use[i]);
		}
        printf("\n");           // This line!
		return;
	}

	for(int i=1;i<=n;i++)
	{
		if(used[i]==0)
		{
			used[i]=1;
			use[x]=i;
			digui( x+1, n );
			used[i]=0;
		}
	}
}
int main()
{
	int n;
	scanf("%d",&n);
	digui(0,n);
	
	system( "pause" );
 }
