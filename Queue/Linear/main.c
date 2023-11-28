#include "queue.c"

int main(){
    queue p;
    init(&p, 5);
    enqueue(&p, 1);
    display(p);
    enqueue(&p, 2);
    display(p);
    enqueue(&p, 3);
    enqueue(&p, 4);
    return 0;
}