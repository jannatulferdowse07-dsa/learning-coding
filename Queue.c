#include <stdio.h>
#include <stdlib.h>

struct Queue
{
    int front;
    int rear;
    int size;
    int *arr;
};

// Create Queue
void createQueue(struct Queue *q, int size)
{
    q->front = -1;
    q->rear = -1;
    q->size = size;
    q->arr = (int *)malloc(size * sizeof(int));
}

// Check Empty
int isEmpty(struct Queue *q)
{
    return (q->front == -1 || q->front > q->rear);
}

// Check Full
int isFull(struct Queue *q)
{
    return (q->rear == q->size - 1);
}

// Enqueue
void enqueue(struct Queue *q, int value)
{
    if (isFull(q))
    {
        printf("Queue Overflow!\n");
        return;
    }

    if (q->front == -1)
        q->front = 0;

    q->rear++;
    q->arr[q->rear] = value;

    printf("%d inserted into Queue.\n", value);
}

// Dequeue
void dequeue(struct Queue *q)
{
    if (isEmpty(q))
    {
        printf("Queue Underflow!\n");
        return;
    }

    printf("%d deleted from Queue.\n", q->arr[q->front]);

    q->front++;

    if (q->front > q->rear)
    {
        q->front = -1;
        q->rear = -1;
    }
}

// Display
void display(struct Queue *q)
{
    if (isEmpty(q))
    {
        printf("Queue is Empty!\n");
        return;
    }

    printf("Queue Elements: ");

    for (int i = q->front; i <= q->rear; i++)
    {
        printf("%d ", q->arr[i]);
    }

    printf("\n");
}

int main()
{
    struct Queue q;
    int size;

    printf("Enter Queue Size: ");
    scanf("%d", &size);

    createQueue(&q, size);

    enqueue(&q, 10);
    enqueue(&q, 20);
    enqueue(&q, 30);

    display(&q);

    dequeue(&q);

    display(&q);

    enqueue(&q, 40);
    enqueue(&q, 50);

    display(&q);

    free(q.arr);

    return 0;
}
