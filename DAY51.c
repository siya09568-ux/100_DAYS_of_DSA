//Find the Lowest Common Ancestor (LCA) of two nodes in a Binary Search Tree.
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

// Insert into BST
Node* insert(Node* root, int data) {
    if (root == NULL)
        return createNode(data);

    if (data < root->data)
        root->left = insert(root->left, data);
    else
        root->right = insert(root->right, data);

    return root;
}

// Find LCA in BST
Node* findLCA(Node* root, int n1, int n2) {
    if (root == NULL)
        return NULL;

    // If both smaller → go left
    if (n1 < root->data && n2 < root->data)
        return findLCA(root->left, n1, n2);

    // If both greater → go right
    if (n1 > root->data && n2 > root->data)
        return findLCA(root->right, n1, n2);

    // Split point → LCA
    return root;
}

int main() {
    int n, x, n1, n2;
    scanf("%d", &n);

    Node* root = NULL;

    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        root = insert(root, x);
    }

    scanf("%d %d", &n1, &n2);

    Node* lca = findLCA(root, n1, n2);

    if (lca != NULL)
        printf("%d\n", lca->data);

    return 0;
}
