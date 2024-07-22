#include <stdio.h>
#include <string.h> 
void copyString(char *source, char *destination) {
    if (*source == '\0') {
        *destination = '\0';
        return;
    }
    *destination = *source;
    copyString(source + 1, destination + 1);
}
int main() {
    char source[100], destination[100];
    
    printf("Enter source string: ");
    fgets(source, sizeof(source), stdin);
    source[strcspn(source, "\n")] = '\0';
    copyString(source, destination);
    printf("Source String: %s\n", source);
    printf("Copied String: %s\n", destination);
    return 0;
}
