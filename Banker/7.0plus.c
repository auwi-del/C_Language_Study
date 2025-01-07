#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <windows.h>
#include <string.h>
#include <time.h>

#define ROOT_PSWD "123456"				// �������Ա����

struct zh
{
	char name[30];
	char code[7];  
};



// ����ԭ��
int record2(char na[100],double d,double p,double m);
int delSomeOne( char na[30], struct zh* list );

/*
�������û�ע��ģ��
���û������޸�����
����Ա����ɾ���û�
*/
// ��������: ����Ա����
int rooter(struct zh* list)
{
	char choice[20];			// �洢����ָ��
	char na[30];				// �洢�û���
	int i,j,k;
	while(1)
	{
		printf("\n\n\n\n\t\t\t\t------------ [ R  O  O  T  ] ----------\n");
		printf("\t\t\t\t����������:\n");
		printf("\t\t\t\tdel : ɾ���û�\n");
		printf("\t\t\t\tlist: �鿴�û��б�\n");
		printf("\t\t\t\tmod : �޸��û����� (��δ���)\n");
		printf("\t\t\t\tquit: �˳�����Ա (���ڰ�ȫ�Կ���, ��ѡ���ر�ϵͳ)\n");

		scanf("%s",&choice);
		if(strcmp(choice,"del")==0)
		{
			printf("\t\t\t\t������Ҫɾ�����û���:\n");
			scanf("%s",&na);
			delSomeOne( na, list );
		}

		if(strcmp(choice,"list")==0)
		{
			for(i=0;i<10;i++)
			{
				if (list[i].name[0] == '\0')
				{
					break;
				}
				else
				{
					printf("%d : \t%-10s%s\n", i, list[i].name, list[i].code );
				}
			}
		}

		if(strcmp(choice,"quit")==0)
		{
			exit(0);
		}
	}
	// if(strcmp(choice,"mod")==0)
	// {
	// 	printf("\t\t\t\t������Ҫ�޸�������û���:");
	// 	scanf("%s",&na);
	// 	// modSomeOne(na);
	// }
	// return 0;
}

int delSomeOne( char na[30], struct zh* list )
{
	int i,j,k;
	int numOfSeekFileP = 0;					// �ļ�ָ��ƫ����
	FILE *fp;
	
	for(i=0;i<10;i++)
	{
		if(strcmp(na,list[i].name)==0)
		{
			numOfSeekFileP = i;
			break;
		}
	}

	if(i == 10)
	{
		printf("\t\t\t\tû�и��û���\n");
		return 0;
	}


	fp = fopen( "zh.txt", "w+" );			// �ļ�д��ģʽΪ ����
	if(fp==NULL)
	{
		printf("\t\t\t\t�޷��򿪸��ļ���\n");
		return 0;
	}

	for(i=numOfSeekFileP;i<10;i++)		// ɾ��ָ���û�
	{
		list[i] = list[i+1];
	}
	for(i=0;i<10;i++)				// ����д���ļ�
	{
		if( i == 9 || list[i].name[0] == '\0' )
		{
			break;
		}
		fprintf(fp,"%s %s\n",list[i].name,list[i].code);
	}
	fclose(fp);
}

// ���û�ע��ģ��
int my_register()
{
	int i,j,k;
	char name[30],code[30];
	FILE *fp;
	fp = fopen( "zh.txt", "a+" );			// �ļ�д��ģʽΪ ׷��
	if(fp==NULL)
	{
		printf("\t\t\t\t�޷��򿪸��ļ���\n");
		return 0;
	}
	printf("\t\t\t\t��������������:\n");
	scanf("%s",&name);
	printf("\t\t\t\t��������������:\n");
	scanf("%s",&code);
	fprintf(fp,"%s %s\n",name,code);
	fclose(fp);

	printf("\t\t\t\tע��ɹ��������µ�½ϵͳ! \n");
	return 0;

}

// ��ӡʱ��ĺ���
int B()
{
	int mon,year,day,hour,min,sec;
	time_t t;
	struct tm *m;				// ���� tm ���͵Ľṹ�壬��Ϊm��
	time( &t );
	m=localtime(&t);
	year=m->tm_year;
	mon=m->tm_mon;
	day=m->tm_mday;
	hour=m->tm_hour;
	min=m->tm_min;
	sec=m->tm_sec; 
	printf("\t\t\t\t%d��%d��%d��%dʱ%d��%d��\n",year+1900,mon+1,day,hour,min,sec);
}

