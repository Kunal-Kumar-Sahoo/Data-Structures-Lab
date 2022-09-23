#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

Node *initialize(int data) {
    Node *node = (Node *)malloc(sizeof(Node));
    node->data = data;
    node->next = NULL;

    return node;
}

void insert_at_beginning(Node **head, int data) {
    Node *node = initialize(data);
    if(*head == NULL) {
        *head = node;
        (*head)->next = *head;
    }
    else {
        Node *tp;
        for(tp = *head; (tp->next)->data != *head; tp = tp->next);
        node->next = *head;
        tp->next = node;
        *head = node;
    }
}

void insert_at_end(Node **head, int data) {
    Node *node = initialize(data);
    if(*head == NULL) {
        *head = node;
        (*head)->next = *head;
    }
    else {
        Node *tp;
        for(tp = *head; (tp->next)->data != *head; tp = tp->next);
        node->next = *head;
        tp->next = node;
    }
}

void insert_after_node(Node **head, int node_data, int data) {
    Node *node = initialize(data);
    if(*head == NULL) 
        printf("Head not found\n");
    else {
        Node *tp;
        for(tp = *head; tp->data != node_data; tp = tp->next);
        if
    }
}