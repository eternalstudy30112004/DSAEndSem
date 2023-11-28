#include "stack.c"

int main() {
    stack s1, s2;
    init(&s1,100);
    init(&s2, 10);
    int item;
    push(&s1, 11);
    push(&s1, 10);
    push(&s1, 6);
    push(&s1, 7);
    printf("Stack 1\n");
    while((item = pop(&s1))!= INT_MIN)
        printf("%d\n", item);
    return 0;
}