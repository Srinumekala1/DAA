#include <stdio.h>
#include <stdbool.h>
#define V 4  
void printSolution(int color[]);
bool isSafe(int graph[V][V], int color[], int v, int c) {
    for (int i = 0; i < V; i++) {
        if (graph[v][i] && color[i] == c) {
            return false;
        }
    }
    return true;
}
bool graphColoringUtil(int graph[V][V], int m, int color[], int v) {
    if (v == V) {
        return true;
    }
    for (int c = 1; c <= m; c++) {
        if (isSafe(graph, color, v, c)) {
            color[v] = c;
            if (graphColoringUtil(graph, m, color, v + 1)) {
                return true;
            }
            color[v] = 0;  
        }
    }
    return false;
}
bool graphColoring(int graph[V][V], int m) {
    int color[V];
    for (int i = 0; i < V; i++) {
        color[i] = 0;
    }
    if (graphColoringUtil(graph, m, color, 0) == false) {
        printf("Solution does not exist\n");
        return false;
    }
    printSolution(color);
    return true;
}
void printSolution(int color[]) {
    printf("Solution exists: Following are the assigned colors:\n");
    for (int i = 0; i < V; i++) {
        printf("Vertex %d -> Color %d\n", i, color[i]);
    }
}
int main() {
    int graph[V][V] = {
        {0, 1, 1, 1},
        {1, 0, 1, 0},
        {1, 1, 0, 1},
        {1, 0, 1, 0}
    };

    int m;  
    printf("Enter the number of colors: ");
    scanf("%d", &m);
    graphColoring(graph, m);
    return 0;
}
