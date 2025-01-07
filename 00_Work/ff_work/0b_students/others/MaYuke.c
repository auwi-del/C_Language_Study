
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
    printf("-----1.��ѧ�Ų�ѯ-----\n");
    printf("-----2.��������ѯ-----\n");
    printf("-----3.�˳����˵�-----\n");
    printf("------------------\n");
    while (1){
        printf("��ѡ���Ӳ˵����:");
        scanf("%d", &item);
        flag = 0;
        switch (item){
            case 1:
                printf("������Ҫ��ѯ��ѧ����ѧ��:\n");
                scanf("%s", s1);
                for (i = 0; i<n; i++)
                    if (strcmp(s1,stu[i].StudentId) == 0){
                        flag = 1;
                        printf("ѧ��ѧ��\tѧ������\tC���Գɼ�\t�ߵ���ѧ\t��ѧӢ��ɼ�\n");
                        printf("--------------------------------------------------------------------\n");
                        printf("%s\t%s\t%.1f\t%.1f\t%.1f\n", stu[i].StudentId,stu[i].StudentName,stu[i].score[0],stu[i].score[1],stu[i].score[2]);
                    }
                if (0 == flag)
                    printf("��ѧ�Ų����ڣ�\n"); break;
            case 2:
                printf("������Ҫ��ѯ��ѧ��������:\n");
                scanf("%s", s1);
                for (i = 0; i<n; i++)
                    if (strcmp(stu[i].StudentName, s1) == 0){
                        flag = 1;
                        printf("ѧ��ѧ��\tѧ������\tC���Գɼ�\t�ߵ���ѧ\t��ѧӢ��ɼ�\n");
                        printf("--------------------------------------------------------------------\n");
                        printf("%s\t%s\t%.1f\t%.1f\t%.1f\n", stu[i].StudentId, stu[i].StudentName, stu[i].score[0], stu[i].score[1], stu[i].score[2]);
                    }
                if (0 == flag)
                    printf("�����������ڣ�\n"); break;
            case 3:return;
            default:printf("����1-3֮��ѡ��\n");
        }
    }
}

void modify(){
    int i, item, num = -1;
    char sex1, s1[LEN + 1], s2[LEN + 1];
    float score1;
    printf("������ҪҪ�޸ĵ�ѧ����ѧ��:\n");
    scanf("%s", s1);
    for (i = 0; i < n; i++){
        if (strcmp(stu[i].StudentId, s1) == 0){
            num = i;
            printf("------------------\n");
            printf("1.�޸�����\n");
            printf("2.�޸�C���Գɼ�\n");
            printf("3.�޸ĸߵ���ѧ�ɼ�\n");
            printf("4.�޸Ĵ�ѧӢ��ɼ�\n");
            printf("5.�˳����˵�\n");
            printf("------------------\n");
            while (1){
                printf("��ѡ���Ӳ˵����:");
                scanf("%d", &item);
                switch (item){
                    case 1:
                        printf("�������µ�����:\n");
                        scanf("%s", s2);
                        strcpy(stu[num].StudentName, s2);
                        break;
                    case 2:
                        printf("�������µ�C���Գɼ�:\n");
                        scanf("%f", &score1);
                        stu[num].score[0] = score1;
                        break;
                    case 3:
                        printf("�������µĸߵ���ѧ�ɼ�:\n");
                        scanf("%f", &score1);
                        stu[num].score[1] = score1;
                        break;
                    case 4:
                        printf("�������µĴ�ѧӢ��ɼ�:\n");
                        scanf("%f", &score1);
                        stu[num].score[2] = score1;
                        break;
                    case 5: return;
                    default:printf("����1-5֮��ѡ��\n");
                }
            }
            printf("�޸���ϣ��뼰ʱ���棡\n");
        }
        else{
            printf("û�и�ѧ��ѧ��!!!");
        }
    }
}

void sort(){ // ����һ����Ϊsort�ĺ������޷���ֵ�Ͳ���
int i, j, k; // �����������ͱ���i��j��k������ѭ������
char temp[LEN + 1], ctemp; // ����һ���ַ�����temp��һ���ַ�����ctemp�����ڽ���ѧ����Ϣ
float ftemp; // ����һ�������ͱ���ftemp�����ڽ���ѧ���ɼ�
for (i = 0; i<n - 1; i++){ // ���ѭ�����ӵ�һ��ѧ����ʼ��ѭ���������ڶ���ѧ��
	for (j = n - 1; j>i; j--) // �ڲ�ѭ���������һ��ѧ����ʼ��ѭ������ǰ���ѭ����ѧ��
		if (strcmp(stu[j - 1].StudentId, stu[j].StudentId)>0)
		{ // ���ǰһ��ѧ����ID���ں�һ��ѧ����ID
			strcpy(temp, stu[j - 1].StudentId); // ����ѧ��ID
			strcpy(stu[j - 1].StudentId, stu[j].StudentId);
			strcpy(stu[j].StudentId, temp);
			strcpy(temp, stu[j - 1].StudentName); // ����ѧ������
			strcpy(stu[j - 1].StudentName, stu[j].StudentName);
			strcpy(stu[j].StudentName, temp);
			for (k = 0; k<3; k++)
			{ 	// ѭ������ѧ���ɼ�
				ftemp = stu[j - 1].score[k];
				stu[j - 1].score[k] = stu[j].score[k];
				stu[j].score[k] = ftemp;
			}
		}
	}
}

void insert(){
    int i = n, j, flag;
    printf("����������ӵ�ѧ����:\n");
    scanf("%d", &m);
    if (m > 0){
        do{
            flag = 1;
            while (flag){
                flag = 0;
                printf("�������%dλѧ����ѧ��:\n", i + 1);
                scanf("%s", stu[i].StudentId);
                for (j = 0; j < i; j++){
                    if (strcmp(stu[i].StudentId, stu[j].StudentId) == 0){
                        printf("��ѧ���Ѵ��ڣ����������룡\n");
                        flag = 1;
                        break;
                    }
                }
            }
            printf("�������%d ��ѧ��������:\n", i+1);
            scanf("%s", stu[i].StudentName);
            printf("�������%d ��ѧ����C���Գɼ�\n",i+1);
            scanf("%f", &stu[i].score[0]);
            printf("�������%d ��ѧ���ĸߵ���ѧ�ɼ�:\n", i+1);
            scanf("%f", &stu[i].score[1]);
            printf("�������%d ��ѧ���Ĵ�ѧӢ��ɼ�:\n", i+1);
            scanf("%f", &stu[i].score[2]);
            if (0 == flag){
                i++;
            }
        }
	}wile()
}