int g( char* na )
{
 double m,r,d,p;
 int n;
//  char na[30];
  r=0.01;
  printf("                                     ϵͳ����:���� ����:2024��4�µ�����\n\n");
  printf("                                    ************************************\n\n");
  printf("                                     **********��ӭʹ�ô��ϵͳ**********\n");
 // printf("\t\t\t\t�����봢������:");
 // scanf("%s",&c);
  printf("\t\t\t\t�����������:");
  scanf("%lf",&d);
  printf("\t\t\t\t������׼��ÿ�»����Ϊ:");
  scanf("%lf",&p);
  m=(log(p)-log(p-d*r))/log(1+r);
  printf("\t\t\t\t%��������m=%.1lf:\n",m);
  printf("\n\t\t\t\t�Ƿ��¼��Ϣ(��¼1 ����¼0):");         
  	 scanf("%d",&n);
  	 {
		if(n==1)
  	 	record2(na,d,p,m);
  	 	else;
  	 }
}

//��������Ϣģ�� 1
int record1(char na[100],double m,char choice[20],double p)             
{
	FILE *cunkuan=fopen( "CunKuan Log.txt", "a+" );			// �ļ�д��ģʽΪ ׷��
	// ����ʱ�亯������ʱ��
	int mon,year,day,hour,min,sec;     
	time_t t;
	struct tm *x;
	time(&t);
	x=localtime(&t);
	year=x->tm_year;
	mon=x->tm_mon;
	day=x->tm_mday;
	hour=x->tm_hour;
	min=x->tm_min;
	sec=x->tm_sec;
	if(cunkuan==NULL)
	{
		printf("\t\t\t\t�޷��򿪸��ļ���\n");
		return 0;
	}
	fprintf(cunkuan,"�����:%s\n�����:%.2lfԪ\n��ʽ:%s\n��Ϣ��:%.2lfԪ\n\n", na, m, choice, p );
	fprintf(cunkuan,"%d��%d��%d��%dʱ%d��%d��\n",year+1900,mon+1,day,hour,min,sec);
	fclose(cunkuan);
	return 0;
}


//���������Ϣģ�� 
int record2(char na[100],double d,double p,double m)             
{
	FILE *daikuan=fopen("DaiKuan Log.txt","a+");
	int mon,year,day,hour,min,sec;
	time_t t;
	struct tm *x;
	time(&t);
	x=localtime(&t);
	year=x->tm_year;
	mon=x->tm_mon;
	day=x->tm_mday;
	hour=x->tm_hour;
	min=x->tm_min;
	sec=x->tm_sec;
	if(daikuan==NULL)
	{
		printf("\t\t\t\t�޷��򿪸��ļ���\n");
		return 0;
	}
	fprintf(daikuan,"������:%s\n������:%.2lfԪ\nÿ�»�����:%.2lfԪ\n������������:%.1lf��\n\n",na,d,p,m);
	fprintf(daikuan,"%d��%d��%d��%dʱ%d��%d��\n",year+1900,mon+1,day,hour,min,sec);
	fclose(daikuan);
	return 0;
}

