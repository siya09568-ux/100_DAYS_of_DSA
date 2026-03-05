//Rotate Linked List Right by k Places - Implement using linked list with dynamic memory allocation.
#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

int main() {
    int n, k, i;
    struct node *head = NULL, *temp, *newnode, *last;

    // Input number of nodes
    scanf("%d", &n);

    // Create Linked List
    for(i = 0; i < n; i++) {
        newnode = (struct node*)malloc(sizeof(struct node));
        scanf("%d", &newnode->data);
        newnode->next = NULL;

        if(head == NULL) {
            head = newnode;
            temp = head;
        } else {
            temp->next = newnode;
            temp = newnode;
        }
    }

    // Input k
    scanf("%d", &k);

    // Find last node
    last = head;
    int count = 1;
    while(last->next != NULL) {
        last = last->next;
        count++;
    }

    // Make circular
    last->next = head;

    k = k % count;

    // Move to (n-k)th node
    temp = head;
    for(i = 1; i < count - k; i++) {
        temp = temp->next;
    }

    // New head
    head = temp->next;

    // Break circle
    temp->next = NULL;

    // Print rotated list
    temp = head;
    while(temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }

    return 0;
}
