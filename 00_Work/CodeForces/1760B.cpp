#include<iostream>
using namespace std;
int main()
{
	int  t,i,n,s,max;
	char a[1000];                           /////////////// 这里尽量不要用字符串，用字符数组哦， 因为string比较奇怪，不能直接用下标访问
	scanf("%d",&t);             // 输入测试用例个数
	while(t--)
	{
		max=0;                  // 每次循环都要初始化
		s=0;                    // 每次循环都要初始化
		scanf("%d",&n);         // 输入字符串长度
		scanf("%s",&a);          // 输入字符串
		for(i=0;i<n;i++)        // 遍历字符串
		{
			s=a[i]-96;
			if(s>max)
			{
				max=s;
			}
		}
		printf("%d\n",max);
	}
    // system ("pause");
	return 0;
}