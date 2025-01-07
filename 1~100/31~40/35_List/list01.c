#include <stdio.h>
#include <stdlib.h>

typedef struct _node
{
    int value;
    struct _node *next;

} Node;

int main()
{
    Node * head = NULL;
    int number;
    do
    {
        scanf("%d", &number);
        if( number != -1 )
        {
            //add link to list
            Node *p = (Node*)malloc(sizeof(Node));      // 分配一块内存, 大小为Node
            p->value = number;
            p->next = NULL; 
            // find the last
            Node *last = head;
            while ( last->next )
            {
                last = last->next;
            }
            // attach

        }
    } while (number != -1);
    
}