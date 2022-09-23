#include <stdio.h>
#include <stdlib.h>

#define MAX 50

typedef unsigned int uint;

typedef struct Stack {
    uint capacity;
    int top;
    char *arr;
} Stack;

Stack *initialize(uint capacity) {
    Stack *s = (Stack *)malloc(sizeof(Stack));
    s->capacity = capacity;
    s->arr = (char *)malloc(s->capacity * sizeof(char));
    s->top = -1;

    return s;
}

int checkUnderflow(Stack *s) {
    return s->top == -1;
}

int checkOverflow(Stack *s) {
    return s->top == s->capacity-1;
}

void push(Stack *s, char x) {
    if(checkOverflow(s)) {
        printf("Stack is full\n");
        return;
    }
    s->arr[++s->top] = x;
}

char pop(Stack *s) {
    if(checkUnderflow(s)) {
        printf("Stack is empty\n");
        return '\0';
    }
    return s->arr[s->top--];
}

int peek(Stack *s) {
    if(checkUnderflow(s)) {
        printf("Stack is empty\n");
        return '\0';
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

void reverse(char s[]) {
    Stack *st = initialize(MAX);
    for(int i=0; s[i]!='\0';i++)
        push(st, s[i]);
    
    for(int i=0; !checkUnderflow(st); i++)
        s[i] = pop(st);
}

int main() {
    char s[MAX];
    printf("Enter a string: ");
    scanf("%s", s);
    printf("Original string: %s\n", s);
    reverse(s);
    printf("Reversed string: %s\n", s);

    return 0;
}