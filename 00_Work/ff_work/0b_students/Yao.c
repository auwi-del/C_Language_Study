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
 printf("\t\t\t|          ��ӭ����ѧ���ɼ�����ϵͳ        |\n");
 printf("\t\t\t|                                          |\n");
 printf("\t\t\t|==========================================|\n");
 printf("\t\t\t|            ��ѡ��Ҫ����������            |\n");
 printf("\t\t\t|------------------------------------------|\n");
 printf("\t\t\t|                                          |\n");
 printf("\t\t\t|              1.¼��ѧ����Ϣ              |\n");
 printf("\t\t\t|              2.����ƽ���ɼ�              |\n");
 printf("\t\t\t|              3.����                      |\n");
 printf("\t\t\t|              4.��ѯ                      |\n");
 printf("\t\t\t|              5.�˳�                      |\n");
 printf("\t\t\t|                                          |\n");
 printf("\t\t\t============================================\n");
 int Item;
 pnode phead=NULL;
 while(1)
 {
  printf("��ѡ���������:");
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
//¼��ѧ����Ϣ
pnod46e inputt()
{
 int num;
 node stu;
 pnode phead=(pnode)malloc(sizeof(node));
 if(NULL==phead)
 {
  printf("�ڴ����ʧ��,������ֹ!\n");
  exit(-1);
 }
 pnode ptail=phead;
 ptail->pnext=NULL;
 printf("������ѧ��������:");
 scanf("%d",&num);
 int i;
 for(i=0;i<num;i++)
 {
  printf("�������%d��ѧ��������:",i+1);
  scanf("%s",stu.st.Name);
  printf("�������%d��ѧ����ѧ��:",i+1);
  scanf("%d",&stu.st.Num);
  printf("�������%d��ѧ���ļ�����ɼ�:",i+1);
  scanf("%f",&stu.st.Computer);
  printf("�������%d��ѧ���ĸ����ɼ�:",i+1);
  scanf("%f",&stu.st.Math);
  printf("�������%d��ѧ����Ӣ��ɼ�:",i+1);
  scanf("%f",&stu.st.English);
  stu.st.Total=stu.st.Computer+stu.st.Math+stu.st.English;
  stu.st.Ave=stu.st.Total/3.0f;
  // if(NULL==pnew)
  // {
  //  printf("�ڴ����ʧ��,������ֹ!\n");
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
 printf("����  ѧ�� ����� ����  Ӣ�� �ܷ� ƽ����\n");
 while(NULL!=p)
 {
  printf("%s    %d    %g    %g    %g   %g    %g\n",p->st.Name,p->st.Num,p->st.Computer,p->st.Math,p->st.English,p->st.Total,p->st.Ave);
  p=p->pnext;
 }
}

//�ܷ�����
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