/* Note:Your choice is C IDE */
/*9.18����ҵ�ο����룬��9.11��ҵ�����ϣ�ɾ��˳���������λ�õ�Ԫ�أ����߱�����Ԫ��e���߲�����e*/
#include "stdio.h"
#define MAXSIZE 50

typedef struct{
	char data[MAXSIZE];	
	int length;
}SqList;
/*��ʼ��˳���*/
/*int initList(SqList *L){
	L->length=0;
	 return 0;
}*/
/*ѭ������Ԫ�أ�����˳���,Ԫ������ֱ��-1����*/
void CreateList(SqList *L){
	int i,e;
	L->length=0;
	printf("������˳���Ԫ�أ�");
	for(i=0;i<MAXSIZE;i++){
		  scanf("%d",&e);
		  if(e==-1)
		  	break;
		  L->data[i]=e;
		  L->length++;
   }
}

/*��ӡ˳���*/
void printfList(SqList *L){
	int i;
	printf("˳���ĳ���Ϊ��%d\n",L->length);
	if(L->length==0){
		printf("���ǿձ�û��Ԫ��");
        return;
	}
	for(i=0;i<L->length;i++)
		printf("\n˳���ĵ�%d��Ԫ��Ϊ��%d",(i+1),L->data[i]);
	printf("\n");
}

/*������λ�ò���˳���Ԫ��*/
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
/*��ָ��λ��ɾ��˳���Ԫ�أ�������ɾ����Ԫ��e�����*/
int deleteList (SqList *L,int i ){
	int j, k;			// �������� �� ���汻ɾ����Ԫ��
	k = L->data[i-1];	// ��ȡ��ɾ����Ԫ��
	for( j = i-1; j < L->length-1; j++ )
		L->data[j] = L->data[j+1];
	L->length--;		// ɾ����Ԫ��, ���Գ���-1
	return k;
}
/*��ָ��λ��ɾ��˳���Ԫ�أ���������ɾ����Ԫ��*/
int deleteList1 (SqList *L,int i){
	int j;			// ��������
	for( j = i-1; j < L->length-1; j++ )
		L->data[j] = L->data[j+1];
	L->length--;		// ɾ����Ԫ��, ���Գ���-1
	return 1;
}

/*������*/
void main()
{
    SqList L;
	int i,e,k;//����˳ѵ�����ʱ��ʵ�Σ�i��e
	//int k;//������ɾ��Ԫ��e��ʵ��k
	//initList(&L);	
	CreateList(&L);//��������������-1����
	printfList(&L);//��ӡ˳���
	
	/*���ò����㷨����ָ��λ�ã�����ָ��Ԫ�أ���Ҫ�ֶ��������λ��i������Ԫ��e*/
	printf("������Ҫ�����Ԫ��λ��i��Ԫ��e��");
	scanf("%d,%d",&i,&e);
	insertList (&L,i,e);//���ò���Ԫ�ص��㷨
	printfList(&L);//��ӡ˳���
	
	/*����ɾ���㷨����ָ��λ��ɾ��Ԫ�أ�������ɾ����Ԫ��e��������򲻱�����Ҳ�����e�����ַ���ʵ��*/
	printf("������Ҫɾ����Ԫ��λ��i��");
	scanf("%d",&i);
	/*������ɾ��Ԫ��*/
	k=deleteList ( &L, i );
	printfList( &L );
	printf( "��ɾ����Ԫ���ǣ�%d\n\n", k );
	
	
	//��������ɾ��Ԫ��
	printf( "������Ҫɾ���Ҳ�������Ԫ��λ��i��" );
	scanf( "%d", &i );
	deleteList1 ( &L, i );
	printfList( &L );
	system( "pause" );		// ��ͣ����
}