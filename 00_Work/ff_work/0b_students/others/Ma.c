/* Note:Your choice is C IDE */
#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>	/*I/O����*/
#include<stdlib.h>	/*����˵��*/
#include<string.h>	/*�ַ�������*/

#define LEN 15		/* ѧ�ź���������ַ���,ʵ�������*/
#define N 50		/* ���ѧ������,ʵ�������*/

int k = 1, n = 0, m = 0;/* n����ǰ��¼��ѧ������*/

//��������
void seek();
void modify();
void insert();
void del();
void menu();

//�ṹ�屣��ѧ����Ϣ
struct student{
	char StudentId[LEN+1];
	char StudentName[LEN+1];
	float score[3];
	float aver;
}stu[N];



void printStu(struct student stu[], int n)
{
	int i;
	printf("\n\n\n\n\nѧ��\t����\tC����\t\t�ߵ���ѧ\tӢ��ɼ�\n");
	for(i=0;i<n;i++)
	{
		printf("%s\t%s\t%.2f\t\t%.2f\t\t%.2f\n",stu[i].StudentId,stu[i].StudentName,stu[i].score[0],stu[i].score[1],stu[i].score[2]);
	}
}

//������
int main()
{
	while (k)
	{
		menu();
	}
	system("pause");
	return 0;
}
//����ѧ����Ϣ
void seek() /*����*/
{
	int i, item, flag;
	char s1[21]; /* ��������ѧ�������+1Ϊ׼*/
	printf("------------------\n");
	printf("-----1.��ѧ�Ų�ѯ-----\n");
	printf("-----2.��������ѯ-----\n");
	printf("-----3.�˳����˵�-----\n");
	printf("------------------\n");
	while (1)
	{
		printf("��ѡ���Ӳ˵����:");
		scanf("%d", &item);
		flag = 0;
		switch (item)
		{
		case 1:
			printf("������Ҫ��ѯ��ѧ����ѧ��:\n");
			scanf("%s", s1);
			for (i = 0; i<n; i++)
			if (strcmp(s1,stu[i].StudentId) == 0)
			{
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
			if (strcmp(stu[i].StudentName, s1) == 0)
			{
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

//�޸�ѧ����Ϣ
void modify() /*�޸���Ϣ*/
{
	int i, item, num = -1;
	char sex1, s1[LEN + 1], s2[LEN + 1]; /* ��������ѧ�������+1Ϊ׼*/
	float score1;
	printf("������ҪҪ�޸ĵ�ѧ����ѧ��:\n");
	scanf("%s", s1);
	for (i = 0; i < n; i++){
		if (strcmp(stu[i].StudentId, s1) == 0){/*�Ƚ��ַ����Ƿ����*/
			num = i;
			printf("------------------\n");
			printf("1.�޸�����\n");
			printf("2.�޸�C���Գɼ�\n");
			printf("3.�޸ĸߵ���ѧ�ɼ�\n");
			printf("4.�޸Ĵ�ѧӢ��ɼ�\n");
			printf("5.�˳����˵�\n");
			printf("------------------\n");
			while (1)
			{
				printf("��ѡ���Ӳ˵����:");
				scanf("%d", &item);
				switch (item)
				{
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
				case 5:	return;
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

void sort()//���ܷ�����
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

//���ѧ����Ϣ����
void insert() /*���뺯��*/
{
	int i = n, j, flag;
	printf("����������ӵ�ѧ����:\n");
	scanf("%d", &m);
	if (m > 0){
		do
		{
			flag = 1;
			while (flag)
			{
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
		} while (i<n + m);
	}
		n += m;
		printf("ѧ����Ϣ������ϣ�����\n");
		system("pause");
}

//ɾ��ѧ����Ϣ����
void del()
{
	int i, j, flag = 0;
	char s1[LEN + 1];
	printf("������Ҫɾ��ѧ����ѧ��:\n");
	scanf("%s", s1);
	for (i = 0; i < n; i++){
		if (strcpy(stu[i].StudentId, s1) == 0){
			flag = 1;
			//Ҫɾ��ѧ�������ѧ����ǰ��һλ
			for (j = i; j < n - 1; j++){
				stu[j] = stu[j + 1];
			}
		}
	}
		//����ʧ��
		if (0 == flag){
			printf("��ѧ�Ų�����!!!\n");
		}
		if (1 == flag){
			printf("ɾ���ɹ�������");
			//ɾ���ɹ���ѧ��������1
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
	
void menu()/* ����*/
{
	int num;
	printf(" \n\n                    \n\n");
	printf("  ******************************************************\n\n");
	printf("  *                ѧ����Ϣ����ϵͳ                    *\n \n");
	printf("  ******************************************************\n\n");
	printf("*********************ϵͳ���ܲ˵�*************************       \n");
	printf("     ----------------------   ----------------------   \n");
	printf("     ************************************r*********     \n");
	printf("     * 1.����ѧ����Ϣ    * *  2.�޸�ѧ����Ϣ     *     \n");
	printf("     *********************************************     \n");
	printf("     * 3.��ѯѧ����Ϣ    * *  4.��ѧ��ɾ����Ϣ   *     \n");
	printf("     *********************************************     \n");
	printf("     * 5.����ƽ����      * *  6.�˳�ϵͳ         *      \n");
	printf("     ********************** *********************     \n");
	printf("     * 7.   ��   ��      * *  8.��ʾ����         *     \n");
	printf("     ********************** **********************     \n");
	printf("     ----------------------   ----------------------                           \n");
	printf("��ѡ��˵����:");
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
		printf("�����˳�����!\n");
		break;
	case 7:
		sort();
		printStu( stu, n);
		break;
	case 8:
		printStu( stu, n);
		break;

	default:printf("����1-6֮��ѡ��\n");
	}
}
