#include <iostream>
using namespace std;
int visit[100];//�����ж���������Ƿ񱻷��ʹ� �� visit[2]=1;˵������2�����ʹ� 
int a[100];//0-(n-1)������� 
void dfs(int index,int n)
{
    if(index==n)//��ֹ���� 
    {
        for(int i=0;i<n;i++)
        {
            cout<<a[i]<<" ";
        }
        cout<<endl;
        return;
    }
    for(int i=1;i<=n;i++)//�ж������Ƿ񱻷��ʹ� 
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
    dfs(0,n);//ǰ�߱�ʾĿǰ�ǵڼ������֣����߱�ʾ n(����������ֹ�����жϵ�)
    return 0;
    system( "pause" );
}
