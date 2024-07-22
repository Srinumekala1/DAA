#include <stdio.h>
#include <string.h> // Include string.h for strlen function

// Function to print reverse of a string recursively
void printReverse(char str[], int length) {
    // Base case: If length is 0, return
    if (length == 0) {
        return;
    }
    
    // Print current character and recurse for the rest of the string
    printf("%c", str[length - 1]);
    printReverse(str, length - 1);
}

int main() {
    char str[100];
    
    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);
    
    // Remove newline character if present
    str[strcspn(str, "\n")] = '\0';
    
    // Calculate length of the string
    int length = strlen(str);
    
    // Call function to print reverse of the string recursively
    printf("Reverse of the string: ");
    printReverse(str, length);
    printf("\n");
    
    return 0;
}
