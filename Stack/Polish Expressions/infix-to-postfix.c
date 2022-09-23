#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct Stack {
    int capacity;
    int top;
    char *arr;
} Stack;

Stack *initialize(int cap) {
    Stack *s = (Stack *)malloc(sizeof(Stack));
    s->capacity = cap;
    s->top = -1;
    s->arr = (char *)malloc(s->capacity*sizeof(char));

    return s;
}

int checkUnderflow(Stack *s) {
    return s->top == -1;
}

int checkOverflow(Stack *s) {
    return s->top == s->capacity-1;
}

void push(Stack *s, char c) {
    if(checkOverflow(s)) {
        printf("Stack is full\n");
        return;
    }
    s->arr[++s->top] = c;
} 

char pop(Stack *s) {
    if(checkUnderflow(s)) 
        return '$';
    return s->arr[s->top--];
}

int get_precedence(char c) {
    switch(c) {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        case '^':
            return 3;
    } return -1;
}

char *get_prefix_expression(char infix[]) {
    char *prefix = (char *)malloc(strlen(infix)*sizeof(char));
    Stack *s = initialize(strlen(infix));
    int k=0;
    for(int i=0; infix[i]!='\0'; i++) {
        if(infix[i] == ')')
            push(s, ')');
        else if(isalnum(infix[i]))
            prefix[k++] = infix[i];
        else if(infix[i] == '(') {
            while(s->arr[s->top] != ')')
                prefix[k++] = pop(s);
            pop(s);
        }
        else {
            while(get_precedence(s->arr[s->top]) >= get_precedence(infix[i]))
                prefix[k++] = pop(s);
            push(s, infix[i]);
        }
    }
    while(!checkUnderflow(s)) 
        prefix[k++] = pop(s);
    prefix[k] = '\0';

    return prefix;
}

int main() {
    char string[50];
    printf("Enter a string of infix expression: ");
    scanf("%s", string);

    printf("Original infix expression: %s\n", string);
    char *prfx = get_prefix_expression(string);
    printf("Prefix expression: %s\n", prfx);

    return 0;
}
