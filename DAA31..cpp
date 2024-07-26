#include <stdio.h>
#include <stdlib.h> 
int main() {
    int number, sum = 0, temp;
    printf("Enter an integer: ");
    scanf("%d", &number);
    temp = abs(number);
    while (temp > 0) {
        sum += temp % 10;  
        temp /= 10;        
    }
    printf("The sum of the digits is: %d\n", sum);
    return 0;
}
