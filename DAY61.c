#include <stdio.h>

#define MAX 100

int main() {
    int n, m;
    int adj[MAX][MAX];

    // Input number of vertices and edges
    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter number of edges: ");
    scanf("%d", &m);

    // Initialize matrix with 0
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            adj[i][j] = 0;
        }
    }

    int directed;
    printf("Enter 1 for Directed graph, 0 for Undirected graph: ");
    scanf("%d", &directed);

    // Input edges
    printf("Enter %d edges (u v):\n", m);
    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);

        adj[u][v] = 1;

        if (!directed) {
            adj[v][u] = 1; // for undirected graph
        }
    }

    // Print adjacency matrix
    printf("\nAdjacency Matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", adj[i][j]);
        }
        printf("\n");
    }

    return 0;
}
