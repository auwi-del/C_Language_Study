#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <windows.h>
#include <string.h>
#include <time.h>

#define ROOT_PSWD "123456"				// 定义管理员密码

struct zh
{
	char name[30];
	char code[7];  
};



// 函数原型
int record2(char na[100],double d,double p,double m);
int delSomeOne( char na[30], struct zh* list );

/*
增加新用户注册模块
老用户可以修改密码
管理员可以删除用户
*/
// 新增功能: 管理员功能
int rooter(struct zh* list)
{
	char choice[20];			// 存储输入指令
	char na[30];				// 存储用户名
	int i,j,k;
	while(1)
	{
		printf("\n\n\n\n\t\t\t\t------------ [ R  O  O  T  ] ----------\n");
		printf("\t\t\t\t请输入命令:\n");
		printf("\t\t\t\tdel : 删除用户\n");
		printf("\t\t\t\tlist: 查看用户列表\n");
		printf("\t\t\t\tmod : 修改用户密码 (暂未完成)\n");
		printf("\t\t\t\tquit: 退出管理员 (出于安全性考虑, 此选项会关闭系统)\n");

		scanf("%s",&choice);
		if(strcmp(choice,"del")==0)
		{
			printf("\t\t\t\t请输入要删除的用户名:\n");
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
	// 	printf("\t\t\t\t请输入要修改密码的用户名:");
	// 	scanf("%s",&na);
	// 	// modSomeOne(na);
	// }
	// return 0;
}

int delSomeOne( char na[30], struct zh* list )
{
	int i,j,k;
	int numOfSeekFileP = 0;					// 文件指针偏移量
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
		printf("\t\t\t\t没有该用户！\n");
		return 0;
	}


	fp = fopen( "zh.txt", "w+" );			// 文件写入模式为 覆盖
	if(fp==NULL)
	{
		printf("\t\t\t\t无法打开该文件！\n");
		return 0;
	}

	for(i=numOfSeekFileP;i<10;i++)		// 删除指定用户
	{
		list[i] = list[i+1];
	}
	for(i=0;i<10;i++)				// 重新写入文件
	{
		if( i == 9 || list[i].name[0] == '\0' )
		{
			break;
		}
		fprintf(fp,"%s %s\n",list[i].name,list[i].code);
	}
	fclose(fp);
}

// 新用户注册模块
int my_register()
{
	int i,j,k;
	char name[30],code[30];
	FILE *fp;
	fp = fopen( "zh.txt", "a+" );			// 文件写入模式为 追加
	if(fp==NULL)
	{
		printf("\t\t\t\t无法打开该文件！\n");
		return 0;
	}
	printf("\t\t\t\t请输入您的姓名:\n");
	scanf("%s",&name);
	printf("\t\t\t\t请输入您的密码:\n");
	scanf("%s",&code);
	fprintf(fp,"%s %s\n",name,code);
	fclose(fp);

	printf("\t\t\t\t注册成功！请重新登陆系统! \n");
	return 0;

}

// 打印时间的函数
int B()
{
	int mon,year,day,hour,min,sec;
	time_t t;
	struct tm *m;				// 声明 tm 类型的结构体，名为m。
	time( &t );
	m=localtime(&t);
	year=m->tm_year;
	mon=m->tm_mon;
	day=m->tm_mday;
	hour=m->tm_hour;
	min=m->tm_min;
	sec=m->tm_sec; 
	printf("\t\t\t\t%d年%d月%d日%d时%d分%d秒\n",year+1900,mon+1,day,hour,min,sec);
}

int g( char* na )
{
 double m,r,d,p;
 int n;
//  char na[30];
  r=0.01;
  printf("                                     系统开发:王涵 日期:2024年4月第六版\n\n");
  printf("                                    ************************************\n\n");
  printf("                                     **********欢迎使用存款系统**********\n");
 // printf("\t\t\t\t请输入储户姓名:");
 // scanf("%s",&c);
  printf("\t\t\t\t请输入贷款金额:");
  scanf("%lf",&d);
  printf("\t\t\t\t请输入准备每月还款额为:");
  scanf("%lf",&p);
  m=(log(p)-log(p-d*r))/log(1+r);
  printf("\t\t\t\t%还清月数m=%.1lf:\n",m);
  printf("\n\t\t\t\t是否记录信息(记录1 不记录0):");         
  	 scanf("%d",&n);
  	 {
		if(n==1)
  	 	record2(na,d,p,m);
  	 	else;
  	 }
}

//存入存款信息模块 1
int record1(char na[100],double m,char choice[20],double p)             
{
	FILE *cunkuan=fopen( "CunKuan Log.txt", "a+" );			// 文件写入模式为 追加
	// 利用时间函数计算时间
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
		printf("\t\t\t\t无法打开该文件！\n");
		return 0;
	}
	fprintf(cunkuan,"存款人:%s\n存款金额:%.2lf元\n存款方式:%s\n本息和:%.2lf元\n\n", na, m, choice, p );
	fprintf(cunkuan,"%d年%d月%d日%d时%d分%d秒\n",year+1900,mon+1,day,hour,min,sec);
	fclose(cunkuan);
	return 0;
}


