#include <stdio.h>
#include <stdlib.h>

// Tree Node
typedef struct Node {
    int data;
    struct Node *left, *right;
} Node;

// Queue Node
typedef struct Queue {
    Node* data;
    struct Queue* next;
} Queue;

Queue *front = NULL, *rear = NULL;

// Create new tree node
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Enqueue
void enqueue(Node* node) {
    Queue* temp = (Queue*)malloc(sizeof(Queue));
    temp->data = node;
    temp->next = NULL;

    if (rear == NULL) {
        front = rear = temp;
        return;
    }

    rear->next = temp;
    rear = temp;
}

// Dequeue
Node* dequeue() {
    if (front == NULL)
        return NULL;

    Queue* temp = front;
    Node* node = temp->data;
    front = front->next;

    if (front == NULL)
        rear = NULL;

    free(temp);
    return node;
}

// Check if queue is empty
int isEmpty() {
    return front == NULL;
}

// Build tree from level order
Node* buildTree(int arr[], int n, int i) {
    if (i >= n || arr[i] == -1)
        return NULL;

    Node* root = createNode(arr[i]);

    root->left = buildTree(arr, n, 2*i + 1);
    root->right = buildTree(arr, n, 2*i + 2);

    return root;
}

// Level Order Traversal
void levelOrder(Node* root) {
    if (root == NULL)
        return;

    enqueue(root);

    while (!isEmpty()) {
        Node* curr = dequeue();
        printf("%d ", curr->data);

        if (curr->left)
            enqueue(curr->left);

        if (curr->right)
            enqueue(curr->right);
    }
}

int main() {
    int n;
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    Node* root = buildTree(arr, n, 0);

    levelOrder(root);

    return 0;
}
