#include <stdio.h>
#include <limits.h>

// Function to find minimum of two values
int min(int a, int b) {
    return (a < b) ? a : b;
}

// Function to find optimal BST cost using dynamic programming
int optimalBST(int keys[], int freq[], int n) {
    // Create a 2D array to store computed costs
    int cost[n][n];

    // Initialize all costs as 0
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cost[i][j] = 0;
        }
    }

    // Compute cost for single keys (diagonal elements)
    for (int i = 0; i < n; i++) {
        cost[i][i] = freq[i];
    }

    // Build the cost array using dynamic programming approach
    // l is chain length
    for (int l = 2; l <= n; l++) { // corrected loop condition: l <= n
        for (int i = 0; i <= n - l; i++) { // corrected loop condition: i <= n - l
            int j = i + l - 1;
            cost[i][j] = INT_MAX;

            // Try making all keys in keys[i..j] as root
            for (int k = i; k <= j; k++) {
                // Cost when keys[k] becomes root of this subtree
                int c = ((k > i) ? cost[i][k - 1] : 0) +
                        ((k < j) ? cost[k + 1][j] : 0) +
                        sum(freq, i, j);
                if (c < cost[i][j]) {
                    cost[i][j] = c;
                }
            }
        }
    }

    // Return the computed optimal BST cost
    return cost[0][n - 1];
}

// Function to calculate sum of frequencies between indices i and j
int sum(int freq[], int i, int j) {
    int s = 0;
    for (int k = i; k <= j; k++) {
        s += freq[k];
    }
    return s;
}

int main() {
    int keys[] = {10, 12, 20};
    int freq[] = {34, 8, 50};
    int n = sizeof(keys) / sizeof(keys[0]);

    int optimalCost = optimalBST(keys, freq, n);

    printf("Optimal BST cost: %d\n", optimalCost);

    return 0;
}
