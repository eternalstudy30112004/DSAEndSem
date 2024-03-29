#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int data;
    struct node * next;
    struct node * prev;
} node;

typedef struct list{
    node *front;
    node *rear;
} list;

void init(list*);
int isempty(list);
void insertright(list*, int);
void printlistLR(list );
void printlistRL(list );
int length(list );
void reverse(list *l);
void insertsorted(list *,int);
void removelist(list*, int);
void freelist(list*);
// void sort(list*);
int search(list l, int);
list listunion(const list, list);