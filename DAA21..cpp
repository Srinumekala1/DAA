#include<stdio.h>
int max(int a, int b) {
    return (a > b) ? a : b;
}
void knapsack(int W, int wt[], int val[], int n) {
    int i, w;
    int K[n+1][W+1]; 
    for (i = 0; i <= n; i++) {
        for (w = 0; w <= W; w++) {
            if (i == 0 || w == 0)
                K[i][w] = 0;
            else if (wt[i-1] <= w)
                K[i][w] = max(val[i-1] + K[i-1][w-wt[i-1]], K[i-1][w]);
            else
                K[i][w] = K[i-1][w];
        }
    }
    printf("Maximum value that can be put in a knapsack of capacity %d: %d\n", W, K[n][W]);
    int result = K[n][W];
    w = W;
    printf("Items included in the knapsack:\n");
    for (i = n; i > 0 && result > 0; i--) {
        if (result == K[i-1][w])
            continue;
        else {
            printf("Item %d (weight = %d, value = %d)\n", i, wt[i-1], val[i-1]);
            result -= val[i-1];
            w -= wt[i-1];
        }
    }
}

int main() {
    int val[] = {60, 100, 120};
    int wt[] = {10, 20, 30};
    int W = 50; 
    int n = sizeof(val) / sizeof(val[0]);

    knapsack(W, wt, val, n);

    return 0;
}
