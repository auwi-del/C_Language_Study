/* Note:Your choice is C IDE */
#include "stdio.h"

struct Date
{
       int year;int month;int day;int m;
}d1,d2;
	


void main()
{      
    int days,day;
    printf("\n��������ʼʱ��,��ʽΪ: ��-��-��(2021-10-23) \n");
 
    scanf("%d-%d-%d", &d1.year, &d1.month, &d1.day ); 
 
    printf("\n���������ʱ��,��ʽΪ:��-��-��(2021-10-23)\n");
 
    scanf("%d-%d-%d",&d2.year,&d2.month,&d2.day);
    if (d1.year < 0 || d1.month>12 || d1.month < 1 || d1.day>31 || d1.day < 1)
    {
  printf("�������");

 }
 
 if(d1.year%4==0&&d1.year%100!=0||d1.year%400==0)
 { if(d1.month==2||d1.day>29)
  {
   printf("�������");

  }
 }
  else
 {
  if (d1.month == 2 ||d1.day > 28)
  {
   printf("�������");

  }
 }
  if (d2.year < 0 || d2.month>12 || d2.month < 1 || d2.day>31 || d2.day < 1)
 {
  printf("�������");

 }
 if(d2.year%4==0&&d2.year%100!=0||d2.year%400==0)
 {
  printf("�������");

  
 }
 if(d2.year%4==0&&d2.year%100!=0||d2.year%400==0)
 {
  if (d2.month == 2 ||d2.day > 29)
  {
   printf("�������");

  }
 }
 else
 {
  if (d2.month == 2 ||d2.day > 28)
  {
   printf("�������");

  } 
  }
 //�ж�����������Ƿ����

if(d1.year>d2.year)
{if(d2.year%400==0||(d2.year%4==0&&d2.year%100!=0))
	{days=days+366;}
	else
	{days=days+365;}
	d2.year--;
}
 
 
 switch(d1.month)
 {case 1:d1.m=0; break;
        case 2:d1.m=31; break;
        case 3:d1.m=31+28; break;
        case 4:d1.m=31+28+31; break; 
        case 5:d1.m=31+28+31+30; break; 
        case 6:d1.m=31+28+31+30+31; break;
        case 7:d1.m=31+28+31+30+31+30; break;
        case 8:d1.m=31+28+31+30+31+30+31; break;
        case 9:d1.m=31+28+31+30+31+30+31+31; break;
        case 10:d1.m=31+28+31+30+31+30+31+31+30; break;
        case 11:d1.m=31+28+31+30+31+30+31+31+30+31; break;
        case 12:d1.m=31+28+31+30+31+30+31+31+30+31+30; break;
 }
 d1.m=d1.m+d1.day;
 switch(d2.month)
 {case 1:d2.m=0; break;
        case 2:d2.m=31; break;
        case 3:d2.m=31+29; break;
        case 4:d2.m=31+29+31; break;
        case 5:d2.m=31+29+31+30; break; 
        case 6:d2.m=31+29+31+30+31; break;
        case 7:d2.m=31+29+31+30+31+30; break;
        case 8:d2.m=31+29+31+30+31+30+31; break;
        case 9:d2.m=31+29+31+30+31+30+31+31; break;
        case 10:d2.m=31+29+31+30+31+30+31+31+30; break;
        case 11:d2.m=31+29+31+30+31+30+31+31+30+31; break;
        case 12:d2.m=31+29+31+30+31+30+31+31+30+31+30; break;
    
 }
if(d2.year%400==0||(d2.year%4==0&&d2.year%100!=0)) ;
 {if(d2.month>2)
 {day++;}
 }
  d2.m=d2.m+d2.day;
  days=d1.m-d2.m+day;
  printf("��������%d��\n",days); 

  system( "pause" );
  return 0;
}
