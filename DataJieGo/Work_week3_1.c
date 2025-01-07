#include <stdio.h>
#include <stdlib.h>

typedef struct _Node
{
    int num;
    struct _Node * next; 
} Node;


// 传入链表头节点, 长度
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
    Node * head = (Node*)malloc(sizeof(Node));      // 创建头节点
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

    printf( "\n\n\n接下来进行插入元素的功能, 格式为\n数值,位置, 如:" );
    printf( "5, 8\n将会把数值5插入到第八个位置上\n\n");

    while( 1 )
    {
        p = head->next;
        scanf( "%d,%d", &num, &index );
        if( index > len )
        {
            printf( "插入的位置超过了链表长度, 重新输入\n" );
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