#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct CircularQueue {
    size_t capacity;
    int front, rear;
    int *arr;
} CircularQueue;

CircularQueue *initialize(size_t cap) {
    CircularQueue *q = (CircularQueue *)malloc(sizeof(CircularQueue));
    q->capacity = cap;
    q->arr = (int *)malloc(q->capacity * sizeof(int));
    q->front = q->rear = -1;
    printf("Circular queue created\n");
    return q;
}

void destroy(CircularQueue *cq) {
    free(cq->arr);
    cq->arr = NULL;
    free(cq);
    cq = NULL;
    printf("Circular queue destroyed\n");
}

int isEmpty(CircularQueue *cq) {
    return cq->front == -1;
}

int isFull(CircularQueue *cq) {
    return cq->front == (cq->rear+1)%cq->capacity;
}

void enqueue(CircularQueue *cq, int x) {
    if(isFull(cq)) {
        printf("Circular queue is full\n");
        return;
    }
    if(isEmpty(cq)) cq->front = 0;
    cq->rear = (cq->rear+1)%cq->capacity;
    cq->arr[cq->rear] = x;
    printf("Element %d enqueued\n", x);
}

int dequeue(CircularQueue *cq) {
    if(isEmpty(cq)) {
        printf("Circular queue is empty\n");
        return INT_MIN;
    }
    int x = cq->arr[cq->front];
    if(cq->front == cq->rear)
        cq->front = cq->rear = -1;
    else cq->front = (cq->front+1) % cq->capacity;
    return x;
}

int peek(CircularQueue *cq) {
    if(isEmpty(cq)) {
        printf("Circular queue is empty\n");
        return INT_MIN;
    }
    return cq->arr[cq->front];
}

void traverse(CircularQueue *cq) {
    if(isEmpty(cq)) {
        printf("Circular queue is empty\n");
        return;
    }
    int i;
    for(i=cq->front; i!=cq->rear; i=(i+1)%cq->capacity)
        printf("%d ", cq->arr[i]);
    printf("%d\n", cq->arr[i]);
}

int main() {
    printf("Enter capacity of circular queue: ");
    size_t n; scanf("%lu", &n);
    CircularQueue *cq = initialize(n);

    int x, status = 1;

    while (status) {
        printf("\nEnter your choice:\n");
        printf("1. Enqueue:\n");
        printf("2. Dequeue:\n");
        printf("3. Peek:\n");
        printf("4. Traverse:\n");
        printf("5. Exit:\n:");

        int choice; scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter an element to be enqueued: ");
                scanf("%d", &x);
                enqueue(cq, x);
                break;
            case 2:
                x = dequeue(cq);
                if(x != INT_MIN)
                    printf("Popped element: %d\n", x);
                break;
            case 3:
                x = peek(cq);
                if(x != INT_MIN)
                    printf("Element at rear: %d\n", x);
                break;
            case 4:
                traverse(cq);
                break;
            case 5:
                destroy(cq);
                status = 0;
                break;
            default:
                printf("Invalid choice\n");
        }
    }
    

    return 0;
}