#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef long long LL;
LL n,a,b,ans,lcm;       // lcm, ��С������

// �������
LL gcd(LL a,LL b)
{   return a%b==0?b:gcd(b,a%b);
}
// ����ֵ
LL abss(LL a)
{   return a>=0?a:-a;
}
// Сֵ
LL min(LL a,LL b)
{   return a>b?b:a;
}
// ��ֵ
LL max(LL a,LL b)
{   return a<b?b:a;
}
// 
void doit1()
{   LL t;
    for (int i=0;i<lcm;i++)
        {if (i>=n) break;   //��Ϊ���Ϊ0~n-1
         t=(n-1-i)/lcm+1;
        ans+=abss(i%a-i%b)*t;
        }
}
 
void doit2()
{   LL q,l,r,ll,rr;
    for (int i=0;;i++)
    { 
        l=a*i; r=a*(i+1)-1;
        if (r>=n) r=n-1;
        if (l>=n) break;
        q=l/b;
        for (int j=q;;j++)
        {
            ll=b*j;
            rr=b*(j+1)-1;
            if (min(rr,r)<max(ll,l)) break;
            ans+=abss((a*i-b*j))*(min(rr,r)-max(ll,l)+1);
                
        }
    }
}
void doit()
{   scanf("%lld%lld%lld",&n,&a,&b);
    lcm=a*b/gcd(a,b);
    ans=0;
    if (lcm<1000000) doit1(); 
    else doit2();
    printf("%I64d\n",ans);  //ע�⣡��
}
 
int main()
{   int cas;
    scanf("%d",&cas);
    while (cas--)doit();
    return 0;
}