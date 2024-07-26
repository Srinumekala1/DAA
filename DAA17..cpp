#include <stdio.h>
struct Pair {
    int min;
    int max;
};
struct Pair findMinMax(int arr[], int low, int high) {
    struct Pair minmax, leftminmax, rightminmax;
    int mid;
    if (low == high) {
        minmax.min = arr[low];
        minmax.max = arr[low];
        return minmax;
    }
    if (high == low + 1) {
        if (arr[low] < arr[high]) {
            minmax.min = arr[low];
            minmax.max = arr[high];
        } else {
            minmax.min = arr[high];
            minmax.max = arr[low];
        }
        return minmax;
    }
    mid = (low + high) / 2;
    leftminmax = findMinMax(arr, low, mid);
    rightminmax = findMinMax(arr, mid + 1, high);
    if (leftminmax.min < rightminmax.min)
        minmax.min = leftminmax.min;
    else
        minmax.min = rightminmax.min;

    if (leftminmax.max > rightminmax.max)
        minmax.max = leftminmax.max;
    else
        minmax.max = rightminmax.max;

    return minmax;
}

int main() {
    int arr[] = {1000, 11, 445, 1, 330, 3000};
    int size = sizeof(arr) / sizeof(arr[0]);
    struct Pair minmax = findMinMax(arr, 0, size - 1);
    printf("Minimum element in the array: %d\n", minmax.min);
    printf("Maximum element in the array: %d\n", minmax.max);

    return 0;
}