// f() �����ڼ������ʵĹ��ܺ���
int f( char * na )
{
	double p,m,r5=0.03,r2=0.021,r3=0.0275,r1=0.015,rh=0.0035;
	int choice,k;
	char choice1[20]="������ ",choice2[20]="������+����",choice3[20]="������+����",choice4[20]="����������",choice5[20]="�����";
	system("cls");
	printf("\n\n");
	printf("                                     ϵͳ����:���� ����:2024��4�µ�����\n\n");
	printf("                                     ***********************************\n\n");
	printf("                                     **********��ӭʹ�ô��ϵͳ**********\n");
	printf("                                     *******  1   ������          *******\n");
	printf("                                     *******  2   ������+����     *******\n");
	printf("                                     *******  3   ������+����     *******\n");
	printf("                                     *******  4   ����������      *******\n");
	printf("                                     *******  5   �����          *******\n");
	printf("                                     ************************************\n");
	//printf("\t\t\t\t�����봢������:");
	//scanf("%s",&c);
	printf("\t\t\t\t���������ѡ��1~5:");
	scanf("%d",&choice);

	printf("\t\t\t\t�����뱾��: ");
	scanf("%lf",&m);
	if(m>10000)
	{
		switch(choice)
		{
			case 1:
			p=m+m*5*r5;
			break;
			
			case 2:
			p=m+m*2*r2;
			p=p+p*3*r3;
			break;
			
			case 3:
			p=m+m*3*r3;
			p=p+p*2*r2;
			break;

			case 4:
			p=m+m*1*r1;
			p=p+p*1*r1;
			p=p+p*1*r1;
			p=p+p*1*r1;
			p=p+p*1*r1;
			break;

			case 5:
			p=m+(m*rh/4)*(m*rh/4);
			break;
		}
		printf( "\t\t\t\t������: %s,��Ϣ��Ϊ%.2fԪ\n" ,na , p );
	}

	else if(m<=0)
	{ 
		printf("\t\t\t\t����,��������ȷ���\n");
	}

	else
	{
		p=m+(m*rh/4)*(m*rh/4);
		printf("\t\t\t\t��������10000Ԫ��ֻ�ɻ��ڴ��\n");
		printf("\t\t\t\t������: %s,��Ϣ��Ϊ%.2fԪ\n",na,p);
	}

		// ��ӡʱ��
		B();

		printf("\n\t\t\t\t�Ƿ��¼��Ϣ(��¼1 ����¼0):");         
		scanf("%d",&k);
		if(k==1)
		{
			// ���õĶ��� record1 ����
			if(choice==1)
				record1(na,m,choice1,p);
			if(choice==2)
				record1(na,m,choice2,p);
			if(choice==3)
				record1(na,m,choice3,p);
			if(choice==4)
				record1(na,m,choice4,p);
			if(choice==5)
				record1(na,m,choice5,p);     
		}
		else; 
}

