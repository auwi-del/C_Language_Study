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
/*10.16�յ������һ��ʵ�������*/
#include "stdio.h"
#include "malloc.h"
#define OK       1
#define ERROR    0
//��ͳ���巽��
typedef int ElemType;
typedef struct LNode{
	ElemType data;//����int�͵�������ֵԪ��	
	struct LNode *next;//����next�ṹ��ָ�������ָ����һ���ṹ�����͵ĵ�������
}LinkList;

/*1.��ʼ��������*/
LinkList initLinkList(LinkList *L){
		L=(LinkList*)malloc(sizeof(LinkList));
	    L->next=NULL;
		return *L;
}

/*2.ͷ�巨����������--����*/
LinkList CreateLinkH (LinkList *L,ElemType a[],int n,int loc){//�˴���Ҫ��Ӻ���ʵ�����
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
/*3.β�巨����������--����*/
LinkList CreateLinkR (LinkList *L,ElemType a[],int n,int first){//�˴���Ҫ��Ӻ���ʵ�����
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

/*4.������Ԫ�ز���--����*/
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

/*5.������Ԫ��ɾ��--����*/
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

/*6.������ĵĳ���*/
int LengthList(LinkList *L){
	
	
	
	
	
	
}
/*7.ȡ������ĵ�i��λ���ϵ�Ԫ��*/
int GetElemLinkList(LinkList *L,int i){
	
	
	
	
	
}

/*8.���ҵ�һ��data��Ϊe��Ԫ��λ��\n*/
int GetLocateElemLinkList(LinkList *L,ElemType e){
	
	
	
	
	
}

/*9.�������Ƿ�Ϊ��*/
int IsEmptyLinkList(LinkList *L){
	
	
	
}

/*10.��յ�����*/
void ClearLinkList(LinkList *L){
	
	
	
	
	
}




/*��ӡ������*/
void printLinkList(LinkList *L){
	LinkList *p;
	p=L;
	printf("������Ԫ��Ϊ:\n");
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
    printf("\t\t �������������\n");
    printf("\n");
    printf("\t\t 1.��ʼ��������\n");
    printf("\t\t 2.ͷ�巨����������\n");
    printf("\t\t 3.β�巨����������\n");
    printf("\t\t 4.��ָ��λ�ò��뵥��������Ԫ��\n");
    printf("\t\t 5.��ָ��λ��ɾ������������Ԫ��\n");
    
    printf("\t\t 6.������ĳ���\n");
    printf("\t\t 7.ȡ������ĵ�i��λ���ϵ�Ԫ��\n");
    printf("\t\t 8.���ҵ�һ��data��Ϊe��Ԫ��λ��\n");
    printf("\t\t 9.�������Ƿ�Ϊ��\n");
    printf("\t\t 10.��յ�����\n");
    
    printf("\t\t*********************\n");
    printf("������Ҫִ�еĲ���\n");
    
    printf("�˳��밴0\n");
    
    scanf("%d",&sel);
    while(sel!=0){
    	switch(sel){
    		case 1:
    			L = initLinkList(&L);
    		    break;

    		case 2:
    		    printf("���������ɸ�Ԫ�أ���-1����\n");
    		    loc=i;
    		    scanf("%d",&a[i]);
    		    while(a[i]!=-1){
    		    		i++;
    		    		scanf("%d",&a[i]);//��������
    		    	}
    			p=CreateLinkH (&L,a,i,loc);
    			printLinkList(&p);
    		    break;

    		case 3:
    		    printf("���������ɸ�Ԫ�أ���-1����\n");
    		    loc=i;
    		    scanf("%d",&a[i]);
    		    while(a[i]!=-1){
    		    		i++;
    		    		scanf("%d",&a[i]);//��������
    		    	}
    			p=CreateLinkR (&L,a,i,loc);
    			printLinkList(&p);
    		    break;

    		case 4:
    		    printf("������Ҫ�����Ԫ��λ�ú�Ԫ��\n");
    		    scanf( "%d,%d", &j, &data ); 
    		    InsertLinkList(&p,j,data);	
    		    printLinkList(&p);
    		    break;

    		case 5:
    		    printf("������Ҫɾ����Ԫ��λ��\n");
    		    scanf("%d",&w); 
    		    z=DeleteLinkList( &p, w, y );
    		    printf("��ɾ����Ԫ����:%d\n",z);	
    		    printLinkList( &p );
    		    break;

    		case 6:
    			//l=LengthList(&L);
    		    printf("������ĳ�����:%d\n",LengthList(&p));
    		    break;

    	    case 7:
    			printf("������Ҫ���ҵ�Ԫ��λ��\n");
    		    scanf("%d",&w); 
    		    z=GetElemLinkList(&p,w);
    		    printf("��%dλ�õ�Ԫ����:%d\n",w,z);
    		    break;

    		case 8:
    			printf("���ҵ�һ��data��Ϊe��Ԫ��λ��\n");
    		    scanf("%d",&w); 
    		    z=GetLocateElemLinkList(&p,w);
    		    printf("��һ��data��Ϊ%d��Ԫ��λ��:%d\n",w,z);
    		    break;

    		case 9:
    			printf("������Ϊ%s\n",(IsEmptyLinkList(&p)?"��":"����"));
    			//printf("%d",IsEmptyLinkList(&L));
    		    break;

    		case 10:
    			printf("����յ�����\n");
    			ClearLinkList(&p);
    		    break;

    		default:
    			printf("ѡ����������ѡ��");
    	}
    	  printf("������Ҫִ�еĲ������˳��밴0\n");
          scanf("%d",&sel);
    	}
}

