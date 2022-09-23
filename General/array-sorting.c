#include <stdio.h>

void input_elements(int *arr, int n) {
    for(int i=0; i<n; i++)
        scanf("%d", arr+i);
}

void print_array(int *arr, int n) {
    for(int i=0; i<n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

void swap(int *a, int *b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void sort_asc(int *arr, int n) {
    int swapped;
    for(int i=0; i<n; i++) {
        swapped = 0;
        for(int j=1; j<n-i; j++)
            if(arr[j-1] > arr[j]) {
                swap(arr+j-1, arr+j);
                swapped = 1;
            }
        if(!swapped) break;
    }
}

void sort_desc(int *arr, int n) {
    int swapped;
    for(int i=0; i<n; i++) {
        swapped = 0;
        for(int j=1; j<n-i; j++)
            if(arr[j-1] < arr[j]) {
                swap(arr+j-1, arr+j);
                swapped = 1;
            }
        if(!swapped) break;
    }
}

int main(void) {
    printf("Enter size of the array: ");
    size_t size;
    scanf("%d", &size);
    int arr[size];

    printf("Enter elements for the array:\n");
    input_elements(arr, size);

    printf("Original array: ");
    print_array(arr, size);

    printf("Enter choice:\n1: Sorting in increasing order\n2: Sorting in decreasing order\n:");
    int choice; scanf("%d", &choice);

    switch(choice) {
        case 1:
            sort_asc(arr, size);
            break;
        case 2:
            sort_desc(arr, size);
            break;
        default:
            printf("Invalid choice!\n");
            return 0;
    }

    printf("Sorted array: ");
    print_array(arr, size);

    return 0;
}