#include <stdio.h>
#include <limits.h>
#include <stdbool.h>
#define N 4  
int tsp(int dist[N][N], int dp[1 << N][N], int visited, int pos) {
    if (visited == (1 << N) - 1) {
        return dist[pos][0];
    }
    if (dp[visited][pos] != -1) {
        return dp[visited][pos];
    }
    int minCost = INT_MAX;
    for (int city = 0; city < N; city++) {
        if ((visited & (1 << city)) == 0) {
            int newCost = dist[pos][city] + tsp(dist, dp, visited | (1 << city), city);
            if (newCost < minCost) {
                minCost = newCost;
            }
        }
    }
    dp[visited][pos] = minCost;
    return minCost;
}
int main() {
    int dist[N][N] = {
        {0, 10, 15, 20},
        {10, 0, 35, 25},
        {15, 35, 0, 30},
        {20, 25, 30, 0}
    };
    int dp[1 << N][N];
    for (int i = 0; i < (1 << N); i++) {
        for (int j = 0; j < N; j++) {
            dp[i][j] = -1;
        }
    }
    int minCost = tsp(dist, dp, 1, 0);
    printf("The minimum cost of the TSP tour is: %d\n", minCost);
    return 0;
}
