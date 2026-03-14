/*A Deque is a linear data structure that allows insertion and deletion of elements from both the front and the rear.
It provides more flexibility than a standard queue or stack.*/
#include <stdio.h>

#define MAX 100

int deque[MAX];
int front = -1, rear = -1;

void push_front(int x)
{
    if(front == 0)
    {
        printf("Deque Overflow\n");
        return;
    }

    if(front == -1)
    {
        front = rear = 0;
    }
    else
    {
        front--;
    }

    deque[front] = x;
}

void push_back(int x)
{
    if(rear == MAX-1)
    {
        printf("Deque Overflow\n");
        return;
    }

    if(front == -1)
    {
        front = rear = 0;
    }
    else
    {
        rear++;
    }

    deque[rear] = x;
}

void pop_front()
{
    if(front == -1)
    {
        printf("-1\n");
        return;
    }

    printf("%d\n", deque[front]);

    if(front == rear)
        front = rear = -1;
    else
        front++;
}

void pop_back()
{
    if(rear == -1)
    {
        printf("-1\n");
        return;
    }

    printf("%d\n", deque[rear]);

    if(front == rear)
        front = rear = -1;
    else
        rear--;
}

void show_front()
{
    if(front == -1)
        printf("-1\n");
    else
        printf("%d\n", deque[front]);
}

void show_back()
{
    if(rear == -1)
        printf("-1\n");
    else
        printf("%d\n", deque[rear]);
}

int empty()
{
    if(front == -1)
        return 1;
    return 0;
}

int size()
{
    if(front == -1)
        return 0;
    return rear - front + 1;
}

int main()
{
    push_back(10);
    push_back(20);
    push_front(5);

    show_front();   // 5
    show_back();    // 20

    pop_front();    // removes 5
    pop_back();     // removes 20

    printf("Size: %d\n", size());

    if(empty())
        printf("Deque is empty\n");
    else
        printf("Deque is not empty\n");

    return 0;
}
