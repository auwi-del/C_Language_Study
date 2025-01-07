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
    printf("\n\n---------------请输入学生信息---------------\n");           
    for(i=0;i<20;i++)   
    {     
        printf( "\n\n\n请输入学生学号\n" );    
        scanf( "%d", &s[i].num);         
        getchar();              

        printf( "\n请输入学生姓名\n" );    
        scanf( "%s", &s[i].name[20] );
        getchar();

        printf( "\n请输入学生 数学 成绩\n" );    
        scanf( "%d", &s[i].score[0] );       
        getchar();

        printf( "\n请输入学生 英语 成绩\n" );    
        scanf( "%d", &s[i].score[1] );       
        getchar();

        printf( "\n请输入学生 C语言 成绩\n" );    
        scanf( "%d", &s[i].score[2] );       
        getchar();

    } 

}


//查看成绩 平均值
void chengji()
 {
 	int i, j;
    // 这里中括号不用填数字, 会自动分配空间
 	char str[]="学号,姓名,数学成绩,英语成绩,c语言成绩,总成绩,平均成绩";
 	int arr[50][7];             // 定义了一个 50 * 7 的 "矩阵" 
 	for( i = 0; i <= 50; i++ )
 	{
 	 arr[1][i]=str[i];
 	}
 	
 	
 	
 	
 	
 }
 
  //查找
 void find()
 {
 	char name[20][20],search[20];
int i;
int flag=0;

for(i=0;i<20;i++)
scanf("%s",name[i]);

printf("\n本班同学为");
for(i=0;i<20;i++)
printf("%s\t",name[i]);

printf("请输入查询的名字:");
scanf("%s",search);	

for(i=0;i<20;i++)
{
if(strcmp(name[i],search)==0)
flag=1;
}

if(flag==1)
printf("查到此人");
else
printf("查无此人");
 	}
void main(){  
    int choice;     

    printf("\n\n\t\t------------------------------------------------------");
    printf("\n\t\t|        欢迎进入长春中医药大学成绩查询系统          |");
    printf("\n\t\t------------------------------------------------------");      
    printf("\n\t\t|1.录入学生信息                                      |");
    printf("\n\t\t|2.查看成绩 平均值                                   |");            
    printf("\n\t\t|3.查看排名                                          |");            
    printf("\n\t\t|4.查找                                              |");      
    printf("\n\t\t|5.回到主页面                                        |");
    printf("\n\t\t------------------------------------------------------\n");        
    printf("\n请输入你的选择：");  
    
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