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
		printf("ѧ����ѧ�ţ�");
		scanf("%d",&id);
		for(i=0;i<n;i++)
			if(id==st[i].id)
			{
				printf("���������ѧ��\n");
			}
	{
	st[i].id=id;
	printf("ѧ����������");
	scanf("%s",&st[i].name);
	printf("ѧ���ĸ����ɼ���");
	scanf("%f",&st[i].score[1]);
	printf("ѧ����C���Գɼ���");
	scanf("%f",&st[i].score[2]);
	printf("ѧ����Ӣ��ɼ���");
	scanf("%f",&st[i].score[3]);
	n++;
	printf("��ѡ���Ƿ����(T/F)");
	scanf("\t%c",&quit);
	}
	while (quit !='F')
	{
		continue;			// ���������ڸ�ʲô
	}
}