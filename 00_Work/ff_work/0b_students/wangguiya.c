/* Note:Your choice is C IDE */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 100 // 学生数量上限

struct student{
char name[50];
float score;
};
int addStudent(struct student students[], int n);
float calcAverage(struct student students[], int n);
void sortScores(float scores[], int n);
void sortStudents(struct student students[], int n);
void queryStudent(struct student students[], int n);
void exitProgram();
int main()
{
struct student students[N];
int count = 0, choice;
float avg_score;
while(1)
{
printf("\t\t\t\t------------------");
printf("\n\t\t\t\t    教务系统");
printf("\n\t\t\t\t------------------");
printf("\n\t\t\t\t1. 录入学生信息");
printf("\n\t\t\t\t2. 计算平均成绩");
printf("\n\t\t\t\t3. 平均成绩排序");
printf("\n\t\t\t\t4. 查询学生信息");
printf("\n\t\t\t\t5. 退出程序");
printf("\n\t\t\t\t------------------");
printf("\n\t\t\t\t请选择操作:");
while(1)
{
scanf("%d", &choice);
switch(choice)
{
case 1:
count = addStudent(students, count);
break;
case 2:
avg_score = calcAverage(students, count);
printf("平均成绩为：%.1f\n", avg_score);
break;
case 3:
sortStudents(students, count);
break;
case 4:
queryStudent(students, count);
break;
case 5:
exitProgram();
default:
printf("请输入正确的选项！\n");
if(choice==5)
{
   break;
}
}
}
}
return 0;
}
int addStudent(struct student students[], int n){
int i;
char name[50];
float score;
printf("请输入学生姓名和成绩（用空格隔开，输入-1结束）：\n");
for(i = n; i < N; i++)
{
scanf("%s%f", &name, &score);
if( !strcmp( name, "-1" ) )   // 判断退出的条件 
   break;
strcpy(students[i].name, name);
students[i].score = score;
printf("录入成功！\n");
}
return i;
}
float calcAverage(struct student students[], int n)
{
int i;
float sum = 0.0, avg = 0.0;
for(i = 0; i < n; i++)
{
sum += students[i].score;
}
if(n != 0) avg = sum / n;
return avg;
}
void sortScores(float scores[], int n)
{
int i, j, temp_pos;
float temp_score;

 // 冒泡排序
for(i = 0; i < n - 1; ++i)
{
temp_pos = i;
for(j = i + 1; j < n; ++j)
{
if(scores[j] > scores[temp_pos])
{
temp_pos = j;
}
}
if(temp_pos != i)
{
temp_score = scores[i];
scores[i] = scores[temp_pos];
scores[temp_pos] = temp_score;
}
}
}
void sortStudents(struct student students[], int n)
{
int i;
float scores[N];
for(i = 0; i < n; i++)
{
scores[i] = students[i].score;
}
sortScores(scores, n);
printf("平均成绩排序结果：\n");
for(i = 0; i < n; i++)
{
printf("%s %.1f\n", students[i].name, scores[i]);
}
}
void queryStudent(struct student students[], int n)
{
int i;
char name[50];
printf("请输入要查询的学生姓名：\n");
scanf("%s", name);
for(i = 0; i < n; i++)
{
if(strcmp(students[i].name, name) == 0)
{
printf("姓名：%s，成绩：%.1f\n", students[i].name, students[i].score);
return;
}
}
printf("没有找到该学生！\n");
}
void exitProgram()
{
printf("感谢使用，再见！\n");
exit(0);
}