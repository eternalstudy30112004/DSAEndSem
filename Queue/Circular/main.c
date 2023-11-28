#include "queue.c"

int main(){
    circular q;
    init(&q, 5);
    printf("EMPTY : %d", isEmpty(q));
    enqueue(&q, 10);
    enqueue(&q, 20);
    enqueue(&q, 30);
    enqueue(&q, 44);
    dequeue(&q);
    printf("\n%d", isEmpty(q));
    dequeue(&q);
    enqueue(&q, 30);
    enqueue(&q, 44);
    display(q);

    return 0;
}