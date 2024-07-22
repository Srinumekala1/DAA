#include <stdio.h>
#include <string.h>
void printReverse(char str[], int length) {
    if (length == 0) {
        return;
    }
    printf("%c", str[length - 1]);
    printReverse(str, length - 1);
}

int main() {
    char str[100];
    
    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);
    str[strcspn(str, "\n")] = '\0';
    int length = strlen(str);
    printf("Reverse of the string: ");
    printReverse(str, length);
    printf("\n"); 
    return 0;
}
