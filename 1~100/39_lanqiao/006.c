/*
2020 年春节期间，有一个特殊的日期引起了大家的注意：2020 年 2 月 2 日。
因为如果将这个日期按 “yyyymmdd” 的格式写成一个 8 位数是 20200202，
恰好是一个回文数。我们称这样的日期是回文日期。

有人表示 20200202 是 “千年一遇” 的特殊日子。对此小明很不认同，
因为不到 2 年之后就是下一个回文日期：20211202 即 2021 年 12 月 2 日。

也有人表示 20200202 并不仅仅是一个回文日期，还是一个 ABABBABA 型的回文日期。
对此小明也不认同，因为大约 100 年后就能遇到下一个 ABABBABA 型的回文日期：
21211212 即 2121 年 12 月 12 日。算不上 “千年一遇”，顶多算 “千年两遇”。

给定一个 8 位数的日期，
请你计算该日期之后下一个回文日期和下一个 ABABBABA 型的回文日期各是哪一天。



CSDN:

https://blog.csdn.net/qq_42341521/article/details/123929671
*/




#include<stdio.h>
int huiwen(int num) {
	int right=0;
	int count=0;
	while(count<4){
		right=right*10+num%10;
		num/=10;
		count++;
	}
	if(right==num)return 1;
	else return 0;
}
// 判断日期是否合法
int judge(int num){
	int day[13] = {0,31,28,31,30,31,30,31,31,30,31,30,31};
	int y,m,d;
	y = num/10000;
	m = num%10000/100;
	d = num%100;

	// 判断闰年
	if((y % 4 == 0 && y % 100 == 0) || y % 400 == 0) {
		day[2] = 29;
	}
	if(m > 12 || m <= 0) {
		return 0;
	}else {
		if(d <= day[m] && d > 0){
			if(d == m)return 2;             // 注意只需要 ABABBABA 式即可, 就是月份 == 日期.
			 else return 1;                 // 当 2 满足的时候, 1 肯定也满足.
		} else return 0;
	}
}
 
 
int main(){
	int date;
	int only = 0,i;
	scanf("%d",&date);
	
	for(i=date+1;i<100000000;i++){
		if(huiwen(i)&&judge(i)) {
			if(!only){                      // 只需要回文就行的第 1 行 输出
				printf("%d\n",i);
				only++;
			}
			if(judge(i) == 2){
				printf("%d",i);
				break;
			}
		}
	}
	return 0;
}

/*

输入:
20200202

输出:
20211202
21211212

*/