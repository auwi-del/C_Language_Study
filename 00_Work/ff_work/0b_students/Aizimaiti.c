#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LEN 10

typedef struct student {
int id;
char name[MAX_NAME_LEN];
int score_c;
int score_e;
int score_m;
float avg_score;
struct student *next;
} Student;

Student *head = NULL;

void add_student() {
Student *new_student = (Student *)malloc(sizeof(Student));
printf("������ѧ����Ϣ��\n");
printf("ѧ�ţ�");
scanf("%d", &(new_student->id));
printf("������");
scanf("%s", new_student->name);
printf("C���Գɼ���");
scanf("%d", &(new_student->score_c));
printf("Ӣ��ɼ���");
scanf("%d", &(new_student->score_e));
printf("��ѧ�ɼ���");
scanf("%d", &(new_student->score_m));
new_student->avg_score = (new_student->score_c + new_student->score_e + new_student->score_m) / 3.0;
new_student->next = NULL;

if (head == NULL) {
    head = new_student;
} else {
    Student *p = head;
    while (p->next != NULL) {
        p = p->next;
    }
    p->next = new_student;
}
}

void print_students() {
printf("ѧ��\t����\tC����\tӢ��\t��ѧ\tƽ����\n");
Student *p = head;
while (p != NULL) {
printf("%d\t%s\t%d\t%d\t%d\t%.2f\n", p->id, p->name, p->score_c, p->score_e, p->score_m, p->avg_score);
p = p->next;
}
}

void sort_students() {
if (head == NULL) {
printf("����Ϊ�գ��޷�����\n");
return;
}

Student *p = head;
Student *q = NULL;
float tmp_score;
int tmp_id;
char tmp_name[MAX_NAME_LEN];
while (p != NULL) {
    q = p->next;
    while (q != NULL) {
        if (q->avg_score > p->avg_score) {
            tmp_score = p->avg_score;
            p->avg_score = q->avg_score;
            q->avg_score = tmp_score;

            tmp_id = p->id;
            p->id = q->id;
            q->id = tmp_id;

            strcpy(tmp_name, p->name);
            strcpy(p->name, q->name);
            strcpy(q->name, tmp_name);

            tmp_score = p->score_c;
            p->score_c = q->score_c;
            q->score_c = tmp_score;

            tmp_score = p->score_e;
            p->score_e = q->score_e;
            q->score_e = tmp_score;

            tmp_score = p->score_m;
            p->score_m = q->score_m;
            q->score_m = tmp_score;
        }
        q = q->next;
    }
    p = p->next;
}
}

int main() {
int choice;
while (1) {
printf("\n\n\n��ѡ�������\n");
printf(" 1. ����ѧ������\n");
printf(" 2. �鿴����ѧ������\n");
printf(" 3. ����\n");
printf(" 4. �˳�\n");
scanf("%d", &choice);
switch (choice) {
case 1:
add_student();
break;
case 2:
print_students();
break;
case 3:
sort_students();
break;
case 4:
exit(0);
default:
printf("��Ч��ѡ�����������롣\n");
}
}
return 0;
}