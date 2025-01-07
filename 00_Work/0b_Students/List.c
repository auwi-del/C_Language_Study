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
    float ave;              // 平均
    struct _Node *Next;
} Node;

// 管理链表的结构
typedef struct _List
{
    Node* head;               // 链表头节点
    Node* last;               // 指向末尾节点的指针
    int   length;             // 长度
} List;

#endif

List* mkList();                     // 创建链表方法, 返回一个 [管理链表] 的结构的指针
Node* mkNode();                     // 初始化节点函数, 返回一个初始化好的节点的地址
List* Node_add( List* LIST );       // 对已知List 的末尾增加一个 Node
void see_the_list( List* LIST );    // 遍历当前链表
List *Sort( List *LIST );           // 排序算法
int AppendNode( List *LIST, Node *p );      // 追加节点
List *mkEmptyList();                // 新建纯纯的空列表
int ListPop( List *LIST );          // 删除 LIST 的末尾节点.


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


// 创建链表方法, 返回一个 [管理链表] 的结构的指针
List* mkList()
{
    List* p = (List*)malloc(sizeof(List));      // [管理链表] 用的临时指针
    Node* q = mkNode();                         // 传说中的头节点

    p -> head = q;
    p -> last = q;
    p -> length = 1;

    return p;
    // printf("新的链表创建完成!");
}

// 初始化节点函数, 返回一个初始化好的节点
Node* mkNode()
{
    int i = 0;
    Node* p = (Node*)malloc(sizeof(Node));      // 申请一块内存

    // 字符串域初始化
    for ( i = 0; i < STRLEN - 1; i++ )
    {
        p -> name[i] = ' ';
    }
    p -> name[i] = '\0';            // name字符串的最后一个元素应为\0 

    // 数值域初始化
    for ( i = 0; i < SCORLEN; i++ )
    {
        p -> score[i] = 0;
    }
    p -> Next = NULL;

    // 小数域初始化
    p->ave += 0.001;

    return p;
}

// 对已知List 的末尾增加一个 Node
List* Node_add( List* LIST )
{
    Node* s = mkNode();              // 创建一个新的节点
    LIST -> last -> Next = s;        // 将原有last节点的next指向s
    LIST -> last = s;                // 然后将[管理链表]中的last指向s
    LIST -> length++;                // 增加计数
    return LIST;
}

// 传入链表, 垃圾排序
List *Sort( List *LIST )
{
    ListPop( LIST );
    int i, j;
    // 双窗口
    Node *a, *b, *maxP;
    List *newList = mkEmptyList();

    // 实际有效节点数 == length - 1, 外层循环
    for( i = 0; LIST->length-1 > 0; i++ )
    {
        a = LIST->head;
        b = LIST->head->Next;
        maxP = LIST->head;

        if( b->ave > a->ave )
        {
            maxP = b;
        }

        // 找到最大的maxP. 并且非头节点情况下 *a 为 maxP 的前节点, maxP == b;
        // 若头节点最大, 则maxP == a;
        while( 1 )
        {
            if( b->ave > maxP->ave )
            {
                maxP = b;
            }
            
            // b的下一节点( 全零 )的下一节点( Next为NULL )
            // 先赋值, 在判断能不能移动窗口, 再移动窗口, 注意顺序.
            if( b->Next == NULL )
            {
                break;                  // 预期 : b 停留在最后一个有效节点上
            }

            a = a->Next;
            b = b->Next;
        }

        // maxP == LIST->head 的情况, 即头节点最大:
        if( maxP == LIST->head )
        {
            LIST->head = maxP->Next;        // 记 2节点 为头
            LIST->length--;
            AppendNode( newList, maxP );
        }


        // maxP->Next == b->Next == LIST->last 的情况, 即尾节点最大:
        // 原因: 为了运算方便, 程序中的链表最后一个节点为 全零节点.
        else if ( maxP == LIST -> last )
        {
            LIST->last = a;                         // 记 倒数第二节点( a, 倒数第二有效节点 ) 为最后有效尾
            LIST->last->Next = NULL;                // 所以, 倒数第二节点就不能有 Next 了, { 这一步相当于 解锁节点 }
            LIST->length--;
            AppendNode( newList, maxP );
        }
        
        // 剩下的就是在原有LIST中间的情况, 比较简单
        else
        {
            a->Next = b->Next;              // a 指向了 c, 将 b 短路了, 然而, b 没丢, 仍被 maxP 指向
            LIST->length--;
            AppendNode( newList, maxP );
        }
    }
    AppendNode( newList, LIST->head );
    // ListPop( LIST );
    Node_add( newList );
    return newList;
}

// 传入( 链表LIST, 地址p ), 此函数在 LIST 末尾 追加一个p.
int AppendNode( List *LIST, Node *p )
{   
    // 说明是此链表的头节点
    if( LIST->length == 0 )
    {
        LIST->head = LIST->last = p;
        p->Next = NULL;                 // 尾节点没有Next
    }

    // 一般情况, 都是在新链表的尾
    else
    {
        LIST->last->Next = p;           // 原来的尾节点应该是指向 NULL 的, 现在指向 p
        LIST->last = p;                 // 注意前后顺序
        p->Next = NULL;
    }

    LIST->length++;                     // 链表得到追加, 长度增长
}

// 返回一个空的LIST, LIST->length == 0;
List *mkEmptyList()
{
    List* LIST = (List*)malloc(sizeof(List));
    LIST->head = LIST->last = NULL;
    LIST->length = 0;
    return LIST;
}


// 传入一个链表, 删除它的最后节点.( 用于规整链表 )
int ListPop( List *LIST )
{
    Node *a;
    a = LIST->head;
    
    // 如果只有一个节点, 希望这种事情不要发生 
    if( a->Next == NULL )
    {
        free( a );
        return 0;
    }
        

    while( 1 )
    {
        if( a->Next->Next == NULL )         // a所在的就是倒数第二节点
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


// 遍历当前链表
void see_the_list( List* LIST )
{
    int i;
    Node* p = LIST -> head;                                 // 先指向头节点

    // 基本参数
    printf("该链表一共有 %d 个节点!\n", LIST -> length );
    printf("节点大小为: %d\n\n", sizeof( Node ) );

    // 打印表头
    printf("| 编号\t |    NAME   | s[0] | s[1] | s[2] | s[3] | s[4] |  Avge  | NEXT\t|\n");
    printf("+--------+-----------+------+------+------+------+------+--------+------+\n");

    for( i = 1; i <= LIST->length; i++ )
    {
        //       num   name    0     1    2      3     4     ave
        printf("|%d\t | %9s | %4d | %4d | %4d | %4d | %4d | %6.2f |%x|\n",
                i, p->name, p->score[0], p->score[1], p->score[2], p->score[3], p->score[4], p->ave, p->Next );
        
        p = p -> Next;      // 指针向下一节点移动
    }
    
    printf("\n");
}
