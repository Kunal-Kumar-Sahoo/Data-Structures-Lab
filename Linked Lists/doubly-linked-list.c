#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct Node {
    int data;
    struct Node *previous, *next;
} Node;

Node *initialize(int data) {
    Node *node = (Node *)malloc(sizeof(Node));
    node->data = data;
    node->previous = node->next = NULL;

    return node;
}

void insert_at_front(Node **head, int data) {
    Node *node = initialize(data);
    if((*head)->previous == NULL) {
        node->next = *head;
        (*head)->previous = node;
        *head = node;
    } else {
        printf("Invalid head node\n");
        free(node);
    }
}

void insert_at_end(Node **head, int data) {
    Node *tp, *node = initialize(data);
    if(*head == NULL) {
        printf("Invalid head node\n");
        free(node);
    }
    else {
        for(tp=*head; tp->next!=NULL; tp=tp->next);
        tp->next = node;
        node->previous = tp;
    }
}



void insert_after_node(Node **head, int element, int data) {
    Node *tp, *node = initialize(data);
    for(tp=*head; tp->data!=element && tp!=NULL; tp=tp->next);
    Node *tmp = tp->next;
    if(tmp == NULL) {
        insert_at_end(head, data);
        free(tmp);
    }
    else {
        tp->next = node;
        node->previous = tp;
        node->next = tmp;
        tmp->previous = node;
    }
}

void insert_before_node(Node **head, int element, int data) {
    Node *tp, *node = initialize(data);
    for(tp=*head; tp->data!=element && tp != NULL; tp=tp->next);
    Node *tmp = tp->previous;
    if(tmp == NULL) {
        insert_at_front(head, data);
        free(tmp);
    }
    else {
        tp->previous = node;
        node->next = tp;
        node->previous = tmp;
        tmp->next = node;
    }
}

void traverse(Node **head) {
    Node *last;
    printf("Traverse in forward direction:\n");
    printf("[start]->");
    for(Node *tp=*head; tp!=NULL; tp=tp->next) {
        last = tp;
        printf("%d->", tp->data);
    }
    printf("[end]\n");
    printf("Traverse in reverse direction:\n");

    printf("[end]->");
    for(Node *tp=last; tp!=NULL; tp=tp->previous)
        printf("%d->", tp->data);
    printf("[start]\n");
}

void delete_from_beginning(Node **head) {
    if(*head == NULL)
        return;
    Node *tmp = (*head)->next;
    (*head)->next = NULL;
    tmp->previous = NULL;
    free(*head);
    *head = tmp;
}

void delete_at_end(Node **head) {
    if(*head == NULL)
        return;
    Node *tp;
    for(tp=*head; tp->next!=NULL; tp=tp->next);
    free(tp);
    tp = NULL;
}

void delete_after_node(Node **head, int element_data) {
    if(*head == NULL)
        return;
    Node *tp;
    for(tp=*head; tp->data!=element_data && tp!=NULL; tp=tp->next);
    Node *tmp = tp->next;
    tp->next = tmp->next;
    (tmp->next)->previous = tp;
    free(tmp);
}
void delete_before_node(Node **head, int element_data) {
    if(*head == NULL)
        return;
    Node *tp;
    for(tp=*head; tp->data!=element_data && tp!=NULL; tp=tp->next);
    Node *tmp = tp->previous;
    tp->previous = tmp->previous;
    (tmp->previous)->next = tp;
    free(tmp);
}

int main() {
    printf("Enter data for the head node: ");
    int data, tmp; scanf("%d", &data);
    Node *head = initialize(data);

    int status = 1, choice;
    while(status) {
        printf("Enter your choice: ");
        printf("\n1. Insert node at beginning");
        printf("\n2. Insert node after another node");
        printf("\n3. Insert node before another node");
        printf("\n4. Insert node at end");
        printf("\n5. Delete node from beginning");
        printf("\n6. Delete node after another node");
        printf("\n7. Delete node before another node");
        printf("\n8. Delete node from end");
        printf("\n9. Traverse");
        printf("\n10.Exit\n");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter element: ");
                scanf("%d", &data);
                insert_at_front(&head, data);
                break;
            case 2:
                printf("Enter element after which the node has to be inserted: ");
                scanf("%d", &tmp);
                printf("Enter element: ");
                scanf("%d", &data);
                insert_after_node(&head, tmp, data);
                break;
            case 3:
                printf("Enter element after which the node has to be inserted: ");
                scanf("%d", &tmp);
                printf("Enter element: ");
                scanf("%d", &data);
                insert_before_node(&head, tmp, data);
                break;
            case 4:
                printf("Enter element: ");
                scanf("%d", &data);
                insert_at_end(&head, data);
                break;
            case 9:
                traverse(&head);
                break;
            case 10:
                status = 0;
                break;
            default:
                printf("Invalid argument\n");
        }
    }

    return 0;
}
