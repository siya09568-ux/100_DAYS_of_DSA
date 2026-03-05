// Convert an infix expression to postfix notation using stack.
#include <stdio.h>
#include <ctype.h>

#define MAX 100

char stack[MAX];
int top = -1;

// Push function
void push(char x) {
    stack[++top] = x;
}

// Pop function
char pop() {
    return stack[top--];
}

// Check precedence
int precedence(char x) {
    if(x == '+' || x == '-')
        return 1;
    if(x == '*' || x == '/')
        return 2;
    if(x == '^')
        return 3;
    return 0;
}

int main() {
    char infix[MAX], postfix[MAX];
    int i, j = 0;

    // Input infix expression
    scanf("%s", infix);

    for(i = 0; infix[i] != '\0'; i++) {

        // If operand → add to postfix
        if(isalnum(infix[i])) {
            postfix[j++] = infix[i];
        }

        // If operator
        else {
            while(top != -1 && precedence(stack[top]) >= precedence(infix[i])) {
                postfix[j++] = pop();
            }
            push(infix[i]);
        }
    }

    // Pop remaining operators
    while(top != -1) {
        postfix[j++] = pop();
    }

    postfix[j] = '\0';

    // Print postfix
    printf("%s", postfix);

    return 0;
}
