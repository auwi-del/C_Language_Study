
#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define LEN 15
#define N 50

int k = 1, n = 0, m = 0;

void seek();
void modify();
void insert();
void del();
void menu();
void sort();

struct student{
    char StudentId[LEN+1];
    char StudentName[LEN+1];
    float score[3];
    float aver;
}stu[N];

int main(){
    while (k){
        menu();
    }
    system("pause");
    return 0;
}

void seek(){
    int i, item, flag;
    char s1[21];
    printf("------------------\n");
    printf("-----1.按学号查询-----\n");
    printf("-----2.按姓名查询-----\n");
    printf("-----3.退出本菜单-----\n");
    printf("------------------\n");
    while (1){
        printf("请选择子菜单编号:");
        scanf("%d", &item);
        flag = 0;
        switch (item){
            case 1:
                printf("请输入要查询的学生的学号:\n");
                scanf("%s", s1);
                for (i = 0; i<n; i++)
                    if (strcmp(s1,stu[i].StudentId) == 0){
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
                    if (strcmp(stu[i].StudentName, s1) == 0){
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

void modify(){
    int i, item, num = -1;
    char sex1, s1[LEN + 1], s2[LEN + 1];
    float score1;
    printf("请输入要要修改的学生的学号:\n");
    scanf("%s", s1);
    for (i = 0; i < n; i++){
        if (strcmp(stu[i].StudentId, s1) == 0){
            num = i;
            printf("------------------\n");
            printf("1.修改姓名\n");
            printf("2.修改C语言成绩\n");
            printf("3.修改高等数学成绩\n");
            printf("4.修改大学英语成绩\n");
            printf("5.退出本菜单\n");
            printf("------------------\n");
            while (1){
                printf("请选择子菜单编号:");
                scanf("%d", &item);
                switch (item){
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
                    case 5: return;
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

void sort(){ // 定义一个名为sort的函数，无返回值和参数
int i, j, k; // 定义三个整型变量i、j、k，用于循环计数
char temp[LEN + 1], ctemp; // 定义一个字符数组temp和一个字符变量ctemp，用于交换学生信息
float ftemp; // 定义一个浮点型变量ftemp，用于交换学生成绩
for (i = 0; i<n - 1; i++){ // 外层循环，从第一个学生开始，循环到倒数第二个学生
	for (j = n - 1; j>i; j--) // 内层循环，从最后一个学生开始，循环到当前外层循环的学生
		if (strcmp(stu[j - 1].StudentId, stu[j].StudentId)>0)
		{ // 如果前一个学生的ID大于后一个学生的ID
			strcpy(temp, stu[j - 1].StudentId); // 交换学生ID
			strcpy(stu[j - 1].StudentId, stu[j].StudentId);
			strcpy(stu[j].StudentId, temp);
			strcpy(temp, stu[j - 1].StudentName); // 交换学生姓名
			strcpy(stu[j - 1].StudentName, stu[j].StudentName);
			strcpy(stu[j].StudentName, temp);
			for (k = 0; k<3; k++)
			{ 	// 循环交换学生成绩
				ftemp = stu[j - 1].score[k];
				stu[j - 1].score[k] = stu[j].score[k];
				stu[j].score[k] = ftemp;
			}
		}
	}
}

void insert(){
    int i = n, j, flag;
    printf("请输入待增加的学生数:\n");
    scanf("%d", &m);
    if (m > 0){
        do{
            flag = 1;
            while (flag){
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
        }
	}wile()
}