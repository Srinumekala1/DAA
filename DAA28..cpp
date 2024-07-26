#include <stdio.h>
void printNumbers(int i) {
    if (i > 0) {
        printNumbers(i - 1); 
        printf("%d ", i);
    }
}
void printPattern(int n, int currentRow) {
    if (currentRow <= n) {
        printNumbers(currentRow); 
        printf("\n");
        printPattern(n, currentRow + 1); 
    }
}
int main() {
    int n = 4; 
    printPattern(n, 1);
    return 0;
}
