/* Note:Your choice is C IDE */
#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>	/*I/O函数*/
#include<stdlib.h>	/*其它说明*/
#include<string.h>	/*字符串函数*/

#define LEN 15		/* 学号和姓名最大字符数,实际请更改*/
#define N 50		/* 最大学生人数,实际请更改*/

int k = 1, n = 0, m = 0;/* n代表当前记录的学生人数*/

//函数声明
void seek();
void modify();
void insert();
void del();
void menu();

//结构体保存学生信息
struct student{
	char StudentId[LEN+1];
	char StudentName[LEN+1];
	float score[3];
	float aver;
}stu[N];



void printStu(struct student stu[], int n)
{
	int i;
	printf("\n\n\n\n\n学号\t姓名\tC语言\t\t高等数学\t英语成绩\n");
	for(i=0;i<n;i++)
	{
		printf("%s\t%s\t%.2f\t\t%.2f\t\t%.2f\n",stu[i].StudentId,stu[i].StudentName,stu[i].score[0],stu[i].score[1],stu[i].score[2]);
	}
}

//主函数
int main()
{
	while (k)
	{
		menu();
	}
	system("pause");
	return 0;
}
//查找学生信息
void seek() /*查找*/
{
	int i, item, flag;
	char s1[21]; /* 以姓名和学号最长长度+1为准*/
	printf("------------------\n");
	printf("-----1.按学号查询-----\n");
	printf("-----2.按姓名查询-----\n");
	printf("-----3.退出本菜单-----\n");
	printf("------------------\n");
	while (1)
	{
		printf("请选择子菜单编号:");
		scanf("%d", &item);
		flag = 0;
		switch (item)
		{
		case 1:
			printf("请输入要查询的学生的学号:\n");
			scanf("%s", s1);
			for (i = 0; i<n; i++)
			if (strcmp(s1,stu[i].StudentId) == 0)
			{
				flag = 1;
				printf("学生学号\t学生姓名\tC语言成绩\t高等数学\t大学英语成绩\n");
				printf("--------------------------------------------------------------------\n");
				printf("%s\t%s\t%.1f\t%.1f\t%.1f\n", stu[i].StudentId,stu[i].StudentName,stu[i].score[0],stu[i].score[1],stu[i].score[2]);
			}
			if (0 == flag)
				printf("该学号不存在！\n"); break;
		case 2:
			printf("请输入要查询的学生的姓名:\n");
			scanf("%s", s1);
			for (i = 0; i<n; i++)
			if (strcmp(stu[i].StudentName, s1) == 0)
			{
				flag = 1;
				printf("学生学号\t学生姓名\tC语言成绩\t高等数学\t大学英语成绩\n");
				printf("--------------------------------------------------------------------\n");
				printf("%s\t%s\t%.1f\t%.1f\t%.1f\n", stu[i].StudentId, stu[i].StudentName, stu[i].score[0], stu[i].score[1], stu[i].score[2]);
			}
			if (0 == flag)
				printf("该姓名不存在！\n"); break;
		case 3:return;
		default:printf("请在1-3之间选择\n");
		}
	}
}

//修改学生信息
void modify() /*修改信息*/
{
	int i, item, num = -1;
	char sex1, s1[LEN + 1], s2[LEN + 1]; /* 以姓名和学号最长长度+1为准*/
	float score1;
	printf("请输入要要修改的学生的学号:\n");
	scanf("%s", s1);
	for (i = 0; i < n; i++){
		if (strcmp(stu[i].StudentId, s1) == 0){/*比较字符串是否相等*/
			num = i;
			printf("------------------\n");
			printf("1.修改姓名\n");
			printf("2.修改C语言成绩\n");
			printf("3.修改高等数学成绩\n");
			printf("4.修改大学英语成绩\n");
			printf("5.退出本菜单\n");
			printf("------------------\n");
			while (1)
			{
				printf("请选择子菜单编号:");
				scanf("%d", &item);
				switch (item)
				{
				case 1:
					printf("请输入新的姓名:\n");
					scanf("%s", s2);
					strcpy(stu[num].StudentName, s2);
					break;
				case 2:
					printf("请输入新的C语言成绩:\n");
					scanf("%f", &score1);
					stu[num].score[0] = score1;
					break;
				case 3:
					printf("请输入新的高等数学成绩:\n");
					scanf("%f", &score1);
					stu[num].score[1] = score1;
					break;
				case 4:
					printf("请输入新的大学英语成绩:\n");
					scanf("%f", &score1);
					stu[num].score[2] = score1;
					break;
				case 5:	return;
				default:printf("请在1-5之间选择\n");
				}
			}
			printf("修改完毕！请及时保存！\n");
		}
		else{
			printf("没有该学生学号!!!");
		}
	}
}

