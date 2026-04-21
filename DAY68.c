#include <stdio.h>

#define MAX 100

int adj[MAX][MAX];
int indegree[MAX];
int queue[MAX];
int n;

// Function for Kahn's Algorithm
void topoSort() {
    int front = 0, rear = -1;

    // Step 1: Calculate indegree
    for (int i = 0; i < n; i++) {
        indegree[i] = 0;
        for (int j = 0; j < n; j++) {
            if (adj[j][i] == 1) {
                indegree[i]++;
            }
        }
    }

    // Step 2: Add vertices with indegree 0 to queue
    for (int i = 0; i < n; i++) {
        if (indegree[i] == 0) {
            queue[++rear] = i;
        }
    }

    printf("Topological Order: ");

    int count = 0;

    // Step 3: Process queue
    while (front <= rear) {
        int v = queue[front++];
        printf("%d ", v);
        count++;

        // Reduce indegree of adjacent vertices
        for (int i = 0; i < n; i++) {
            if (adj[v][i] == 1) {
                indegree[i]--;
                if (indegree[i] == 0) {
                    queue[++rear] = i;
                }
            }
        }
    }

    // Step 4: Check for cycle
    if (count != n) {
        printf("\nGraph has a cycle! Topological sort not possible.\n");
    }
}

int main() {
    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &adj[i][j]);
        }
    }

    topoSort();

    return 0;
}
