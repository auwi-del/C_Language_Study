#include <stdio.h>
#include <stdlib.h>

typedef struct _Node
{
    int num;
    struct _Node * next; 
} Node;


// ��������ͷ�ڵ�, ����
prtList( Node* head, int len )
{
    int i;
    Node * p;

    printf( "len : %d\n", len );
    p = head->next;
    for( i = 0; i < len; i++ )
    {
        printf( "%d,", p->num );
        p = p->next;
    }
}



int main()
{
    int input, len = 0, i, j, num, index;
    Node * head = (Node*)malloc(sizeof(Node));      // ����ͷ�ڵ�
    Node *p = (Node*)malloc(sizeof(Node));
    Node *q;
    head->next = p;
    while( 1 )
    {
        scanf( "%d", &input );
        if( input == -1 )
            break;
        p->num = input;
        q = (Node*)malloc(sizeof(Node));
        p->next = q;
        p = q;
        len++;
    }
    prtList( head, len );

    printf( "\n\n\n���������в���Ԫ�صĹ���, ��ʽΪ\n��ֵ,λ��, ��:" );
    printf( "5, 8\n�������ֵ5���뵽�ڰ˸�λ����\n\n");

    while( 1 )
    {
        p = head->next;
        scanf( "%d,%d", &num, &index );
        if( index > len )
        {
            printf( "�����λ�ó�����������, ��������\n" );
            continue;
        }
        for( i = 0; i < index-1; i++ )
            p = p->next;
        q = (Node*)malloc(sizeof(Node));
        q->num = num;
        q->next = p->next;
        p->next = q;
        len++;
        prtList( head, len );
    }
}