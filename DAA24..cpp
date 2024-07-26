#include <stdio.h>
int reverseNumber(int num) {
    if (num < 10) {
        return num;
    }
    int lastDigit = num % 10;
    int remainingDigits = num / 10;
    int reversedNum = reverseNumber(remainingDigits);
    int result = lastDigit;
    while (reversedNum >= 10) {
        lastDigit = reversedNum % 10;
        result = result * 10 + lastDigit;
        reversedNum = reversedNum / 10;
    }
    result = result * 10 + reversedNum;

    return result;
}

int main() {
    int num;
    printf("Enter a number to reverse: ");
    scanf("%d", &num);

    int reversed = reverseNumber(num);

    printf("Reverse of %d is: %d\n", num, reversed);

    return 0;
}
