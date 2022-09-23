// abcd, efgh -> aebfcgdh

#include <stdio.h>

#define MAX 50

size_t length(char s[]) {
    size_t len = 0;
    while(s[len++] != '\0');
    return len-1;
}

void join(char s1[], char s2[]) {
    if(length(s1) != length(s2)) {
        printf("Cannot join since both strings are of different lengths\n");
        return;
    }
    for(int i=0; s1[i]!='\0'; i++)
        printf("%c%c", s1[i], s2[i]);
    printf("\n");
}

int main() {
    char s1[MAX], s2[MAX];
    printf("Enter two strings: ");
    scanf("%s", s1); getchar(); // getchar() to handle '\n'
    scanf("%s", s2);

    join(s1, s2);

    return 0;
}