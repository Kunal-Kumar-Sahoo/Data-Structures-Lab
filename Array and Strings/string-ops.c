#include <stdio.h>

#define MAX 100

size_t length(char s[]) {
    int i = 0;
    while(s[i++] != '\0');
    return i-1;
}

void reverse(char s[]) {
    size_t len = length(s);
    char temp;
    for(size_t i=0; i<len/2; i++) {
        temp = s[i];
        s[i] = s[len-i-1];
        s[len-i-1] = temp;
    }
}

void concat(char s1[], char s2[]) {
    size_t len1 = length(s1);
    size_t len2 = length(s2);
    if(len1+len2 > MAX) {
        printf("Buffer overflow\n");
        return;
    }
    for(size_t i=0; i<len2; i++)
        s1[len1+i] = s2[i];
}

int main(void) {
    char str1[MAX];
    printf("Enter a string: ");
    gets(str1);

    printf("Length of string: %u\n", length(str1));

    reverse(str1);
    printf("Reverse of string: %s\n", str1);
    reverse(str1);

    concat(str1, " World");
    printf("New string: %s\n", str1);

    return 0;
}