#include <stdlib.h>
#include <stdio.h>
#include <limits.h>

typedef struct node
{
    int data;
    struct node *next;
} node;

typedef node * list;

typedef struct stack{
    list l;
    node *top;
} stack;

void init_stack(stack *s){
    init_list(&s->l);
    s->top = NULL;
}
void init_list(list *l){
    *l = NULL;
}
node* createNode(int data){
    node *n =(node *) malloc(sizeof(node));
    n->data = data;
    n->next = NULL;
    return n;
}
void delete_end(list *l){
    node *q, *p = *l;
    while(p->next){
        q = p;
        p = p->next;
    }
    free(p);
    q->next = NULL;
}
void insert(list *l, int data){
    node *n = createNode(data);
    node *p = *l;
    while(p->next){
        p = p->next;
    }
    p->next = n;
}
int peek(stack s){
    if(!s.top)return INT_MAX;
    return s.top->data;
}
int pop(stack *s){
    if(!s->top)return INT_MAX;
    int dt = peek(*s);
    delete_end(s->l);
    return dt;
}


