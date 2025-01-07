/* Note:Your choice is C IDE */
/*9.18日作业参考代码，在9.11作业基础上；删除顺序表中任意位置的元素，或者保留的元素e或者不保留e*/
#include "stdio.h"
#define MAXSIZE 50

typedef struct{
	char data[MAXSIZE];	
	int length;
}SqList;
/*初始化顺序表*/
/*int initList(SqList *L){
	L->length=0;
	 return 0;
}*/
/*循环输入元素，建立顺序表,元素输入直到-1结束*/
void CreateList(SqList *L){
	int i,e;
	L->length=0;
	printf("请输入顺序表元素：");
	for(i=0;i<MAXSIZE;i++){
		  scanf("%d",&e);
		  if(e==-1)
		  	break;
		  L->data[i]=e;
		  L->length++;
   }
}

/*打印顺序表*/
void printfList(SqList *L){
	int i;
	printf("顺序表的长度为：%d\n",L->length);
	if(L->length==0){
		printf("这是空表，没有元素");
        return;
	}
	for(i=0;i<L->length;i++)
		printf("\n顺序表的第%d个元素为：%d",(i+1),L->data[i]);
	printf("\n");
}

/*在任意位置插入顺序表元素*/
int insertList (SqList *L,int i,int e){
	int j=0;
	if(i<1||i>L->length+1||L->length>=MAXSIZE)
		return 0;
	for(j=L->length;j>=i;j--)
	   L->data[j]=L->data[j-1];
	L->data[i-1]=e;
	L->length++;
	return 1;
}
/*在指定位置删除顺序表元素，保留被删除的元素e并输出*/
int deleteList (SqList *L,int i ){
	int j, k;			// 计数变量 与 储存被删除的元素
	k = L->data[i-1];	// 获取被删除的元素
	for( j = i-1; j < L->length-1; j++ )
		L->data[j] = L->data[j+1];
	L->length--;		// 删除了元素, 所以长度-1
	return k;
}
/*在指定位置删除顺序表元素，不保留被删除的元素*/
int deleteList1 (SqList *L,int i){
	int j;			// 计数变量
	for( j = i-1; j < L->length-1; j++ )
		L->data[j] = L->data[j+1];
	L->length--;		// 删除了元素, 所以长度-1
	return 1;
}

/*主函数*/
void main()
{
    SqList L;
	int i,e,k;//插入顺训表操作时的实参，i，e
	//int k;//保留被删除元素e的实参k
	//initList(&L);	
	CreateList(&L);//创建单链表，输入-1结束
	printfList(&L);//打印顺序表
	
	/*调用插入算法，在指定位置，插入指定元素，需要手动输入插入位置i，插入元素e*/
	printf("请输入要插入的元素位置i及元素e：");
	scanf("%d,%d",&i,&e);
	insertList (&L,i,e);//调用插入元素的算法
	printfList(&L);//打印顺序表
	
	/*调用删除算法，在指定位置删除元素，保留被删除的元素e，并输出或不保留，也不输出e的两种方法实现*/
	printf("请输入要删除的元素位置i：");
	scanf("%d",&i);
	/*保留被删除元素*/
	k=deleteList ( &L, i );
	printfList( &L );
	printf( "被删除的元素是：%d\n\n", k );
	
	
	//不保留被删除元素
	printf( "请输入要删除且不保留的元素位置i：" );
	scanf( "%d", &i );
	deleteList1 ( &L, i );
	printfList( &L );
	system( "pause" );		// 暂停程序
}