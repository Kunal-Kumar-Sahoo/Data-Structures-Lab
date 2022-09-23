#include <stdio.h>

#define MAX 20

int arr[MAX] = {1};

unsigned long factorial(unsigned int n) {
    if(n <= 1)
        return 1;
    return n * factorial(n-1);
}

int main(void) {
    printf("Enter number: ");
    unsigned int n;
    scanf("%u", &n);

    printf("%u! = %lu\n", n, factorial(n));

    return 0;
}