//存入贷款信息模块 
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
		printf("\t\t\t\t无法打开该文件！\n");
		return 0;
	}
	fprintf(daikuan,"贷款人:%s\n贷款金额:%.2lf元\n每月还款金额:%.2lf元\n还清所需月数:%.1lf月\n\n",na,d,p,m);
	fprintf(daikuan,"%d年%d月%d日%d时%d分%d秒\n",year+1900,mon+1,day,hour,min,sec);
	fclose(daikuan);
	return 0;
}

// f() 是用于计算利率的功能函数
int f( char * na )
{
	double p,m,r5=0.03,r2=0.021,r3=0.0275,r1=0.015,rh=0.0035;
	int choice,k;
	char choice1[20]="存五年 ",choice2[20]="存两年+三年",choice3[20]="存三年+两年",choice4[20]="连续存五年",choice5[20]="存活期";
	system("cls");
	printf("\n\n");
	printf("                                     系统开发:王涵 日期:2024年4月第六版\n\n");
	printf("                                     ***********************************\n\n");
	printf("                                     **********欢迎使用存款系统**********\n");
	printf("                                     *******  1   存五年          *******\n");
	printf("                                     *******  2   存两年+三年     *******\n");
	printf("                                     *******  3   存三年+两年     *******\n");
	printf("                                     *******  4   连续存五年      *******\n");
	printf("                                     *******  5   存活期          *******\n");
	printf("                                     ************************************\n");
	//printf("\t\t\t\t请输入储户姓名:");
	//scanf("%s",&c);
	printf("\t\t\t\t请输入你的选择1~5:");
	scanf("%d",&choice);

	printf("\t\t\t\t请输入本金: ");
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
		printf( "\t\t\t\t储户是: %s,本息和为%.2f元\n" ,na , p );
	}

	else if(m<=0)
	{ 
		printf("\t\t\t\t错误,请输入正确金额\n");
	}

	else
	{
		p=m+(m*rh/4)*(m*rh/4);
		printf("\t\t\t\t存款金额低于10000元，只可活期存款\n");
		printf("\t\t\t\t储户是: %s,本息和为%.2f元\n",na,p);
	}

		// 打印时间
		B();

		printf("\n\t\t\t\t是否记录信息(记录1 不记录0):");         
		scanf("%d",&k);
		if(k==1)
		{
			// 调用的都是 record1 函数
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
	int wrongPassWordTime = 0;			// 用于记录用户输入错误密码的次数
	int exitOrNot = 0;					// 此值为 1 时, 程序会退出
	int choice,h=2;//h为利息
	// 创建 数组 l[10], 存储 10 个人的账号
	struct zh l[10];
	int i, j, k;

	char na[30];
	char co[30];
	int y=0,v=0;
	FILE*fp;

	// 这部分代码从 zh.txt 中读取账号信息。
	//原来：fp = fopen("d:\\zh.txt","r");
	fp = fopen( "zh.txt", "r" );			// 当不写完整路径的时候， 默认认为是当前路径下的文件
	while( ( fscanf( fp, "%s %s" , l[y].name, l[y].code ) ) !=EOF )
	{
		printf("%-10s%s\n",l[y].name,l[y].code);		// 如果读取到， 打印出来
		y++;
	}
	fclose(fp);

	// 读取用户输入用户名的循环
	while(1)
	{
		printf("\t\t\t\t请输入姓名 (输入 reg 进行注册) :\n");
		// 原来：scanf("%s",na);
		scanf("%s",&na);					// 应为 &na，貌似谁的代码无论输入什么名字都会显示合法用户，就是这里没搞清楚。因为从键盘读取到的用户名根本没有写入 na 。

		// 开始逐个对比用户名
		for(y=0;y<10;y++)
		{
			if(strcmp(na,l[y].name)==0)
				break;						// 如果哪个用户名对了，停止对比。跳出循环。
		}

		if(strcmp(na, "reg")==0)					// 如果输入 reg ， 则进行注册
		{
			my_register();
			system("pause");
			exit(0);							// 退出
		}

		if(y<10)							// y<10 说明用户在用户列表内
		{
			printf("\t\t\t\t该用户存在，您为合法用户\n");
			// 原来的代码此处缺少跳出的循环：
			// 即使用户输入了正确的用户名，开始输入密码了，也会被退出。
			// 故此处应加入break;
			break;
		}

		else								// 否则意味着：完全遍历了用户列表 l[10] ,也没有找到该用户。
		{
			printf("\t\t\t\t您不是合法用户\n");
			exit(0);						// 没有这个人， 就退出了。
		}
	}


	// 读取用户输入密码的循环
	while(1)
	{
		printf("\t\t\t\t请输入密码:\n");
		// 原来：scanf("%s",co);
		scanf("%s",&co);						// &是取其地址的意思， &co， 是把 co 在内存中的地址取出来， 告诉scanf该把数据放在这个地址里头

		// 与判断名字算法类似， 开始判断密码是否正确
		for(v=0;v<7;v++)
		{
			if(strcmp(co,l[y].code)==0)
				break;
		}
		if(v<7)
		{
			printf("\t\t\t\t欢迎使用本系统\n");
			break;
		}
		else
		{
			printf( "\t\t\t\t密码错误!您不是合法用户\n" );
			wrongPassWordTime++;					// 记录错误次数
			if(wrongPassWordTime>=3)				// 如果错误次数大于等于3次
			{
			    printf( "\t\t\t\t密码错误次数过多，系统将自动退出\n" );
				system("pause");
				exit(0);						// 退出
			}
			{
				printf( "\t\t\t\t密码错误次数: %d\n\n", wrongPassWordTime );
				continue;						// 继续循环， 即重新输入密码
			}
		}
	}
	
	// 让用户选择功能的循环
	while(2)
	{
		printf("\n\n");
		printf("\t\t\t\t| 请输入您的操作\n\n");
		printf("\t\t\t\t| 2 : 利息计算     \n");
		printf("\t\t\t\t| 3 : 贷款计算     \n");
		printf("\t\t\t\t| 4 : 修改本账户密码  \n");
		printf("\t\t\t\t| 5 : 管理员账户登陆 (123456)     \n");

		scanf("%d",&h);
		// 用户选择2 利息计算
		if(h==2)
		{
			// 计算利率
			f( na );
			printf("\t\t\t\t请输入您操作1继续 0退出: ");
			scanf("%d",&choice);
			if(choice==1)
			{
				f( na );
			}

			if(choice==0)
			{
				printf("\t\t\t\t******感谢使用******"); 
				exit(0);
			}
		}

		// 用户选择3 贷款计算
		if(h==3)
		{
			{
				g( na );
				B();
			}
			printf("\t\t\t\t请输入您操作1继续0退出:");
			scanf("%d",&choice);
			if(choice==1)
			{
				g( na );
			}
			if(choice==0)
			{
				printf("\t\t\t\t******感谢使用******"); 
				exit(0);
			}
		}

		// 用户选择4 修改本账户密码n
		if(h==4)
		{
			printf("\t\t\t\t请输入您的新密码:\n");
			printf("\t\t\t\t(密码为可见, 所以仅需输入一次)\n");
			scanf("%s",&co);
			strcpy(l[y].code,co);			// 把新密码写入 l[y].code
			fopen("zh.txt","w");			// 清除原文件
			for(i=0;i<10;i++)				// 重新写入文件
			{
				if( i == 1 || l[i].name[0] == '\0' )
				{
					break;
				}
				fprintf(fp,"%s %s\n",l[i].name,l[i].code);
			}
			fclose(fp);


			printf("\t\t\t\t密码修改成功\n");
		}



		// 用户选择5 管理员登陆
		if(h==5)
		{
			wrongPassWordTime = 0;
			while(1)
			{
				printf("\t\t\t\t请输入管理员密码:\n");
				scanf("%s",&co);
				if(strcmp(co,ROOT_PSWD)==0)
				{
					printf("\t\t\t\t管理员登陆成功\n");
					break;						// 登陆成功跳出循环
				}
				else
				{
					printf("\t\t\t\t密码错误,请重新输入\n");
					wrongPassWordTime++;
					if(wrongPassWordTime>=3)
					{
					    printf("\t\t\t\t密码错误次数过多，系统将自动退出\n");
						system("pause");
						exit(0);
					}
				}
			}
			// 管理员登陆成功后， 开始进行操作
			rooter(&l);
		}
	}
}