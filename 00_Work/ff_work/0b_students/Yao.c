#include "stdio.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct Student
{
 char Name[10];
 int Num;
 float Computer;
 float Math;
 float English;
 float Total;
 float Ave;
};
typedef struct Node
{
 struct Student st;
 struct node *pnext;
}node,*pnode;
pnode lnputt();
void ave(pnode phead);
void sort(pnode phead);
void search(pnode phead);
// void exit(pnode phead);
void main()
{
  int i, j, k;
 system("cls");
 printf("\n\n");
 printf("\t\t\t============================================\n");
 printf("\t\t\t|                                          |\n");
 printf("\t\t\t|          欢迎来到学生成绩管理系统        |\n");
 printf("\t\t\t|                                          |\n");
 printf("\t\t\t|==========================================|\n");
 printf("\t\t\t|            请选择要操作的命令            |\n");
 printf("\t\t\t|------------------------------------------|\n");
 printf("\t\t\t|                                          |\n");
 printf("\t\t\t|              1.录入学生信息              |\n");
 printf("\t\t\t|              2.计算平均成绩              |\n");
 printf("\t\t\t|              3.排序                      |\n");
 printf("\t\t\t|              4.查询                      |\n");
 printf("\t\t\t|              5.退出                      |\n");
 printf("\t\t\t|                                          |\n");
 printf("\t\t\t============================================\n");
 int Item;
 pnode phead=NULL;
 while(1)
 {
  printf("请选择操作命令:");
  scanf("%d",&Item);
  system("cls");
  switch(i)
  {
 case 1: pnode = inputt();break;
 case 2:ave();break;
 case 3:sort();break;
 case 4:search();break;
 case 5:exit();break;
   default:
   break;
  }
 }
 system("pause");
}
//录入学生信息
pnod46e inputt()
{
 int num;
 node stu;
 pnode phead=(pnode)malloc(sizeof(node));
 if(NULL==phead)
 {
  printf("内存分配失败,程序终止!\n");
  exit(-1);
 }
 pnode ptail=phead;
 ptail->pnext=NULL;
 printf("请输入学生的人数:");
 scanf("%d",&num);
 int i;
 for(i=0;i<num;i++)
 {
  printf("请输入第%d个学生的姓名:",i+1);
  scanf("%s",stu.st.Name);
  printf("请输入第%d个学生的学号:",i+1);
  scanf("%d",&stu.st.Num);
  printf("请输入第%d个学生的计算机成绩:",i+1);
  scanf("%f",&stu.st.Computer);
  printf("请输入第%d个学生的高数成绩:",i+1);
  scanf("%f",&stu.st.Math);
  printf("请输入第%d个学生的英语成绩:",i+1);
  scanf("%f",&stu.st.English);
  stu.st.Total=stu.st.Computer+stu.st.Math+stu.st.English;
  stu.st.Ave=stu.st.Total/3.0f;
  // if(NULL==pnew)
  // {
  //  printf("内存分配失败,程序终止!\n");
  //  exit(-1);
  // }
  pnew->st=stu.st;
  ptail->pnext=pnew;
  pnew->pnext=NULL;
  ptail=pnew;
 }
 return phead;
}


void ave(pnode phead)
{
 pnode p=phead->pnext;
 printf("姓名  学号 计算机 高数  英语 总分 平均分\n");
 while(NULL!=p)
 {
  printf("%s    %d    %g    %g    %g   %g    %g\n",p->st.Name,p->st.Num,p->st.Computer,p->st.Math,p->st.English,p->st.Total,p->st.Ave);
  p=p->pnext;
 }
}

//总分排序
void Sort(pnode phead)
{
 pnode p, q;
 node temp;
 for(p=phead->pnext;NULL!=p;p=p->pnext)
 {
  for(q=p->pnext;NULL!=q;q=q->pnext)
    {
   if(p->st.Total<q->st.Total)
      {
    temp.st=p->st;
    p->st=q->st;
    q->st=temp.st;
   }
  }
 }
}