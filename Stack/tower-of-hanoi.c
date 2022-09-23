#include <stdio.h>

void solve_hanoi(int no_of_discs, char from, char between, char to) {
    if(no_of_discs == 1) {
        printf("Move disc no. %d from %c to %c\n", no_of_discs, from, to);
        return;
    }
    solve_hanoi(no_of_discs-1, from, to, between);
    printf("Move disc no. %d from %c to %c\n", no_of_discs, from, to);
    solve_hanoi(no_of_discs-1, between, from, to);
}

int main(void) {
    printf("Enter number of discs: ");
    int n; scanf("%d", &n);
    solve_hanoi(n, 'A', 'B', 'C');

    return 0;
}