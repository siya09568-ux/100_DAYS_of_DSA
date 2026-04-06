#include <stdio.h>
#include <stdlib.h>

#define MAX 100

// Node structure
struct Node {
    int vertex;
    struct Node* next;
};

// Graph structure
struct Graph {
    int numVertices;
    struct Node** adjLists;
};

// Queue structure
struct Queue {
    int items[MAX];
    int front, rear;
};

// Create queue
struct Queue* createQueue() {
    struct Queue* q = (struct Queue*)malloc(sizeof(struct Queue));
    q->front = -1;
    q->rear = -1;
    return q;
}

// Check empty
int isEmpty(struct Queue* q) {
    return q->front == -1;
}

// Enqueue
void enqueue(struct Queue* q, int value) {
    if (q->rear == MAX - 1) return;

    if (q->front == -1)
        q->front = 0;

    q->items[++q->rear] = value;
}

// Dequeue
int dequeue(struct Queue* q) {
    int item = q->items[q->front];

    if (q->front >= q->rear) {
        q->front = q->rear = -1;
    } else {
        q->front++;
    }

    return item;
}

// Create node
struct Node* createNode(int v) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

// Create graph
struct Graph* createGraph(int vertices) {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->numVertices = vertices;

    graph->adjLists = (struct Node**)malloc(vertices * sizeof(struct Node*));

    for (int i = 0; i < vertices; i++)
        graph->adjLists[i] = NULL;

    return graph;
}

// Add edge (undirected)
void addEdge(struct Graph* graph, int src, int dest) {
    struct Node* newNode = createNode(dest);
    newNode->next = graph->adjLists[src];
    graph->adjLists[src] = newNode;

    newNode = createNode(src);
    newNode->next = graph->adjLists[dest];
    graph->adjLists[dest] = newNode;
}

// BFS function
void bfs(struct Graph* graph, int start) {
    int visited[MAX] = {0};

    struct Queue* q = createQueue();

    visited[start] = 1;
    enqueue(q, start);

    while (!isEmpty(q)) {
        int current = dequeue(q);
        printf("%d ", current);

        struct Node* temp = graph->adjLists[current];

        while (temp) {
            int adjVertex = temp->vertex;

            if (!visited[adjVertex]) {
                visited[adjVertex] = 1;
                enqueue(q, adjVertex);
            }

            temp = temp->next;
        }
    }
}

int main() {
    int n, m;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter number of edges: ");
    scanf("%d", &m);

    struct Graph* graph = createGraph(n);

    printf("Enter edges (u v):\n");
    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        addEdge(graph, u, v);
    }

    int start;
    printf("Enter starting vertex: ");
    scanf("%d", &start);

    printf("BFS Traversal: ");
    bfs(graph, start);
    printf("\n");

    return 0;
}
