#include <stdio.h>
#include <stdlib.h>

#define MAX 1000

typedef struct Node {
    int data;
    struct Node *left, *right;
} Node;

// Create node
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
Node* queue[MAX];
int front = 0, rear = 0;

void enqueue(Node* node) {
    queue[rear++] = node;
}

Node* dequeue() {
    return queue[front++];
}

int isEmpty() {
    return front == rear;
}

// Zigzag traversal
void zigzagTraversal(Node* root) {
    if (root == NULL)
        return;

    enqueue(root);
    int leftToRight = 1;

    while (!isEmpty()) {
        int size = rear - front;
        int level[size];

        // Store current level
        for (int i = 0; i < size; i++) {
            Node* curr = dequeue();

            int index = leftToRight ? i : (size - 1 - i);
            level[index] = curr->data;

            if (curr->left)
                enqueue(curr->left);
            if (curr->right)
                enqueue(curr->right);
        }

        // Print level
        for (int i = 0; i < size; i++)
            printf("%d ", level[i]);

        leftToRight = !leftToRight;
    }
}

int main() {
    int n;
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    Node* root = buildTree(arr, n, 0);

    zigzagTraversal(root);

    return 0;
}
