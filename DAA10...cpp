#include <stdio.h>
#include <stdbool.h>
#include <string.h>

// Function to check if a string is palindrome recursively
bool isPalindrome(char str[], int start, int end) {
    // Base case: If there is only one character
    if (start >= end) {
        return true;
    }
    
    // If characters at start and end are not equal
    if (str[start] != str[end]) {
        return false;
    }
    
    // Recursively check substring
    return isPalindrome(str, start + 1, end - 1);
}

int main() {
    char str[100];
    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);
    
    // Remove newline character if present
    str[strcspn(str, "\n")] = '\0';

    int len = strlen(str);
    
    if (isPalindrome(str, 0, len - 1)) {
        printf("%s is a palindrome.\n", str);
    } else {
        printf("%s is not a palindrome.\n", str);
    }
    
    return 0;
}
