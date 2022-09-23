#include <stdio.h>
#include <stdlib.h>

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

void traverse(Node **head) {
    if(*head == NULL) 
        printf("Head not found\n");
    else {
        printf("[start] => ");
        for(Node *tp=*head; tp!=NULL; tp=tp->next)
            printf("%d => ", tp->data);
        printf("[end]\n");
    }
}

void insert_at_beginning(Node **head, int data) {
    Node *node = initialize(data);
    node->next = *head;
    *head = node;
}

void insert_at_end(Node **head, int data) {
    Node *node = initialize(data);
    if(*head == NULL) 
        *head = node;
    else {
        Node *tp;
        for(tp=*head; tp->next!=NULL; tp=tp->next);
        tp->next = node;
    }
}

void insert_after_element(Node **head, int element_data, int data) {
    Node *node = initialize(data);
    if(*head == NULL) 
        printf("Head not found\n");
    else {
        Node *tp;
        for(tp=*head; tp->data!=element_data; tp=tp->next);
        if(tp == NULL)
            printf("Element is not present in the linked-list\n");
        else {
            Node *tmp = tp->next;
            tp->next = node;
            node->next = tmp;
        }
    }
}

void delete_from_beginning(Node **head) {
    if(*head == NULL)
        printf("Head does not exist\n");
    else {
        Node *tmp = *head;
        *head = (*head)->next;
        free(tmp);
        printf("Element deleted\n");
    }
}

void delete_from_end(Node **head) {
    if(*head == NULL)
        printf("Head does not exist\n");
    else {
        Node *tp;
        for(tp=*head; (tp->next)->next!=NULL; tp=tp->next);
        free(tp->next);
        tp->next = NULL;
        printf("Element deleted\n");
    }
}

void delete_node(Node **head, int data) {
    if(*head == NULL)
        printf("Head does not exist\n");
    else {
        Node *tp;
        for(tp=*head; (tp->next)->data!=data && tp!=NULL; tp=tp->next);
        if(tp == NULL)
            printf("Element is not present in linked-list\n");
        else {
            Node *tmp = (tp->next)->next;
            free(tp->next);
            tp->next = tmp;
        }
    }
}

int length(Node **head) {
    if(*head == NULL)
        return 0;
    int length_ = 1;
    for(Node *tp=*head; tp->next!=NULL; tp=tp->next, length_++);
    return length_;
}

int main(void) {
    printf("Enter data for head node: " );
    int data; scanf("%d", &data);

    Node *head = initialize(data);

    int tmp, choice, status = 1;
    while(status) {
        printf("Enter your choice:\n");
        printf("1. Insert at beginning\n");
        printf("2. Insert at end\n");
        printf("3. Insert after an element\n");
        printf("4. Delete node at beginning\n");
        printf("5. Delete node at end\n");
        printf("6. Delete a node\n");
        printf("7. Traverse\n");
        printf("8. Length of linked-list\n");
        printf("9. Exit\n");

        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter data to be inserted at beginning: ");
                scanf("%d", &data);
                insert_at_beginning(&head, data);
                break;
            case 2:
                printf("Enter data to be inserted at end: ");
                scanf("%d", &data);
                insert_at_end(&head, data);
                break;
            case 3:
                printf("Enter the element of previous node: ");
                scanf("%d", &tmp);
                printf("Enter data to be inserted: ");
                scanf("%d", &data);
                insert_after_element(&head, tmp, data);
                break;
            case 4:
                delete_from_beginning(&head);
                break;
            case 5:
                delete_from_end(&head);
                break;
            case 6:
                printf("Enter the element of previous node: ");
                scanf("%d", &tmp);
                delete_node(&head, tmp);
                break;
            case 7:
                traverse(&head);
                break;
            case 8:
                printf("Length of linked-list: %d\n", length(&head));
                break;
            case 9:
                status = 0;
                break;
            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}
