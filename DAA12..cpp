#include <stdio.h>

// Function to perform binary search
int binarySearch(int arr[], int left, int right, int target) {
    while (left <= right) {
        int mid = left + (right - left) / 2;

        // Check if target is present at mid
        if (arr[mid] == target)
            return mid;

        // If target greater, ignore left half
        if (arr[mid] < target)
            left = mid + 1;
        // If target is smaller, ignore right half
        else
            right = mid - 1;
    }

    // If target is not found in array
    return -1;
}

int main() {
    int arr[] = {2, 3, 4, 10, 40};
    int n = sizeof(arr) / sizeof(arr[0]);
    int target = 10;

    int result = binarySearch(arr, 0, n - 1, target);
    if (result != -1)
        printf("Element %d is present at index %d.\n", target, result);
    else
        printf("Element %d is not present in array.\n", target);

    return 0;
}
