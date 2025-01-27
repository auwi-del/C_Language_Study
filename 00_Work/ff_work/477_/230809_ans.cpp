#include <iostream>
using namespace std;
int visit[100];//用来判断这个数字是否被访问过 如 visit[2]=1;说明数字2被访问过 
int a[100];//0-(n-1)存放数字 
void dfs(int index,int n)
{
    if(index==n)//终止条件 
    {
        for(int i=0;i<n;i++)
        {
            cout<<a[i]<<" ";
        }
        cout<<endl;
        return;
    }
    for(int i=1;i<=n;i++)//判断数字是否被访问过 
    {
        if(visit[i]==0)
        {
            visit[i]=1;
            a[index]=i;
            dfs(index+1,n);
            visit[i]=0;
        }
    }
}
int main()
{   int n;  
    cin>>n;
    dfs(0,n);//前者表示目前是第几个数字，后者表示 n(用来进行终止条件判断的)
    return 0;
    system( "pause" );
}
