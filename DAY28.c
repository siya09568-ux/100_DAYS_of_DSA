// Circular Linked List Creation and Traversal - Implement using linked list with dynamic memory allocation.
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

int main() {
    int n, i, value;
    struct Node *head = NULL, *temp = NULL, *newnode = NULL;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("List is empty\n");
        return 0;
    }

    // Creating Circular Linked List
    for (i = 0; i < n; i++) {
        scanf("%d", &value);

        newnode = (struct Node*)malloc(sizeof(struct Node));
        newnode->data = value;
        newnode->next = NULL;

        if (head == NULL) {
            head = newnode;
            temp = head;
        } else {
            temp->next = newnode;
            temp = newnode;
        }
    }

    // Make it circular
    temp->next = head;

    // Traversing Circular Linked List
    printf("Circular Linked List: ");

    temp = head;
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != head);

    return 0;
}
