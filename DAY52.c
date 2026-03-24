//Find the Lowest Common Ancestor (LCA) of two nodes in a Binary Tree.
#include <stdio.h>
#include <stdlib.h>

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

// Build tree from level order
Node* buildTree(int arr[], int n, int i) {
    if (i >= n || arr[i] == -1)
        return NULL;

    Node* root = createNode(arr[i]);

    root->left = buildTree(arr, n, 2*i + 1);
    root->right = buildTree(arr, n, 2*i + 2);

    return root;
}

// Find LCA in Binary Tree
Node* findLCA(Node* root, int n1, int n2) {
    if (root == NULL)
        return NULL;

    // If one of the nodes matches
    if (root->data == n1 || root->data == n2)
        return root;

    Node* left = findLCA(root->left, n1, n2);
    Node* right = findLCA(root->right, n1, n2);

    // If both sides return non-NULL → LCA
    if (left != NULL && right != NULL)
        return root;

    // Else return non-NULL side
    return (left != NULL) ? left : right;
}

int main() {
    int n, n1, n2;
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    scanf("%d %d", &n1, &n2);

    Node* root = buildTree(arr, n, 0);

    Node* lca = findLCA(root, n1, n2);

    if (lca != NULL)
        printf("%d\n", lca->data);

    return 0;
}
