#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct Queue {
    size_t capacity;
    int front;
    int rear;
    int *arr;
} Queue;

Queue *initialize(size_t cap) {
    Queue *q = (Queue *)malloc(sizeof(Queue));
    q->capacity = cap;
    q->arr = (int *)malloc(q->capacity*sizeof(int));
    q->front = q->rear = -1;
    printf("Queue has been initialized\n");

    return q;
}

void destroy(Queue *q) {
    free(q->arr);
    q->arr = NULL;
    free(q);
    q = NULL;
    printf("Queue has been destroyed\n");
}

int isEmpty(Queue *q) {
    return q->front == -1;
}

int isFull(Queue *q) {
    return q->rear == (int)(q->capacity-1);
}

void enqueue(Queue *q, int x) {
    if(isFull(q)) {
        printf("Queue is full\n");
        return;
    }
    if(isEmpty(q))
        q->front = 0;
    q->arr[++q->rear] = x;
    printf("%d enqueued successfully\n", x);
}

int dequeue(Queue *q) {
    if(isEmpty(q)) {
        printf("Queue is empty\n");
        return INT_MIN;
    }
    int x = q->rear;
    if(q->front == q->rear) 
        q->front = q->rear = -1;
    else q->front++;
    return x;
}

int peek(Queue *q) {
    if(isEmpty(q)) {
        printf("Queue is empty\n");
        return INT_MIN;
    }
    return q->arr[q->front];
}

void traverse(Queue *q) {
    if(isEmpty(q)) 
        printf("Queue is empty\n");
    for(int i=q->front; i<=q->rear; i++)
        printf("%d ", q->arr[i]);
    printf("\n");
}

int main() {
    printf("Enter linear queue capacity: ");
    size_t cap; scanf("%lu", &cap);
    Queue *lq = initialize(cap);

    int x, status = 1;
    while(status) {
        printf("Enter your choice:\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Peek\n");
        printf("4. Traverse\n");
        printf("0. Exit\n:");

        int choice; scanf("%d", &choice);

        switch(choice) {
            case 0:
                destroy(lq);
                status = 0;
                break;
            case 1:
                printf("Enter element to be enqueued: ");
                scanf("%d", &x); 
                enqueue(lq, x);
                break;
            case 2:
                x = dequeue(lq);
                if(x != INT_MIN)
                    printf("Popped element: %d\n", x);
                break;
            case 3:
                x = peek(lq);
                if(x != INT_MIN)
                    printf("Element at front: %d\n", x);
                break;
            case 4:
                traverse(lq);
                break;
            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}