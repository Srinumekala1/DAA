#include <stdio.h>
#include <limits.h>
#define N 4  
void assignmentProblem(int cost[N][N]);
int minCost(int cost[N][N], int assigned[], int n, int row, int mask);
void branchAndBound(int cost[N][N], int n, int row, int assigned[], int currentCost, int *minCost, int mask);

int main() {
    int cost[N][N] = {
        {10, 2, 8, 5},
        {6, 7, 12, 10},
        {14, 9, 16, 11},
        {10, 13, 8, 7}
    };
    printf("Cost matrix:\n");
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%d ", cost[i][j]);
        }
        printf("\n");
    }
    assignmentProblem(cost);
    return 0;
}
void assignmentProblem(int cost[N][N]) {
    int assigned[N] = {0};  
    int minCost = INT_MAX; 
    branchAndBound(cost, N, 0, assigned, 0, &minCost, 0);
    printf("Minimum cost: %d\n", minCost);
}
int minCost(int cost[N][N], int assigned[], int n, int row, int mask) {
    int min = INT_MAX;
    int i, j;
    for (i = 0; i < n; i++) {
        if (!(mask & (1 << i))) {
            int costForAssignment = cost[row][i];
            min = (costForAssignment < min) ? costForAssignment : min;
        }
    }
    return min;
}
void branchAndBound(int cost[N][N], int n, int row, int assigned[], int currentCost, int *minCost, int mask) {
    if (row == n) {
        if (currentCost < *minCost) {
            *minCost = currentCost;
        }
        return;
    }
    for (int col = 0; col < n; col++) {
        if (!(mask & (1 << col)) && cost[row][col] != INT_MAX) {
            assigned[row] = col;
            int newMask = mask | (1 << col);
            int newCost = currentCost + cost[row][col];
            branchAndBound(cost, n, row + 1, assigned, newCost, minCost, newMask);
            assigned[row] = -1;
        }
    }
}
