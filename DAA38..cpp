#include <stdio.h>
void printFactors(int n, int divisor) {
    if (divisor > n) {
        return;
    }
    if (n % divisor == 0) {
        printf("%d ", divisor);
    }
    printFactors(n, divisor + 1);
}
int main() {
    int n;
    printf("Enter a number to find its factors: ");
    scanf("%d", &n);
    if (n <= 0) {
        printf("Number should be greater than 0.\n");
        return 1;
    }
    printf("Factors of %d are: ", n);
    printFactors(n, 1);
    printf("\n");
    return 0;
}
