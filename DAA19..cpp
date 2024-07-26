#include <stdio.h>
struct Item {
    int value;
    int weight;
};
int compare(const void *a, const void *b) {
    double ratio1 = (double)(((struct Item *)a)->value) / (((struct Item *)a)->weight);
    double ratio2 = (double)(((struct Item *)b)->value) / (((struct Item *)b)->weight);
    return (ratio2 > ratio1) - (ratio2 < ratio1); // Compare in descending order of ratios
}
void knapsack(struct Item items[], int n, int capacity) {
    qsort(items, n, sizeof(struct Item), compare);
    int currentWeight = 0; 
    double totalValue = 0.0; 
    for (int i = 0; i < n; i++) {
        if (currentWeight + items[i].weight <= capacity) {
            currentWeight += items[i].weight;
            totalValue += items[i].value;
            printf("Added item with value %d and weight %d\n", items[i].value, items[i].weight);
        } else {
            int remainingCapacity = capacity - currentWeight;
            totalValue += items[i].value * ((double)remainingCapacity / items[i].weight);
            printf("Added item with value %d and weight %d (fraction)\n", items[i].value, items[i].weight);
            break; 
        }
    }
    printf("Total value in knapsack: %.2f\n", totalValue);
}

int main() {
    struct Item items[] = {{60, 10}, {100, 20}, {120, 30}};
    int n = sizeof(items) / sizeof(items[0]);
    int capacity = 50;

    printf("Items available:\n");
    for (int i = 0; i < n; i++) {
        printf("Item %d: Value = %d, Weight = %d\n", i + 1, items[i].value, items[i].weight);
    }

    printf("\nKnapsack capacity: %d\n", capacity);
    printf("\nGreedy approach to Knapsack problem:\n");
    knapsack(items, n, capacity);

    return 0;
}
