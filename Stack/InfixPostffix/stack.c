#include <stdlib.h>
#include <stdio.h>
#include <limits.h>

typedef struct stack{
    int *data;
    int top;
    int size;
} stack;

void init(stack *s, int size){
    s->size = size;
    int *data = (int *)malloc(sizeof(int) * size);
    if(data){
        s->data= data;
        s->top = -1;
    }
    return;
}
int isEmpty(stack s){
    return s.top == -1;
}
int isFull(stack s){
    return s.top == (s.size - 1);
}
void push(stack *s, int data){
    if(isFull(*s)){
        printf("stack overflow !1");
        return;
    };
    s->top++;
    s->data[s->top] = data;
}

int pop(stack *s){
    if(isEmpty(*s)){
        printf("stack underflow 1!");
        return INT_MIN;
    }
    
    s->top--;
    return s->data[s->top + 1];

}

int peek(stack *s){
    if(isEmpty(*s)){
        printf("stack underflow 1!");
        return INT_MIN;
    }
    return s->data[s->top];
}