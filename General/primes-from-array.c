#include <stdio.h>
#include <math.h>

void input_elements(int arr[], size_t n) {
    for(size_t i=0; i<n; i++)
        scanf("%d", arr+i);
}

int check_prime(int x) {
    if(x <= 1) return 0;
    for(int i=2; i<=sqrt(x); i++)
        if(x % i == 0)
            return 0;
    return 1;
}

void print_prime(int arr[], size_t n) {
    for(size_t i=0; i<n; i++)
        if(check_prime(arr[i]))
            printf("%d ", arr[i]);
    printf("\n");
}

int main(void) {
    printf("Enter size of the array: ");
    size_t n; scanf("%d", &n);

    unsigned int arr[n];
    printf("Enter elements of the array:\n");
    input_elements(arr, n);

    printf("Prime elements are: ");
    print_prime(arr, n);

    return 0;
}