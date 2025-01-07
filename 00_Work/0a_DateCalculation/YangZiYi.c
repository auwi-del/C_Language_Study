/* Note:Your choice is C IDE */
#include "stdio.h"
void main()
{
  int day1,day2;//两个年份的天数
  int m,n;//天数差
  struct Date
  {
  	int y;//年
  	int m;//月
  	int d;//日
  }d1,d2;
  
  printf("请输入第一个年份\n");//第一个日期年份的错误处理
  while(1)
  {
  scanf("%d",&d1.y);
  if(d1.y>1&&d1.y<3000)
  {
  printf("输入的是%d年\n",d1.y);
  break;
  }
  else
  {
  printf("输入的第一个年份出错，请重新输入\n");
  continue;
  }
  }
  
  printf("请输入第一个月份\n");//第一个日期月份的错误处理
  while(1)
  {
  scanf("%d",&d1.m);
  if(d1.m>=1&&d1.m<=12)
  {
  printf("输入的是%d月\n",d1.m);
  break;
  }
  else
  {
  printf("输入的第一个月份出错，请重新输入\n");
  continue;
  }
  }
  
  while(1)
  {
  	printf("请输入第一个日期\n");//第一个日期的错误处理
  scanf("%d",&d1.d);
  if(d1.m==1||d1.m==3||d1.m==5||d1.m==7||d1.m==8||d1.m==10||d1.m==12)//大月份31天
  {
  	if(d1.d>0&&d1.d<=31)
  	{printf("输入的是%d日\n",d1.d);
  	break;}
  	else
  	printf("输入的第一个日期出错，请重新输入\n");
  	continue;
  }
  
  if(d1.m==4||d1.m==6||d1.m==9||d1.m==11)//小月份30天
  {
  	if(d1.d>0&&d1.d<=30)
  	{printf("输入的是%d日\n",d1.d);
  	break;}
  	else
  	printf("输入的第一个日期出错，请重新输入\n");
  	continue;
  }
  
  if(d1.m==2)//正常28天 闰年29天
  {
  	if((d1.y%4==0&&d1.y%100!=0)||(d1.y%400==0))
  	
  	{
    if(d1.d>0&&d1.d<=29)
  	{printf("输入的是%d日\n",d1.d);
  	break;}
  	else printf("输入第一个日期有错误，请重新输入\n");
  	continue;
  	}
  	else
  	{
  	if(d1.d>0&&d1.d<=28)
  	{
  	printf("输入的是%d日\n",d1.d);
  	break;}
    else printf("输入第一个日期有错误，请重新输入\n");
  	continue;
  }
  }
  }
  
  printf("请输入第二个年份\n");//第二个日期年份的错误处理
  while(1)
  {
  	
  scanf("%d",&d2.y);
  if(d2.y>1&&d2.y<3000)
  {
  	printf("输入的是%d年\n",d2.y);
  	break;
  }
  else
  {
  	printf("输入第二个年份有错误，请重新输入\n");
  	continue;
  	}
  }
  
  printf("请输入第二个月份\n");//第二个日期月份的错误处理
  while(1)
  {
  scanf("%d",&d2.m);
  if(d2.m>=1&&d2.m<=12)
  {
  	printf("输入的是%d月\n",d2.m);
  	break;
  }
  else
  {
  	printf("输入第二个月份有错误，请重新输入\n");
  	continue;
  	}
  }
  
  printf("请输入第二个日期\n");//第二个日期的错误处理
  while(1)
  {
  scanf("%d",&d2.d);
  if(d2.m==1||d2.m==3||d2.m==5||d2.m==7||d2.m==8||d2.m==10||d2.m==12)
  {
  	if(d2.d>0&&d2.d<=31)
  	{printf("输入的是%d日\n",d2.d);
  	break;
  	}
  	else
  	printf("输入第二个日期有错误，请重新输入\n");
  	continue;
  }
  
  if(d2.m==4||d2.m==6||d2.m==9||d2.m==11)
  {
  if(d2.d>0&&d2.d<=30)
  {printf("输入的是%d日\n",d1.d);
  break;}
  else
  printf("输入第二个日期有错误，请重新输入\n");
  continue;
  }
  
  if(d2.m==2)
  {
  if((d2.y%4==0&&d2.y%100!=0)||(d2.y%400==0))
  {
  if(d2.d>0&&d2.d<=29)
  {
  printf("输入的是%d日\n",d2.d);
  break;}
  else printf("输入第二个日期有错误，请重新输入\n");
  continue;
  	}
  else
  {
  if(d2.d>0&&d2.d<=28)
  {
  printf("输入的是%d日\n",d2.d);
  break;}
  else 
  printf("输入第二个日期有错误，请重新输入\n");
  continue;
  }
  }
  }
  
 if((d1.y%4==0&&d1.y%100!=0)||(d1.y%400==0))//闰年天数总数的算法
 { switch(d1.m)
  {
  	case 1:day1=d1.d;break;
  	case 2:day1=31+d1.d;break;
  	case 3:day1=31+29+d1.d;break;
  	case 4:day1=31+29+31+d1.d;break;
  	case 5:day1=31+29+31+30+d1.d;break;
  	case 6:day1=31+29+31+30+31+d1.d;break;
  	case 7:day1=31+29+31+30+31+30+d1.d;break;
  	case 8:day1=31+29+31+30+31+30+31+d1.d;break;
  	case 9:day1=31+29+31+30+31+30+31+31+d1.d;break;
  	case 10:day1=31+29+31+30+31+30+31+31+30+d1.d;break;
  	case 11:day1=31+29+31+30+31+30+31+31+30+31+d1.d;break;
  	case 12:day1=31+29+31+30+31+30+31+31+30+31+30+d1.d;break;
  	}
 }
  if(!(d1.y%4==0&&d1.y%100!=0)||(d1.y%400==0))//平年天数总数的算法
 { 
  switch(d1.m)
  {
  	case 1:day1=d1.d;break;
  	case 2:day1=31+d1.d;break;
  	case 3:day1=31+28+d1.d;break;
  	case 4:day1=31+28+31+d1.d;break;
  	case 5:day1=31+28+31+30+d1.d;break;
  	case 6:day1=31+28+31+30+31+d1.d;break;
  	case 7:day1=31+28+31+30+31+30+d1.d;break;
  	case 8:day1=31+28+31+30+31+30+31+d1.d;break;
  	case 9:day1=31+28+31+30+31+30+31+31+d1.d;break;
  	case 10:day1=31+28+31+30+31+30+31+31+30+d1.d;break;
  	case 11:day1=31+28+31+30+31+30+31+31+30+31+d1.d;break;
  	case 12:day1=31+28+31+30+31+30+31+31+30+31+30+d1.d;break;
  	}
 }
  
  if((d2.y%4==0&&d2.y%100!=0)||(d2.y%400==0))//第二个日期重复计算
  { switch(d2.m)
  {
  	case 1:day2=d2.d;break;
  	case 2:day2=31+d2.d;break;
  	case 3:day2=31+29+d2.d;break;
  	case 4:day2=31+29+31+d2.d;break;
  	case 5:day2=31+29+31+30+d2.d;break;
  	case 6:day2=31+29+31+30+31+d2.d;break;
  	case 7:day2=31+29+31+30+31+30+d2.d;break;
  	case 8:day2=31+29+31+30+31+30+31+d2.d;break;
  	case 9:day2=31+29+31+30+31+30+31+31+d2.d;break;
  	case 10:day2=31+29+31+30+31+30+31+31+30+d2.d;break;
  	case 11:day2=31+29+31+30+31+30+31+31+30+31+d2.d;break;
  	case 12:day2=31+29+31+30+31+30+31+31+30+31+30+d2.d;break;
  	}
    }
  if((d2.y%4==0&&d2.y%100!=0)||(d2.y%400==0))
 { 
  switch(d2.m)
  {
  	case 1:day2=d2.d;break;
  	case 2:day2=31+d2.d;break;
    case 3:day2=31+28+d2.d;break;
    case 4:day2=31+28+31+d2.d;break;
    case 5:day2=31+28+31+30+d2.d;break;
  	case 6:day2=31+28+31+30+31+d2.d;break;
  	case 7:day2=31+28+31+30+31+30+d2.d;break;
  	case 8:day2=31+28+31+30+31+30+31+d2.d;break;
  	case 9:day2=31+28+31+30+31+30+31+31+d2.d;break;
    case 10:day2=31+28+31+30+31+30+31+31+30+d2.d;break;
  	case 11:day2=31+28+31+30+31+30+31+31+30+31+d2.d;break;
  	case 12:day2=31+28+31+30+31+30+31+31+30+31+30+d2.d;break;
  	}
 }
 
 
 if(d1.y>d2.y)//第一个日期大的情况
 m=(d1.y-d2.y)*365+((d1.y-d2.y)/4);
 if(d2.y>d1.y)//第二个日期大的情况
 m=(d2.y-d1.y)*365+((d2.y-d1.y)/4);
  
 n=m+day2-day1;//天数差的计算 
 printf("日期相差数为：%d",n);
 system("pause");
 }