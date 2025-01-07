/* Note:Your choice is C IDE */
#include "stdio.h"
#include "string.h"
#include "stdlib.h"
#define HH printf("%-10s%-10%s-10%s-10s%-10%s-10%s-10%s\n","学号","姓名","英语","高数","c语言","总分","平均分")

// 以下是函数原型
void input();//输入
void awer();//平均值
void sort();//排序
void search();//查询
void retu();//退出

struct student
{
 int id;
 char name[20];
 int english,math,c,sum;
 float avg;
};
static int n;

void menu()
{
  int choice;
  printf("\n\n\t\t--------------------");
  printf("\n\t\t\t学生管理系统1.0");
  printf("\n1:输入学生信息");
  printf("\n2:计算平均成绩");
  printf("\n3:排序");
  printf("\n4:查询");
  printf("\n5:退出");
  printf("\n\n\t\t--------------------");

  printf("\n请输入你的选择: ");
  scanf("%d",&choice);
  switch(choice)
  {
    case 1: input();break;
    case 2: awer();break;
    case 3: sort();break;
    case 4: search();break;
    case 5: retu();break;
    
    default:printf("输入有误请输入正确操作");	
  }
}

void input(struct student stu[])//输入
{
	int i,n;
	int id=0;
	char quit;
	do
{
	printf("学号:");
	scanf("%d",&id);
	for(i=0;i<n;i++) 
{
	if (id==stu[i].id);
{
printf("此学号存在!\n");
return;
}
}
    stu[i].id=id;
    printf("姓名:");
    scanf("%s",&stu[i].name);
    printf("英语成绩:");
    scanf("%d",&stu[i].english);
    printf("高数成绩:");
    scanf("%d",&stu[i].math);
    printf("c语言成绩:");
    scanf("%d",&stu[i].c);
    stu[i].sum=stu[i].english+stu[i].math+stu[i].c;

    n++; //记录增加的次数
    printf("是否继续增加？(Y/N)");
    scanf("\t%c",&quit);
} while(quit !='N');
    printf("-%10d",stu[i].id);
    printf("-%10d",stu[i].name);
    printf("-%10d",stu[i].english);
	printf("-%10d",stu[i].math);	
    printf("-%10d",stu[i].c);
    printf("-%10d",stu[i].sum);
}

void awer()//平均值
{
   int a,b,c,d;
   int x;
   int sum;
   scanf("输入各科成绩:");
   sum=a+b+c+d;
   x=sum/4;
   printf("总成绩为:%d",sum);
   printf("平均成绩为:%d",x);
} 

void sort()//排序
{  
   int a[5];
   int k,j,t;
   printf("\n输入5门成绩: ");
   for (k=0;k<5;k++)
   scanf("%d",%a[k]);
   printf("\n");
   for(j=0;j=4;j++)
   for(k=0;k<4-j;k++)
   if (a[k]>[k+1]);
   (t=a[k];a[k]=a[k+1];a[k+1]=t);
   printf("顺序为：\n");
   for(k=0;k<5;k++)
   printf("%d",a[k]);
   printf("\n");
}

void search()//查询
{  
  char name[3][20];
  int i;
  char search[20];
  int flag=0;
   
  for(i=0;i<3;i++)
  scanf("%s",name[i]);
  printf("该班级同学如下:\n");
  
  for(i=0;i<3;i++)
  printf("%d %s\n",i+1,name[i]);
  printf("请输入查询学生姓名:");
  scanf("%s",search);
  
  for(i=0;i<3;i++)
  {
   if(strcmp(name[i],search)==0)
  {flag=1;break;}
  }
  if(flag==1)
  printf("查到此人");
  else
  printf("查无此人");
}

void retu()//退出
{
  struct student stu[50];
  int retu,quit=0;
  while(1)
{
  menu();
  scanf("%d",&select);
  if((retu>=CMD_END)||retu<0)
{
  printf("请输入0-6之间的选择\n");
}
    else 
{   
	if(retu==CMD_END)
{
	quit=1;
}
    else
{
	proc[retu].runcmd(stu);
}
}
    if (quit=1)
{
	break;
}
    printf("任意键返回\n");
    getchar();
    getchar();
}
    printf("结束\n");
} 