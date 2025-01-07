/*
1
3
1 3 5 7 9 -1
4
2,50
5
2

*/

/* Note:Your choice is C IDE */
/*10.16日单链表第一次实验代码框架*/
#include "stdio.h"
#include "malloc.h"
#define OK       1
#define ERROR    0
//传统定义方法
typedef int ElemType;
typedef struct LNode{
	ElemType data;//定义int型单链表数值元素	
	struct LNode *next;//定义next结构体指针变量，指向下一个结构体类型的单链表结点
}LinkList;

/*1.初始化单链表*/
LinkList initLinkList(LinkList *L){
		L=(LinkList*)malloc(sizeof(LinkList));
	    L->next=NULL;
		return *L;
}

/*2.头插法建立单链表--必做*/
LinkList CreateLinkH (LinkList *L,ElemType a[],int n,int loc){//此处需要添加函数实现语句
	int i, j;
	LinkList *p;
	for( i = 0; i < n; i++ )
	{
		p = (LinkList*)malloc(sizeof(LinkList));
		p->data = a[i];
		p->next = L->next;
		L->next = p;
	}
    return *L;
}
/*3.尾插法建立单链表--必做*/
LinkList CreateLinkR (LinkList *L,ElemType a[],int n,int first){//此处需要添加函数实现语句
	int i, j;
	LinkList *p;
	LinkList *theLastNode = L;
	for( i = 0; i < n; i++ )
	{
		p = (LinkList*)malloc(sizeof(LinkList));
		p->data = a[i];
		p->next = NULL;
		theLastNode->next = p;
		theLastNode = p;
	}
    return *L;
}

/*4.单链表元素插入--必做*/
int InsertLinkList (LinkList *L, int i, ElemType e){
	LinkList *p = L;
	LinkList *q = (LinkList*)malloc(sizeof(LinkList));
	q->data = e;

	int j = 0;
	for( j = 0; j < i-1; j++ )
		p = p->next;

	q->next = p->next;
	p->next = q;
	return L;
}

/*5.单链表元素删除--必做*/
int DeleteLinkList(LinkList *L,int i,ElemType e){
	LinkList *p = L->next;
	LinkList *q;
	int j = 0;
	for( j = 0; j < i-2; j++ )
		p = p->next;
	
	q = p->next;
	p->next = p->next->next;

	free(q);
	return e;
}

/*6.求单链表的的长度*/
int LengthList(LinkList *L){
	
	
	
	
	
	
}
/*7.取单链表的第i个位置上的元素*/
int GetElemLinkList(LinkList *L,int i){
	
	
	
	
	
}

/*8.查找第一个data域为e的元素位置\n*/
int GetLocateElemLinkList(LinkList *L,ElemType e){
	
	
	
	
	
}

/*9.单链表是否为空*/
int IsEmptyLinkList(LinkList *L){
	
	
	
}

/*10.清空单链表*/
void ClearLinkList(LinkList *L){
	
	
	
	
	
}




/*打印单链表*/
void printLinkList(LinkList *L){
	LinkList *p;
	p=L;
	printf("单链表元素为:\n");
	p=p->next;
	while(p!=NULL){
		printf("%d ",p->data);
		p=p->next;
	}
	printf("\n");	
    
}
void main()
{
    int sel,a[100],i=0,loc=0;
    LinkList L;
    LinkList p;
    int j,data,w,y=0,z;
    printf("\t\t*********************\n");
    printf("\n");
    printf("\t\t 单链表基本操作\n");
    printf("\n");
    printf("\t\t 1.初始化单链表\n");
    printf("\t\t 2.头插法建立单链表\n");
    printf("\t\t 3.尾插法建立单链表\n");
    printf("\t\t 4.在指定位置插入单链表任意元素\n");
    printf("\t\t 5.在指定位置删除单链表任意元素\n");
    
    printf("\t\t 6.求单链表的长度\n");
    printf("\t\t 7.取单链表的第i个位置上的元素\n");
    printf("\t\t 8.查找第一个data域为e的元素位置\n");
    printf("\t\t 9.单链表是否为空\n");
    printf("\t\t 10.清空单链表\n");
    
    printf("\t\t*********************\n");
    printf("请输入要执行的操作\n");
    
    printf("退出请按0\n");
    
    scanf("%d",&sel);
    while(sel!=0){
    	switch(sel){
    		case 1:
    			L = initLinkList(&L);
    		    break;

    		case 2:
    		    printf("请输入若干个元素，以-1结束\n");
    		    loc=i;
    		    scanf("%d",&a[i]);
    		    while(a[i]!=-1){
    		    		i++;
    		    		scanf("%d",&a[i]);//继续输入
    		    	}
    			p=CreateLinkH (&L,a,i,loc);
    			printLinkList(&p);
    		    break;

    		case 3:
    		    printf("请输入若干个元素，以-1结束\n");
    		    loc=i;
    		    scanf("%d",&a[i]);
    		    while(a[i]!=-1){
    		    		i++;
    		    		scanf("%d",&a[i]);//继续输入
    		    	}
    			p=CreateLinkR (&L,a,i,loc);
    			printLinkList(&p);
    		    break;

    		case 4:
    		    printf("请输入要插入的元素位置和元素\n");
    		    scanf( "%d,%d", &j, &data ); 
    		    InsertLinkList(&p,j,data);	
    		    printLinkList(&p);
    		    break;

    		case 5:
    		    printf("请输入要删除的元素位置\n");
    		    scanf("%d",&w); 
    		    z=DeleteLinkList( &p, w, y );
    		    printf("被删除的元素是:%d\n",z);	
    		    printLinkList( &p );
    		    break;

    		case 6:
    			//l=LengthList(&L);
    		    printf("单链表的长度是:%d\n",LengthList(&p));
    		    break;

    	    case 7:
    			printf("请输入要查找的元素位置\n");
    		    scanf("%d",&w); 
    		    z=GetElemLinkList(&p,w);
    		    printf("第%d位置的元素是:%d\n",w,z);
    		    break;

    		case 8:
    			printf("查找第一个data域为e的元素位置\n");
    		    scanf("%d",&w); 
    		    z=GetLocateElemLinkList(&p,w);
    		    printf("第一个data域为%d的元素位置:%d\n",w,z);
    		    break;

    		case 9:
    			printf("单链表为%s\n",(IsEmptyLinkList(&p)?"空":"不空"));
    			//printf("%d",IsEmptyLinkList(&L));
    		    break;

    		case 10:
    			printf("已清空单链表\n");
    			ClearLinkList(&p);
    		    break;

    		default:
    			printf("选择有误，重新选择");
    	}
    	  printf("请输入要执行的操作，退出请按0\n");
          scanf("%d",&sel);
    	}
}

