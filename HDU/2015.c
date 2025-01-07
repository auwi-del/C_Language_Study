#include<stdio.h>
#include<math.h>
void main()
{
    // 要读取的n, 要读取的m, 总和!
	int n,m,i=1,sum=0;

    // 开始读取!
	while(scanf("%d%d",&n,&m)!=EOF)
	{
		sum=0;              // 这个循环每一次, 都是独立的一行输入, 所以要让总和归零!
		for(i=1;i<=n;i++)   // 你看, 这里比较有意思! 用的不是i+=2, 而是让i每次只+1, 是为了编码方便奥,,,
		{
			sum+=(i*2);     // 无论如何, 将 i * 2 的值存给sum
			


// ------------------------ 下面是求和的部分! -----------------------
            if(i%m==0)      // 每间隔 m个元素 进行[求和]的操作!
			{
				if(i<n)     // 如果当前的计数(i), 还没到数列的长度(n), 直接输出
                            // 到此为止的平均值就好, 在跟上一个空格就行啦
                    printf("%d ",sum/m);  //注意输出格式，中间数据用空格隔开，最后一项换行
				else        // 如果不是这样! 也就是说 i==n 之类的情况, 说明这一行的任务完成啦! 
                            // 因为已经处理到数列的结尾了!
					printf("%d\n",sum/m);               // 直接输出一个换行
				sum=0;      // 然后再将总和归零!
			}
			else if(i==n&&i%m!=0)           // 这是什么情况呢!
                                            // i==n 意味着已经是在 {处理数列最后一位} 了!
                                            // 而 i%m!=0 意味着, {不是正常应该进行[求和]操作} 的地方!
                                            // 也就是题里说的末尾情况!
			{
				printf("%d\n",sum/(n%m)); //这是特殊情况，最后一次不够m项, 所以不处理, 直接输出(根据题意!)
			}
		}
	}
}