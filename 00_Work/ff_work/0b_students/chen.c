/* Note:Your choice is C IDE */
#include "stdio.h"


struct student
{
    int num;     
    char name[20];     
    int score[10];    
};

typedef struct student Stu;

void input()
{ 
    int i;  
    Stu s[20];
    printf("\n\n---------------������ѧ����Ϣ---------------\n");           
    for(i=0;i<20;i++)   
    {     
        printf( "\n\n\n������ѧ��ѧ��\n" );    
        scanf( "%d", &s[i].num);         
        getchar();              

        printf( "\n������ѧ������\n" );    
        scanf( "%s", &s[i].name[20] );
        getchar();

        printf( "\n������ѧ�� ��ѧ �ɼ�\n" );    
        scanf( "%d", &s[i].score[0] );       
        getchar();

        printf( "\n������ѧ�� Ӣ�� �ɼ�\n" );    
        scanf( "%d", &s[i].score[1] );       
        getchar();

        printf( "\n������ѧ�� C���� �ɼ�\n" );    
        scanf( "%d", &s[i].score[2] );       
        getchar();

    } 

}


//�鿴�ɼ� ƽ��ֵ
void chengji()
 {
 	int i, j;
    // ���������Ų���������, ���Զ�����ռ�
 	char str[]="ѧ��,����,��ѧ�ɼ�,Ӣ��ɼ�,c���Գɼ�,�ܳɼ�,ƽ���ɼ�";
 	int arr[50][7];             // ������һ�� 50 * 7 �� "����" 
 	for( i = 0; i <= 50; i++ )
 	{
 	 arr[1][i]=str[i];
 	}
 	
 	
 	
 	
 	
 }
 
  //����
 void find()
 {
 	char name[20][20],search[20];
int i;
int flag=0;

for(i=0;i<20;i++)
scanf("%s",name[i]);

printf("\n����ͬѧΪ");
for(i=0;i<20;i++)
printf("%s\t",name[i]);

printf("�������ѯ������:");
scanf("%s",search);	

for(i=0;i<20;i++)
{
if(strcmp(name[i],search)==0)
flag=1;
}

if(flag==1)
printf("�鵽����");
else
printf("���޴���");
 	}
void main(){  
    int choice;     

    printf("\n\n\t\t------------------------------------------------------");
    printf("\n\t\t|        ��ӭ���볤����ҽҩ��ѧ�ɼ���ѯϵͳ          |");
    printf("\n\t\t------------------------------------------------------");      
    printf("\n\t\t|1.¼��ѧ����Ϣ                                      |");
    printf("\n\t\t|2.�鿴�ɼ� ƽ��ֵ                                   |");            
    printf("\n\t\t|3.�鿴����                                          |");            
    printf("\n\t\t|4.����                                              |");      
    printf("\n\t\t|5.�ص���ҳ��                                        |");
    printf("\n\t\t------------------------------------------------------\n");        
    printf("\n���������ѡ��");  
    
    scanf("%d",&choice);    
    
    
  while(choice!=5)
  {
  	switch(choice)
  	{
  	case 1:system("cls");
  	       input();
    case 2:system("cls");
           chengji();     
  	case 4:system("cls");
  	       find();
  	}
  }
}