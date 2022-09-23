/*
        1
      1 3 1 
    1 3 5 3 1
*/

#include <stdio.h>

void draw(unsigned int rows) {
    for(int i=0; i<rows; i++) {
        // spaces
        for(int j=0; j<rows-i; j++)
            printf("  ");
        // numbers first half
        for(int j=1; j<=2*i+1; j+=2)
            printf("%d ", j);
        // numbers second half
        for(int j=2*i-1; j>0; j-=2)
            printf("%d ", j);
        // newline
        printf("\n");
    }

}

int main() {
    printf("Enter number of rows: ");
    unsigned int rows;
    scanf("%u", &rows);

    draw(rows);

    return 0;
}