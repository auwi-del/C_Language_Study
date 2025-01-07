#include<iostream>
#include<algorithm>
#include<math.h>
#define INF 0x3f3f3f3f
#define maxn 100010
using namespace std;

struct note
{
    double x,y;
};
note p[maxn],t[maxn];

int cmpxy(note a,note b)
{
    if(a.x==b.x)
    return a.y<b.y;
    return a.x<b.x;
}
int cmpy(note a,note b)
{
    return a.y<b.y;
}

//计算两点间的距离 
double dis(note a,note b)
{
    return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}

double closet(int left,int right)
{
    double d=INF;//赋初值为极大 
    if(left==right)
    return d;//一个点时，直接返回极大 
    if(left+1==right)//当分到只剩两个点时直接算出他们的距离 
    {
        return dis(p[left],p[right]);
    }
    int mid=(left+right)/2;//算中间值 
    double d1=closet(left,mid);
    double d2=closet(mid+1,right);//递归 
    d=min(d1,d2);//更新小值 
    int k=0;
    for(int i=left;i<=right;i++)
    {
        if(fabs(p[i].x-p[mid].x)<=d)//大于d的就不要了 
        t[k++]=p[i];
    }
    sort(t,t+k,cmpy);//以y的值由小到大排序 
    for(int i=0;i<k;i++)
    {
        for(int j=i+1;j<k&&t[j].y-t[i].y<d;j++)//大于d就不要了 
        {
            
            d=min(d,dis(t[i],t[j]));//更新d的值，直到找到最小 
        }
    }
    return d;
}

int main()
{
    int n;
    while(scanf("%d",&n)!=EOF&&n)
    {
        for(int i=0;i<n;i++)
        {
            scanf("%lf%lf",&p[i].x,&p[i].y);
        }
        sort(p,p+n,cmpxy);//排序，以x的坐标由小到大排序 
        printf("%.2lf\n",closet(0,n-1)/2);//输出最小的值的一半 
    }
    return 0;
}