void sort()//按总分排序
{
	int i,j;
	struct student temp;
	for(i=0;i<n-1;i++)
	{
		for(j=0;j<n-i-1;j++)
		{
			if(stu[j].score[0]+stu[j].score[1]+stu[j].score[2]<stu[j+1].score[0]+stu[j+1].score[1]+stu[j+1].score[2])
			{
				temp=stu[j];
				stu[j]=stu[j+1];
				stu[j+1]=temp;
			}
		}
	}
}

//添加学生信息函数
void insert() /*插入函数*/
{
	int i = n, j, flag;
	printf("请输入待增加的学生数:\n");
	scanf("%d", &m);
	if (m > 0){
		do
		{
			flag = 1;
			while (flag)
			{
				flag = 0;
				printf("请输入第%d位学生的学号:\n", i + 1);
				scanf("%s", stu[i].StudentId);
				for (j = 0; j < i; j++){
					if (strcmp(stu[i].StudentId, stu[j].StudentId) == 0){
						printf("该学号已存在，请重新输入！\n");
						flag = 1;
						break;
					}
				}
			}
			printf("请输入第%d 个学生的姓名:\n", i+1);
			scanf("%s", stu[i].StudentName);
			printf("请输入第%d 个学生的C语言成绩\n",i+1);
			scanf("%f", &stu[i].score[0]);
			printf("请输入第%d 个学生的高等数学成绩:\n", i+1);
			scanf("%f", &stu[i].score[1]);
			printf("请输入第%d 个学生的大学英语成绩:\n", i+1);
			scanf("%f", &stu[i].score[2]);
			if (0 == flag){
				i++;
			}
		} while (i<n + m);
	}
		n += m;
		printf("学生信息增加完毕！！！\n");
		system("pause");
}

//删除学生信息函数
void del()
{
	int i, j, flag = 0;
	char s1[LEN + 1];
	printf("请输入要删除学生的学号:\n");
	scanf("%s", s1);
	for (i = 0; i < n; i++){
		if (strcpy(stu[i].StudentId, s1) == 0){
			flag = 1;
			//要删除学生后面的学生往前移一位
			for (j = i; j < n - 1; j++){
				stu[j] = stu[j + 1];
			}
		}
	}
		//查找失败
		if (0 == flag){
			printf("该学号不存在!!!\n");
		}
		if (1 == flag){
			printf("删除成功！！！");
			//删除成功，学生人数减1
			n--;
		}
		system("pause");
}
int pjs()
{
	int i,m;
	void insert(m);
	for(i=0;i<m;i++)
	{
	stu[i].aver=(stu[i].score[0]+stu[i].score[1]+stu[i].score[2])/3;
	printf("%.2f",stu[i].aver);
	break;
	}
}
	
void menu()/* 界面*/
{
	int num;
	printf(" \n\n                    \n\n");
	printf("  ******************************************************\n\n");
	printf("  *                学生信息管理系统                    *\n \n");
	printf("  ******************************************************\n\n");
	printf("*********************系统功能菜单*************************       \n");
	printf("     ----------------------   ----------------------   \n");
	printf("     ************************************r*********     \n");
	printf("     * 1.增添学生信息    * *  2.修改学生信息     *     \n");
	printf("     *********************************************     \n");
	printf("     * 3.查询学生信息    * *  4.按学号删除信息   *     \n");
	printf("     *********************************************     \n");
	printf("     * 5.计算平均数      * *  6.退出系统         *      \n");
	printf("     ********************** *********************     \n");
	printf("     * 7.   排   序      * *  8.显示所有         *     \n");
	printf("     ********************** **********************     \n");
	printf("     ----------------------   ----------------------                           \n");
	printf("请选择菜单编号:");
	scanf("%d", &num);
	switch (num)
	{
	case 1:insert(); break;
	case 2:modify(); break;
	case 3:seek(); break;
	case 4:del(); break;
		k = 0; 
	case 5:pjs();break;
	case 6:
		printf("即将退出程序!\n");
		break;
	case 7:
		sort();
		printStu( stu, n);
		break;
	case 8:
		printStu( stu, n);
		break;

	default:printf("请在1-6之间选择\n");
	}
}
