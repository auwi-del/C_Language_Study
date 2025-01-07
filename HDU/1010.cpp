#include<stdio.h>
#include<math.h>
#include<string.h>
int n,m,t;
int visit[8][8];
char arr[8][8];
int sx,sy,dx,dy;
int dir[4][2]={1,0,-1,0,0,1,0,-1};
int check(int x,int y)
{
	if(x>=0&&x<n&&y>=0&&y<m)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
void  dfs(int x,int y,int time)
{
	int i,a,b;
	if(time>t)
	{
		printf("NO\n");
		return;
	}
	if((time==t)&&(arr[x][y]=='D'))
	{
		printf("YES\n");
		return;
	}
	for(i=0;i<4;i++)
	{
		a=x+dir[i][0];
		b=y+dir[i][1];
		if(check(a,b)&&visit[a][b]&&(arr[a][b]!='X'))
		{
			visit[a][b]=0;
			dfs(a,b,time+1);
			visit[a][b]=1;
		}
	}
}
int main()
{
	int i,j,s,l;
	while(scanf("%d%d%d",&n,&m,&t)!=EOF)
	{
		getchar();
		if(n==0&&m==0&&t==0)
		break;
		memset(visit,1,sizeof(visit));
		for(i=0;i<n;i++)
		{
			for(j=0;j<m;j++)
			{
				scanf("%c",&arr[i][j]);
			}
		}
		for(i=0;i<n;i++)
		{
			for(j=0;j<m;j++)
			{
				if(arr[i][j]=='S')
				{
					sx=i;
					sy=j;
				}
				if(arr[i][j]=='D')
				{
					dx=i;
					dy=j;
				}
				if(arr[i][j]=='.')
				{
					s+=1;
				}
			}
		}
		l=abs(sx-dx)+abs(sy-dy);
		if(s<t)
		{
			printf("NO\n");
			continue;	
		}
		if(l%2==0)
		{
			if(t%2==1)
			{
				printf("NO\n");
				continue;
			}
		}
		if(l%2==1)
		{
			if(t%2==0)
			{
				printf("NO\n");
				continue;
			}
		}
		visit[sx][sy]=1;
		dfs(sx,sy,0);
		
	}
}





