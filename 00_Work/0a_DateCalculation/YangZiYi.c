/* Note:Your choice is C IDE */
#include "stdio.h"
void main()
{
  int day1,day2;//������ݵ�����
  int m,n;//������
  struct Date
  {
  	int y;//��
  	int m;//��
  	int d;//��
  }d1,d2;
  
  printf("�������һ�����\n");//��һ��������ݵĴ�����
  while(1)
  {
  scanf("%d",&d1.y);
  if(d1.y>1&&d1.y<3000)
  {
  printf("�������%d��\n",d1.y);
  break;
  }
  else
  {
  printf("����ĵ�һ����ݳ�������������\n");
  continue;
  }
  }
  
  printf("�������һ���·�\n");//��һ�������·ݵĴ�����
  while(1)
  {
  scanf("%d",&d1.m);
  if(d1.m>=1&&d1.m<=12)
  {
  printf("�������%d��\n",d1.m);
  break;
  }
  else
  {
  printf("����ĵ�һ���·ݳ�������������\n");
  continue;
  }
  }
  
  while(1)
  {
  	printf("�������һ������\n");//��һ�����ڵĴ�����
  scanf("%d",&d1.d);
  if(d1.m==1||d1.m==3||d1.m==5||d1.m==7||d1.m==8||d1.m==10||d1.m==12)//���·�31��
  {
  	if(d1.d>0&&d1.d<=31)
  	{printf("�������%d��\n",d1.d);
  	break;}
  	else
  	printf("����ĵ�һ�����ڳ�������������\n");
  	continue;
  }
  
  if(d1.m==4||d1.m==6||d1.m==9||d1.m==11)//С�·�30��
  {
  	if(d1.d>0&&d1.d<=30)
  	{printf("�������%d��\n",d1.d);
  	break;}
  	else
  	printf("����ĵ�һ�����ڳ�������������\n");
  	continue;
  }
  
  if(d1.m==2)//����28�� ����29��
  {
  	if((d1.y%4==0&&d1.y%100!=0)||(d1.y%400==0))
  	
  	{
    if(d1.d>0&&d1.d<=29)
  	{printf("�������%d��\n",d1.d);
  	break;}
  	else printf("�����һ�������д�������������\n");
  	continue;
  	}
  	else
  	{
  	if(d1.d>0&&d1.d<=28)
  	{
  	printf("�������%d��\n",d1.d);
  	break;}
    else printf("�����һ�������д�������������\n");
  	continue;
  }
  }
  }
  
  printf("������ڶ������\n");//�ڶ���������ݵĴ�����
  while(1)
  {
  	
  scanf("%d",&d2.y);
  if(d2.y>1&&d2.y<3000)
  {
  	printf("�������%d��\n",d2.y);
  	break;
  }
  else
  {
  	printf("����ڶ�������д�������������\n");
  	continue;
  	}
  }
  
  printf("������ڶ����·�\n");//�ڶ��������·ݵĴ�����
  while(1)
  {
  scanf("%d",&d2.m);
  if(d2.m>=1&&d2.m<=12)
  {
  	printf("�������%d��\n",d2.m);
  	break;
  }
  else
  {
  	printf("����ڶ����·��д�������������\n");
  	continue;
  	}
  }
  
  printf("������ڶ�������\n");//�ڶ������ڵĴ�����
  while(1)
  {
  scanf("%d",&d2.d);
  if(d2.m==1||d2.m==3||d2.m==5||d2.m==7||d2.m==8||d2.m==10||d2.m==12)
  {
  	if(d2.d>0&&d2.d<=31)
  	{printf("�������%d��\n",d2.d);
  	break;
  	}
  	else
  	printf("����ڶ��������д�������������\n");
  	continue;
  }
  
  if(d2.m==4||d2.m==6||d2.m==9||d2.m==11)
  {
  if(d2.d>0&&d2.d<=30)
  {printf("�������%d��\n",d1.d);
  break;}
  else
  printf("����ڶ��������д�������������\n");
  continue;
  }
  
  if(d2.m==2)
  {
  if((d2.y%4==0&&d2.y%100!=0)||(d2.y%400==0))
  {
  if(d2.d>0&&d2.d<=29)
  {
  printf("�������%d��\n",d2.d);
  break;}
  else printf("����ڶ��������д�������������\n");
  continue;
  	}
  else
  {
  if(d2.d>0&&d2.d<=28)
  {
  printf("�������%d��\n",d2.d);
  break;}
  else 
  printf("����ڶ��������д�������������\n");
  continue;
  }
  }
  }
  
 if((d1.y%4==0&&d1.y%100!=0)||(d1.y%400==0))//���������������㷨
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
  if(!(d1.y%4==0&&d1.y%100!=0)||(d1.y%400==0))//ƽ�������������㷨
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
  
  if((d2.y%4==0&&d2.y%100!=0)||(d2.y%400==0))//�ڶ��������ظ�����
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
 
 
 if(d1.y>d2.y)//��һ�����ڴ�����
 m=(d1.y-d2.y)*365+((d1.y-d2.y)/4);
 if(d2.y>d1.y)//�ڶ������ڴ�����
 m=(d2.y-d1.y)*365+((d2.y-d1.y)/4);
  
 n=m+day2-day1;//������ļ��� 
 printf("���������Ϊ��%d",n);
 system("pause");
 }