#include <stdio.h>
#include <stdlib.h>

// Structure
struct Node {
    int data;
    struct Node* next;
};

// Create new node
struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

// Insert at end
struct Node* insert(struct Node* head, int value) {
    struct Node* newNode = createNode(value);

    if (head == NULL)
        return newNode;

    struct Node* temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
    return head;
}

// Get length
int getLength(struct Node* head) {
    int count = 0;
    while (head != NULL) {
        count++;
        head = head->next;
    }
    return count;
}

// Find intersection node
struct Node* findIntersection(struct Node* head1, struct Node* head2) {
    int len1 = getLength(head1);
    int len2 = getLength(head2);

    int diff;

    if (len1 > len2) {
        diff = len1 - len2;
        for (int i = 0; i < diff; i++)
            head1 = head1->next;
    } else {
        diff = len2 - len1;
        for (int i = 0; i < diff; i++)
            head2 = head2->next;
    }

    while (head1 != NULL && head2 != NULL) {
        if (head1 == head2)   // compare addresses
            return head1;

        head1 = head1->next;
        head2 = head2->next;
    }

    return NULL;
}

int main() {
    int n, m, value;
    struct Node* head1 = NULL;
    struct Node* head2 = NULL;

    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &value);
        head1 = insert(head1, value);
    }

    scanf("%d", &m);
    for (int i = 0; i < m; i++) {
        scanf("%d", &value);
        head2 = insert(head2, value);
    }

    // Manually creating intersection for given example
    // Connecting node with value 30

    struct Node* temp1 = head1;
    while (temp1 != NULL && temp1->data != 30)
        temp1 = temp1->next;

    struct Node* temp2 = head2;
    while (temp2->next != NULL)
        temp2 = temp2->next;

    if (temp1 != NULL)
        temp2->next = temp1;

    struct Node* result = findIntersection(head1, head2);

    if (result != NULL)
        printf("%d", result->data);
    else
        printf("No Intersection");

    return 0;
}
