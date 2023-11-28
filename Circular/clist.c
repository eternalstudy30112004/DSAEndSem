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
        n->next = NULL;
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
    node *p = *c;
    while (p->next != *c)
    {
        p = p->next;
    }

    n->next = *c;
    p->next = n;
    *c = n;
    return;
}

void insert_end(clist *c, int data){
    node *n = createNode(data);
    if (*c == NULL){
        insert_beg(c, data);
        return;
    }
    node *p;
    while(p->next != *c)
    {
        p = p->next;
    }
    p->next = n;
    n->next = *c;
    return;
}


void traverse(clist c)
{

    printf("\n[ ");
    node *p = c;
    if (p == NULL){
        printf("]\n");
        return;
        }
    do
    {
        printf("%d ", p->data);
        p = p->next;
    } while (p != c);
    printf("]\n");
    return;
}

void delete_beg(clist *c){
    node *p = *c;
    if(p == NULL)
    return;
    if(p->next == *c){
        *c = NULL;
        return;
    }

    while(p->next != *c){
        p = p->next;
    }
    p->next = (*c)->next;
    node *q = *c;
    *c = p->next;
    free(q);
}

void delete_end(clist *c){
    node *p = *c;
    if(p == NULL)
    return;
    if(p->next == *c){
        *c = NULL;
        return;
    }
    node *q;
    while(p->next != *c){
        q = p;
        p = p->next;
    }
    free(p);
    q->next = *c;

}