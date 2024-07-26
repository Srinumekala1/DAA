#include <stdio.h>
void sortItems(int items[], int n) {
    int i, j, temp;
    for (i = 0; i < n-1; i++) {
        for (j = i+1; j < n; j++) {
            if (items[i] > items[j]) {
                temp = items[i];
                items[i] = items[j];
                items[j] = temp;
            }
        }
    }
}
int computeMaxItems(int items[], int n, int capacity) {
    int currentWeight = 0;
    int count = 0;

    for (int i = 0; i < n; i++) {
        if (currentWeight + items[i] <= capacity) {
            currentWeight += items[i];
            count++;
        } else {
            break;
        }
    }
    return count;
}
int main() {
    int n; 
    int capacity; 
    printf("Enter the number of items: ");
    scanf("%d", &n);
    int items[n];
    printf("Enter the weights of the items:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &items[i]);
    }
    printf("Enter the capacity of the container: ");
    scanf("%d", &capacity);
    sortItems(items, n);
    int maxItems = computeMaxItems(items, n, capacity);
    printf("Maximum number of items that can be loaded: %d\n", maxItems);
    return 0;
}
