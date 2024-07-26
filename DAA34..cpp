#include <stdio.h>
#define MAX_SIZE 100  
void insertInSortedArray(int arr[], int *size, int num) {
    int i, j;
    for (i = 0; i < *size; i++) {
        if (arr[i] > num) {
            break;
        }
    }
    for (j = *size; j > i; j--) {
        arr[j] = arr[j - 1];
    }
    arr[i] = num;
    (*size)++; 
}
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
int main() {
    int arr[MAX_SIZE];
    int size = 0;
    int num, position;
    arr[size++] = 1;
    arr[size++] = 3;
    arr[size++] = 5;
    arr[size++] = 7;
    arr[size++] = 9;
    printf("Current array: ");
    printArray(arr, size);
    printf("Enter a number to insert: ");
    scanf("%d", &num);
    insertInSortedArray(arr, &size, num);
    printf("Array after insertion: ");
    printArray(arr, size);
    return 0;
}
