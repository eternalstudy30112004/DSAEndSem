#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#include "st.h"

void init_list(list *l){
   *l = NULL;
    return;
}

void insert(list *l,int d){
    node *p,*nn;
    nn = (node*)malloc(sizeof(node));
	if(nn){
		nn->data = d;
        nn->next = NULL;
	}
	else
	return;
    nn->next = *l;
    *l = nn;
    return;
}
void delete1(list *l){
  node *p = *l;

  // if there are no nodes in Linked List can't delete
  if (!p)
      return ;


  *l = p->next;
  free(p);

    return;
}

int isemptyl(list l){
    if(!(l))
        return 1;
    else
        return 0;
}


void init_stack(stack *s){
    init_list(&(s->l));
    s->top=NULL;
    return;
}
int isempty(stack s){
    if(s.top==NULL)
        return 1;
    else
        return 0;
}
void push(stack *s,int d){
    insert(&(s->l),d);
    node *p=s->l;
    s->top=s->l;
    return;
}
int peek(stack s){
    if(isempty(s))
        return INT_MAX;
    else
        return ((s.top)->data);
}
int pop(stack* s){
    if(isempty(*s))
        return INT_MAX;
    int j= peek(*s);
    delete1(&(s->l));
    s->top=s->l;
    return j;
}
void display(stack s){
    if(isempty(s)){
        printf("Stack is empty");
        return;
    }
    printf("[ ");
    node *p=s.top;
    while(p){
        printf("%d ",p->data);
        p=p->next;
    }
    printf("]\n");
    return;
}

