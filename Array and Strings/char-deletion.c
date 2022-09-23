#include <stdio.h>
#include <ctype.h>

#define MAX 50

void delete_char(char s[], char c) {
    for(size_t i=0; s[i]!='\0'; i++)
        if(tolower(s[i]) == tolower(c)) {
            for(size_t j=i; s[j]!='\0'; j++)
                s[j] = s[j+1];
            i--;
        }
        
}

int main(void) {
    char string[MAX], c;

    printf("Enter a string: ");
    gets(string);

    printf("Enter a character to be deleted: ");
    c = getchar();

    printf("Original string: %s\n", string);
    delete_char(string, c);
    printf("New string: %s\n", string);

    return 0;
}
