#include <stdio.h>
#include <limits.h>

#define CAPACITY 7

void traverse(int arr[], unsigned int n) {
    for(int i=0; i<n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

unsigned int insert(int arr[], unsigned int n, unsigned int idx, int key) {
    if(idx > n) {
        printf("Index out of bound\n");
        return n;
    }
    else {
        if(n < CAPACITY) {
            for(int i=n-1; i>= idx; i--)
                arr[i+1] = arr[i];
            arr[idx] = key;
            printf("%d inserted at %u index in the array.\n", key, idx);
            return n+1;
        }
        else {
             printf("Array is full\n");
             return n;
        }
    }
}

void update(int arr[], unsigned int n, unsigned int idx, int key) {
    if(idx >= n)
        printf("Index out of bound\n");
    else {
        arr[idx] = key;
        printf("%d updated at index %u in the array.\n", key, idx);
    }
}

int search(int arr[], unsigned int n, unsigned int idx) {
    if(n <= 0) return INT_MIN;
    if(idx >= n) return INT_MAX;
    return arr[idx];
}

int delete(int arr[], unsigned int n, unsigned int idx) {
    if(n <= 0) {
        printf("Array is empty\n");
        return n;
    }
    if(idx >= n) {
        printf("Index out of bound\n");
        return n;
    }
    for(int i=idx+1; i<n; i++)
        arr[i-1] = arr[i];
    printf("Element at index %u deleted\n", idx);
    return n-1;
}

int main(void) {
    printf("Enter length of array: ");
    unsigned int n; scanf("%d", &n);

    if(n >= CAPACITY) {
        printf("Length is out of bound. Creating an array of capacity %d\n", CAPACITY);
        n = CAPACITY;
    }

    int arr[CAPACITY];

    printf("Enter %d elements in the array:\n", n);
    for(unsigned int i=0; i<n; i++)
        scanf("%d", (arr+i));

    int status = 1;

    while(status) {
        printf("Enter your choice:\n");
        printf("1: Traverse\n");
        printf("2: Insert\n");
        printf("3: Update\n");
        printf("4: Search\n");
        printf("5: Delete\n");
        printf("0: Exit\n:");

        scanf("%d", &status);

        switch(status) {
            case 1:
                traverse(arr, n);
                break;
            case 2:
                printf("Enter index and element that has to be inserted:\n");
                size_t idx; int x;
                scanf("%u %d", &idx, &x);
                n = insert(arr, n, idx, x);
                break;
            case 3:
                printf("Enter index and element that have to be updated:\n");
                size_t idx; int x;
                scanf("%u %d", &idx, &x);
                update(arr, n, idx, x);
                break;
            case 4:
                printf("Enter index whose value is to be fetched:\n");
                size_t idx; scanf("%u", &idx);
                int x = search(arr, n, idx);

                switch(x) {
                    case INT_MIN:
                        printf("Array is empty\n");
                        break;
                    case INT_MAX:
                        printf("Index out of bound\n");
                        break;
                    default:
                        printf("Element at index %u: %d\n", idx, x);
                }
            case 5:
                printf("Enter index whose item is to be deleted: ");
                size_t idx; scanf("%u", &idx);
                n = delete(arr, n, idx);
                break;
            case 0:
                status = 0;
                break;
            default:
                printf("Invalid choice\n");
        }

    }

    return 0;
}