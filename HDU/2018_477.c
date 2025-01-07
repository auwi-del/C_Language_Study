/* Note:Your choice is C IDE */
#include <stdio.h>
int main()
{
     int n,i,s=0,k,j;
     while(scanf("%d",&n)!=EOF)
     {
     	if(n==0)
     	{
     		break;
     	}
     	k=n%4;
     	if(k==0)
     	{
     		
     			for(i=1;i<=(n/4);i++)
     			{
     				for(j=1;j<=4;j++)
     				{
     					s=s+i;
     				}
     			}
     		printf("%d\n",s);
     		s=0;
     		
     	}
     	if(k!=0)
     	{
     		if(n<4)
     		{
     			for(i=1;i<=n;i++)
     			{
     				s=s+1;
     			}
     			printf("%d\n",s);
     			s=0;
     		}
     		if(n>4)
     		{
     			for(i=1;i<=n;i=i+4)
     			{
     				for(j=1;j<=k;j++)
     				{
     					s=s+i;
     				}
     			}
     			printf("%d\n",s);
     			s=0;
     		}
     	}
     	
     }
     return 0;
       
}