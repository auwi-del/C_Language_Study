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
        printf("ѧ�������Ѵﵽ���ޣ��޷�����µ�ѧ����\n");
        return;
    }

    printf("������ѧ��������");
    scanf("%s", students[numStudents].name);

    printf("���������������");
    scanf("%d", &students[numStudents].calculusScore);

    printf("������C���Է�����");
    scanf("%d", &students[numStudents].cLanguageScore);

    printf("������Ӣ�������");
    scanf("%d", &students[numStudents].englishScore);

    numStudents++;

    printf("ѧ����Ϣ��¼�롣\n");
}

// ����ƽ����
float calculateAverageScore()
{
    int totalScore = 0;
    int i;

    if ( numStudents == 0 )
    {
        printf("��ǰû��ѧ����Ϣ��\n");
        return 0.0;
    }

    for (i = 0; i < numStudents; i++)
    {
        totalScore += students[i].calculusScore + students[i].cLanguageScore + students[i].englishScore;
    }

    return (float)totalScore / (numStudents * 3);

    
}

// ��������ָ��, ���� a���ܷ� - b���ܷ�
int compareStudents( const void *a, const void *b )
{
    // �Դ������� ָ�� ���п���
    Student *studentA = (Student *)a;
    Student *studentB = (Student *)b;

    // �����ܷ�
    int totalScoreA = studentA->calculusScore + studentA->cLanguageScore + studentA->englishScore;
    int totalScoreB = studentB->calculusScore + studentB->cLanguageScore + studentB->englishScore;

    return totalScoreA - totalScoreB;
}

void sortStudents()
{
    if (numStudents == 0)
    {
        printf("��ǰû��ѧ����Ϣ��\n");
        return;
    }

    qsort(students, numStudents, sizeof(Student), compareStudents);

    printf("ѧ����Ϣ������\n");
}

void printStudents()
{
	int i;
    if (numStudents == 0)
    {
        printf("��ǰû��ѧ����Ϣ��\n");
        return;
    }

    printf("����ѧ����Ϣ��\n");
    for (i = 0; i < numStudents; i++)
    {
        printf("ѧ��������%s��������%d��C���ԣ�%d��Ӣ�%d\n", students[i].name, students[i].calculusScore, students[i].cLanguageScore, students[i].englishScore);
    }
}

void searchStudent()
{
    char searchName[MAX_NAME_LENGTH];
    int found = 0;
    int i;
    if (numStudents == 0)
    {
        printf("��ǰû��ѧ����Ϣ��\n");
        return;
    }

    printf("������Ҫ��ѯ��ѧ��������");
    scanf("%s", searchName);



    for (i = 0; i < numStudents; i++)
    {
        if (strcmp(students[i].name, searchName) == 0)
        {
            printf("ѧ��������%s��������%d��C���ԣ�%d��Ӣ�%d\n", students[i].name, students[i].calculusScore, students[i].cLanguageScore, students[i].englishScore);
            found = 1;
        }
    }

    if (!found)
    {
        printf("δ�ҵ���ѧ����\n");
    }
}

int main()
{
    int choice;

    while (1)
    {
        printf("********** ѧ������ϵͳ **********\n");
        printf("1. ¼��ѧ����Ϣ\n");
        printf("2. ����ƽ���ɼ�\n");
        printf("3. ����ѧ����Ϣ\n");
        printf("4. �������ѧ����Ϣ\n"); // Modified option
        printf("5. ��ѯѧ����Ϣ\n");
        printf("6. �˳�\n"); // Updated option
        printf("*********************************\n");

        printf("����������ѡ��");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            addStudent();
            break;
        case 2:
            printf("ƽ���ɼ�Ϊ��%.2f\n", calculateAverageScore());
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
            printf("��лʹ��ѧ������ϵͳ���ټ���\n");
            exit(0);
        default:
            printf("��Ч��ѡ�����������롣\n");
            break;
        }

        printf("\n");
    }

    return 0;
}
