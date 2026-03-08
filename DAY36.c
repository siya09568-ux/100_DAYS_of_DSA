//Circular Queue Using Array - Implement using linked list with dynamic memory allocation.
#include <stdio.h>

#define MAX 100

int queue[MAX];
int front = -1, rear = -1;

// Enqueue
void enqueue(int value)
{
    if(front == -1)  // first element
        front = 0;

    rear = (rear + 1) % MAX;
    queue[rear] = value;
}

// Dequeue
void dequeue()
{
    if(front == -1)
        return;

    if(front == rear)   // only one element
    {
        front = rear = -1;
    }
    else
    {
        front = (front + 1) % MAX;
    }
}

// Display queue
void display()
{
    int i = front;

    if(front == -1)
        return;

    while(1)
    {
        printf("%d ", queue[i]);
        if(i == rear)
            break;

        i = (i + 1) % MAX;
    }
}

int main()
{
    int n, m, i, x;

    scanf("%d", &n);

    // Enqueue elements
    for(i = 0; i < n; i++)
    {
        scanf("%d", &x);
        enqueue(x);
    }

    // Number of dequeue operations
    scanf("%d", &m);

    for(i = 0; i < m; i++)
        dequeue();

    // Display remaining queue
    display();

    return 0;
}
