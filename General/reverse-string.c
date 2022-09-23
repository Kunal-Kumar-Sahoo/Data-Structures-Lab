#include <stdio.h>

#define MAX 50

size_t length(char s[]) {
    size_t len = 0;
    while(s[len++] != '\0');
    return len-1;
}

void swap(char *a, char *b) {
    char tmp = *a;
    *a = *b;
    *b = tmp;
}

void reverse(char s[]) {
    size_t len = length(s);
    for(int i=0; i<len/2; i++)
        swap(s+i, s+len-i-1);
}

int main(void) {
    char str[MAX];
    printf("Enter a string: ");
    gets(str);

    printf("Original string: %s\n", str);
    reverse(str);
    printf("Reversed string: %s\n", str);

    return 0;
}