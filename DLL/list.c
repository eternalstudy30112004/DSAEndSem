#include "list.h"

void init(list *l1)
{
    l1->front = l1->rear = NULL;
}

int isEmpty(list l1)
{
    return l1.front == l1.rear && l1.front == NULL;
}
node *createNode(int data)
{
    node *new = (node *)malloc(sizeof(node));
    new->data = data;
    new->prev = new->next = NULL;
}
void insertright(list *l1, int data)
{
    node *new = createNode(data);
    if (isEmpty(*l1))
    {
        l1->front = l1->rear = new;
        return;
    }
    l1->rear->next = new;
    new->prev = l1->rear;
    l1->rear = new;
}
void printlistLR(list l1)
{
    node *p = l1.front;
    printf("\n[ ");
    while (p)
    {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("]\n");
};
void printlistRL(list l1)
{
    node *p = l1.rear;
    printf("\n[ ");
    while (p)
    {
        printf("%d ", p->data);
        p = p->prev;
    }
    printf("]\n");
};

int length(list l1)
{
    node *p = l1.front;
    int l = 0;
    while (p)
    {
        p = p->next;
        l++;
    }
    return l;
}

void reverse(list *l)
{
    node *start = l->front;
    node *end = l->rear;
    int temp;
    while (!(start == end || start->prev == end))
    {
        printf("--");
        temp = start->data;
        start->data = end->data;
        end->data = temp;
        start = start->next;
        end = end->prev;
    }
    
    return;
}

void insertsorted(list *l, int data)
{
    node *new = createNode(data);
    if (isEmpty(*l))
    {
        insertright(l, data);
        return;
    }
    node *p = l->front;
    while (p->data < data && p->next)
    {
        p = p->next;
    }
    if (p == l->front)
    {
        if (data > p->data)
        {
            p->next = new;
            new->prev = p;
            l->rear = new;
        }
        else
        {
            l->rear = l->front;
            l->front = new;
            l->front->next = l->rear;
            l->rear->prev = l->front;
        }
        return;
    }
    if (p == l->rear && p->data < data)
    {
        p->next = new;
        new->prev = p;
        l->rear = new;
        return;
    }
        p=p->prev;
         printf("\n%d",p->data);
         new->next = p->next;
         p->next = new;
         new->prev = p;
    return;
}

void removelist(list *l, int data)
{
    node *p = l->front;
    if (isEmpty(*l))
        return;
    while (p->data != data && p->next)
    {
        p = p->next;
    }
    if (p->data == data)
    {
        if (p == l->front || p == l->rear)
        {
            if (p == l->rear)
            {
                l->rear = p->prev;
                free(p);
            }
            if (p == l->front)
            {
                l->front = p->next;
                free(p);
            }
            return;
        }

        p->prev->next = p->next;
        p->next->prev = p->prev;
        free(p);
    }
}

void freelist(list *l)
{
    node *q, *p = l->front;
    while (p)
    {
        q = p;
        p = p->next;
        free(q);
    }
    l->front = l->rear = NULL;
}

int search(list l, int elm)
{
    node *p = l.front;
    while (p)
    {
        if (p->data == elm)
            return 1;
        p = p->next;
    }
    return 0;
}

list listunion(list l1, list l2)
{
    node *a = l1.front, *b = l2.front;
    list l3;
    init(&l3);
    while (a)
    {
        insertright(&l3, a->data);
        a = a->next;
    }
    while (b)
    {
        if (!search(l1, b->data))
            insertright(&l3, b->data);

        b = b->next;
    }
    return l3;
}