#ifndef __List__
#define __List__

#include <stdio.h>
#include <stdlib.h>

#define STRLEN 10
#define SCORLEN 10

typedef struct _Node
{
    char name[ STRLEN ];
    int score[ SCORLEN ];
    float ave;              // ƽ��
    struct _Node *Next;
} Node;

// ��������Ľṹ
typedef struct _List
{
    Node* head;               // ����ͷ�ڵ�
    Node* last;               // ָ��ĩβ�ڵ��ָ��
    int   length;             // ����
} List;

#endif

List* mkList();                     // ����������, ����һ�� [��������] �Ľṹ��ָ��
Node* mkNode();                     // ��ʼ���ڵ㺯��, ����һ����ʼ���õĽڵ�ĵ�ַ
List* Node_add( List* LIST );       // ����֪List ��ĩβ����һ�� Node
void see_the_list( List* LIST );    // ������ǰ����
List *Sort( List *LIST );           // �����㷨
int AppendNode( List *LIST, Node *p );      // ׷�ӽڵ�
List *mkEmptyList();                // �½������Ŀ��б�
int ListPop( List *LIST );          // ɾ�� LIST ��ĩβ�ڵ�.


/*
========================================================
             -----  M  A  I  N  -----
========================================================
*/
// int main()
// {
//     int i, j, k;
//     List* students = mkList();
//     for ( i = 0; i < 10; i++ )
//     {
//         Node_add( students );
//     }
//     see_the_list( students );
// }


// ����������, ����һ�� [��������] �Ľṹ��ָ��
List* mkList()
{
    List* p = (List*)malloc(sizeof(List));      // [��������] �õ���ʱָ��
    Node* q = mkNode();                         // ��˵�е�ͷ�ڵ�

    p -> head = q;
    p -> last = q;
    p -> length = 1;

    return p;
    // printf("�µ����������!");
}

// ��ʼ���ڵ㺯��, ����һ����ʼ���õĽڵ�
Node* mkNode()
{
    int i = 0;
    Node* p = (Node*)malloc(sizeof(Node));      // ����һ���ڴ�

    // �ַ������ʼ��
    for ( i = 0; i < STRLEN - 1; i++ )
    {
        p -> name[i] = ' ';
    }
    p -> name[i] = '\0';            // name�ַ��������һ��Ԫ��ӦΪ\0 

    // ��ֵ���ʼ��
    for ( i = 0; i < SCORLEN; i++ )
    {
        p -> score[i] = 0;
    }
    p -> Next = NULL;

    // С�����ʼ��
    p->ave += 0.001;

    return p;
}

// ����֪List ��ĩβ����һ�� Node
List* Node_add( List* LIST )
{
    Node* s = mkNode();              // ����һ���µĽڵ�
    LIST -> last -> Next = s;        // ��ԭ��last�ڵ��nextָ��s
    LIST -> last = s;                // Ȼ��[��������]�е�lastָ��s
    LIST -> length++;                // ���Ӽ���
    return LIST;
}

