#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STUDENTS 100
#define MAX_NAME_LENGTH 50

typedef struct
{
    char name[MAX_NAME_LENGTH];
    int calculusScore;
    int cLanguageScore;
    int englishScore;
    float avge;
} Student;

Student students[MAX_STUDENTS];
int numStudents = 0;

void addStudent()
{
    if (numStudents >= MAX_STUDENTS)
    {
        printf("学生数量已达到上限，无法添加新的学生。\n");
        return;
    }

    printf("请输入学生姓名：");
    scanf("%s", students[numStudents].name);

    printf("请输入高数分数：");
    scanf("%d", &students[numStudents].calculusScore);

    printf("请输入C语言分数：");
    scanf("%d", &students[numStudents].cLanguageScore);

    printf("请输入英语分数：");
    scanf("%d", &students[numStudents].englishScore);

    numStudents++;

    printf("学生信息已录入。\n");
}

// 计算平均分
float calculateAverageScore()
{
    int totalScore = 0;
    int i;

    if ( numStudents == 0 )
    {
        printf("当前没有学生信息。\n");
        return 0.0;
    }

    for (i = 0; i < numStudents; i++)
    {
        totalScore += students[i].calculusScore + students[i].cLanguageScore + students[i].englishScore;
    }

    return (float)totalScore / (numStudents * 3);

    
}

// 传入两个指针, 传回 a的总分 - b的总分
int compareStudents( const void *a, const void *b )
{
    // 对传进来的 指针 进行拷贝
    Student *studentA = (Student *)a;
    Student *studentB = (Student *)b;

    // 计算总分
    int totalScoreA = studentA->calculusScore + studentA->cLanguageScore + studentA->englishScore;
    int totalScoreB = studentB->calculusScore + studentB->cLanguageScore + studentB->englishScore;

    return totalScoreA - totalScoreB;
}

void sortStudents()
{
    if (numStudents == 0)
    {
        printf("当前没有学生信息。\n");
        return;
    }

    qsort(students, numStudents, sizeof(Student), compareStudents);

    printf("学生信息已排序。\n");
}

void printStudents()
{
	int i;
    if (numStudents == 0)
    {
        printf("当前没有学生信息。\n");
        return;
    }

    printf("所有学生信息：\n");
    for (i = 0; i < numStudents; i++)
    {
        printf("学生姓名：%s，高数：%d，C语言：%d，英语：%d\n", students[i].name, students[i].calculusScore, students[i].cLanguageScore, students[i].englishScore);
    }
}

void searchStudent()
{
    char searchName[MAX_NAME_LENGTH];
    int found = 0;
    int i;
    if (numStudents == 0)
    {
        printf("当前没有学生信息。\n");
        return;
    }

    printf("请输入要查询的学生姓名：");
    scanf("%s", searchName);



    for (i = 0; i < numStudents; i++)
    {
        if (strcmp(students[i].name, searchName) == 0)
        {
            printf("学生姓名：%s，高数：%d，C语言：%d，英语：%d\n", students[i].name, students[i].calculusScore, students[i].cLanguageScore, students[i].englishScore);
            found = 1;
        }
    }

    if (!found)
    {
        printf("未找到该学生。\n");
    }
}

int main()
{
    int choice;

    while (1)
    {
        printf("********** 学生管理系统 **********\n");
        printf("1. 录入学生信息\n");
        printf("2. 计算平均成绩\n");
        printf("3. 排序学生信息\n");
        printf("4. 输出所有学生信息\n"); // Modified option
        printf("5. 查询学生信息\n");
        printf("6. 退出\n"); // Updated option
        printf("*********************************\n");

        printf("请输入您的选择：");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            addStudent();
            break;
        case 2:
            printf("平均成绩为：%.2f\n", calculateAverageScore());
            break;
        case 3:
            sortStudents();
            break;
        case 4:
            printStudents(); // New option
            break;
        case 5:
            searchStudent();
            break;
        case 6:
            printf("感谢使用学生管理系统，再见！\n");
            exit(0);
        default:
            printf("无效的选择，请重新输入。\n");
            break;
        }

        printf("\n");
    }

    return 0;
}
