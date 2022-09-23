#include <stdio.h>
#include <ctype.h>

size_t length(char s[]) {
    size_t len = 0;
    while(s[len++] != '\0');
    return len-1;
}

int check_palindrome(char s[]) {
    size_t len = length(s);
    for(size_t i=0; i<len/2; i++)
        if(tolower(s[i]) != tolower(s[len-i-1]))
            return 0;
    return 1;
}

int main() {    
    char *string;
    printf("Enter a string: ");
    gets(string);
    printf("Entered string is: %s\n", string);

    switch(check_palindrome(string)) {
        case 1:
            printf("%s is a palindrome\n", string);
            break;
        case 0:
            printf("%s is not a palindrome\n", string);
            break;
    }

    return 0;
}