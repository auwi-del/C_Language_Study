/* Note:Your choice is C IDE */

#include<stdio.h>
#include<stdlib.h>
#define N 50
 
struct Student  //����һ��ѧ��
{
 int num;    //ѧ��
 char name[20];   //����
 int math;    //��ѧ�ɼ�
 int english;      //Ӣ��ɼ�
 int c;   //c���Գɼ�
 int zong;
 float pingjun;
}Stu[99];
 
 int n;
 int choice;
void Exit()
{    
             system("cls");
                printf("\n\n\n\n");
                printf("\t\t\t****************************************************************\n");
                printf("\t\t\t||                                                            ||\n");
                printf("\t\t\t||                      ��лʹ�ñ�����                      ||\n");
                printf("\t\t\t||                                                            ||\n");
                printf("\t\t\t||                                                            ||\n");
                printf("\t\t\t||                                                            ||\n");
                printf("\t\t\t****************************************************************\n");
    }
void Menu()
{
 
 printf("                              *************************ѧ���ɼ�����ϵͳ************************\n");
 printf("                                                  ��ѡ��Ҫ���еĲ���\n                                             \n");
 printf("                                                   1 : ����ѧ����Ϣ\n");
 printf("                                                   2 : ��ʾ����ѧ����Ϣ\n");
 printf("                                                   3 : ����ѧ����Ϣ\n");
 printf("                                                   4 : ����ѧ����Ϣ\n");
 printf("                                                   5 : ɾ��ѧ����Ϣ\n");
 printf("                                                   6 : �˳�\n");
 printf("���������ѡ��: \n");
 scanf("%d",&choice);
 
}

 

 
 int InputStudent()  //����ѧ����Ϣ 
 {
 int d; 
 int i=1;
  
 while(i)
 {
  system("cls");
   printf("========================ѧ���ɼ�����========================\n\n");
    
   printf("\n�������%d��ѧ������Ϣ:\n",i);
   
   printf("ѧ��: ");
   scanf("%d",&Stu[i].num);
   
   printf("����: ");
   scanf("%s",Stu[i].name);
   
   printf("��ѧ�ɼ�: ");
   scanf("%d",&Stu[i].math);
   
   printf("c���Գɼ�: ");
   scanf("%d",&Stu[i].c);
   
   printf("Ӣ��ɼ�: ");
   scanf("%d",&Stu[i].english);
   
   i++;
   n++;
   
   printf("�Ƿ��������?(1.���� 2.�˳�)\n");
   scanf("%d",&d);
   if(d==2){
    system("cls");
     return main();
    }
    }
  }
void PrintStudent()  //��ʾѧ����Ϣ
 {
 
  int i;
   system("cls");
  printf("========================ѧ���ɼ���ʾ========================\n\n\n");
  printf("\nѧ��\t����\t��ѧ�ɼ�\tC���Գɼ�\tӢ��ɼ�\t�ܳɼ�\tƽ���ɼ�\n\n\n");
 
 for(i=1; i<=n; i++)
 {
  Stu[i].zong=Stu[i].c+Stu[i].english+Stu[i].math;
  Stu[i].pingjun=(Stu[i].c+Stu[i].english+Stu[i].math)/3;
  printf("%d\t%s\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n", Stu[i].num, Stu[i].name, Stu[i].math,Stu[i].c,Stu[i].english,Stu[i].zong,Stu[i].zong/3);
 }
 
  return main();
 }
void SortStudent()  //ѧ����Ϣ����
 { 
  struct Student k; 
  int j;
  int i; 
  system("cls");
  printf("\n============��ѧ�Ŵ�С��������===========\n");
  for(j=0;j<n-1;j++)
   for(i=1;i<n-j;i++){
    if(Stu[i].num>Stu[i+1].num){
       k=Stu[i];
       Stu[i]=Stu[i+1];
       Stu[i+1]=k;
      } 
     }
     for(i=1;i<=n;i++){
  Stu[i].zong=Stu[i].c+Stu[i].english+Stu[i].math;
        printf("ѧ����ѧ��Ϊ:%d\n",Stu[i].num);
        printf("ѧ��������Ϊ:%s\n",Stu[i].name);
        printf("��ѧ�ɼ�Ϊ:%d\n",Stu[i].math);
  printf("c���Գɼ�Ϊ:%d\n",Stu[i].c);
  printf("Ӣ��ɼ�Ϊ:%d\n",Stu[i].english);
  printf("ѧ�����ܳɼ�Ϊ:%d\n\n",Stu[i].zong);
  
  }
       printf("\n");
       return main();
}
void FindStudent()  //����ѧ����Ϣ
 {
  int renming;
  int i,q;
  system("cls");
  printf("\n============���������в���===========\n");
  printf("������Ҫ���ҵ�����: ");
  scanf("%d",&renming);
 
  for(i=1;i<=n;i++){
   if(renming==Stu[i].name){
    Stu[i].zong=Stu[i].c+Stu[i].english+Stu[i].math;
    printf("\n���ҳɹ�!\n\n\n");
    printf("ѧ����ѧ��Ϊ:%d\n",Stu[i].num);
    printf("ѧ��������Ϊ:%s\n",Stu[i].name);
    printf("��ѧ�ɼ�Ϊ:%d\n",Stu[i].math);
    printf("c���Գɼ�Ϊ:%d\n",Stu[i].c);
    printf("Ӣ��ɼ�Ϊ:%d\n",Stu[i].english);
    printf("ѧ���ܳɼ�Ϊ:%d\n",Stu[i].zong);
     
    }
  }
 
 return main();
 
 }
 void DeleteStudent() //ɾ��ѧ����Ϣ
 {
  int nums;
  int i,j,d;
  system("cls");
  printf("\n============��ѧ�Ž���ɾ����Ϣ===========\n");
  printf("������Ҫɾ���˵�ѧ��: ");
  scanf("%d",&nums);
   
  for(i=1;i<=n;i++)
  {
   if(nums==Stu[i].num)
   {
   printf("ѧ��\t����\t��ѧ\tc����\tӢ��\t\n");
   printf("%d\t%s\t%d\t%d\t%d\t\n",Stu[i].num,Stu[i].name,Stu[i].math,Stu[i].c,Stu[i].english);
   
   printf("ȷ��ɾ��!(1.Y 2.N)\n");
   scanf("%d",&d);
   if(d==1)
{
     for(j=i;j<=n;j++)
     {
      Stu[j].num=Stu[j+1].num;
         strcpy(Stu[j].name,Stu[j+1].name);
      Stu[j].math=Stu[j+1].math;
      Stu[j].c=Stu[j+1].c;
      Stu[j].english=Stu[j+1].english;
     }
     n--;
   return main();
   }
   if(d==2)
   {
   return main();
   }
  }
 }
}

 
 

  int main()
  {
   
   Menu();
  
  switch (choice)
  {
    case 1:  //����ѧ����Ϣ
 
    InputStudent(Stu,N);
     break;
    case 2:  //��ʾѧ����Ϣ
     PrintStudent(Stu,N);
     break;
    case 3:  //����
     SortStudent(Stu,N);
      break;
    case 4:  //����
FindStudent(Stu,N);
     break;
    case 5:  //ɾ��
     DeleteStudent(Stu,N);
     break;
    case 6:  //�˳�
     Exit(Stu,N);
      break;
     } 
    return 0;
   
  }