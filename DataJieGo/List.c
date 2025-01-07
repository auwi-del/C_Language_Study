#include <stdio.h>
#include <stdlib.h>

// 声明链表节点的结构
struct node {
    int data;
    struct node *next;
};

// 以后, LinkList 就是 struct node 的意思了, typedef , type define 的意思, 声明一种 type
typedef struct node LinkList;

// 声明链表的函数, 传入链表的开始节点, 传入一个数组, 传入一个链表长度n,
// 本函数能够将数组倒序存在链表里, 如有 开始节点L, 数组a如下:
/*

    a : { 1, 2, 3, 4, 5, 8, 9, 0 };

    当你 CreateList( L, a,  sizeof(a)/sizeof(int)  ));

    将会得到如下链表:
    [L -> ] [0 -> ] [9 -> ] [8 -> ] [4 -> ] [5 -> ] [3 -> ] [2 -> ] [1 -> NULL]
*/
void CreateList( LinkList *L, int a[], int n ) {
    // 创建一个指向 LinkList 类型的指针, 实际上就是指向 struct node 类型.
    LinkList *s;
    // 计数变量
    int i;

    //   将malloc到的内存强制转化成 
    //   LinkList 指针(LinkList*) 类型      申请一块内存      大小为
    L = (LinkList*)                        malloc(          sizeof(LinkList)                  );

    // 初始化头节点
    // 以上操作只是拥有了一块内存, 现在我们来把这块内存赋初始值

    // 因为 L 的 本质不是一个结构变量, 而是 指向一个结构变量的 指针, 所以, 
    // 下面这行的全称是  L指针 所指向的 结构体里 的 next 变量 ( 实际上, next也是个指针, 指向另一个和自己同类型的结构体, 所以叫链表呀 )
    // 将头节点的 下一节点指针( next ), 赋值为 NULL. 即 当前链表为空表, 所以没有下一节点
    L->next = NULL;
    
    for ( i = 0; i < n; i++ ) {
        // 每一轮循环都申请一新节点, 用s指向那个新的节点. 原理同 22 行的解释.
        s = ( LinkList* )malloc(sizeof(LinkList));

        // 一下逻辑比较烦恼
        s->data = a[i];
        s->next = L->next;        // 把新节点插入到头节点之后
        L->next = s;              // 把新节点赋给头节点
    
        // 这里解释一下
        // L 是开始节点, 不作为数据存储功能, 只作为一个开头, 
        // L 的 next 在 每一轮 for 循环49行之后, 才会变化, 始终指向最新生成的节点.

        // 每次在 47 行之后, 由于 L的next(L->next) 仍然指向 目前 倒数第二新的节点,
        // 所以 只需将 当前最新节点的下一节点( s->next ) 和 L->next 相同, 即可认为
        // 当前最新节点 已经插入到 链表中.
        
        // 最后, s 已经成为了 最新的节点, 所以, L->next 更新为 s;
        // 循环进入到下一轮, 重复以上过程
        
    }
}