void main()
{
	int wrongPassWordTime = 0;			// ���ڼ�¼�û������������Ĵ���
	int exitOrNot = 0;					// ��ֵΪ 1 ʱ, ������˳�
	int choice,h=2;//hΪ��Ϣ
	// ���� ���� l[10], �洢 10 ���˵��˺�
	struct zh l[10];
	int i, j, k;

	char na[30];
	char co[30];
	int y=0,v=0;
	FILE*fp;

	// �ⲿ�ִ���� zh.txt �ж�ȡ�˺���Ϣ��
	//ԭ����fp = fopen("d:\\zh.txt","r");
	fp = fopen( "zh.txt", "r" );			// ����д����·����ʱ�� Ĭ����Ϊ�ǵ�ǰ·���µ��ļ�
	while( ( fscanf( fp, "%s %s" , l[y].name, l[y].code ) ) !=EOF )
	{
		printf("%-10s%s\n",l[y].name,l[y].code);		// �����ȡ���� ��ӡ����
		y++;
	}
	fclose(fp);

	// ��ȡ�û������û�����ѭ��
	while(1)
	{
		printf("\t\t\t\t���������� (���� reg ����ע��) :\n");
		// ԭ����scanf("%s",na);
		scanf("%s",&na);					// ӦΪ &na��ò��˭�Ĵ�����������ʲô���ֶ�����ʾ�Ϸ��û�����������û���������Ϊ�Ӽ��̶�ȡ�����û�������û��д�� na ��

		// ��ʼ����Ա��û���
		for(y=0;y<10;y++)
		{
			if(strcmp(na,l[y].name)==0)
				break;						// ����ĸ��û������ˣ�ֹͣ�Աȡ�����ѭ����
		}

		if(strcmp(na, "reg")==0)					// ������� reg �� �����ע��
		{
			my_register();
			system("pause");
			exit(0);							// �˳�
		}

		if(y<10)							// y<10 ˵���û����û��б���
		{
			printf("\t\t\t\t���û����ڣ���Ϊ�Ϸ��û�\n");
			// ԭ���Ĵ���˴�ȱ��������ѭ����
			// ��ʹ�û���������ȷ���û�������ʼ���������ˣ�Ҳ�ᱻ�˳���
			// �ʴ˴�Ӧ����break;
			break;
		}

		else								// ������ζ�ţ���ȫ�������û��б� l[10] ,Ҳû���ҵ����û���
		{
			printf("\t\t\t\t�����ǺϷ��û�\n");
			exit(0);						// û������ˣ� ���˳��ˡ�
		}
	}


	// ��ȡ�û����������ѭ��
	while(1)
	{
		printf("\t\t\t\t����������:\n");
		// ԭ����scanf("%s",co);
		scanf("%s",&co);						// &��ȡ���ַ����˼�� &co�� �ǰ� co ���ڴ��еĵ�ַȡ������ ����scanf�ð����ݷ��������ַ��ͷ

		// ���ж������㷨���ƣ� ��ʼ�ж������Ƿ���ȷ
		for(v=0;v<7;v++)
		{
			if(strcmp(co,l[y].code)==0)
				break;
		}
		if(v<7)
		{
			printf("\t\t\t\t��ӭʹ�ñ�ϵͳ\n");
			break;
		}
		else
		{
			printf( "\t\t\t\t�������!�����ǺϷ��û�\n" );
			wrongPassWordTime++;					// ��¼�������
			if(wrongPassWordTime>=3)				// �������������ڵ���3��
			{
			    printf( "\t\t\t\t�������������࣬ϵͳ���Զ��˳�\n" );
				system("pause");
				exit(0);						// �˳�
			}
			{
				printf( "\t\t\t\t����������: %d\n\n", wrongPassWordTime );
				continue;						// ����ѭ���� ��������������
			}
		}
	}
	
	// ���û�ѡ���ܵ�ѭ��
	while(2)
	{
		printf("\n\n");
		printf("\t\t\t\t| ���������Ĳ���\n\n");
		printf("\t\t\t\t| 2 : ��Ϣ����     \n");
		printf("\t\t\t\t| 3 : �������     \n");
		printf("\t\t\t\t| 4 : �޸ı��˻�����  \n");
		printf("\t\t\t\t| 5 : ����Ա�˻���½ (123456)     \n");

		scanf("%d",&h);
		// �û�ѡ��2 ��Ϣ����
		if(h==2)
		{
			// ��������
			f( na );
			printf("\t\t\t\t������������1���� 0�˳�: ");
			scanf("%d",&choice);
			if(choice==1)
			{
				f( na );
			}

			if(choice==0)
			{
				printf("\t\t\t\t******��лʹ��******"); 
				exit(0);
			}
		}

		// �û�ѡ��3 �������
		if(h==3)
		{
			{
				g( na );
				B();
			}
			printf("\t\t\t\t������������1����0�˳�:");
			scanf("%d",&choice);
			if(choice==1)
			{
				g( na );
			}
			if(choice==0)
			{
				printf("\t\t\t\t******��лʹ��******"); 
				exit(0);
			}
		}

		// �û�ѡ��4 �޸ı��˻�����n
		if(h==4)
		{
			printf("\t\t\t\t����������������:\n");
			printf("\t\t\t\t(����Ϊ�ɼ�, ���Խ�������һ��)\n");
			scanf("%s",&co);
			strcpy(l[y].code,co);			// ��������д�� l[y].code
			fopen("zh.txt","w");			// ���ԭ�ļ�
			for(i=0;i<10;i++)				// ����д���ļ�
			{
				if( i == 1 || l[i].name[0] == '\0' )
				{
					break;
				}
				fprintf(fp,"%s %s\n",l[i].name,l[i].code);
			}
			fclose(fp);


			printf("\t\t\t\t�����޸ĳɹ�\n");
		}



		// �û�ѡ��5 ����Ա��½
		if(h==5)
		{
			wrongPassWordTime = 0;
			while(1)
			{
				printf("\t\t\t\t���������Ա����:\n");
				scanf("%s",&co);
				if(strcmp(co,ROOT_PSWD)==0)
				{
					printf("\t\t\t\t����Ա��½�ɹ�\n");
					break;						// ��½�ɹ�����ѭ��
				}
				else
				{
					printf("\t\t\t\t�������,����������\n");
					wrongPassWordTime++;
					if(wrongPassWordTime>=3)
					{
					    printf("\t\t\t\t�������������࣬ϵͳ���Զ��˳�\n");
						system("pause");
						exit(0);
					}
				}
			}
			// ����Ա��½�ɹ��� ��ʼ���в���
			rooter(&l);
		}
	}
}