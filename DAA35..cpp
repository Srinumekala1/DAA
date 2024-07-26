#include <stdio.h>
#define MAX_SIZE 100
void printSubset(int subset[], int subsetSize) {
    printf("{ ");
    for (int i = 0; i < subsetSize; i++) {
        printf("%d ", subset[i]);
    }
    printf("}\n");
}
void findSubsets(int arr[], int n, int target, int index, int subset[], int subsetSize) {
    if (target == 0) {
        printSubset(subset, subsetSize);
        return;
    }
    if (index >= n || target < 0) {
        return;
    }
    subset[subsetSize] = arr[index];
    findSubsets(arr, n, target - arr[index], index + 1, subset, subsetSize + 1);
    findSubsets(arr, n, target, index + 1, subset, subsetSize);
}
int main() {
    int arr[MAX_SIZE];
    int n, target;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    printf("Enter the elements:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    printf("Enter the target sum: ");
    scanf("%d", &target);
    int subset[MAX_SIZE];
    printf("Subsets that sum to %d are:\n", target);
    findSubsets(arr, n, target, 0, subset, 0);
    return 0;
}
