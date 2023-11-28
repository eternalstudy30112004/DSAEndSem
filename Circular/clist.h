#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    int data;
    struct node *next;
} node;

typedef node *clist;

void init(clist *c)
{
    *c = NULL;
}
node *createNode(int data)
{
    node *n = (node *)malloc(sizeof(node));
    if (n)
    {
        n->data = data;
        n->next - NULL;
    }
    return n;
}

void insert_beg(clist *c, int data)
{
    node *n = createNode(data);
    if (*c == NULL)
    {
        *c = n;
        n->next = *c;
        return;
    }
    node *q;
    node *p = *c;
    while (p->next != *c)
    {
        q = p;
        p = p->next;
    }

    n->next = *c;
    q->next = n;
    *c = n;
    return;
}