#include <stdlib.h>
#include <stdio.h>

typedef struct queue
{
    int front, rear, size;
    int *data;
} queue;

void init(queue *q, int size)
{
    q->front = q->rear = -1;
    q->data = (int *)calloc(sizeof(int), size);
}

int isEmpty(queue q)
{
    return q.front == q.rear;
}
int isFull(queue q)
{
    return q.rear == q.size - 1;
}
void enqueue(queue *q, int data)
{
    if (isFull(*q))
        return;
    q->data[++q->rear] = data;
}

void dequeue(queue *q)
{
    if (isEmpty(*q))
        return;
    q->front++;
}

void display(queue q)
{
    printf("\n");
    for (int i = q.front; i <= q.rear; i++)
    {
        printf("%d ", q.data[i]);
    }
    printf("\n");
}