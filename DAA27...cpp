#include <stdio.h>
void printSpaces(int spaces) {
    if (spaces > 0) {
        printf(" ");
        printSpaces(spaces - 1);
    }
}
void printStars(int stars) {
    if (stars > 0) {
        printf("*");
        printStars(stars - 1);
    }
}
void printRow(int n, int row) {
    if (row > 0) {
        printSpaces(n - row);
        printStars(2 * row - 1);
        printf("\n");
        printRow(n, row - 1);
    }
}
int main() {
    int n;
    printf("Enter the number of rows for the pyramid: ");
    scanf("%d", &n);
    printRow(n, n);
    return 0;
}
