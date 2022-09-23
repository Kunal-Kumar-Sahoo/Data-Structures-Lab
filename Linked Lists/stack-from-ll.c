#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define CAPACITY 5

typedef struct Node {
    int data;
    struct Node *link;
} Node;

Node *initialize(int data) {
    Node *node = (Node *)malloc(sizeof(Node));
    node->data = data;
    node->link = NULL;
    return node;
}

int length(Node **top) {
    int len = 0;
    if(*top != NULL) {
        for(Node *tp = *top; tp != NULL; tp = tp->link)
            len++;
    }
    return len;
}

int checkUnderflow(Node **top) {
    return length(top) == 0;
}

int checkOverflow(Node **top) {
    return length(top) == CAPACITY;
}

void push(Node **top, int data) {
    if(checkOverflow(top)) {
        printf("Stack is full\n");
        return;
    }
    Node *node = initialize(data);
    if(!checkUnderflow(top))
        node->link = *top;
    *top = node;
}

int pop(Node **top) {
    if(checkUnderflow(top)) {
        printf("Stack is empty\n");
        return INT_MIN;
    }
    Node *tmp = *top;
    *top = (*top)->link;
    int data = tmp->data;
    free(tmp);
    return data;
}

int peek(Node **top) {
    if(checkUnderflow(top)) {
        printf("Stack is empty\n");
        return INT_MIN;
    }
    return (*top)->data;
}

void traverse(Node **top) {
    if(checkUnderflow(top)) {
        printf("Stack is empty\n");
        return;
    }
    for(Node *tp = *top; tp != NULL; tp = tp->link) 
        printf("%d ", tp->data);
    printf("\n");
}

int main() {
    Node *top = NULL;
    int data, choice, status = 1;
    while(status) {
        printf("Enter your choice: ");
        printf("\n1. Push:");
        printf("\n2. Pop:");
        printf("\n3. Peek:");
        printf("\n4. Traverse:");
        printf("\n5. Exit\n");

        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter an element to be pushed: ");
                scanf("%d", &data);
                push(&top, data);
                break;
            case 2:
                data = pop(&top);
                if(data != INT_MIN)
                    printf("Element popped: %d\n", data);
                break;
            case 3:
                data = peek(&top);
                if(data != INT_MIN)
                    printf("Element at top: %d\n", data);
                break;
            case 4:
                traverse(&top);
                break;
            case 5: 
                status = 0;
                break;
            default:
                printf("Invalid choice\n");
        }    
    }

    return 0;
}