/* Note:Your choice is C IDE */
#include "stdio.h"
typedef struct student
{
	int id;
	char name[20];
	int score[3];
	float aver;
} STU;

void main( STU st[],int n )
{
	int i,id;
	char quit;
	do{
		printf("学生的学号：");
		scanf("%d",&id);
		for(i=0;i<n;i++)
			if(id==st[i].id)
			{
				printf("不可输入此学号\n");
			}
	{
	st[i].id=id;
	printf("学生的姓名：");
	scanf("%s",&st[i].name);
	printf("学生的高数成绩：");
	scanf("%f",&st[i].score[1]);
	printf("学生的C语言成绩：");
	scanf("%f",&st[i].score[2]);
	printf("学生的英语成绩：");
	scanf("%f",&st[i].score[3]);
	n++;
	printf("请选择是否继续(T/F)");
	scanf("\t%c",&quit);
	}
	while (quit !='F')
	{
		continue;			// 不懂这里在干什么
	}
}