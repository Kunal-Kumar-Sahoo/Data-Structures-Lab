#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef unsigned int uint;

typedef struct Stack {
    uint capacity;
    int top;
    int *arr;
} Stack;

Stack *initialize(uint capacity) {
    Stack *s = (Stack *)malloc(sizeof(Stack));
    s->capacity = capacity;
    s->arr = (int *)malloc(s->capacity * sizeof(int));
    s->top = -1;

    return s;
}

int checkUnderflow(Stack *s) {
    return s->top == -1;
}

int checkOverflow(Stack *s) {
    return s->top == s->capacity-1;
}

void push(Stack *s, int x) {
    if(checkOverflow(s)) {
        printf("Stack is full\n");
        return;
    }
    s->arr[++s->top] = x;
}

int pop(Stack *s) {
    if(checkUnderflow(s)) {
        printf("Stack is empty\n");
        return INT_MIN;
    }
    return s->arr[s->top--];
}

int peek(Stack *s) {
    if(checkUnderflow(s)) {
        printf("Stack is empty\n");
        return INT_MIN;
    }
    return s->arr[s->top];    
}

void traverse(Stack *s) {
    if(checkUnderflow(s)) {
        printf("Stack is empty\n");
        return;
    }
    for(int i=s->top; i>=0; i--)
        printf("%d ", s->arr[i]);
    printf("\n"); 
}

int main(void) {
    printf("Enter capacity of a stack: ");
    uint cap; scanf("%d", &cap);

    Stack *st = initialize(cap);

    int x, status = 1;
    while(status) {
        printf("Enter your choice:\n");
        printf("1: Push\n");
        printf("2: Pop\n");
        printf("3: Peek\n");
        printf("4: Traverse\n");
        printf("0: Exit\n:");
        int choice; scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter an element to be pushed: ");
                scanf("%d", &x);
                push(st, x);
                break;
            case 2:
                x = pop(st);
                if(x != INT_MIN)
                    printf("Popped element: %d\n", x);
                break;
            case 3:
                x = peek(st);
                if(x != INT_MIN)
                    printf("Element at top: %d\n", x);
                break;
            case 4:
                traverse(st);
                break;
            case 0:
                return 0;
            default:
                printf("Enter a valid choice!\n");
        }
    }

    return 0;   
}