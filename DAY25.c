//Count Occurrences of an Element in Linked List - Implement using linked list with dynamic memory allocation.
#include <stdio.h>
#include <stdlib.h>

// Structure definition
struct Node {
    int data;
    struct Node* next;
};

// Create new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Insert at end
struct Node* insertEnd(struct Node* head, int data) {
    struct Node* newNode = createNode(data);
    
    if(head == NULL)
        return newNode;
    
    struct Node* temp = head;
    while(temp->next != NULL)
        temp = temp->next;
    
    temp->next = newNode;
    return head;
}

// Count occurrences of key
int countOccurrences(struct Node* head, int key) {
    int count = 0;
    struct Node* temp = head;
    
    while(temp != NULL) {
        if(temp->data == key)
            count++;
        temp = temp->next;
    }
    
    return count;
}

int main() {
    int n, value, key;
    struct Node* head = NULL;
    
    scanf("%d", &n);
    
    for(int i = 0; i < n; i++) {
        scanf("%d", &value);
        head = insertEnd(head, value);
    }
    
    scanf("%d", &key);
    
    int result = countOccurrences(head, key);
    
    printf("%d", result);
    
    return 0;
}
