/* Note:Your choice is C IDE */
#include "stdio.h"
#include "string.h"
#include "stdlib.h"
#define HH printf("%-10s%-10%s-10%s-10s%-10%s-10%s-10%s\n","ѧ��","����","Ӣ��","����","c����","�ܷ�","ƽ����")

// �����Ǻ���ԭ��
void input();//����
void awer();//ƽ��ֵ
void sort();//����
void search();//��ѯ
void retu();//�˳�

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
  printf("\n\t\t\tѧ������ϵͳ1.0");
  printf("\n1:����ѧ����Ϣ");
  printf("\n2:����ƽ���ɼ�");
  printf("\n3:����");
  printf("\n4:��ѯ");
  printf("\n5:�˳�");
  printf("\n\n\t\t--------------------");

  printf("\n���������ѡ��: ");
  scanf("%d",&choice);
  switch(choice)
  {
    case 1: input();break;
    case 2: awer();break;
    case 3: sort();break;
    case 4: search();break;
    case 5: retu();break;
    
    default:printf("����������������ȷ����");	
  }
}

void input(struct student stu[])//����
{
	int i,n;
	int id=0;
	char quit;
	do
{
	printf("ѧ��:");
	scanf("%d",&id);
	for(i=0;i<n;i++) 
{
	if (id==stu[i].id);
{
printf("��ѧ�Ŵ���!\n");
return;
}
}
    stu[i].id=id;
    printf("����:");
    scanf("%s",&stu[i].name);
    printf("Ӣ��ɼ�:");
    scanf("%d",&stu[i].english);
    printf("�����ɼ�:");
    scanf("%d",&stu[i].math);
    printf("c���Գɼ�:");
    scanf("%d",&stu[i].c);
    stu[i].sum=stu[i].english+stu[i].math+stu[i].c;

    n++; //��¼���ӵĴ���
    printf("�Ƿ�������ӣ�(Y/N)");
    scanf("\t%c",&quit);
} while(quit !='N');
    printf("-%10d",stu[i].id);
    printf("-%10d",stu[i].name);
    printf("-%10d",stu[i].english);
	printf("-%10d",stu[i].math);	
    printf("-%10d",stu[i].c);
    printf("-%10d",stu[i].sum);
}

void awer()//ƽ��ֵ
{
   int a,b,c,d;
   int x;
   int sum;
   scanf("������Ƴɼ�:");
   sum=a+b+c+d;
   x=sum/4;
   printf("�ܳɼ�Ϊ:%d",sum);
   printf("ƽ���ɼ�Ϊ:%d",x);
} 

void sort()//����
{  
   int a[5];
   int k,j,t;
   printf("\n����5�ųɼ�: ");
   for (k=0;k<5;k++)
   scanf("%d",%a[k]);
   printf("\n");
   for(j=0;j=4;j++)
   for(k=0;k<4-j;k++)
   if (a[k]>[k+1]);
   (t=a[k];a[k]=a[k+1];a[k+1]=t);
   printf("˳��Ϊ��\n");
   for(k=0;k<5;k++)
   printf("%d",a[k]);
   printf("\n");
}

void search()//��ѯ
{  
  char name[3][20];
  int i;
  char search[20];
  int flag=0;
   
  for(i=0;i<3;i++)
  scanf("%s",name[i]);
  printf("�ð༶ͬѧ����:\n");
  
  for(i=0;i<3;i++)
  printf("%d %s\n",i+1,name[i]);
  printf("�������ѯѧ������:");
  scanf("%s",search);
  
  for(i=0;i<3;i++)
  {
   if(strcmp(name[i],search)==0)
  {flag=1;break;}
  }
  if(flag==1)
  printf("�鵽����");
  else
  printf("���޴���");
}

void retu()//�˳�
{
  struct student stu[50];
  int retu,quit=0;
  while(1)
{
  menu();
  scanf("%d",&select);
  if((retu>=CMD_END)||retu<0)
{
  printf("������0-6֮���ѡ��\n");
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
    printf("���������\n");
    getchar();
    getchar();
}
    printf("����\n");
} 