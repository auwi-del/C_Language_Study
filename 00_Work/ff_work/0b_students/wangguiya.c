/* Note:Your choice is C IDE */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 100 // ѧ����������

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
printf("\n\t\t\t\t    ����ϵͳ");
printf("\n\t\t\t\t------------------");
printf("\n\t\t\t\t1. ¼��ѧ����Ϣ");
printf("\n\t\t\t\t2. ����ƽ���ɼ�");
printf("\n\t\t\t\t3. ƽ���ɼ�����");
printf("\n\t\t\t\t4. ��ѯѧ����Ϣ");
printf("\n\t\t\t\t5. �˳�����");
printf("\n\t\t\t\t------------------");
printf("\n\t\t\t\t��ѡ�����:");
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
printf("ƽ���ɼ�Ϊ��%.1f\n", avg_score);
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
printf("��������ȷ��ѡ�\n");
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
printf("������ѧ�������ͳɼ����ÿո����������-1��������\n");
for(i = n; i < N; i++)
{
scanf("%s%f", &name, &score);
if( !strcmp( name, "-1" ) )   // �ж��˳������� 
   break;
strcpy(students[i].name, name);
students[i].score = score;
printf("¼��ɹ���\n");
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

 // ð������
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
printf("ƽ���ɼ���������\n");
for(i = 0; i < n; i++)
{
printf("%s %.1f\n", students[i].name, scores[i]);
}
}
void queryStudent(struct student students[], int n)
{
int i;
char name[50];
printf("������Ҫ��ѯ��ѧ��������\n");
scanf("%s", name);
for(i = 0; i < n; i++)
{
if(strcmp(students[i].name, name) == 0)
{
printf("������%s���ɼ���%.1f\n", students[i].name, students[i].score);
return;
}
}
printf("û���ҵ���ѧ����\n");
}
void exitProgram()
{
printf("��лʹ�ã��ټ���\n");
exit(0);
}