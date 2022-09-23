#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct Deque{
    int capacity;
    int front, rear;
    int *arr;
} Deque;

Deque*initialize(int capacity) {
    Deque*q = (Deque*)malloc(sizeof(Deque));
    q->capacity = capacity;
    q->front = q->rear = -1;
    q->arr = (int *)malloc(q->capacity*sizeof(int));

    return q;
}

int checkUnderflow(Deque *q) {
    return q->front == q->rear && q->front == -1;
}

int checkOverflow(Deque *q) {
    return q->front == 0 && q->rear == q->capacity-1;
}

void enqueue_front(Deque *q, int x) {
    if(checkOverflow(q)) 
        printf("Deque is full\n");
    else if(q->front == -1) {
        q->front = q->rear = 0;
        q->arr[q->front] = x;
    }
    else if(q->rear < q->capacity-1 && q->front == 0) {
        for(int i=q->rear; i>=q->front; i--)
            q->arr[i+1] = q->arr[i];
        q->arr[q->front] = x;
        q->rear++;
    }
    else if(q->front > 0)
        q->arr[--q->front] = x;
}

void enqueue_rear(Deque *q, int x) {
    if(checkOverflow(q)) 
        printf("Deque is full\n");
    else if(q->front == -1) {
        q->front = q->rear = 0;
        q->arr[q->rear] = x;
    }
    else if(q->rear == q->capacity-1 && q->front > 0) {
        for(int i=q->front; i<=q->rear; i++)
            q->arr[i-1] = q->arr[i];
        q->rear = x;
        q->front--;
    }
    else if(q->rear < q->capacity-1)
        q->arr[++q->rear] = x;
}

int dequeue_front(Deque *q) {
    if(checkUnderflow(q)) {
        printf("Deque is empty\n");
        return INT_MIN;
    }
    int x = q->arr[q->front];
    if(q->front == q->rear)
        q->front = q->rear = -1;
    else q->front++;
    return x;
}

int dequeue_rear(Deque *q) {
    if(checkUnderflow(q)) {
        printf("Deque is empty\n");
        return INT_MIN;
    }
    int x = q->arr[q->rear];
    if(q->front == q->rear)
        q->front = q->rear = -1;
    else q->rear--;
    return x;
}

int peek_front(Deque *q) {
    if(checkUnderflow(q)) {
        printf("Deque is empty\n");
        return INT_MIN;
    }
    return q->arr[q->front];
}

int peek_rear(Deque *q) {
    if(checkUnderflow(q)) {
        printf("Deque is empty\n");
        return INT_MIN;
    }
    return q->arr[q->rear];
}

void traverse(Deque *q) {
    if(checkUnderflow(q)) {
        printf("Deque is empty\n");
        return;
    }
    for(int i=q->front; i<=q->rear; i++)
        printf("%d ", q->arr[i]);
    printf("\n");
}

int main() {
    printf("Enter size of the deque: ");
    int size; scanf("%d", &size);

    Deque *dq = initialize(size);

    int x, choice, status = 1;
    while(status) {
        printf("Enter your choice:");
        printf("\n1. Insert at front");
        printf("\n2. Insert at rear");
        printf("\n3. Dequeue from front");
        printf("\n4. Dequeue from rear");
        printf("\n5. Peek from front");
        printf("\n6. Peek from rear");
        printf("\n7. Traverse");
        printf("\n8. Exit\n");

        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter an element: ");
                scanf("%d", &x);
                enqueue_front(dq, x);
                break;
            case 2:
                printf("Enter an element: ");
                scanf("%d", &x);
                enqueue_rear(dq, x);
                break;
            case 3:
                x = dequeue_front(dq);
                if(x != INT_MIN)
                    printf("%d\n", x);
                break;
            case 4:
                x = dequeue_rear(dq);
                if(x != INT_MIN)
                    printf("%d\n", x);
                break;
            case 5:
                x = peek_front(dq);
                if(x != INT_MIN)
                    printf("%d\n", x);
                break;
            case 6:
                x = peek_rear(dq);
                if(x != INT_MIN)
                    printf("%d\n", x);
                break;
            case 7:
                traverse(dq);
                break;
            case 8:
                status = 0;
                break;
            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}