// ��������, ��������
List *Sort( List *LIST )
{
    ListPop( LIST );
    int i, j;
    // ˫����
    Node *a, *b, *maxP;
    List *newList = mkEmptyList();

    // ʵ����Ч�ڵ��� == length - 1, ���ѭ��
    for( i = 0; LIST->length-1 > 0; i++ )
    {
        a = LIST->head;
        b = LIST->head->Next;
        maxP = LIST->head;

        if( b->ave > a->ave )
        {
            maxP = b;
        }

        // �ҵ�����maxP. ���ҷ�ͷ�ڵ������ *a Ϊ maxP ��ǰ�ڵ�, maxP == b;
        // ��ͷ�ڵ����, ��maxP == a;
        while( 1 )
        {
            if( b->ave > maxP->ave )
            {
                maxP = b;
            }
            
            // b����һ�ڵ�( ȫ�� )����һ�ڵ�( NextΪNULL )
            // �ȸ�ֵ, ���ж��ܲ����ƶ�����, ���ƶ�����, ע��˳��.
            if( b->Next == NULL )
            {
                break;                  // Ԥ�� : b ͣ�������һ����Ч�ڵ���
            }

            a = a->Next;
            b = b->Next;
        }

        // maxP == LIST->head �����, ��ͷ�ڵ����:
        if( maxP == LIST->head )
        {
            LIST->head = maxP->Next;        // �� 2�ڵ� Ϊͷ
            LIST->length--;
            AppendNode( newList, maxP );
        }


        // maxP->Next == b->Next == LIST->last �����, ��β�ڵ����:
        // ԭ��: Ϊ�����㷽��, �����е��������һ���ڵ�Ϊ ȫ��ڵ�.
        else if ( maxP == LIST -> last )
        {
            LIST->last = a;                         // �� �����ڶ��ڵ�( a, �����ڶ���Ч�ڵ� ) Ϊ�����Чβ
            LIST->last->Next = NULL;                // ����, �����ڶ��ڵ�Ͳ����� Next ��, { ��һ���൱�� �����ڵ� }
            LIST->length--;
            AppendNode( newList, maxP );
        }
        
        // ʣ�µľ�����ԭ��LIST�м�����, �Ƚϼ�
        else
        {
            a->Next = b->Next;              // a ָ���� c, �� b ��·��, Ȼ��, b û��, �Ա� maxP ָ��
            LIST->length--;
            AppendNode( newList, maxP );
        }
    }
    AppendNode( newList, LIST->head );
    // ListPop( LIST );
    Node_add( newList );
    return newList;
}

// ����( ����LIST, ��ַp ), �˺����� LIST ĩβ ׷��һ��p.
int AppendNode( List *LIST, Node *p )
{   
    // ˵���Ǵ������ͷ�ڵ�
    if( LIST->length == 0 )
    {
        LIST->head = LIST->last = p;
        p->Next = NULL;                 // β�ڵ�û��Next
    }

    // һ�����, �������������β
    else
    {
        LIST->last->Next = p;           // ԭ����β�ڵ�Ӧ����ָ�� NULL ��, ����ָ�� p
        LIST->last = p;                 // ע��ǰ��˳��
        p->Next = NULL;
    }

    LIST->length++;                     // ����õ�׷��, ��������
}

// ����һ���յ�LIST, LIST->length == 0;
List *mkEmptyList()
{
    List* LIST = (List*)malloc(sizeof(List));
    LIST->head = LIST->last = NULL;
    LIST->length = 0;
    return LIST;
}


// ����һ������, ɾ���������ڵ�.( ���ڹ������� )
int ListPop( List *LIST )
{
    Node *a;
    a = LIST->head;
    
    // ���ֻ��һ���ڵ�, ϣ���������鲻Ҫ���� 
    if( a->Next == NULL )
    {
        free( a );
        return 0;
    }
        

    while( 1 )
    {
        if( a->Next->Next == NULL )         // a���ڵľ��ǵ����ڶ��ڵ�
        {
            LIST->last = a;
            free( a->Next );
            a->Next = NULL;
            break;
        }
        a = a->Next;
    }
    LIST->length--;
}


// ������ǰ����
void see_the_list( List* LIST )
{
    int i;
    Node* p = LIST -> head;                                 // ��ָ��ͷ�ڵ�

    // ��������
    printf("������һ���� %d ���ڵ�!\n", LIST -> length );
    printf("�ڵ��СΪ: %d\n\n", sizeof( Node ) );

    // ��ӡ��ͷ
    printf("| ���\t |    NAME   | s[0] | s[1] | s[2] | s[3] | s[4] |  Avge  | NEXT\t|\n");
    printf("+--------+-----------+------+------+------+------+------+--------+------+\n");

    for( i = 1; i <= LIST->length; i++ )
    {
        //       num   name    0     1    2      3     4     ave
        printf("|%d\t | %9s | %4d | %4d | %4d | %4d | %4d | %6.2f |%x|\n",
                i, p->name, p->score[0], p->score[1], p->score[2], p->score[3], p->score[4], p->ave, p->Next );
        
        p = p -> Next;      // ָ������һ�ڵ��ƶ�
    }
    
    printf("\n");
}
