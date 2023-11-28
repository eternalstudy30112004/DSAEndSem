#include <stdio.h>
#include <stdlib.h>

typedef struct circular
{
    int size;
    int front;
    int rear;
    int *data;
} circular;

void init(circular *q, int size)
{
    q->data = (int *)calloc(sizeof(int), size);
    q->front = q->rear = 0;
    q->size = size;
}

int isEmpty(circular q)
{
    return q.front == q.rear;
}
int isFull(circular q)
{
    return (q.front == (q.rear + 1) % q.size);
}
void enqueue(circular *q, int data)
{
    if (isFull(*q))
        return;
    q->rear = ((q->rear + 1) % q->size);
    q->data[q->rear] = data;
    return;
}

void dequeue(circular *q)
{
    if (isEmpty(*q))
        return;
    q->front = (q->front + 1) % q->size;
    return;
}

void display(circular q)
{
    printf("\n %d[", q.front);

    int p = q.front;
    do
    {

        printf("%d ", q.data[(++p) % q.size]);
    } while (p%q.size != q.rear);
    printf("]\n");
}
