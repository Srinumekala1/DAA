#include <stdio.h>
#include <stdbool.h> 
bool isPrime(int n, int divisor) {
    if (n <= 1) {
        return false;
    }
    if (divisor == 1) {
        return true;
    }
    if (n % divisor == 0) {
        return false;
    }
    return isPrime(n, divisor - 1);
}
void printPrimes(int start, int end) {
    if (start <= end) {
        if (isPrime(start, start / 2)) {
            printf("%d ", start);
        }
        printPrimes(start + 1, end);
    }
}

int main() {
    int start, end;

    printf("Enter the range (start and end): ");
    scanf("%d %d", &start, &end);

    printf("Prime numbers between %d and %d are: ", start, end);
    printPrimes(start, end);
    printf("\n");

    return 0;
}
