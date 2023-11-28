#include <stdlib.h>
#include <stdio.h>
#include <limits.h>

typedef struct stack{
    char *data;
    int top;
    int size;
} stack;

void init(stack *s, int size){
    s->size = size;
    char *data = (char *)malloc(sizeof(char) * size);
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
void push(stack *s, char data){
    if(isFull(*s)){
        printf("stack overflow !1");
        return;
    };
    s->top++;
    s->data[s->top] = data;
}

char pop(stack *s){
    if(isEmpty(*s)){
        printf("stack underflow 1!");
        return '#';
    }
    
    s->top--;
    return s->data[s->top + 1];

}

char peek(stack *s){
    if(isEmpty(*s)){
        printf("stack underflow 1!");
        return '#';
    }
    return s->data[s->top];
}