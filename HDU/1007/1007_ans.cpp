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

//���������ľ��� 
double dis(note a,note b)
{
    return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}

double closet(int left,int right)
{
    double d=INF;//����ֵΪ���� 
    if(left==right)
    return d;//һ����ʱ��ֱ�ӷ��ؼ��� 
    if(left+1==right)//���ֵ�ֻʣ������ʱֱ��������ǵľ��� 
    {
        return dis(p[left],p[right]);
    }
    int mid=(left+right)/2;//���м�ֵ 
    double d1=closet(left,mid);
    double d2=closet(mid+1,right);//�ݹ� 
    d=min(d1,d2);//����Сֵ 
    int k=0;
    for(int i=left;i<=right;i++)
    {
        if(fabs(p[i].x-p[mid].x)<=d)//����d�ľͲ�Ҫ�� 
        t[k++]=p[i];
    }
    sort(t,t+k,cmpy);//��y��ֵ��С�������� 
    for(int i=0;i<k;i++)
    {
        for(int j=i+1;j<k&&t[j].y-t[i].y<d;j++)//����d�Ͳ�Ҫ�� 
        {
            
            d=min(d,dis(t[i],t[j]));//����d��ֵ��ֱ���ҵ���С 
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
        sort(p,p+n,cmpxy);//������x��������С�������� 
        printf("%.2lf\n",closet(0,n-1)/2);//�����С��ֵ��һ�� 
    }
    return 0;
}