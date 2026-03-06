//Evaluate Postfix Expression - Implement using linked list with dynamic memory allocation.
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

struct node {
    int data;
    struct node *next;
};

struct node *top = NULL;

// Push operation
void push(int value) {
    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = value;
    newnode->next = top;
    top = newnode;
}

// Pop operation
int pop() {
    if(top == NULL) {
        printf("Stack Underflow\n");
        return -1;
    }
    
    struct node *temp = top;
    int value = temp->data;
    top = top->next;
    free(temp);
    
    return value;
}

int main() {
    char postfix[100];
    int i, a, b, result;

    fgets(postfix, sizeof(postfix), stdin);

    for(i = 0; postfix[i] != '\0'; i++) {

        // If operand
        if(isdigit(postfix[i])) {
            push(postfix[i] - '0');
        }

        // If operator
        else if(postfix[i] == '+' || postfix[i] == '-' ||
                postfix[i] == '*' || postfix[i] == '/') {

            b = pop();
            a = pop();

            if(postfix[i] == '+')
                push(a + b);
            else if(postfix[i] == '-')
                push(a - b);
            else if(postfix[i] == '*')
                push(a * b);
            else if(postfix[i] == '/')
                push(a / b);
        }
    }

    result = pop();
    printf("%d", result);

    return 0;
}
