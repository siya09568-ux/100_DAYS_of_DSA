#include <stdio.h>
#include <stdlib.h>

#define MAX 1000

// Tree Node
typedef struct Node {
    int data;
    struct Node *left, *right;
} Node;

// Queue Node (for BFS with HD)
typedef struct QNode {
    Node* node;
    int hd;
} QNode;

// Create new node
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Build tree
Node* buildTree(int arr[], int n, int i) {
    if (i >= n || arr[i] == -1)
        return NULL;

    Node* root = createNode(arr[i]);
    root->left = buildTree(arr, n, 2*i + 1);
    root->right = buildTree(arr, n, 2*i + 2);

    return root;
}

// Simple queue
QNode queue[MAX];
int front = 0, rear = 0;

void enqueue(Node* node, int hd) {
    queue[rear].node = node;
    queue[rear].hd = hd;
    rear++;
}

QNode dequeue() {
    return queue[front++];
}

int isEmpty() {
    return front == rear;
}

// Vertical Order Traversal
void verticalOrder(Node* root) {
    if (root == NULL)
        return;

    // To store nodes by HD
    int map[MAX][MAX];
    int count[MAX] = {0};

    int offset = MAX / 2; // to handle negative HD

    enqueue(root, 0);

    while (!isEmpty()) {
        QNode temp = dequeue();
        Node* curr = temp.node;
        int hd = temp.hd + offset;

        map[hd][count[hd]++] = curr->data;

        if (curr->left)
            enqueue(curr->left, temp.hd - 1);

        if (curr->right)
            enqueue(curr->right, temp.hd + 1);
    }

    // Print from leftmost to rightmost
    for (int i = 0; i < MAX; i++) {
        if (count[i] > 0) {
            for (int j = 0; j < count[i]; j++)
                printf("%d ", map[i][j]);
            printf("\n");
        }
    }
}

int main() {
    int n;
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    Node* root = buildTree(arr, n, 0);

    verticalOrder(root);

    return 0;
}
